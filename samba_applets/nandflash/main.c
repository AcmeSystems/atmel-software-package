/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2016, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "applet.h"
#include "board.h"
#include "chip.h"
#include "trace.h"
#include "intmath.h"

#include "peripherals/pio.h"
#include "peripherals/hsmc.h"
#include "peripherals/pmecc.h"
#include "peripherals/pmecc_gallois_field_1024.h"
#include "peripherals/pmecc_gallois_field_512.h"

#include "memories/nand-flash/nand_flash.h"
#include "memories/nand-flash/nand_flash_skip_block.h"
#include "memories/nand-flash/nand_flash_spare_scheme.h"
#include "memories/nand-flash/nand_flash_model_list.h"
#include "memories/nand-flash/nand_flash_model.h"
#include "memories/nand-flash/nand_flash_ecc.h"
#include "memories/nand-flash/nand_flash_onfi.h"
#include "memories/nand-flash/nand_flash_dma.h"
#include "memories/nand-flash/nand_flash_raw.h"

#include "misc/console.h"

#include "pin_defs.h"

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*----------------------------------------------------------------------------
 *        Local definitions
 *----------------------------------------------------------------------------*/

#if !defined(CONFIG_SOC_SAMA5D2) && !defined(CONFIG_SOC_SAMA5D4)
#error Unsupported SOC!
#endif

#define NAND_HEADER_KEY  (0x0cu)

/* Header inserted at beginning of NAND flash.
 * Used by ROM-code to know how to configure NAND & PMECC */
union _nand_header
{
	uint32_t uint32_value;
	struct {
		uint32_t use_pmecc            : 1;
		uint32_t nb_sector_per_page   : 3; /* Number of Sectors per Page (0..3) */
		uint32_t spare_size           : 9; /* size of spare zone in bytes */
		uint32_t ecc_bit_req          : 3; /* Number of ECC Bits Required (0..5) */
		uint32_t sector_size          : 2; /* 0 for 512 bytes, 1 for 1024 bytes per sector, other val for future use */
		uint32_t ecc_offset           : 9; /* offset of the first ecc byte in spare zone */
		uint32_t reserved             : 1;
		uint32_t key                  : 4;
	} bitfield;
};

/*----------------------------------------------------------------------------
 *         Local variables
 *----------------------------------------------------------------------------*/

static bool initialized = false;

static uint8_t *buffer;
static uint32_t buffer_size;

static struct _nand_flash nand;
static uint32_t page_size;
static uint32_t block_size;

static uint8_t ecc_bit_req_2_tt[] = {
#if defined(CONFIG_SOC_SAMA5D2)
	2, 4, 8, 12, 24, 32
#elif defined(CONFIG_SOC_SAMA5D4)
	2, 4, 8, 12, 24
#endif
};

/*----------------------------------------------------------------------------
 *         Local functions
 *----------------------------------------------------------------------------*/

static bool configure_instance_pio(uint32_t ioset)
{
	int i;
	for (i = 0; i < num_nandflash_pin_defs; i++) {
		const struct nandflash_pin_definition* def = &nandflash_pin_defs[i];
		if (def->ioset == ioset) {
			pio_configure(def->pins, def->num_pins);
			return true;
		}
	}
	return false;
}

