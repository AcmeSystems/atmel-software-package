/* ---------------------------------------------------------------------------- */
/*                Microchip Microcontroller Software Support                    */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Microchip Technology Inc.                    */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Microchip's name may not be used to endorse or promote products derived from */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS  */
/* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES */
/* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT    */
/* ARE DISCLAIMED. IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT,        */
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES           */
/* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; */
/* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  */
/* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF     */
/* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.            */
/* ---------------------------------------------------------------------------- */

#ifndef _SAM9X_PMC_COMPONENT_
#define _SAM9X_PMC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Power Management Controller */
/* ============================================================================= */
/** \addtogroup SAM9X_PMC Power Management Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Pmc hardware registers */
typedef struct {
  __O  uint32_t PMC_SCER;       /**< \brief (Pmc Offset: 0x0000) System Clock Enable Register */
  __O  uint32_t PMC_SCDR;       /**< \brief (Pmc Offset: 0x0004) System Clock Disable Register */
  __I  uint32_t PMC_SCSR;       /**< \brief (Pmc Offset: 0x0008) System Clock Status Register */
  __IO uint32_t PMC_PLL_CTRL0;  /**< \brief (Pmc Offset: 0x000C) PLL Control Register 0 */
  __IO uint32_t PMC_PLL_CTRL1;  /**< \brief (Pmc Offset: 0x0010) PLL Control Register 1 */
  __IO uint32_t PMC_PLL_SSR;    /**< \brief (Pmc Offset: 0x0014) PLL Spread Spectrum Register */
  __IO uint32_t PMC_PLL_ACR;    /**< \brief (Pmc Offset: 0x0018) PLL Analog Control Register */
  __IO uint32_t PMC_PLL_UPDT;   /**< \brief (Pmc Offset: 0x001C) PLL Update Register */
  __IO uint32_t CKGR_MOR;       /**< \brief (Pmc Offset: 0x0020) Main Oscillator Register */
  __IO uint32_t CKGR_MCFR;      /**< \brief (Pmc Offset: 0x0024) Main Clock Frequency Register */
  __IO uint32_t PMC_MCKR;    /**< \brief (Pmc Offset: 0x0028) CPU Clock Register */
  __I  uint32_t Reserved1[3];
  __IO uint32_t PMC_USB;        /**< \brief (Pmc Offset: 0x0038) USB Clock Register */
  __I  uint32_t Reserved2[1];
  __IO uint32_t PMC_PCK[2];     /**< \brief (Pmc Offset: 0x40) Programmable Clock Register (chid = 0) */
  __I  uint32_t Reserved3[6];
  __O  uint32_t PMC_IER;        /**< \brief (Pmc Offset: 0x0060) Interrupt Enable Register */
  __O  uint32_t PMC_IDR;        /**< \brief (Pmc Offset: 0x0064) Interrupt Disable Register */
  __I  uint32_t PMC_SR;         /**< \brief (Pmc Offset: 0x0068) Status Register */
  __I  uint32_t PMC_IMR;        /**< \brief (Pmc Offset: 0x006C) Interrupt Mask Register */
  __IO uint32_t PMC_FSMR;       /**< \brief (Pmc Offset: 0x0070) Fast Startup Mode Register */
  __IO uint32_t PMC_WCR;        /**< \brief (Pmc Offset: 0x0074) Wakeup Control Register */
  __O  uint32_t PMC_FOCR;       /**< \brief (Pmc Offset: 0x0078) Fault Output Clear Register */
  __I  uint32_t Reserved4[1];
  __IO uint32_t PMC_WPMR;       /**< \brief (Pmc Offset: 0x0080) Write Protection Mode Register */
  __I  uint32_t PMC_WPSR;       /**< \brief (Pmc Offset: 0x0084) Write Protection Status Register */
  __IO uint32_t PMC_PCR;        /**< \brief (Pmc Offset: 0x0088) Peripheral Control Register */
  __IO uint32_t PMC_OCR;        /**< \brief (Pmc Offset: 0x008C) Oscillator Calibration Register */
  __I  uint32_t PMC_SLPWK_AIPR; /**< \brief (Pmc Offset: 0x0090) SleepWalking Activity In Progress Register */
  __IO uint32_t PMC_SLPWKCR;    /**< \brief (Pmc Offset: 0x0094) SleepWalking Control Register */
  __IO uint32_t PMC_ULPST;      /**< \brief (Pmc Offset: 0x0098) ULP Startup Time Register */
  __IO uint32_t PMC_MCKLIM;     /**< \brief (Pmc Offset: 0x009C) MCK Monitor Limits Register */
  __I  uint32_t PMC_CSR[4];     /**< \brief (Pmc Offset: 0x00A0) Peripheral Clock Status Register 0~3 */
  __I  uint32_t Reserved5[4];
  __I  uint32_t PMC_GCSR[4];    /**< \brief (Pmc Offset: 0x00C0) Generic Clock Status Register 0~3 */
  __I  uint32_t Reserved6[4];
  __O  uint32_t PMC_PLL_IER;    /**< \brief (Pmc Offset: 0x00E0) PLL Interrupt Enable Register */
  __O  uint32_t PMC_PLL_IDR;    /**< \brief (Pmc Offset: 0x00E4) PLL Interrupt Disable Register */
  __I  uint32_t PMC_PLL_IMR;    /**< \brief (Pmc Offset: 0x00E8) PLL Interrupt Mask Register */
  __I  uint32_t PMC_PLL_ISR0;   /**< \brief (Pmc Offset: 0x00EC) PLL Interrupt Status Register 0 */
  __I  uint32_t PMC_PLL_ISR1;   /**< \brief (Pmc Offset: 0x00F0) PLL Interrupt Status Register 1 */
  __I  uint32_t Reserved7[3];
  __I  uint32_t PMC_ADDRSIZE;   /**< \brief (Pmc Offset: 0x0100) Address Size Register */
  __I  uint32_t PMC_NAME[2];    /**< \brief (Pmc Offset: 0x0104) IP Name Register */
  __I  uint32_t PMC_FEATURES;   /**< \brief (Pmc Offset: 0x010C) Features Register */
  __I  uint32_t PMC_VERSION;    /**< \brief (Pmc Offset: 0x0110) Version Register */
} Pmc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PMC_SCER : (PMC Offset: 0x0000) System Clock Enable Register -------- */
#define PMC_SCER_DDRCK (0x1u << 2) /**< \brief (PMC_SCER) DDR Clock Enable */
#define PMC_SCER_LCDCK (0x1u << 3) /**< \brief (PMC_SCER) Enable LCD 2x Clock */
#define PMC_SCER_UHP (0x1u << 6) /**< \brief (PMC_SCER) USB Host OHCI Clocks Enable */
#define PMC_SCER_PCK0 (0x1u << 8) /**< \brief (PMC_SCER) Programmable Clock 0 Output Enable */
#define PMC_SCER_PCK1 (0x1u << 9) /**< \brief (PMC_SCER) Programmable Clock 1 Output Enable */
#define PMC_SCER_ISICLK (0x1u << 18) /**< \brief (PMC_SCER) Enable ISI 2x Clock */
#define PMC_SCER_QSPICLK (0x1u << 19) /**< \brief (PMC_SCER) Enable QSPI 2x Clock */
/* -------- PMC_SCDR : (PMC Offset: 0x0004) System Clock Disable Register -------- */
#define PMC_SCDR_DDRCK (0x1u << 2) /**< \brief (PMC_SCDR) DDR Clock Disable */
#define PMC_SCDR_LCDCK (0x1u << 3) /**< \brief (PMC_SCDR) LCD Clock Disable */
#define PMC_SCDR_UHP (0x1u << 6) /**< \brief (PMC_SCDR) USB Host OHCI Clocks Disable */
#define PMC_SCDR_PCK0 (0x1u << 8) /**< \brief (PMC_SCDR) Programmable Clock 0 Output Disable */
#define PMC_SCDR_PCK1 (0x1u << 9) /**< \brief (PMC_SCDR) Programmable Clock 1 Output Disable */
#define PMC_SCDR_ISICLK (0x1u << 18) /**< \brief (PMC_SCDR) ISI 2x Clock Disable */
#define PMC_SCDR_QSPICLK (0x1u << 19) /**< \brief (PMC_SCDR) QSPI 2x Clock Disable */
/* -------- PMC_SCSR : (PMC Offset: 0x0008) System Clock Status Register -------- */
#define PMC_SCSR_CPU_CLKS (0x1u << 0) /**< \brief (PMC_SCSR) CPU_CLK Status */
#define PMC_SCSR_DDRCK (0x1u << 2) /**< \brief (PMC_SCSR) DDR Clock Status */
#define PMC_SCSR_LCDCK (0x1u << 3) /**< \brief (PMC_SCSR) LCD Clock Status */
#define PMC_SCSR_UHP (0x1u << 6) /**< \brief (PMC_SCSR) USB Host OHCI Clocks Status */
#define PMC_SCSR_PCK0 (0x1u << 8) /**< \brief (PMC_SCSR) Programmable Clock 0 Output Status */
#define PMC_SCSR_PCK1 (0x1u << 9) /**< \brief (PMC_SCSR) Programmable Clock 1 Output Status */
#define PMC_SCSR_ISICLK (0x1u << 18) /**< \brief (PMC_SCSR) ISI 2x Clock Status */
#define PMC_SCSR_QSPICLK (0x1u << 19) /**< \brief (PMC_SCSR) QSPI 2x Clock Status */
/* -------- PMC_PLL_CTRL0 : (PMC Offset: 0x000C) PLL Control Register 0 -------- */
#define PMC_PLL_CTRL0_DIVPMC_Pos 0
#define PMC_PLL_CTRL0_DIVPMC_Msk (0xffu << PMC_PLL_CTRL0_DIVPMC_Pos) /**< \brief (PMC_PLL_CTRL0) Divider for PMC */
#define PMC_PLL_CTRL0_DIVPMC(value) ((PMC_PLL_CTRL0_DIVPMC_Msk & ((value) << PMC_PLL_CTRL0_DIVPMC_Pos)))
#define PMC_PLL_CTRL0_DIVIO_Pos 12
#define PMC_PLL_CTRL0_DIVIO_Msk (0xffu << PMC_PLL_CTRL0_DIVIO_Pos) /**< \brief (PMC_PLL_CTRL0) Divider for PAD */
#define PMC_PLL_CTRL0_DIVIO(value) ((PMC_PLL_CTRL0_DIVIO_Msk & ((value) << PMC_PLL_CTRL0_DIVIO_Pos)))
#define PMC_PLL_CTRL0_ENPLL (0x1u << 28) /**< \brief (PMC_PLL_CTRL0) Enable PLL */
#define PMC_PLL_CTRL0_ENPLLCK (0x1u << 29) /**< \brief (PMC_PLL_CTRL0) Enable PLL Clock for PMC */
#define PMC_PLL_CTRL0_ENLOCK (0x1u << 31) /**< \brief (PMC_PLL_CTRL0) Enable PLL Lock */
/* -------- PMC_PLL_CTRL1 : (PMC Offset: 0x0010) PLL Control Register 1 -------- */
#define PMC_PLL_CTRL1_FRACR_Pos 0
#define PMC_PLL_CTRL1_FRACR_Msk (0x3fffffu << PMC_PLL_CTRL1_FRACR_Pos) /**< \brief (PMC_PLL_CTRL1) Fractional Loop Divider Setting */
#define PMC_PLL_CTRL1_FRACR(value) ((PMC_PLL_CTRL1_FRACR_Msk & ((value) << PMC_PLL_CTRL1_FRACR_Pos)))
#define PMC_PLL_CTRL1_MUL_Pos 24
#define PMC_PLL_CTRL1_MUL_Msk (0x7fu << PMC_PLL_CTRL1_MUL_Pos) /**< \brief (PMC_PLL_CTRL1) Multiplier Factor Value */
#define PMC_PLL_CTRL1_MUL(value) ((PMC_PLL_CTRL1_MUL_Msk & ((value) << PMC_PLL_CTRL1_MUL_Pos)))
/* -------- PMC_PLL_SSR : (PMC Offset: 0x0014) PLL Spread Spectrum Register -------- */
#define PMC_PLL_SSR_STEP_Pos 0
#define PMC_PLL_SSR_STEP_Msk (0xffffu << PMC_PLL_SSR_STEP_Pos) /**< \brief (PMC_PLL_SSR) Spread Spectrum Step Size */
#define PMC_PLL_SSR_STEP(value) ((PMC_PLL_SSR_STEP_Msk & ((value) << PMC_PLL_SSR_STEP_Pos)))
#define PMC_PLL_SSR_NSTEP_Pos 16
#define PMC_PLL_SSR_NSTEP_Msk (0xffu << PMC_PLL_SSR_NSTEP_Pos) /**< \brief (PMC_PLL_SSR) Spread Spectrum Number of Step */
#define PMC_PLL_SSR_NSTEP(value) ((PMC_PLL_SSR_NSTEP_Msk & ((value) << PMC_PLL_SSR_NSTEP_Pos)))
#define PMC_PLL_SSR_ENSPREAD (0x1u << 28) /**< \brief (PMC_PLL_SSR) Spread Spectrum Enable */
/* -------- PMC_PLL_ACR : (PMC Offset: 0x0018) PLL Analog Control Register -------- */
#define PMC_PLL_ACR_CONTROL_Pos 0
#define PMC_PLL_ACR_CONTROL_Msk (0xfffu << PMC_PLL_ACR_CONTROL_Pos) /**< \brief (PMC_PLL_ACR) PLL CONTROL Value Selection */
#define PMC_PLL_ACR_CONTROL(value) ((PMC_PLL_ACR_CONTROL_Msk & ((value) << PMC_PLL_ACR_CONTROL_Pos)))
#define PMC_PLL_ACR_UTMIVR (0x1u << 12) /**< \brief (PMC_PLL_ACR) UPLL Voltage Regulator Control */
#define PMC_PLL_ACR_UTMIBG (0x1u << 13) /**< \brief (PMC_PLL_ACR) UPLL Bandgap Control */
#define PMC_PLL_ACR_LOCK_THR_Pos 16
#define PMC_PLL_ACR_LOCK_THR_Msk (0xffu << PMC_PLL_ACR_LOCK_THR_Pos) /**< \brief (PMC_PLL_ACR) PLL Lock Threshold Value Selection */
#define PMC_PLL_ACR_LOCK_THR(value) ((PMC_PLL_ACR_LOCK_THR_Msk & ((value) << PMC_PLL_ACR_LOCK_THR_Pos)))
#define PMC_PLL_ACR_LOOP_FILTER_Pos 24
#define PMC_PLL_ACR_LOOP_FILTER_Msk (0xffu << PMC_PLL_ACR_LOOP_FILTER_Pos) /**< \brief (PMC_PLL_ACR) LOOP Filter Selection */
#define PMC_PLL_ACR_LOOP_FILTER(value) ((PMC_PLL_ACR_LOOP_FILTER_Msk & ((value) << PMC_PLL_ACR_LOOP_FILTER_Pos)))
/* -------- PMC_PLL_UPDT : (PMC Offset: 0x001C) PLL Update Register -------- */
#define PMC_PLL_UPDT_ID_Pos 0
#define PMC_PLL_UPDT_ID_Msk (0xfu << PMC_PLL_UPDT_ID_Pos) /**< \brief (PMC_PLL_UPDT) PLL ID */
#define PMC_PLL_UPDT_ID(value) ((PMC_PLL_UPDT_ID_Msk & ((value) << PMC_PLL_UPDT_ID_Pos)))
#define PMC_PLL_UPDT_UPDATE (0x1u << 8) /**< \brief (PMC_PLL_UPDT) PLL Setting Update (write-only) */
#define PMC_PLL_UPDT_STUPTIM_Pos 16
#define PMC_PLL_UPDT_STUPTIM_Msk (0xffu << PMC_PLL_UPDT_STUPTIM_Pos) /**< \brief (PMC_PLL_UPDT) Startup Time */
#define PMC_PLL_UPDT_STUPTIM(value) ((PMC_PLL_UPDT_STUPTIM_Msk & ((value) << PMC_PLL_UPDT_STUPTIM_Pos)))
/* -------- CKGR_MOR : (PMC Offset: 0x0020) Main Oscillator Register -------- */
#define CKGR_MOR_MOSCXTEN (0x1u << 0) /**< \brief (CKGR_MOR) Main Crystal Oscillator Enable */
#define CKGR_MOR_MOSCXTBY (0x1u << 1) /**< \brief (CKGR_MOR) Main Crystal Oscillator Bypass */
#define CKGR_MOR_ULP1 (0x1u << 2) /**< \brief (CKGR_MOR) ULP Mode 1 Command (write-only) */
#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main RC Oscillator Enable */
#define CKGR_MOR_MOSCXTST_Pos 8
#define CKGR_MOR_MOSCXTST_Msk (0xffu << CKGR_MOR_MOSCXTST_Pos) /**< \brief (CKGR_MOR) Main Crystal Oscillator Startup Time */
#define CKGR_MOR_MOSCXTST(value) ((CKGR_MOR_MOSCXTST_Msk & ((value) << CKGR_MOR_MOSCXTST_Pos)))
#define CKGR_MOR_KEY_Pos 16
#define CKGR_MOR_KEY_Msk (0xffu << CKGR_MOR_KEY_Pos) /**< \brief (CKGR_MOR) Write Access Password */
#define CKGR_MOR_KEY(value) ((CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos)))
#define   CKGR_MOR_KEY_PASSWD (0x37u << 16) /**< \brief (CKGR_MOR) Writing any other value in this field aborts the write operation.Always reads as 0. */
#define CKGR_MOR_MOSCSEL (0x1u << 24) /**< \brief (CKGR_MOR) Main Clock Oscillator Selection */
#define CKGR_MOR_CFDEN (0x1u << 25) /**< \brief (CKGR_MOR) Clock Failure Detector Enable */
#define CKGR_MOR_XT32KFME (0x1u << 26) /**< \brief (CKGR_MOR) 32.768 kHz Crystal Oscillator Frequency Monitoring Enable */
#define CKGR_MOR_BMCKRST (0x1u << 27) /**< \brief (CKGR_MOR) Bad MCK Clock Reset Enable */
/* -------- CKGR_MCFR : (PMC Offset: 0x0024) Main Clock Frequency Register -------- */
#define CKGR_MCFR_MAINF_Pos 0
#define CKGR_MCFR_MAINF_Msk (0xffffu << CKGR_MCFR_MAINF_Pos) /**< \brief (CKGR_MCFR) Main Clock Frequency */
#define CKGR_MCFR_MAINF(value) ((CKGR_MCFR_MAINF_Msk & ((value) << CKGR_MCFR_MAINF_Pos)))
#define CKGR_MCFR_MAINFRDY (0x1u << 16) /**< \brief (CKGR_MCFR) Main Clock Frequency Measure Ready */
#define CKGR_MCFR_RCMEAS (0x1u << 20) /**< \brief (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) */
#define CKGR_MCFR_CCSS (0x1u << 24) /**< \brief (CKGR_MCFR) Counter Clock Source Selection */
/* -------- PMC_CPU_CKR : (PMC Offset: 0x0028) CPU Clock Register -------- */
#define PMC_MCKR_CSS_Pos 0
#define PMC_MCKR_CSS_Msk (0x3u << PMC_MCKR_CSS_Pos) /**< \brief (PMC_MCKR) Master/Processor Clock Source Selection */
#define PMC_MCKR_CSS(value) ((PMC_MCKR_CSS_Msk & ((value) << PMC_MCKR_CSS_Pos)))
#define   PMC_MCKR_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_MCKR) Slow Clock is selected */
#define   PMC_MCKR_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_MCKR) Main Clock is selected */
#define   PMC_MCKR_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_MCKR) PLLA Clock is selected */
#define   PMC_MCKR_CSS_UPLL_CLK (0x3u << 0) /**< \brief (PMC_MCKR) UPLL Clock is selected */
#define PMC_MCKR_PRES_Pos 4
#define PMC_MCKR_PRES_Msk (0x7u << PMC_MCKR_PRES_Pos) /**< \brief (PMC_MCKR) Master/Processor Clock Prescaler */
#define PMC_MCKR_PRES(value) ((PMC_MCKR_PRES_Msk & ((value) << PMC_MCKR_PRES_Pos)))
#define   PMC_MCKR_PRES_CLOCK (0x0u << 4) /**< \brief (PMC_MCKR) Selected clock */
#define   PMC_MCKR_PRES_CLOCK_DIV2 (0x1u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 2 */
#define   PMC_MCKR_PRES_CLOCK_DIV4 (0x2u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 4 */
#define   PMC_MCKR_PRES_CLOCK_DIV8 (0x3u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 8 */
#define   PMC_MCKR_PRES_CLOCK_DIV16 (0x4u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 16 */
#define   PMC_MCKR_PRES_CLOCK_DIV32 (0x5u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 32 */
#define   PMC_MCKR_PRES_CLOCK_DIV64 (0x6u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 64 */
#define   PMC_MCKR_PRES_CLOCK_DIV3 (0x7u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 3 */
#define PMC_MCKR_MDIV_Pos 8
#define PMC_MCKR_MDIV_Msk (0x3u << PMC_MCKR_MDIV_Pos) /**< \brief (PMC_MCKR) Master Clock Division */
#define PMC_MCKR_MDIV(value) ((PMC_MCKR_MDIV_Msk & ((value) << PMC_MCKR_MDIV_Pos)))
#define   PMC_MCKR_MDIV_EQ_PCK (0x0u << 8) /**< \brief (PMC_MCKR) Master Clock is Prescaler Output Clock divided by 1 */
#define   PMC_MCKR_MDIV_PCK_DIV2 (0x1u << 8) /**< \brief (PMC_MCKR) Master Clock is Prescaler Output Clock divided by 2 */
#define   PMC_MCKR_MDIV_PCK_DIV4 (0x2u << 8) /**< \brief (PMC_MCKR) Master Clock is Prescaler Output Clock divided by 4 */
#define   PMC_MCKR_MDIV_PCK_DIV3 (0x3u << 8) /**< \brief (PMC_MCKR) Master Clock is Prescaler Output Clock divided by 3 */
/* -------- PMC_USB : (PMC Offset: 0x0038) USB Clock Register -------- */
#define PMC_USB_USBS (0x1u << 0) /**< \brief (PMC_USB) USB OHCI Input Clock Selection */
#define PMC_USB_USBDIV_Pos 8
#define PMC_USB_USBDIV_Msk (0xfu << PMC_USB_USBDIV_Pos) /**< \brief (PMC_USB) Divider for USB OHCI Clock */
#define PMC_USB_USBDIV(value) ((PMC_USB_USBDIV_Msk & ((value) << PMC_USB_USBDIV_Pos)))
/* -------- PMC_PCK[2] : (PMC Offset: 0x40) Programmable Clock Register (chid = 0) -------- */
#define PMC_PCK_CSS_Pos 0
#define PMC_PCK_CSS_Msk (0x1fu << PMC_PCK_CSS_Pos) /**< \brief (PMC_PCK[2]) Programmable Clock Source Selection */
#define PMC_PCK_CSS(value) ((PMC_PCK_CSS_Msk & ((value) << PMC_PCK_CSS_Pos)))
#define   PMC_PCK_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_PCK[2]) Slow Clock is selected */
#define   PMC_PCK_CSS_TD_SLOW_CLOCK (0x1u << 0) /**< \brief (PMC_PCK[2]) TD_SLCK is selected */
#define   PMC_PCK_CSS_MAIN_CLK (0x2u << 0) /**< \brief (PMC_PCK[2]) MAINCK is selected */
#define   PMC_PCK_CSS_MCK (0x3u << 0) /**< \brief (PMC_PCK[2]) MCK is selected */
#define   PMC_PCK_CSS_PLLA_CLK (0x4u << 0) /**< \brief (PMC_PCK[2]) PLLA is selected. */
#define   PMC_PCK_CSS_UPLL_CLK (0x5u << 0) /**< \brief (PMC_PCK[2]) UPLL is selected. */
#define PMC_PCK_PRES_Pos 8
#define PMC_PCK_PRES_Msk (0xffu << PMC_PCK_PRES_Pos) /**< \brief (PMC_PCK[2]) Programmable Clock Prescaler */
#define PMC_PCK_PRES(value) ((PMC_PCK_PRES_Msk & ((value) << PMC_PCK_PRES_Pos)))
/* -------- PMC_IER : (PMC Offset: 0x0060) Interrupt Enable Register -------- */
#define PMC_IER_MOSCXTS (0x1u << 0) /**< \brief (PMC_IER) Main Crystal Oscillator Status Interrupt Enable */
#define PMC_IER_MCKRDY (0x1u << 3) /**< \brief (PMC_IER) Master Clock Ready Interrupt Enable */
#define PMC_IER_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IER) Programmable Clock Ready 0 Interrupt Enable */
#define PMC_IER_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IER) Programmable Clock Ready 1 Interrupt Enable */
#define PMC_IER_MOSCSELS (0x1u << 16) /**< \brief (PMC_IER) Main Clock Source Oscillator Selection Status Interrupt Enable */
#define PMC_IER_MOSCRCS (0x1u << 17) /**< \brief (PMC_IER) Main RC Oscillator Status Interrupt Enable */
#define PMC_IER_CFDEV (0x1u << 18) /**< \brief (PMC_IER) Clock Failure Detector Event Interrupt Enable */
#define PMC_IER_XT32KERR (0x1u << 21) /**< \brief (PMC_IER) 32.768 kHz Crystal Oscillator Error Interrupt Enable */
#define PMC_IER_MCKMON (0x1u << 23) /**< \brief (PMC_IER) Master Clock  Clock Monitor Interrupt Enable */
/* -------- PMC_IDR : (PMC Offset: 0x0064) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable */
#define PMC_IDR_MCKRDY (0x1u << 3) /**< \brief (PMC_IDR) Master Clock Ready Interrupt Disable */
#define PMC_IDR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable */
#define PMC_IDR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable */
#define PMC_IDR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IDR) Main Clock Source Oscillator Selection Status Interrupt Disable */
#define PMC_IDR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IDR) Main RC Status Interrupt Disable */
#define PMC_IDR_CFDEV (0x1u << 18) /**< \brief (PMC_IDR) Clock Failure Detector Event Interrupt Disable */
#define PMC_IDR_XT32KERR (0x1u << 21) /**< \brief (PMC_IDR) 32.768 kHz Crystal Oscillator Error Interrupt Disable */
#define PMC_IDR_MCKMON (0x1u << 23) /**< \brief (PMC_IDR) Master Clock  Clock Monitor Interrupt Disable */
/* -------- PMC_SR : (PMC Offset: 0x0068) Status Register -------- */
#define PMC_SR_MOSCXTS (0x1u << 0) /**< \brief (PMC_SR) Main Crystal Oscillator Status */
#define PMC_SR_MCKRDY (0x1u << 3) /**< \brief (PMC_SR) Master Clock Status */
#define PMC_SR_LOCKU (0x1u << 6) /**< \brief (PMC_SR) UPLL Clock Status */
#define PMC_SR_OSCSELS (0x1u << 7) /**< \brief (PMC_SR) Monitoring Domain Slow Clock Source Oscillator Selection */
#define PMC_SR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_MOSCSELS (0x1u << 16) /**< \brief (PMC_SR) Main Clock Source Oscillator Selection Status */
#define PMC_SR_MOSCRCS (0x1u << 17) /**< \brief (PMC_SR) Main RC Oscillator Status */
#define PMC_SR_CFDEV (0x1u << 18) /**< \brief (PMC_SR) Clock Failure Detector Event */
#define PMC_SR_CFDS (0x1u << 19) /**< \brief (PMC_SR) Clock Failure Detector Status */
#define PMC_SR_FOS (0x1u << 20) /**< \brief (PMC_SR) Clock Failure Detector Fault Output Status */
#define PMC_SR_XT32KERR (0x1u << 21) /**< \brief (PMC_SR) Slow Crystal Oscillator Error */
#define PMC_SR_MCKMON (0x1u << 23) /**< \brief (PMC_SR) Master Clock Clock Monitor Error */
#define PMC_SR_PLL_INT (0x1u << 25) /**< \brief (PMC_SR) PLL Interrupt Status */
/* -------- PMC_IMR : (PMC Offset: 0x006C) Interrupt Mask Register -------- */
#define PMC_IMR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask */
#define PMC_IMR_MCKRDY (0x1u << 3) /**< \brief (PMC_IMR) Master Clock Ready Interrupt Mask */
#define PMC_IMR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask */
#define PMC_IMR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask */
#define PMC_IMR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IMR) Main Clock Source Oscillator Selection Status Interrupt Mask */
#define PMC_IMR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IMR) Main RC Status Interrupt Mask */
#define PMC_IMR_CFDEV (0x1u << 18) /**< \brief (PMC_IMR) Clock Failure Detector Event Interrupt Mask */
#define PMC_IMR_XT32KERR (0x1u << 21) /**< \brief (PMC_IMR) 32.768 kHz Crystal Oscillator Error Interrupt Mask */
#define PMC_IMR_MCKMON (0x1u << 23) /**< \brief (PMC_IMR) Master Clock  Monitor Error Interrupt Mask */
/* -------- PMC_FSMR : (PMC Offset: 0x0070) Fast Startup Mode Register -------- */
#define PMC_FSMR_RTTAL (0x1u << 16) /**< \brief (PMC_FSMR) RTT Alarm Enable */
#define PMC_FSMR_RTCAL (0x1u << 17) /**< \brief (PMC_FSMR) RTC Alarm Enable */
#define PMC_FSMR_USBAL (0x1u << 18) /**< \brief (PMC_FSMR) USB Alarm Enable */
#define PMC_FSMR_WLAN0 (0x1u << 24) /**< \brief (PMC_FSMR) Wakeup on LAN[x] */
#define PMC_FSMR_WLAN1 (0x1u << 25) /**< \brief (PMC_FSMR) Wakeup on LAN[x] */
/* -------- PMC_WCR : (PMC Offset: 0x0074) Wakeup Control Register -------- */
#define PMC_WCR_WKPIONB_Pos 0
#define PMC_WCR_WKPIONB_Msk (0xfu << PMC_WCR_WKPIONB_Pos) /**< \brief (PMC_WCR) Wakeup Input Number */
#define PMC_WCR_WKPIONB(value) ((PMC_WCR_WKPIONB_Msk & ((value) << PMC_WCR_WKPIONB_Pos)))
#define PMC_WCR_EN (0x1u << 16) /**< \brief (PMC_WCR) Wakeup Input Enable */
#define PMC_WCR_WIP (0x1u << 17) /**< \brief (PMC_WCR) Wakeup Input Polarity */
#define PMC_WCR_CMD (0x1u << 24) /**< \brief (PMC_WCR) Command */
/* -------- PMC_FOCR : (PMC Offset: 0x0078) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR (0x1u << 0) /**< \brief (PMC_FOCR) Fault Output Clear */
/* -------- PMC_WPMR : (PMC Offset: 0x0080) Write Protection Mode Register -------- */
#define PMC_WPMR_WPEN (0x1u << 0) /**< \brief (PMC_WPMR) Write Protection Enable */
#define PMC_WPMR_WPITEN (0x1u << 1) /**< \brief (PMC_WPMR) Write Protection Interrupt Enable */
#define PMC_WPMR_WPKEY_Pos 8
#define PMC_WPMR_WPKEY_Msk (0xffffffu << PMC_WPMR_WPKEY_Pos) /**< \brief (PMC_WPMR) Write Protection Key */
#define PMC_WPMR_WPKEY(value) ((PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos)))
#define   PMC_WPMR_WPKEY_PASSWD (0x504D43u << 8) /**< \brief (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. */
/* -------- PMC_WPSR : (PMC Offset: 0x0084) Write Protection Status Register -------- */
#define PMC_WPSR_WPVS (0x1u << 0) /**< \brief (PMC_WPSR) Write Protection Violation Status */
#define PMC_WPSR_WPVSRC_Pos 8
#define PMC_WPSR_WPVSRC_Msk (0xffffu << PMC_WPSR_WPVSRC_Pos) /**< \brief (PMC_WPSR) Write Protection Violation Source */
/* -------- PMC_PCR : (PMC Offset: 0x0088) Peripheral Control Register -------- */
#define PMC_PCR_PID_Pos 0
#define PMC_PCR_PID_Msk (0x7fu << PMC_PCR_PID_Pos) /**< \brief (PMC_PCR) Peripheral ID */
#define PMC_PCR_PID(value) ((PMC_PCR_PID_Msk & ((value) << PMC_PCR_PID_Pos)))
#define PMC_PCR_GCKCSS_Pos 8
#define PMC_PCR_GCKCSS_Msk (0x1fu << PMC_PCR_GCKCSS_Pos) /**< \brief (PMC_PCR) Generic Clock Source Selection */
#define PMC_PCR_GCKCSS(value) ((PMC_PCR_GCKCSS_Msk & ((value) << PMC_PCR_GCKCSS_Pos)))
#define   PMC_PCR_GCKCSS_SLOW_CLK (0x0u << 8) /**< \brief (PMC_PCR) MD_SLCK is selected */
#define   PMC_PCR_GCKCSS_TD_SLOW_CLOCK (0x1u << 8) /**< \brief (PMC_PCR) TD_SLCK is selected */
#define   PMC_PCR_GCKCSS_MAIN_CLK (0x2u << 8) /**< \brief (PMC_PCR) MAINCK is selected */
#define   PMC_PCR_GCKCSS_MCK_CLK (0x3u << 8) /**< \brief (PMC_PCR) MCK is selected */
#define   PMC_PCR_GCKCSS_PLLA_CLK (0x4u << 8) /**< \brief (PMC_PCR) PLLA is selected. */
#define   PMC_PCR_GCKCSS_UPLL_CLK (0x5u << 8) /**< \brief (PMC_PCR) UPLL is selected. */
#define PMC_PCR_DIV_Pos 14
#define PMC_PCR_DIV_Msk (0x3u << PMC_PCR_DIV_Pos) /**< \brief (PMC_PCR) Peripheral Clock Division Ratio */
#define PMC_PCR_DIV(value) ((PMC_PCR_DIV_Msk & ((value) << PMC_PCR_DIV_Pos)))
#define   PMC_PCR_DIV_DIV1 (0x0u << 14) /**< \brief (PMC_PCR) MCK is divided by 1. */
#define   PMC_PCR_DIV_DIV2 (0x1u << 14) /**< \brief (PMC_PCR) MCK is divided by 2. */
#define   PMC_PCR_DIV_DIV4 (0x2u << 14) /**< \brief (PMC_PCR) MCK is divided by 4. */
#define   PMC_PCR_DIV_DIV8 (0x3u << 14) /**< \brief (PMC_PCR) MCK is divided by 8. */
#define PMC_PCR_GCKDIV_Pos 20
#define PMC_PCR_GCKDIV_Msk (0xffu << PMC_PCR_GCKDIV_Pos) /**< \brief (PMC_PCR) Generic Clock Division Ratio */
#define PMC_PCR_GCKDIV(value) ((PMC_PCR_GCKDIV_Msk & ((value) << PMC_PCR_GCKDIV_Pos)))
#define PMC_PCR_EN (0x1u << 28) /**< \brief (PMC_PCR) Enable */
#define PMC_PCR_GCKEN (0x1u << 29) /**< \brief (PMC_PCR) Generic Clock Enable */
#define PMC_PCR_CMD (0x1u << 31) /**< \brief (PMC_PCR) Command */
/* -------- PMC_OCR : (PMC Offset: 0x008C) Oscillator Calibration Register -------- */
#define PMC_OCR_CAL12_Pos 16
#define PMC_OCR_CAL12_Msk (0x7fu << PMC_OCR_CAL12_Pos) /**< \brief (PMC_OCR) Main RC Oscillator Calibration Bits */
#define PMC_OCR_CAL12(value) ((PMC_OCR_CAL12_Msk & ((value) << PMC_OCR_CAL12_Pos)))
#define PMC_OCR_SEL12 (0x1u << 23) /**< \brief (PMC_OCR) Selection of Main RC Oscillator Calibration Bits */
/* -------- PMC_SLPWK_AIPR : (PMC Offset: 0x0090) SleepWalking Activity In Progress Register -------- */
#define PMC_SLPWK_AIPR_AIP (0x1u << 0) /**< \brief (PMC_SLPWK_AIPR) Activity In Progress */
/* -------- PMC_SLPWKCR : (PMC Offset: 0x0094) SleepWalking Control Register -------- */
#define PMC_SLPWKCR_PID_Pos 0
#define PMC_SLPWKCR_PID_Msk (0x7fu << PMC_SLPWKCR_PID_Pos) /**< \brief (PMC_SLPWKCR) Peripheral ID */
#define PMC_SLPWKCR_PID(value) ((PMC_SLPWKCR_PID_Msk & ((value) << PMC_SLPWKCR_PID_Pos)))
#define PMC_SLPWKCR_CMD (0x1u << 12) /**< \brief (PMC_SLPWKCR) Command */
#define PMC_SLPWKCR_ASR (0x1u << 16) /**< \brief (PMC_SLPWKCR) Activity Status Register */
#define PMC_SLPWKCR_SLPWKSR (0x1u << 28) /**< \brief (PMC_SLPWKCR) SleepWalking Sleep Register */
/* -------- PMC_ULPST : (PMC Offset: 0x0098) ULP Startup Time Register -------- */
#define PMC_ULPST_ULPST_Pos 0
#define PMC_ULPST_ULPST_Msk (0xffu << PMC_ULPST_ULPST_Pos) /**< \brief (PMC_ULPST) Ultra Low Power Mode Startup Time */
#define PMC_ULPST_ULPST(value) ((PMC_ULPST_ULPST_Msk & ((value) << PMC_ULPST_ULPST_Pos)))
#define PMC_ULPST_KEY_Pos 24
#define PMC_ULPST_KEY_Msk (0xffu << PMC_ULPST_KEY_Pos) /**< \brief (PMC_ULPST) Write Access Password */
#define PMC_ULPST_KEY(value) ((PMC_ULPST_KEY_Msk & ((value) << PMC_ULPST_KEY_Pos)))
#define   PMC_ULPST_KEY_PASSWD (0x5Au << 24) /**< \brief (PMC_ULPST) Writing any other value in this field aborts the write operation.Always reads as 0. */
/* -------- PMC_MCKLIM : (PMC Offset: 0x009C) MCK Monitor Limits Register -------- */
#define PMC_MCKLIM_MCK_LOW_IT_Pos 0
#define PMC_MCKLIM_MCK_LOW_IT_Msk (0xffu << PMC_MCKLIM_MCK_LOW_IT_Pos) /**< \brief (PMC_MCKLIM) MCK Monitoring Low IT Limit */
#define PMC_MCKLIM_MCK_LOW_IT(value) ((PMC_MCKLIM_MCK_LOW_IT_Msk & ((value) << PMC_MCKLIM_MCK_LOW_IT_Pos)))
#define PMC_MCKLIM_MCK_HIGH_IT_Pos 8
#define PMC_MCKLIM_MCK_HIGH_IT_Msk (0xffu << PMC_MCKLIM_MCK_HIGH_IT_Pos) /**< \brief (PMC_MCKLIM) MCK Monitoring High IT Limit */
#define PMC_MCKLIM_MCK_HIGH_IT(value) ((PMC_MCKLIM_MCK_HIGH_IT_Msk & ((value) << PMC_MCKLIM_MCK_HIGH_IT_Pos)))
#define PMC_MCKLIM_MCK_LOW_RES_Pos 16
#define PMC_MCKLIM_MCK_LOW_RES_Msk (0xffu << PMC_MCKLIM_MCK_LOW_RES_Pos) /**< \brief (PMC_MCKLIM) MCK Monitoring Low RESET Limit */
#define PMC_MCKLIM_MCK_LOW_RES(value) ((PMC_MCKLIM_MCK_LOW_RES_Msk & ((value) << PMC_MCKLIM_MCK_LOW_RES_Pos)))
#define PMC_MCKLIM_MCK_HIGH_RES_Pos 24
#define PMC_MCKLIM_MCK_HIGH_RES_Msk (0xffu << PMC_MCKLIM_MCK_HIGH_RES_Pos) /**< \brief (PMC_MCKLIM) MCK Monitoring High Reset Limit */
#define PMC_MCKLIM_MCK_HIGH_RES(value) ((PMC_MCKLIM_MCK_HIGH_RES_Msk & ((value) << PMC_MCKLIM_MCK_HIGH_RES_Pos)))
/* -------- PMC_CSR0 : (PMC Offset: 0x00A0) Peripheral Clock Status Register 0 -------- */
#define PMC_CSR0_PID2 (0x1u << 2) /**< \brief (PMC_CSR0) Peripheral Clock 2 Status */
#define PMC_CSR0_PID3 (0x1u << 3) /**< \brief (PMC_CSR0) Peripheral Clock 3 Status */
#define PMC_CSR0_PID4 (0x1u << 4) /**< \brief (PMC_CSR0) Peripheral Clock 4 Status */
#define PMC_CSR0_PID5 (0x1u << 5) /**< \brief (PMC_CSR0) Peripheral Clock 5 Status */
#define PMC_CSR0_PID6 (0x1u << 6) /**< \brief (PMC_CSR0) Peripheral Clock 6 Status */
#define PMC_CSR0_PID7 (0x1u << 7) /**< \brief (PMC_CSR0) Peripheral Clock 7 Status */
#define PMC_CSR0_PID8 (0x1u << 8) /**< \brief (PMC_CSR0) Peripheral Clock 8 Status */
#define PMC_CSR0_PID9 (0x1u << 9) /**< \brief (PMC_CSR0) Peripheral Clock 9 Status */
#define PMC_CSR0_PID10 (0x1u << 10) /**< \brief (PMC_CSR0) Peripheral Clock 10 Status */
#define PMC_CSR0_PID11 (0x1u << 11) /**< \brief (PMC_CSR0) Peripheral Clock 11 Status */
#define PMC_CSR0_PID12 (0x1u << 12) /**< \brief (PMC_CSR0) Peripheral Clock 12 Status */
#define PMC_CSR0_PID13 (0x1u << 13) /**< \brief (PMC_CSR0) Peripheral Clock 13 Status */
#define PMC_CSR0_PID14 (0x1u << 14) /**< \brief (PMC_CSR0) Peripheral Clock 14 Status */
#define PMC_CSR0_PID15 (0x1u << 15) /**< \brief (PMC_CSR0) Peripheral Clock 15 Status */
#define PMC_CSR0_PID16 (0x1u << 16) /**< \brief (PMC_CSR0) Peripheral Clock 16 Status */
#define PMC_CSR0_PID17 (0x1u << 17) /**< \brief (PMC_CSR0) Peripheral Clock 17 Status */
#define PMC_CSR0_PID18 (0x1u << 18) /**< \brief (PMC_CSR0) Peripheral Clock 18 Status */
#define PMC_CSR0_PID19 (0x1u << 19) /**< \brief (PMC_CSR0) Peripheral Clock 19 Status */
#define PMC_CSR0_PID20 (0x1u << 20) /**< \brief (PMC_CSR0) Peripheral Clock 20 Status */
#define PMC_CSR0_PID22 (0x1u << 22) /**< \brief (PMC_CSR0) Peripheral Clock 22 Status */
#define PMC_CSR0_PID23 (0x1u << 23) /**< \brief (PMC_CSR0) Peripheral Clock 23 Status */
#define PMC_CSR0_PID24 (0x1u << 24) /**< \brief (PMC_CSR0) Peripheral Clock 24 Status */
#define PMC_CSR0_PID25 (0x1u << 25) /**< \brief (PMC_CSR0) Peripheral Clock 25 Status */
#define PMC_CSR0_PID26 (0x1u << 26) /**< \brief (PMC_CSR0) Peripheral Clock 26 Status */
#define PMC_CSR0_PID27 (0x1u << 27) /**< \brief (PMC_CSR0) Peripheral Clock 27 Status */
#define PMC_CSR0_PID28 (0x1u << 28) /**< \brief (PMC_CSR0) Peripheral Clock 28 Status */
#define PMC_CSR0_PID29 (0x1u << 29) /**< \brief (PMC_CSR0) Peripheral Clock 29 Status */
#define PMC_CSR0_PID30 (0x1u << 30) /**< \brief (PMC_CSR0) Peripheral Clock 30 Status */
/* -------- PMC_CSR1 : (PMC Offset: 0x00A4) Peripheral Clock Status Register 1 -------- */
#define PMC_CSR1_PID32 (0x1u << 0) /**< \brief (PMC_CSR1) Peripheral Clock 32 Status */
#define PMC_CSR1_PID33 (0x1u << 1) /**< \brief (PMC_CSR1) Peripheral Clock 33 Status */
#define PMC_CSR1_PID34 (0x1u << 2) /**< \brief (PMC_CSR1) Peripheral Clock 34 Status */
#define PMC_CSR1_PID35 (0x1u << 3) /**< \brief (PMC_CSR1) Peripheral Clock 35 Status */
#define PMC_CSR1_PID36 (0x1u << 4) /**< \brief (PMC_CSR1) Peripheral Clock 36 Status */
#define PMC_CSR1_PID37 (0x1u << 5) /**< \brief (PMC_CSR1) Peripheral Clock 37 Status */
#define PMC_CSR1_PID38 (0x1u << 6) /**< \brief (PMC_CSR1) Peripheral Clock 38 Status */
#define PMC_CSR1_PID39 (0x1u << 7) /**< \brief (PMC_CSR1) Peripheral Clock 39 Status */
#define PMC_CSR1_PID40 (0x1u << 8) /**< \brief (PMC_CSR1) Peripheral Clock 40 Status */
#define PMC_CSR1_PID41 (0x1u << 9) /**< \brief (PMC_CSR1) Peripheral Clock 41 Status */
#define PMC_CSR1_PID42 (0x1u << 10) /**< \brief (PMC_CSR1) Peripheral Clock 42 Status */
#define PMC_CSR1_PID43 (0x1u << 11) /**< \brief (PMC_CSR1) Peripheral Clock 43 Status */
#define PMC_CSR1_PID44 (0x1u << 12) /**< \brief (PMC_CSR1) Peripheral Clock 44 Status */
#define PMC_CSR1_PID45 (0x1u << 13) /**< \brief (PMC_CSR1) Peripheral Clock 45 Status */
/* -------- PMC_GCSR0 : (PMC Offset: 0x00C0) Generic Clock Status Register 0 -------- */
#define PMC_GCSR0_GPID5 (0x1u << 5) /**< \brief (PMC_GCSR0) Generic Clock 5 Status */
#define PMC_GCSR0_GPID6 (0x1u << 6) /**< \brief (PMC_GCSR0) Generic Clock 6 Status */
#define PMC_GCSR0_GPID7 (0x1u << 7) /**< \brief (PMC_GCSR0) Generic Clock 7 Status */
#define PMC_GCSR0_GPID8 (0x1u << 8) /**< \brief (PMC_GCSR0) Generic Clock 8 Status */
#define PMC_GCSR0_GPID9 (0x1u << 9) /**< \brief (PMC_GCSR0) Generic Clock 9 Status */
#define PMC_GCSR0_GPID10 (0x1u << 10) /**< \brief (PMC_GCSR0) Generic Clock 10 Status */
#define PMC_GCSR0_GPID11 (0x1u << 11) /**< \brief (PMC_GCSR0) Generic Clock 11 Status */
#define PMC_GCSR0_GPID12 (0x1u << 12) /**< \brief (PMC_GCSR0) Generic Clock 12 Status */
#define PMC_GCSR0_GPID13 (0x1u << 13) /**< \brief (PMC_GCSR0) Generic Clock 13 Status */
#define PMC_GCSR0_GPID14 (0x1u << 14) /**< \brief (PMC_GCSR0) Generic Clock 14 Status */
#define PMC_GCSR0_GPID15 (0x1u << 15) /**< \brief (PMC_GCSR0) Generic Clock 15 Status */
#define PMC_GCSR0_GPID16 (0x1u << 16) /**< \brief (PMC_GCSR0) Generic Clock 16 Status */
#define PMC_GCSR0_GPID17 (0x1u << 17) /**< \brief (PMC_GCSR0) Generic Clock 17 Status */
#define PMC_GCSR0_GPID19 (0x1u << 19) /**< \brief (PMC_GCSR0) Generic Clock 19 Status */
#define PMC_GCSR0_GPID25 (0x1u << 25) /**< \brief (PMC_GCSR0) Generic Clock 25 Status */
#define PMC_GCSR0_GPID26 (0x1u << 26) /**< \brief (PMC_GCSR0) Generic Clock 26 Status */
/* -------- PMC_GCSR1 : (PMC Offset: 0x00C4) Generic Clock Status Register 1 -------- */
#define PMC_GCSR1_GPID32 (0x1u << 0) /**< \brief (PMC_GCSR1) Generic Clock 32 Status */
#define PMC_GCSR1_GPID33 (0x1u << 1) /**< \brief (PMC_GCSR1) Generic Clock 33 Status */
#define PMC_GCSR1_GPID34 (0x1u << 2) /**< \brief (PMC_GCSR1) Generic Clock 34 Status */
#define PMC_GCSR1_GPID37 (0x1u << 5) /**< \brief (PMC_GCSR1) Generic Clock 37 Status */
#define PMC_GCSR1_GPID42 (0x1u << 10) /**< \brief (PMC_GCSR1) Generic Clock 42 Status */
#define PMC_GCSR1_GPID45 (0x1u << 13) /**< \brief (PMC_GCSR1) Generic Clock 45 Status */
#define PMC_GCSR1_GPID47 (0x1u << 15) /**< \brief (PMC_GCSR1) Generic Clock 47 Status */
/* -------- PMC_PLL_IER : (PMC Offset: 0x00E0) PLL Interrupt Enable Register -------- */
#define PMC_PLL_IER_LOCK0 (0x1u << 0) /**< \brief (PMC_PLL_IER) PLL of index 0 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK1 (0x1u << 1) /**< \brief (PMC_PLL_IER) PLL of index 1 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK2 (0x1u << 2) /**< \brief (PMC_PLL_IER) PLL of index 2 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK3 (0x1u << 3) /**< \brief (PMC_PLL_IER) PLL of index 3 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK4 (0x1u << 4) /**< \brief (PMC_PLL_IER) PLL of index 4 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK5 (0x1u << 5) /**< \brief (PMC_PLL_IER) PLL of index 5 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK6 (0x1u << 6) /**< \brief (PMC_PLL_IER) PLL of index 6 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK7 (0x1u << 7) /**< \brief (PMC_PLL_IER) PLL of index 7 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK8 (0x1u << 8) /**< \brief (PMC_PLL_IER) PLL of index 8 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK9 (0x1u << 9) /**< \brief (PMC_PLL_IER) PLL of index 9 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK10 (0x1u << 10) /**< \brief (PMC_PLL_IER) PLL of index 10 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK11 (0x1u << 11) /**< \brief (PMC_PLL_IER) PLL of index 11 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK12 (0x1u << 12) /**< \brief (PMC_PLL_IER) PLL of index 12 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK13 (0x1u << 13) /**< \brief (PMC_PLL_IER) PLL of index 13 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK14 (0x1u << 14) /**< \brief (PMC_PLL_IER) PLL of index 14 Lock Interrupt Enable */
#define PMC_PLL_IER_LOCK15 (0x1u << 15) /**< \brief (PMC_PLL_IER) PLL of index 15 Lock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK0 (0x1u << 16) /**< \brief (PMC_PLL_IER) PLL of index 0 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK1 (0x1u << 17) /**< \brief (PMC_PLL_IER) PLL of index 1 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK2 (0x1u << 18) /**< \brief (PMC_PLL_IER) PLL of index 2 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK3 (0x1u << 19) /**< \brief (PMC_PLL_IER) PLL of index 3 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK4 (0x1u << 20) /**< \brief (PMC_PLL_IER) PLL of index 4 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK5 (0x1u << 21) /**< \brief (PMC_PLL_IER) PLL of index 5 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK6 (0x1u << 22) /**< \brief (PMC_PLL_IER) PLL of index 6 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK7 (0x1u << 23) /**< \brief (PMC_PLL_IER) PLL of index 7 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK8 (0x1u << 24) /**< \brief (PMC_PLL_IER) PLL of index 8 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK9 (0x1u << 25) /**< \brief (PMC_PLL_IER) PLL of index 9 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK10 (0x1u << 26) /**< \brief (PMC_PLL_IER) PLL of index 10 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK11 (0x1u << 27) /**< \brief (PMC_PLL_IER) PLL of index 11 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK12 (0x1u << 28) /**< \brief (PMC_PLL_IER) PLL of index 12 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK13 (0x1u << 29) /**< \brief (PMC_PLL_IER) PLL of index 13 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK14 (0x1u << 30) /**< \brief (PMC_PLL_IER) PLL of index 14 Unlock Interrupt Enable */
#define PMC_PLL_IER_UNLOCK15 (0x1u << 31) /**< \brief (PMC_PLL_IER) PLL of index 15 Unlock Interrupt Enable */
/* -------- PMC_PLL_IDR : (PMC Offset: 0x00E4) PLL Interrupt Disable Register -------- */
#define PMC_PLL_IDR_LOCK0 (0x1u << 0) /**< \brief (PMC_PLL_IDR) PLL of index 0 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK1 (0x1u << 1) /**< \brief (PMC_PLL_IDR) PLL of index 1 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK2 (0x1u << 2) /**< \brief (PMC_PLL_IDR) PLL of index 2 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK3 (0x1u << 3) /**< \brief (PMC_PLL_IDR) PLL of index 3 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK4 (0x1u << 4) /**< \brief (PMC_PLL_IDR) PLL of index 4 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK5 (0x1u << 5) /**< \brief (PMC_PLL_IDR) PLL of index 5 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK6 (0x1u << 6) /**< \brief (PMC_PLL_IDR) PLL of index 6 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK7 (0x1u << 7) /**< \brief (PMC_PLL_IDR) PLL of index 7 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK8 (0x1u << 8) /**< \brief (PMC_PLL_IDR) PLL of index 8 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK9 (0x1u << 9) /**< \brief (PMC_PLL_IDR) PLL of index 9 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK10 (0x1u << 10) /**< \brief (PMC_PLL_IDR) PLL of index 10 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK11 (0x1u << 11) /**< \brief (PMC_PLL_IDR) PLL of index 11 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK12 (0x1u << 12) /**< \brief (PMC_PLL_IDR) PLL of index 12 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK13 (0x1u << 13) /**< \brief (PMC_PLL_IDR) PLL of index 13 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK14 (0x1u << 14) /**< \brief (PMC_PLL_IDR) PLL of index 14 Lock Interrupt Disable */
#define PMC_PLL_IDR_LOCK15 (0x1u << 15) /**< \brief (PMC_PLL_IDR) PLL of index 15 Lock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK0 (0x1u << 16) /**< \brief (PMC_PLL_IDR) PLL of index 0 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK1 (0x1u << 17) /**< \brief (PMC_PLL_IDR) PLL of index 1 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK2 (0x1u << 18) /**< \brief (PMC_PLL_IDR) PLL of index 2 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK3 (0x1u << 19) /**< \brief (PMC_PLL_IDR) PLL of index 3 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK4 (0x1u << 20) /**< \brief (PMC_PLL_IDR) PLL of index 4 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK5 (0x1u << 21) /**< \brief (PMC_PLL_IDR) PLL of index 5 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK6 (0x1u << 22) /**< \brief (PMC_PLL_IDR) PLL of index 6 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK7 (0x1u << 23) /**< \brief (PMC_PLL_IDR) PLL of index 7 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK8 (0x1u << 24) /**< \brief (PMC_PLL_IDR) PLL of index 8 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK9 (0x1u << 25) /**< \brief (PMC_PLL_IDR) PLL of index 9 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK10 (0x1u << 26) /**< \brief (PMC_PLL_IDR) PLL of index 10 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK11 (0x1u << 27) /**< \brief (PMC_PLL_IDR) PLL of index 11 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK12 (0x1u << 28) /**< \brief (PMC_PLL_IDR) PLL of index 12 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK13 (0x1u << 29) /**< \brief (PMC_PLL_IDR) PLL of index 13 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK14 (0x1u << 30) /**< \brief (PMC_PLL_IDR) PLL of index 14 Unlock Interrupt Disable */
#define PMC_PLL_IDR_UNLOCK15 (0x1u << 31) /**< \brief (PMC_PLL_IDR) PLL of index 15 Unlock Interrupt Disable */
/* -------- PMC_PLL_IMR : (PMC Offset: 0x00E8) PLL Interrupt Mask Register -------- */
#define PMC_PLL_IMR_LOCK0 (0x1u << 0) /**< \brief (PMC_PLL_IMR) PLL of index 0 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK1 (0x1u << 1) /**< \brief (PMC_PLL_IMR) PLL of index 1 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK2 (0x1u << 2) /**< \brief (PMC_PLL_IMR) PLL of index 2 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK3 (0x1u << 3) /**< \brief (PMC_PLL_IMR) PLL of index 3 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK4 (0x1u << 4) /**< \brief (PMC_PLL_IMR) PLL of index 4 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK5 (0x1u << 5) /**< \brief (PMC_PLL_IMR) PLL of index 5 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK6 (0x1u << 6) /**< \brief (PMC_PLL_IMR) PLL of index 6 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK7 (0x1u << 7) /**< \brief (PMC_PLL_IMR) PLL of index 7 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK8 (0x1u << 8) /**< \brief (PMC_PLL_IMR) PLL of index 8 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK9 (0x1u << 9) /**< \brief (PMC_PLL_IMR) PLL of index 9 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK10 (0x1u << 10) /**< \brief (PMC_PLL_IMR) PLL of index 10 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK11 (0x1u << 11) /**< \brief (PMC_PLL_IMR) PLL of index 11 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK12 (0x1u << 12) /**< \brief (PMC_PLL_IMR) PLL of index 12 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK13 (0x1u << 13) /**< \brief (PMC_PLL_IMR) PLL of index 13 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK14 (0x1u << 14) /**< \brief (PMC_PLL_IMR) PLL of index 14 Lock Interrupt Mask */
#define PMC_PLL_IMR_LOCK15 (0x1u << 15) /**< \brief (PMC_PLL_IMR) PLL of index 15 Lock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK0 (0x1u << 16) /**< \brief (PMC_PLL_IMR) PLL of index 0 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK1 (0x1u << 17) /**< \brief (PMC_PLL_IMR) PLL of index 1 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK2 (0x1u << 18) /**< \brief (PMC_PLL_IMR) PLL of index 2 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK3 (0x1u << 19) /**< \brief (PMC_PLL_IMR) PLL of index 3 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK4 (0x1u << 20) /**< \brief (PMC_PLL_IMR) PLL of index 4 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK5 (0x1u << 21) /**< \brief (PMC_PLL_IMR) PLL of index 5 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK6 (0x1u << 22) /**< \brief (PMC_PLL_IMR) PLL of index 6 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK7 (0x1u << 23) /**< \brief (PMC_PLL_IMR) PLL of index 7 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK8 (0x1u << 24) /**< \brief (PMC_PLL_IMR) PLL of index 8 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK9 (0x1u << 25) /**< \brief (PMC_PLL_IMR) PLL of index 9 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK10 (0x1u << 26) /**< \brief (PMC_PLL_IMR) PLL of index 10 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK11 (0x1u << 27) /**< \brief (PMC_PLL_IMR) PLL of index 11 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK12 (0x1u << 28) /**< \brief (PMC_PLL_IMR) PLL of index 12 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK13 (0x1u << 29) /**< \brief (PMC_PLL_IMR) PLL of index 13 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK14 (0x1u << 30) /**< \brief (PMC_PLL_IMR) PLL of index 14 Unlock Interrupt Mask */
#define PMC_PLL_IMR_UNLOCK15 (0x1u << 31) /**< \brief (PMC_PLL_IMR) PLL of index 15 Unlock Interrupt Mask */
/* -------- PMC_PLL_ISR0 : (PMC Offset: 0x00EC) PLL Interrupt Status Register 0 -------- */
#define PMC_PLL_ISR0_LOCK0 (0x1u << 0) /**< \brief (PMC_PLL_ISR0) PLL of index 0 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK1 (0x1u << 1) /**< \brief (PMC_PLL_ISR0) PLL of index 1 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK2 (0x1u << 2) /**< \brief (PMC_PLL_ISR0) PLL of index 2 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK3 (0x1u << 3) /**< \brief (PMC_PLL_ISR0) PLL of index 3 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK4 (0x1u << 4) /**< \brief (PMC_PLL_ISR0) PLL of index 4 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK5 (0x1u << 5) /**< \brief (PMC_PLL_ISR0) PLL of index 5 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK6 (0x1u << 6) /**< \brief (PMC_PLL_ISR0) PLL of index 6 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK7 (0x1u << 7) /**< \brief (PMC_PLL_ISR0) PLL of index 7 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK8 (0x1u << 8) /**< \brief (PMC_PLL_ISR0) PLL of index 8 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK9 (0x1u << 9) /**< \brief (PMC_PLL_ISR0) PLL of index 9 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK10 (0x1u << 10) /**< \brief (PMC_PLL_ISR0) PLL of index 10 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK11 (0x1u << 11) /**< \brief (PMC_PLL_ISR0) PLL of index 11 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK12 (0x1u << 12) /**< \brief (PMC_PLL_ISR0) PLL of index 12 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK13 (0x1u << 13) /**< \brief (PMC_PLL_ISR0) PLL of index 13 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK14 (0x1u << 14) /**< \brief (PMC_PLL_ISR0) PLL of index 14 Lock Interrupt Status */
#define PMC_PLL_ISR0_LOCK15 (0x1u << 15) /**< \brief (PMC_PLL_ISR0) PLL of index 15 Lock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK0 (0x1u << 16) /**< \brief (PMC_PLL_ISR0) PLL of index 0 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK1 (0x1u << 17) /**< \brief (PMC_PLL_ISR0) PLL of index 1 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK2 (0x1u << 18) /**< \brief (PMC_PLL_ISR0) PLL of index 2 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK3 (0x1u << 19) /**< \brief (PMC_PLL_ISR0) PLL of index 3 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK4 (0x1u << 20) /**< \brief (PMC_PLL_ISR0) PLL of index 4 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK5 (0x1u << 21) /**< \brief (PMC_PLL_ISR0) PLL of index 5 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK6 (0x1u << 22) /**< \brief (PMC_PLL_ISR0) PLL of index 6 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK7 (0x1u << 23) /**< \brief (PMC_PLL_ISR0) PLL of index 7 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK8 (0x1u << 24) /**< \brief (PMC_PLL_ISR0) PLL of index 8 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK9 (0x1u << 25) /**< \brief (PMC_PLL_ISR0) PLL of index 9 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK10 (0x1u << 26) /**< \brief (PMC_PLL_ISR0) PLL of index 10 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK11 (0x1u << 27) /**< \brief (PMC_PLL_ISR0) PLL of index 11 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK12 (0x1u << 28) /**< \brief (PMC_PLL_ISR0) PLL of index 12 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK13 (0x1u << 29) /**< \brief (PMC_PLL_ISR0) PLL of index 13 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK14 (0x1u << 30) /**< \brief (PMC_PLL_ISR0) PLL of index 14 Unlock Interrupt Status */
#define PMC_PLL_ISR0_UNLOCK15 (0x1u << 31) /**< \brief (PMC_PLL_ISR0) PLL of index 15 Unlock Interrupt Status */
/* -------- PMC_PLL_ISR1 : (PMC Offset: 0x00F0) PLL Interrupt Status Register 1 -------- */
#define PMC_PLL_ISR1_UDR0 (0x1u << 0) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR1 (0x1u << 1) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR2 (0x1u << 2) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR3 (0x1u << 3) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR4 (0x1u << 4) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR5 (0x1u << 5) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR6 (0x1u << 6) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR7 (0x1u << 7) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR8 (0x1u << 8) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR9 (0x1u << 9) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR10 (0x1u << 10) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR11 (0x1u << 11) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR12 (0x1u << 12) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR13 (0x1u << 13) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR14 (0x1u << 14) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_UDR15 (0x1u << 15) /**< \brief (PMC_PLL_ISR1) PLLx Underflow */
#define PMC_PLL_ISR1_OVR0 (0x1u << 16) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR1 (0x1u << 17) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR2 (0x1u << 18) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR3 (0x1u << 19) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR4 (0x1u << 20) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR5 (0x1u << 21) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR6 (0x1u << 22) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR7 (0x1u << 23) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR8 (0x1u << 24) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR9 (0x1u << 25) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR10 (0x1u << 26) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR11 (0x1u << 27) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR12 (0x1u << 28) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR13 (0x1u << 29) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR14 (0x1u << 30) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
#define PMC_PLL_ISR1_OVR15 (0x1u << 31) /**< \brief (PMC_PLL_ISR1) PLLx Overflow */
/* -------- PMC_ADDRSIZE : (PMC Offset: 0x0100) Address Size Register -------- */
#define PMC_ADDRSIZE_ADDRSIZE_Pos 0
#define PMC_ADDRSIZE_ADDRSIZE_Msk (0xffffffffu << PMC_ADDRSIZE_ADDRSIZE_Pos) /**< \brief (PMC_ADDRSIZE) Address Size */
/* -------- PMC_NAME[2] : (PMC Offset: 0x0104) IP Name Register -------- */
#define PMC_NAME_NAME_Pos 0
#define PMC_NAME_NAME_Msk (0xffffffffu << PMC_NAME_NAME_Pos) /**< \brief (PMC_NAME[2]) Name of the IP */
/* -------- PMC_FEATURES : (PMC Offset: 0x010C) Features Register -------- */
#define PMC_FEATURES_FEATURES_Pos 0
#define PMC_FEATURES_FEATURES_Msk (0xffffffffu << PMC_FEATURES_FEATURES_Pos) /**< \brief (PMC_FEATURES) Features of the PMC */
/* -------- PMC_VERSION : (PMC Offset: 0x0110) Version Register -------- */
#define PMC_VERSION_VERSION_Pos 0
#define PMC_VERSION_VERSION_Msk (0xfffu << PMC_VERSION_VERSION_Pos) /**< \brief (PMC_VERSION) Version of the Hardware Module */
#define PMC_VERSION_MFN_Pos 16
#define PMC_VERSION_MFN_Msk (0x7u << PMC_VERSION_MFN_Pos) /**< \brief (PMC_VERSION) Metal Fix Number */

/*@}*/


#endif /* _SAM9X_PMC_COMPONENT_ */
