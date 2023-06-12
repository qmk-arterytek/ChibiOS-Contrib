/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    TIMv1/hal_gpt_lld.c
 * @brief   AT32 GPT subsystem low level driver source.
 *
 * @addtogroup GPT
 * @{
 */

#include "hal.h"

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   GPTD1 driver identifier.
 * @note    The driver GPTD1 allocates the complex timer TIM1 when enabled.
 */
#if AT32_GPT_USE_TIM1 || defined(__DOXYGEN__)
GPTDriver GPTD1;
#endif

/**
 * @brief   GPTD2 driver identifier.
 * @note    The driver GPTD2 allocates the timer TIM2 when enabled.
 */
#if AT32_GPT_USE_TIM2 || defined(__DOXYGEN__)
GPTDriver GPTD2;
#endif

/**
 * @brief   GPTD3 driver identifier.
 * @note    The driver GPTD3 allocates the timer TIM3 when enabled.
 */
#if AT32_GPT_USE_TIM3 || defined(__DOXYGEN__)
GPTDriver GPTD3;
#endif

/**
 * @brief   GPTD4 driver identifier.
 * @note    The driver GPTD4 allocates the timer TIM4 when enabled.
 */
#if AT32_GPT_USE_TIM4 || defined(__DOXYGEN__)
GPTDriver GPTD4;
#endif

/**
 * @brief   GPTD5 driver identifier.
 * @note    The driver GPTD5 allocates the timer TIM5 when enabled.
 */
#if AT32_GPT_USE_TIM5 || defined(__DOXYGEN__)
GPTDriver GPTD5;
#endif

/**
 * @brief   GPTD6 driver identifier.
 * @note    The driver GPTD6 allocates the timer TIM6 when enabled.
 */
#if AT32_GPT_USE_TIM6 || defined(__DOXYGEN__)
GPTDriver GPTD6;
#endif

/**
 * @brief   GPTD7 driver identifier.
 * @note    The driver GPTD7 allocates the timer TIM7 when enabled.
 */
#if AT32_GPT_USE_TIM7 || defined(__DOXYGEN__)
GPTDriver GPTD7;
#endif

/**
 * @brief   GPTD8 driver identifier.
 * @note    The driver GPTD8 allocates the timer TIM8 when enabled.
 */
#if AT32_GPT_USE_TIM8 || defined(__DOXYGEN__)
GPTDriver GPTD8;
#endif

/**
 * @brief   GPTD9 driver identifier.
 * @note    The driver GPTD9 allocates the timer TIM9 when enabled.
 */
#if AT32_GPT_USE_TIM9 || defined(__DOXYGEN__)
GPTDriver GPTD9;
#endif

/**
 * @brief   GPTD10 driver identifier.
 * @note    The driver GPTD10 allocates the timer TIM10 when enabled.
 */
#if AT32_GPT_USE_TIM10 || defined(__DOXYGEN__)
GPTDriver GPTD10;
#endif

/**
 * @brief   GPTD11 driver identifier.
 * @note    The driver GPTD11 allocates the timer TIM11 when enabled.
 */
#if AT32_GPT_USE_TIM11 || defined(__DOXYGEN__)
GPTDriver GPTD11;
#endif

/**
 * @brief   GPTD12 driver identifier.
 * @note    The driver GPTD12 allocates the timer TIM12 when enabled.
 */
#if AT32_GPT_USE_TIM12 || defined(__DOXYGEN__)
GPTDriver GPTD12;
#endif

/**
 * @brief   GPTD13 driver identifier.
 * @note    The driver GPTD13 allocates the timer TIM13 when enabled.
 */
#if AT32_GPT_USE_TIM13 || defined(__DOXYGEN__)
GPTDriver GPTD13;
#endif

/**
 * @brief   GPTD14 driver identifier.
 * @note    The driver GPTD14 allocates the timer TIM14 when enabled.
 */
#if AT32_GPT_USE_TIM14 || defined(__DOXYGEN__)
GPTDriver GPTD14;
#endif

/**
 * @brief   GPTD15 driver identifier.
 * @note    The driver GPTD14 allocates the timer TIM14 when enabled.
 */
#if AT32_GPT_USE_TIM15 || defined(__DOXYGEN__)
GPTDriver GPTD15;
#endif

/**
 * @brief   GPTD16 driver identifier.
 * @note    The driver GPTD14 allocates the timer TIM14 when enabled.
 */
#if AT32_GPT_USE_TIM16 || defined(__DOXYGEN__)
GPTDriver GPTD16;
#endif

/**
 * @brief   GPTD17 driver identifier.
 * @note    The driver GPTD14 allocates the timer TIM14 when enabled.
 */
#if AT32_GPT_USE_TIM17 || defined(__DOXYGEN__)
GPTDriver GPTD17;
#endif

/**
 * @brief   GPTD21 driver identifier.
 * @note    The driver GPTD21 allocates the timer TIM21 when enabled.
 */
#if AT32_GPT_USE_TIM21 || defined(__DOXYGEN__)
GPTDriver GPTD21;
#endif

/**
 * @brief   GPTD22 driver identifier.
 * @note    The driver GPTD22 allocates the timer TIM22 when enabled.
 */
#if AT32_GPT_USE_TIM22 || defined(__DOXYGEN__)
GPTDriver GPTD22;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_GPT_USE_TIM1 || defined(__DOXYGEN__)
#if !defined(AT32_TIM1_SUPPRESS_ISR)
#if !defined(AT32_TIM1_UP_HANDLER)
#error "AT32_TIM1_UP_HANDLER not defined"
#endif
/**
 * @brief   TIM1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_UP_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM1_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM1 */

#if AT32_GPT_USE_TIM2 || defined(__DOXYGEN__)
#if !defined(AT32_TIM2_SUPPRESS_ISR)
#if !defined(AT32_TIM2_HANDLER)
#error "AT32_TIM2_HANDLER not defined"
#endif
/**
 * @brief   TIM2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM2_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM2 */

#if AT32_GPT_USE_TIM3 || defined(__DOXYGEN__)
#if !defined(AT32_TIM3_SUPPRESS_ISR)
#if !defined(AT32_TIM3_HANDLER)
#error "AT32_TIM3_HANDLER not defined"
#endif
/**
 * @brief   TIM3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM3_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM3 */

#if AT32_GPT_USE_TIM4 || defined(__DOXYGEN__)
#if !defined(AT32_TIM4_SUPPRESS_ISR)
#if !defined(AT32_TIM4_HANDLER)
#error "AT32_TIM4_HANDLER not defined"
#endif
/**
 * @brief   TIM4 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD4);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM4_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM4 */

#if AT32_GPT_USE_TIM5 || defined(__DOXYGEN__)
#if !defined(AT32_TIM5_SUPPRESS_ISR)
#if !defined(AT32_TIM5_HANDLER)
#error "AT32_TIM5_HANDLER not defined"
#endif
/**
 * @brief   TIM5 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM5_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM5 */

#if AT32_GPT_USE_TIM6 || defined(__DOXYGEN__)
#if !defined(AT32_TIM6_SUPPRESS_ISR)
#if !defined(AT32_TIM6_HANDLER)
#error "AT32_TIM6_HANDLER not defined"
#endif
/**
 * @brief   TIM6 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM6_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD6);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM6_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM6 */

#if AT32_GPT_USE_TIM7 || defined(__DOXYGEN__)
#if !defined(AT32_TIM7_SUPPRESS_ISR)
#if !defined(AT32_TIM7_HANDLER)
#error "AT32_TIM7_HANDLER not defined"
#endif
/**
 * @brief   TIM7 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM7_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD7);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM7_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM7 */

#if AT32_GPT_USE_TIM8 || defined(__DOXYGEN__)
#if !defined(AT32_TIM8_SUPPRESS_ISR)
#if !defined(AT32_TIM8_UP_HANDLER)
#error "AT32_TIM8_UP_HANDLER not defined"
#endif
/**
 * @brief   TIM8 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM8_UP_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD8);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM8_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM8 */

#if AT32_GPT_USE_TIM9 || defined(__DOXYGEN__)
#if !defined(AT32_TIM9_SUPPRESS_ISR)
#error "TIM9 ISR not defined by platform"
#endif /* !defined(AT32_TIM9_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM9 */

#if AT32_GPT_USE_TIM10 || defined(__DOXYGEN__)
#if !defined(AT32_TIM10_SUPPRESS_ISR)
#error "TIM10 ISR not defined by platform"
#endif /* !defined(AT32_TIM10_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM10 */

#if AT32_GPT_USE_TIM11 || defined(__DOXYGEN__)
#if !defined(AT32_TIM11_SUPPRESS_ISR)
#error "TIM11 ISR not defined by platform"
#endif /* !defined(AT32_TIM11_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM11 */

#if AT32_GPT_USE_TIM12 || defined(__DOXYGEN__)
#if !defined(AT32_TIM12_SUPPRESS_ISR)
#error "TIM12 ISR not defined by platform"
#endif /* !defined(AT32_TIM12_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM12 */

#if AT32_GPT_USE_TIM13 || defined(__DOXYGEN__)
#if !defined(AT32_TIM13_SUPPRESS_ISR)
#error "TIM13 ISR not defined by platform"
#endif /* !defined(AT32_TIM13_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM13 */

#if AT32_GPT_USE_TIM14 || defined(__DOXYGEN__)
#if !defined(AT32_TIM14_SUPPRESS_ISR)
#error "TIM14 ISR not defined by platform"
#endif /* !defined(AT32_TIM14_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM14 */

#if AT32_GPT_USE_TIM15 || defined(__DOXYGEN__)
#if !defined(AT32_TIM15_SUPPRESS_ISR)
#error "TIM15 ISR not defined by platform"
#endif /* !defined(AT32_TIM15_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM15 */

#if AT32_GPT_USE_TIM16 || defined(__DOXYGEN__)
#if !defined(AT32_TIM16_SUPPRESS_ISR)
#error "TIM16 ISR not defined by platform"
#endif /* !defined(AT32_TIM16_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM16 */

#if AT32_GPT_USE_TIM17 || defined(__DOXYGEN__)
#if !defined(AT32_TIM17_SUPPRESS_ISR)
#error "TIM17 ISR not defined by platform"
#endif /* !defined(AT32_TIM17_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM17 */

#if AT32_GPT_USE_TIM21 || defined(__DOXYGEN__)
#if !defined(AT32_TIM21_SUPPRESS_ISR)
#if !defined(AT32_TIM21_HANDLER)
#error "AT32_TIM21_HANDLER not defined"
#endif
/**
 * @brief   TIM21 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM21_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD21);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM21_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM21 */

#if AT32_GPT_USE_TIM22 || defined(__DOXYGEN__)
#if !defined(AT32_TIM22_SUPPRESS_ISR)
#if !defined(AT32_TIM22_HANDLER)
#error "AT32_TIM22_HANDLER not defined"
#endif
/**
 * @brief   TIM22 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM22_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD22);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM22_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TIM22 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level GPT driver initialization.
 *
 * @notapi
 */
void gpt_lld_init(void) {

#if AT32_GPT_USE_TIM1
  /* Driver initialization.*/
  GPTD1.tim = AT32_TIM1;
  gptObjectInit(&GPTD1);
#endif

#if AT32_GPT_USE_TIM2
  /* Driver initialization.*/
  GPTD2.tim = AT32_TIM2;
  gptObjectInit(&GPTD2);
#endif

#if AT32_GPT_USE_TIM3
  /* Driver initialization.*/
  GPTD3.tim = AT32_TIM3;
  gptObjectInit(&GPTD3);
#endif

#if AT32_GPT_USE_TIM4
  /* Driver initialization.*/
  GPTD4.tim = AT32_TIM4;
  gptObjectInit(&GPTD4);
#endif

#if AT32_GPT_USE_TIM5
  /* Driver initialization.*/
  GPTD5.tim = AT32_TIM5;
  gptObjectInit(&GPTD5);
#endif

#if AT32_GPT_USE_TIM6
  /* Driver initialization.*/
  GPTD6.tim = AT32_TIM6;
  gptObjectInit(&GPTD6);
#endif

#if AT32_GPT_USE_TIM7
  /* Driver initialization.*/
  GPTD7.tim = AT32_TIM7;
  gptObjectInit(&GPTD7);
#endif

#if AT32_GPT_USE_TIM8
  /* Driver initialization.*/
  GPTD8.tim = AT32_TIM8;
  gptObjectInit(&GPTD8);
#endif

#if AT32_GPT_USE_TIM9
  /* Driver initialization.*/
  GPTD9.tim = AT32_TIM9;
  gptObjectInit(&GPTD9);
#endif

#if AT32_GPT_USE_TIM10
  /* Driver initialization.*/
  GPTD10.tim = AT32_TIM10;
  gptObjectInit(&GPTD10);
#endif

#if AT32_GPT_USE_TIM11
  /* Driver initialization.*/
  GPTD11.tim = AT32_TIM11;
  gptObjectInit(&GPTD11);
#endif

#if AT32_GPT_USE_TIM12
  /* Driver initialization.*/
  GPTD12.tim = AT32_TIM12;
  gptObjectInit(&GPTD12);
#endif

#if AT32_GPT_USE_TIM13
  /* Driver initialization.*/
  GPTD13.tim = AT32_TIM13;
  gptObjectInit(&GPTD13);
#endif

#if AT32_GPT_USE_TIM14
  /* Driver initialization.*/
  GPTD14.tim = AT32_TIM14;
  gptObjectInit(&GPTD14);
#endif

#if AT32_GPT_USE_TIM15
  /* Driver initialization.*/
  GPTD15.tim = AT32_TIM15;
  gptObjectInit(&GPTD15);
#endif

#if AT32_GPT_USE_TIM16
  /* Driver initialization.*/
  GPTD16.tim = AT32_TIM16;
  gptObjectInit(&GPTD16);
#endif

#if AT32_GPT_USE_TIM17
  /* Driver initialization.*/
  GPTD17.tim = AT32_TIM17;
  gptObjectInit(&GPTD17);
#endif

#if AT32_GPT_USE_TIM21
  /* Driver initialization.*/
  GPTD21.tim = AT32_TIM21;
  gptObjectInit(&GPTD21);
#endif

#if AT32_GPT_USE_TIM22
  /* Driver initialization.*/
  GPTD22.tim = AT32_TIM22;
  gptObjectInit(&GPTD22);
#endif
}

/**
 * @brief   Configures and activates the GPT peripheral.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_start(GPTDriver *gptp) {
  uint16_t psc;

  if (gptp->state == GPT_STOP) {
    /* Clock activation.*/
#if AT32_GPT_USE_TIM1
    if (&GPTD1 == gptp) {
      crmEnableTMR1(true);
      crmResetTMR1();
#if !defined(AT32_TIM1_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM1_UP_NUMBER, AT32_GPT_TIM1_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM1CLK)
      gptp->clock = AT32_TIM1CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM2
    if (&GPTD2 == gptp) {
      crmEnableTMR2(true);
      crmResetTMR2();
#if !defined(AT32_TIM2_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM2_NUMBER, AT32_GPT_TIM2_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM2CLK)
      gptp->clock = AT32_TIM2CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM3
    if (&GPTD3 == gptp) {
      crmEnableTMR3(true);
      crmResetTMR3();
#if !defined(AT32_TIM3_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM3_NUMBER, AT32_GPT_TIM3_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM3CLK)
      gptp->clock = AT32_TIM3CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM4
    if (&GPTD4 == gptp) {
      crmEnableTMR4(true);
      crmResetTMR4();
#if !defined(AT32_TIM4_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM4_NUMBER, AT32_GPT_TIM4_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM4CLK)
      gptp->clock = AT32_TIM4CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM5
    if (&GPTD5 == gptp) {
      crmEnableTMR5(true);
      crmResetTMR5();
#if !defined(AT32_TIM5_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM5_NUMBER, AT32_GPT_TIM5_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM5CLK)
      gptp->clock = AT32_TIM5CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM6
    if (&GPTD6 == gptp) {
      crmEnableTMR6(true);
      crmResetTMR6();
#if !defined(AT32_TIM6_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM6_NUMBER, AT32_GPT_TIM6_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM6CLK)
      gptp->clock = AT32_TIM6CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM7
    if (&GPTD7 == gptp) {
      crmEnableTMR7(true);
      crmResetTMR7();
#if !defined(AT32_TIM7_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM7_NUMBER, AT32_GPT_TIM7_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM7CLK)
      gptp->clock = AT32_TIM7CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM8
    if (&GPTD8 == gptp) {
      crmEnableTMR8(true);
      crmResetTMR8();
#if !defined(AT32_TIM8_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM8_UP_NUMBER, AT32_GPT_TIM8_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM8CLK)
      gptp->clock = AT32_TIM8CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM9
    if (&GPTD9 == gptp) {
      crmEnableTMR9(true);
      crmResetTMR9();
#if !defined(AT32_TIM9_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM9_NUMBER, AT32_GPT_TIM9_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM9CLK)
      gptp->clock = AT32_TIM9CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM10
    if (&GPTD10 == gptp) {
      crmEnableTMR10(true);
      crmResetTMR10();
#if !defined(AT32_TIM10_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM10_NUMBER, AT32_GPT_TIM10_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM10CLK)
      gptp->clock = AT32_TIM10CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM11
    if (&GPTD11 == gptp) {
      crmEnableTMR11(true);
      crmResetTMR11();
#if !defined(AT32_TIM11_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM11_NUMBER, AT32_GPT_TIM11_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM11CLK)
      gptp->clock = AT32_TIM11CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM12
    if (&GPTD12 == gptp) {
      crmEnableTMR12(true);
      crmResetTMR12();
#if !defined(AT32_TIM12_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM12_NUMBER, AT32_GPT_TIM12_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM12CLK)
      gptp->clock = AT32_TIM12CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM13
    if (&GPTD13 == gptp) {
      crmEnableTMR13(true);
      crmResetTMR13();
#if !defined(AT32_TIM13_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM13_NUMBER, AT32_GPT_TIM13_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM13CLK)
      gptp->clock = AT32_TIM13CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM14
    if (&GPTD14 == gptp) {
      crmEnableTMR14(true);
      crmResetTMR14();
#if !defined(AT32_TIM14_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM14_NUMBER, AT32_GPT_TIM14_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM14CLK)
      gptp->clock = AT32_TIM14CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM15
    if (&GPTD15 == gptp) {
      crmEnableTMR15(true);
      crmResetTMR15();
#if defined(AT32_TIM15CLK)
      gptp->clock = AT32_TIM15CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM16
    if (&GPTD16 == gptp) {
      crmEnableTMR16(true);
      crmResetTMR16();
#if defined(AT32_TIM16CLK)
      gptp->clock = AT32_TIM16CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM17
    if (&GPTD17 == gptp) {
      crmEnableTMR17(true);
      crmResetTMR17();
#if defined(AT32_TIM17CLK)
      gptp->clock = AT32_TIM17CLK;
#else
      gptp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_GPT_USE_TIM21
    if (&GPTD21 == gptp) {
      crmEnableTMR21(true);
      crmResetTMR21();
#if !defined(AT32_TIM21_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM21_NUMBER, AT32_GPT_TIM21_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM21CLK)
      gptp->clock = AT32_TIM21CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_GPT_USE_TIM22
    if (&GPTD22 == gptp) {
      crmEnableTMR22(true);
      crmResetTMR22();
#if !defined(AT32_TIM22_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM22_NUMBER, AT32_GPT_TIM22_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM22CLK)
      gptp->clock = AT32_TIM22CLK;
#else
      gptp->clock = AT32_TIMCLK1;
#endif
    }
#endif
  }

  /* Prescaler value calculation.*/
  psc = (uint16_t)((gptp->clock / gptp->config->frequency) - 1);
  osalDbgAssert(((uint32_t)(psc + 1) * gptp->config->frequency) == gptp->clock,
                "invalid frequency");

  /* Timer configuration.*/
  gptp->timCTRL1  = 0;                          /* Initially stopped.       */
  gptp->timCTRL2  = gptp->config->cr2;
  gptp->tim->PSC  = psc;                        /* Prescaler value.         */
  gptp->tim->SR   = 0;                          /* Clear pending IRQs.      */
  gptp->tim->DIER = gptp->config->dier &        /* DMA-related DIER bits.   */
                    ~AT32_TIM_DIER_IRQ_MASK;
}

/**
 * @brief   Deactivates the GPT peripheral.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop(GPTDriver *gptp) {

  if (gptp->state == GPT_READY) {
    gptp->timCTRL1  = 0;                        /* Timer disabled.          */
    gptp->tim->DIER = 0;                        /* All IRQs disabled.       */
    gptp->tim->SR   = 0;                        /* Clear pending IRQs.      */

#if AT32_GPT_USE_TIM1
    if (&GPTD1 == gptp) {
#if !defined(AT32_TIM1_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM1_UP_NUMBER);
#endif
      crmDisableTMR1();
    }
#endif

#if AT32_GPT_USE_TIM2
    if (&GPTD2 == gptp) {
#if !defined(AT32_TIM2_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM2_NUMBER);
#endif
      crmDisableTMR2();
    }
#endif

#if AT32_GPT_USE_TIM3
    if (&GPTD3 == gptp) {
#if !defined(AT32_TIM3_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM3_NUMBER);
#endif
      crmDisableTMR3();
    }
#endif

#if AT32_GPT_USE_TIM4
    if (&GPTD4 == gptp) {
#if !defined(AT32_TIM4_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM4_NUMBER);
#endif
      crmDisableTMR4();
    }
#endif

#if AT32_GPT_USE_TIM5
    if (&GPTD5 == gptp) {
#if !defined(AT32_TIM5_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM5_NUMBER);
#endif
      crmDisableTMR5();
    }
#endif

#if AT32_GPT_USE_TIM6
    if (&GPTD6 == gptp) {
#if !defined(AT32_TIM6_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM6_NUMBER);
#endif
      crmDisableTMR6();
    }
#endif

#if AT32_GPT_USE_TIM7
    if (&GPTD7 == gptp) {
#if !defined(AT32_TIM7_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM7_NUMBER);
#endif
      crmDisableTMR7();
    }
#endif

#if AT32_GPT_USE_TIM8
    if (&GPTD8 == gptp) {
#if !defined(AT32_TIM8_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM8_UP_NUMBER);
#endif
      crmDisableTMR8();
    }
#endif

#if AT32_GPT_USE_TIM9
    if (&GPTD9 == gptp) {
#if !defined(AT32_TIM9_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM9_NUMBER);
#endif
      crmDisableTMR9();
    }
#endif

#if AT32_GPT_USE_TIM10
    if (&GPTD10 == gptp) {
#if !defined(AT32_TIM10_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM10_NUMBER);
#endif
      crmDisableTMR10();
    }
#endif

#if AT32_GPT_USE_TIM11
    if (&GPTD11 == gptp) {
#if !defined(AT32_TIM11_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM11_NUMBER);
#endif
      crmDisableTMR11();
    }
#endif

#if AT32_GPT_USE_TIM12
    if (&GPTD12 == gptp) {
#if !defined(AT32_TIM12_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM12_NUMBER);
#endif
      crmDisableTMR12();
    }
#endif

#if AT32_GPT_USE_TIM13
    if (&GPTD13 == gptp) {
#if !defined(AT32_TIM13_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM13_NUMBER);
#endif
      crmDisableTMR13();
    }
#endif

#if AT32_GPT_USE_TIM14
    if (&GPTD14 == gptp) {
#if !defined(AT32_TIM14_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM14_NUMBER);
#endif
      crmDisableTMR14();
    }
#endif

#if AT32_GPT_USE_TIM15
    if (&GPTD15 == gptp) {
      crmDisableTMR15();
    }
#endif

#if AT32_GPT_USE_TIM16
    if (&GPTD16 == gptp) {
      crmDisableTMR16();
    }
#endif

#if AT32_GPT_USE_TIM17
    if (&GPTD17 == gptp) {
      crmDisableTMR17();
    }
#endif

#if AT32_GPT_USE_TIM21
    if (&GPTD21 == gptp) {
#if !defined(AT32_TIM21_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM21_NUMBER);
#endif
      crmDisableTMR21();
    }
#endif

#if AT32_GPT_USE_TIM22
    if (&GPTD22 == gptp) {
#if !defined(AT32_TIM22_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM22_NUMBER);
#endif
      crmDisableTMR22();
    }
#endif
  }
}

/**
 * @brief   Starts the timer in continuous mode.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  period in ticks
 *
 * @notapi
 */
void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval) {

  gptp->tim->ARR = (uint32_t)(interval - 1U);   /* Time constant.           */
  gptp->tim->EGR = AT32_TIM_EGR_UG;            /* Update event.            */
  gptp->tim->CNT = 0;                           /* Reset counter.           */

  /* NOTE: After generating the UG event it takes several clock cycles before
     SR bit 0 goes to 1. This is why the clearing of CNT has been inserted
     before the clearing of SR, to give it some time.*/
  gptp->tim->SR = 0;                            /* Clear pending IRQs.      */
  if (NULL != gptp->config->callback)
    gptp->tim->DIER |= AT32_TIM_DIER_UIE;      /* Update Event IRQ enabled.*/
  gptp->timCTRL1 = AT32_TIM_CR1_ARPE | AT32_TIM_CR1_URS | AT32_TIM_CR1_CEN;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {

  gptp->timCTRL1 = 0;                           /* Initially stopped.       */
  gptp->tim->SR = 0;                            /* Clear pending IRQs.      */

  /* All interrupts disabled.*/
  gptp->tim->DIER &= ~AT32_TIM_DIER_IRQ_MASK;
}

/**
 * @brief   Starts the timer in one shot mode and waits for completion.
 * @details This function specifically polls the timer waiting for completion
 *          in order to not have extra delays caused by interrupt servicing,
 *          this function is only recommended for short delays.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  time interval in ticks
 *
 * @notapi
 */
void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval) {

  gptp->tim->ARR = (uint32_t)(interval - 1U);   /* Time constant.           */
  gptp->tim->EGR = AT32_TIM_EGR_UG;            /* Update event.            */
  gptp->tim->SR  = 0;                           /* Clear pending IRQs.      */
  gptp->timCTRL1 = AT32_TIM_CR1_OPM | AT32_TIM_CR1_URS | AT32_TIM_CR1_CEN;
  while (!(gptp->tim->SR & AT32_TIM_SR_UIF))
    ;
  gptp->tim->SR = 0;                            /* Clear pending IRQs.      */
}

/**
 * @brief   Shared IRQ handler.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_serve_interrupt(GPTDriver *gptp) {
  uint32_t sr;

  sr  = gptp->tim->SR;
  sr &= gptp->tim->DIER & AT32_TIM_DIER_IRQ_MASK;
  gptp->tim->SR = ~sr;
  if ((sr & AT32_TIM_SR_UIF) != 0) {
    _gpt_isr_invoke_cb(gptp);
  }
}

#endif /* HAL_USE_GPT */

/** @} */