static bool pmecc_set_header(uint32_t nand_header)
{
	uint16_t sector_size_in_byte, ecc_size_in_byte;
	uint8_t mm;
	uint8_t ecc_correction;
	union _nand_header *header;

	header = (union _nand_header *)&nand_header;
	ecc_correction = ecc_bit_req_2_tt[header->bitfield.ecc_bit_req];

	if (header->bitfield.key != NAND_HEADER_KEY) {
		trace_error_wp("Invalid key field in PMECC configuration\r\n");
		return false;
	}

	if (!header->bitfield.use_pmecc) {
		printf("ECC disabled\r\n");
		nand_set_ecc_type(ECC_NO);
		return true;
	}

	if (ecc_correction < nand_onfi_get_ecc_correctability() &&
		nand_onfi_get_ecc_correctability() != 0xFF) {
		trace_error_wp("Invalid parameter ecc: Incompatible ecc vs ONFI %x\r\n",
				nand_onfi_get_ecc_correctability());
		return false;
	}

	if (header->bitfield.spare_size > nand_onfi_get_spare_size()) {
		trace_error_wp("Invalid parameter spare_size (%u): Spare size (%u) exceed\r\n",
				(unsigned)header->bitfield.spare_size,
				(unsigned)nand_onfi_get_spare_size());
		return false;
	}

	if (header->bitfield.ecc_bit_req >= ARRAY_SIZE(ecc_bit_req_2_tt)) {
		trace_error_wp("Invalid parameter ecc: Only support 2,4,8,12,24,(32)-bit ECC\r\n");
		return false;
	}

	if (header->bitfield.sector_size > 1) {
		trace_error_wp("Invalid parameter sector size: 0 for 512 bytes, 1 for 1024 bytes per sector\r\n");
		return false;
	}

	sector_size_in_byte = (header->bitfield.sector_size == 1) ? 1024 : 512;
	if ((page_size / sector_size_in_byte) > 8) {
		trace_error_wp("Invalid parameter sector size: not supportted page size or sector size\r\n");
		return false;
	}

	if (header->bitfield.ecc_offset > header->bitfield.spare_size) {
		trace_error_wp("Invalid parameter offset: Offset exceed spare zone\r\n");
		return false;
	}

	mm = header->bitfield.sector_size == 0 ? 13 : 14;
	if (((mm * ecc_correction) % 8 ) == 0) {
		ecc_size_in_byte = ((mm * ecc_correction) / 8) *
			(page_size / sector_size_in_byte);
	} else {
		ecc_size_in_byte = (((mm * ecc_correction) / 8 ) + 1) *
			(page_size / sector_size_in_byte);
	}

	if ((header->bitfield.ecc_offset + ecc_size_in_byte) > header->bitfield.spare_size) {
		trace_error_wp("Invalid parameter offset: Offset exceed spare zone\r\n");
		return false;
	}

	nand_set_ecc_type(ECC_PMECC);
	pmecc_initialize(header->bitfield.sector_size, ecc_correction,
					 page_size, header->bitfield.spare_size,
					 header->bitfield.ecc_offset, 0);

	printf("PMECC enabled\r\n");
	printf("Sector size: %d\r\n", sector_size_in_byte);
	printf("Sectors per page: %d\r\n", 1 << header->bitfield.nb_sector_per_page);
	printf("Spare size: %d\r\n", header->bitfield.spare_size);
	printf("ECC bits: %d\r\n", ecc_correction);
	printf("ECC offset: %d\r\n", header->bitfield.ecc_offset);

	return true;
}


