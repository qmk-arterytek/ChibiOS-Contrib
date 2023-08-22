/*
    Copyright (C) Zhaqian

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    AT32F413xx/hal_lld.c
 * @brief   AT32F413xx HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_at32f415xx.h.
 */
uint32_t SystemCoreClock = AT32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the backup domain.
 * @note    WARNING! Changing clock source impossible without resetting
 *          of the whole BKP domain.
 */
static void hal_lld_backup_domain_init(void) {

  /* Backup domain access enabled and left open.*/
  PWC->CTRL |= PWC_CTRL_BPWEN;
  
  /* Reset BKP domain if different clock source selected.*/
  if ((CRM->BPDC & AT32_RTCSEL_MASK) != AT32_RTCSEL) {
    /* Backup domain reset.*/
    CRM->BPDC = CRM_BPDC_BPDRST;
    CRM->BPDC = 0;
  }

  /* If enabled then the LEXT is started.*/
#if AT32_LEXT_ENABLED
#if defined(AT32_LEXT_BYPASS)
  /* LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN | CRM_BPDC_LEXTBYPS;
#else
  /* No LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN;
#endif
  while ((CRM->BPDC & CRM_BPDC_LEXTSTBL) == 0);  /* Waits until LEXT is stable.   */
#endif /* AT32_LEXT_ENABLED */

#if AT32_RTCSEL != AT32_RTCSEL_NOCLOCK
  /* If the backup domain hasn't been initialized yet then proceed with
     initialization.*/
  if ((CRM->BPDC & CRM_BPDC_RTCEN) == 0) {
    /* Selects clock source.*/
    CRM->BPDC |= AT32_RTCSEL;

    /* RTC clock enabled.*/
    CRM->BPDC |= CRM_BPDC_RTCEN;
  }
#endif /* AT32_RTCSEL != AT32_RTCSEL_NOCLOCK */
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all peripherals.*/
  crmResetAPB1(0xFFFFFFFF);
  crmResetAPB2(0xFFFFFFFF);

  /* PWR clocks enabled.*/
  crmEnablePWCInterface(true);
  crmEnableBPRInterface(true);

  /* Initializes the backup domain.*/
  hal_lld_backup_domain_init();

  /* DMA subsystems initialization.*/
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization.*/
  irqInit();

  /* Programmable voltage detector enable.*/
#if AT32_PVM_ENABLE
  PWC->CTRL |= PWC_CTRL_PVMEN | (AT32_PVM & AT32_PVM_MASK);
#endif /* AT32_PVM_ENABLE */
}

void at32_clock_reset(void)
{
  /* reset hexten, hextbyps, cfden and pllen bits */
  CRM->CTRL &= ~(0x010D0000U);

  /* reset cfg register, include sclk switch, ahbdiv, apb1div, apb2div, adcdiv,
     clkout pllrcs, pllhextdiv, pllmult, usbdiv and pllrange bits */
  CRM->CFG = 0;

  /* reset clkout[3], usbbufs, hickdiv, clkoutdiv */
  CRM->MISC1  = 0;
  CRM->MISC3  = 0x0000000D;
  CRM->INTMAP = 0x00000000;
  
  /* disable all interrupts enable and clear pending bits  */
  CRM->CLKINT = 0x009F0000;
}

/*
 * Clocks initialization for all sub-families except CL.
 */
void at32_clock_init(void) {
#if !AT32_NO_INIT
  /* HICK setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  CRM->CTRL |= CRM_CTRL_HICKEN;                                 /* Make sure HICK is ON.        */
  while((CRM->CTRL & CRM_CTRL_HICKSTBL) == 0);                  /* Wait until HICK is stable.   */
  CRM->CTRL &= CRM_CTRL_HICKTRIM | CRM_CTRL_HICKEN;             /* CR Reset value.              */
  CRM->CFG  |= CRM_CFG_SCLK_HICK;                               /* CFGR reset value.            */
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != CRM_CFG_SCLKSTS_HICK); /* Waits until HICK is selected.*/

  at32_clock_reset();
  
#if AT32_HEXT_ENABLED
#if defined(AT32_HEXT_BYPASS)
  /* HEXT Bypass.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN | CRM_CTRL_HEXTBYPS;
#endif
  /* HEXT activation.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN;
  while (!(CRM->CTRL & CRM_CTRL_HEXTSTBL));           /* Waits until HEXT is stable.   */
#endif

#if AT32_LICK_ENABLED
  /* LICK activation.*/
  CRM->CTRLSTS |= CRM_CTRLSTS_LICKEN;
  while ((CRM->CTRLSTS & CRM_CTRLSTS_LICKSTBL) == 0); /* Waits until LICK is stable.   */
#endif

#if (AT32_USBCLK_SRC == AT32_USBCLK_SRC_HICK48)       /* USB use HICK.                 */
  CRM->MISC1 |= CRM_MISC1_HICKDIV;
  CRM->MISC3 |= CRM_MISC3_HICK_TO_USB | CRM_MISC3_HICK_TO_SCLK;
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation.*/
  CRM->CFG  |= AT32_PLLMULT | AT32_PLLHEXTDIV | AT32_PLLRCS | AT32_PLLRANGE;
  CRM->CTRL |= CRM_CTRL_PLLEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLSTBL));       /* Waits until PLL is stable.   */
#endif

  /* Clock settings.*/
  CRM->CFG   |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_CFG_MASK) | AT32_USBDIV | 
               AT32_ADCDIV    | AT32_APB2DIV | AT32_APB1DIV  | AT32_AHBDIV;
  CRM->MISC1 |= (AT32_CLKOUT_SEL & AT32_CLKOUT_SEL_MISC_MASK) >> 11;

  /* PLL Auto Step activation.*/
  CRM->MISC3 |= CRM_MISC3_AUTO_STEP_EN;
  
  /* Switching to the configured clock source if it is different from HICK.*/
#if (AT32_SCLKSEL != AT32_SCLKSEL_HICK)
  /* Switches clock source.*/
  CRM->CFG |= AT32_SCLKSEL;
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != (AT32_SCLKSEL << 2)); /* Waits selection complete.    */
#endif

  /* PLL Auto Step inactivation.*/
  CRM->MISC3 &= ~CRM_MISC3_AUTO_STEP_EN;
  
#if !AT32_HICK_ENABLED
  CRM->CTRL &= ~CRM_CTRL_HICKEN;
#endif
#endif /* !AT32_NO_INIT */
}
/** @} */