static uint32_t handle_cmd_initialize(uint32_t cmd, uint32_t *mailbox)
{
	union initialize_mailbox *mbx = (union initialize_mailbox*)mailbox;
	uint32_t ioset = mbx->in.parameters[0];
	uint32_t bus_width = mbx->in.parameters[1];
	uint32_t nand_header = mbx->in.parameters[2];
	bool onfi_compatible = false;
	struct _nand_flash_model model_from_onfi;
	uint8_t correctability = 0;

	assert(cmd == APPLET_CMD_INITIALIZE);

	applet_set_init_params(mbx->in.comm_type, mbx->in.trace_level);
	initialized = false;

	trace_info_wp("\r\nApplet 'NAND Flash' from softpack "
			SOFTPACK_VERSION ".\r\n");

	trace_info_wp("Initializing NAND ioSet%u Bus Width %d\r\n",
			(unsigned)ioset, (unsigned)bus_width);

	if (bus_width != 8 && bus_width != 16) {
		trace_error_wp("Invalid NAND Bus Width %u, must be 8 or 16.\r\n",
			(unsigned)bus_width);
		return APPLET_FAIL;
	}

	board_cfg_matrix_for_nand();
	hsmc_nand_configure(bus_width);

	if (!configure_instance_pio(ioset)) {
		trace_error_wp("Invalid configuration: NFC ioSet%u\r\n",
			(unsigned)ioset);
		return APPLET_FAIL;
	}

	nand_initialize(&nand, NULL);

	if (!nand_onfi_device_detect(&nand)) {
		trace_error_wp("Can't detect device\r\n");
		return APPLET_FAIL;
	}

	if (nand_onfi_check_compatibility(&nand)) {
		model_from_onfi.device_id =
			nand_onfi_get_manufacturer_id();
		model_from_onfi.options =
			nand_onfi_get_bus_width() ? NANDFLASHMODEL_DATABUS16 : NANDFLASHMODEL_DATABUS8;
		model_from_onfi.page_size_in_bytes =
			nand_onfi_get_page_size();
		model_from_onfi.spare_size_in_bytes =
			nand_onfi_get_spare_size();
		model_from_onfi.device_size_in_mega_bytes =
			((nand_onfi_get_pages_per_block() * nand_onfi_get_blocks_per_lun()) / 1024) *
			nand_onfi_get_page_size() / 1024;
		model_from_onfi.block_size_in_kbytes =
			(nand_onfi_get_pages_per_block() * nand_onfi_get_page_size()) / 1024;

		correctability = nand_onfi_get_ecc_correctability();
		correctability = correctability == 0xFF ? 32 : correctability;

		switch (nand_onfi_get_page_size()) {
		case 256:
			model_from_onfi.scheme = &nand_spare_scheme256;
			break;
		case 512:
			model_from_onfi.scheme = &nand_spare_scheme512;
			break;
		case 2048:
			model_from_onfi.scheme = &nand_spare_scheme2048;
			break;
		case 4096:
			model_from_onfi.scheme = &nand_spare_scheme4096;
			break;
		case 8192:
			model_from_onfi.scheme = &nand_spare_scheme8192;
			break;
		}
		onfi_compatible = true;
	}

	nand_onfi_disable_internal_ecc(&nand);

	if (nand_raw_initialize(&nand,
				onfi_compatible ? &model_from_onfi : NULL)) {
		printf("-E- Device Unknown\r\n");
		return APPLET_FAIL;
	}

	nand_skipblock_initialize(&nand);

	/* Get device parameters */
	page_size = nand_model_get_page_data_size(&nand.model);
	block_size = nand_model_get_block_size_in_pages(&nand.model);
	nand_set_nfc_enabled(false);
	nand_set_nfc_sram_enabled(false);
	nand_set_dma_enabled(false);

	/* Initialize PMECC */
	if (!pmecc_set_header(nand_header)) {
		printf("-E- PMECC initialization failed\r\n");
		return APPLET_FAIL;
	}

	/* round buffer to a multiple of page size and check if it's big enough
	 * for at least one page */
	buffer = applet_buffer;
	buffer_size = applet_buffer_size & ~(page_size - 1);
	if (buffer_size == 0) {
		trace_info_wp("Not enough memory for buffer\r\n");
		return APPLET_FAIL;
	}
	trace_info_wp("Buffer Address: 0x%08x\r\n", (unsigned)buffer);
	trace_info_wp("Buffer Size: %u bytes\r\n", (unsigned)buffer_size);

	mbx->out.buf_addr = (uint32_t)buffer;
	mbx->out.buf_size = buffer_size;
	mbx->out.page_size = page_size;
	mbx->out.mem_size = nand_model_get_device_size_in_pages(&nand.model);
	mbx->out.erase_support = block_size;

	initialized = true;
	trace_info_wp("NAND applet initialized successfully.\r\n");
	return APPLET_SUCCESS;
}

/*
	Write data to NAND flash.
*/
static uint32_t handle_cmd_write_pages(uint32_t cmd, uint32_t *mailbox)
{
	union write_pages_mailbox *mbx = (union write_pages_mailbox*)mailbox;
	uint32_t i;
	uint8_t *buf;
	uint16_t block, page;

	assert(cmd == APPLET_CMD_WRITE_PAGES);

	/* check that requested size does not overflow buffer */
	if (mbx->in.length > buffer_size) {
		trace_error_wp("Buffer overflow\r\n");
		return APPLET_FAIL;
	}

	block = mbx->in.offset / block_size;
	page = mbx->in.offset - block * block_size;

	for (i = 0, buf = buffer; i < mbx->in.length; i++, buf += page_size) {
		trace_debug_wp("Writing %u bytes at block %u page %u (offset 0x%08x)\r\n",
				(unsigned)page_size, block, page,
				(unsigned)((block * block_size + page) * page_size));
		uint8_t status = nand_skipblock_write_page(&nand, block, page, buf, NULL);
		if (status == NAND_ERROR_BADBLOCK) {
			trace_error_wp("Cannot write bad block %u (page %u)\r\n",
					block, page);
			mbx->out.pages_written = i;
			return APPLET_BAD_BLOCK;
		} else if (status != 0) {
			trace_error_wp("Write error at block %u, page %u\r\n",
					block, page);
			mbx->out.pages_written = 0;
			return APPLET_WRITE_FAIL;
		}

		page++;
		if (page == block_size) {
			page = 0;
			block++;
		}
	}


	trace_info_wp("Wrote %u bytes at offset 0x%08x\r\n",
			(unsigned)(mbx->in.length * page_size),
			(unsigned)(mbx->in.offset * page_size));

	mbx->out.pages_written = mbx->in.length;

	return APPLET_SUCCESS;
}

/*
	Read data from NAND flash.
*/
static uint32_t handle_cmd_read_pages(uint32_t cmd, uint32_t *mailbox)
{
	union read_pages_mailbox *mbx = (union read_pages_mailbox*)mailbox;
	uint32_t i;
	uint8_t *buf;
	uint16_t block, page;

	assert(cmd == APPLET_CMD_READ_PAGES);

	/* check that requested size does not overflow buffer */
	if (mbx->in.length > buffer_size) {
		trace_error_wp("Buffer overflow\r\n");
		return APPLET_FAIL;
	}

	block = mbx->in.offset / block_size;
	page = mbx->in.offset - block * block_size;

	for (i = 0, buf = buffer; i < mbx->in.length; i++, buf += page_size) {
		uint8_t status = nand_skipblock_read_page(&nand, block, page, buf, NULL);
		if (status == NAND_ERROR_BADBLOCK) {
			trace_error_wp("Cannot read bad block %u\r\n", block);
			mbx->out.pages_read = i;
			return APPLET_BAD_BLOCK;
		} else if (status != 0) {
			trace_error_wp("Read error at block %u, page %u\r\n",
					block, page);
			mbx->out.pages_read = 0;
			return APPLET_READ_FAIL;
		}

		page++;
		if (page == block_size) {
			page = 0;
			block++;
		}
	}

	trace_info_wp("Read %u bytes at offset 0x%08x\r\n",
			(unsigned)(mbx->in.length * page_size),
			(unsigned)(mbx->in.offset * page_size));

	mbx->out.pages_read = mbx->in.length;

	return APPLET_SUCCESS;
}

/*
	Erase blocks from NAND flash.
*/
static uint32_t handle_cmd_erase_pages(uint32_t cmd, uint32_t *mailbox)
{
	union erase_pages_mailbox *mbx = (union erase_pages_mailbox*)mailbox;
	uint16_t block;
	uint8_t status;

	assert(cmd == APPLET_CMD_ERASE_PAGES);

	if (mbx->in.length != block_size) {
		trace_error("Memory does not support requested erase size %u bytes\r\n",
				(unsigned)(mbx->in.length * page_size));
		return APPLET_FAIL;
	}

	if (mbx->in.offset & (block_size - 1)) {
		trace_error("Unaligned erase offset: 0x%x (erase size %u bytes)\r\n",
				(unsigned)(mbx->in.offset * page_size),
				(unsigned)(mbx->in.length * page_size));
		return APPLET_FAIL;
	}
	block = mbx->in.offset / block_size;

	status = nand_skipblock_erase_block(&nand, block, NORMAL_ERASE);
	if (status == NAND_ERROR_BADBLOCK) {
		trace_error_wp("Cannot erase bad block %u\r\n", block);
		mbx->out.pages_erased = 0;
		return APPLET_BAD_BLOCK;
	} else if (status != 0) {
		trace_error_wp("Erase error at block %u\r\n", block);
		mbx->out.pages_erased = 0;
		return APPLET_ERASE_FAIL;
	}

	trace_info_wp("Erased %u bytes at 0x%08x\r\n",
			(unsigned)(mbx->in.length * page_size),
			(unsigned)(mbx->in.offset * page_size));
	mbx->out.pages_erased = mbx->in.length;

	return APPLET_SUCCESS;
}

/*----------------------------------------------------------------------------
 *         Commands list
 *----------------------------------------------------------------------------*/

const struct applet_command applet_commands[] = {
	{ APPLET_CMD_INITIALIZE, handle_cmd_initialize },
	{ APPLET_CMD_ERASE_PAGES, handle_cmd_erase_pages },
	{ APPLET_CMD_READ_PAGES, handle_cmd_read_pages },
	{ APPLET_CMD_WRITE_PAGES, handle_cmd_write_pages },
	{ 0, NULL }
};