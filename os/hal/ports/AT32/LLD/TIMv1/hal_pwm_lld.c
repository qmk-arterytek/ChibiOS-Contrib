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
 * @file    TIMv1/hal_pwm_lld.c
 * @brief   AT32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if HAL_USE_PWM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 driver identifier.
 * @note    The driver PWMD1 allocates the complex timer TIM1 when enabled.
 */
#if AT32_PWM_USE_TIM1 || defined(__DOXYGEN__)
PWMDriver PWMD1;
#endif

/**
 * @brief   PWMD2 driver identifier.
 * @note    The driver PWMD2 allocates the timer TIM2 when enabled.
 */
#if AT32_PWM_USE_TIM2 || defined(__DOXYGEN__)
PWMDriver PWMD2;
#endif

/**
 * @brief   PWMD3 driver identifier.
 * @note    The driver PWMD3 allocates the timer TIM3 when enabled.
 */
#if AT32_PWM_USE_TIM3 || defined(__DOXYGEN__)
PWMDriver PWMD3;
#endif

/**
 * @brief   PWMD4 driver identifier.
 * @note    The driver PWMD4 allocates the timer TIM4 when enabled.
 */
#if AT32_PWM_USE_TIM4 || defined(__DOXYGEN__)
PWMDriver PWMD4;
#endif

/**
 * @brief   PWMD5 driver identifier.
 * @note    The driver PWMD5 allocates the timer TIM5 when enabled.
 */
#if AT32_PWM_USE_TIM5 || defined(__DOXYGEN__)
PWMDriver PWMD5;
#endif

/**
 * @brief   PWMD8 driver identifier.
 * @note    The driver PWMD8 allocates the timer TIM8 when enabled.
 */
#if AT32_PWM_USE_TIM8 || defined(__DOXYGEN__)
PWMDriver PWMD8;
#endif

/**
 * @brief   PWMD9 driver identifier.
 * @note    The driver PWMD9 allocates the timer TIM9 when enabled.
 */
#if AT32_PWM_USE_TIM9 || defined(__DOXYGEN__)
PWMDriver PWMD9;
#endif

/**
 * @brief   PWMD10 driver identifier.
 * @note    The driver PWMD10 allocates the timer TIM10 when enabled.
 */
#if AT32_PWM_USE_TIM10 || defined(__DOXYGEN__)
PWMDriver PWMD10;
#endif

/**
 * @brief   PWMD11 driver identifier.
 * @note    The driver PWMD11 allocates the timer TIM11 when enabled.
 */
#if AT32_PWM_USE_TIM11 || defined(__DOXYGEN__)
PWMDriver PWMD11;
#endif

/**
 * @brief   PWMD12 driver identifier.
 * @note    The driver PWMD12 allocates the timer TIM12 when enabled.
 */
#if AT32_PWM_USE_TIM12 || defined(__DOXYGEN__)
PWMDriver PWMD12;
#endif

/**
 * @brief   PWMD13 driver identifier.
 * @note    The driver PWMD13 allocates the timer TIM13 when enabled.
 */
#if AT32_PWM_USE_TIM13 || defined(__DOXYGEN__)
PWMDriver PWMD13;
#endif

/**
 * @brief   PWMD14 driver identifier.
 * @note    The driver PWMD14 allocates the timer TIM14 when enabled.
 */
#if AT32_PWM_USE_TIM14 || defined(__DOXYGEN__)
PWMDriver PWMD14;
#endif

/**
 * @brief   PWMD15 driver identifier.
 * @note    The driver PWMD15 allocates the timer TIM15 when enabled.
 */
#if AT32_PWM_USE_TIM15 || defined(__DOXYGEN__)
PWMDriver PWMD15;
#endif

/**
 * @brief   PWMD16 driver identifier.
 * @note    The driver PWMD16 allocates the timer TIM16 when enabled.
 */
#if AT32_PWM_USE_TIM16 || defined(__DOXYGEN__)
PWMDriver PWMD16;
#endif

/**
 * @brief   PWMD17 driver identifier.
 * @note    The driver PWMD17 allocates the timer TIM17 when enabled.
 */
#if AT32_PWM_USE_TIM17 || defined(__DOXYGEN__)
PWMDriver PWMD17;
#endif

/**
 * @brief   PWMD20 driver identifier.
 * @note    The driver PWMD20 allocates the timer TIM20 when enabled.
 */
#if AT32_PWM_USE_TIM20 || defined(__DOXYGEN__)
PWMDriver PWMD20;
#endif

/**
 * @brief   PWMD21 driver identifier.
 * @note    The driver PWMD21 allocates the timer TIM21 when enabled.
 */
#if AT32_PWM_USE_TIM21 || defined(__DOXYGEN__)
PWMDriver PWMD21;
#endif

/**
 * @brief   PWMD22 driver identifier.
 * @note    The driver PWMD22 allocates the timer TIM22 when enabled.
 */
#if AT32_PWM_USE_TIM22 || defined(__DOXYGEN__)
PWMDriver PWMD22;
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

#if AT32_PWM_USE_TIM1 || defined(__DOXYGEN__)
#if !defined(AT32_TIM1_SUPPRESS_ISR)
#if !defined(AT32_TIM1_UP_HANDLER)
#error "AT32_TIM1_UP_HANDLER not defined"
#endif
/**
 * @brief   TIM1 update interrupt handler.
 * @note    It is assumed that this interrupt is only activated if the callback
 *          pointer is not equal to @p NULL in order to not perform an extra
 *          check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_UP_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}

#if !defined(AT32_TIM1_CC_HANDLER)
#error "AT32_TIM1_CC_HANDLER not defined"
#endif
/**
 * @brief   TIM1 compare interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_CC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM1_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM1 */

#if AT32_PWM_USE_TIM2 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM2_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM2 */

#if AT32_PWM_USE_TIM3 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM3_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM3 */

#if AT32_PWM_USE_TIM4 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD4);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM4_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM4 */

#if AT32_PWM_USE_TIM5 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM5_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM5 */

#if AT32_PWM_USE_TIM8 || defined(__DOXYGEN__)
#if !defined(AT32_TIM8_SUPPRESS_ISR)
#if !defined(AT32_TIM8_UP_HANDLER)
#error "AT32_TIM8_UP_HANDLER not defined"
#endif
/**
 * @brief   TIM8 update interrupt handler.
 * @note    It is assumed that this interrupt is only activated if the callback
 *          pointer is not equal to @p NULL in order to not perform an extra
 *          check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM8_UP_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD8);

  OSAL_IRQ_EPILOGUE();
}

#if !defined(AT32_TIM8_CC_HANDLER)
#error "AT32_TIM8_CC_HANDLER not defined"
#endif
/**
 * @brief   TIM8 compare interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM8_CC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD8);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TIM8_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM8 */

#if AT32_PWM_USE_TIM9 || defined(__DOXYGEN__)
#if !defined(AT32_TIM9_SUPPRESS_ISR)
#error "TIM9 ISR not defined by platform"
#endif /* !defined(AT32_TIM9_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM9 */

#if AT32_PWM_USE_TIM10 || defined(__DOXYGEN__)
#if !defined(AT32_TIM10_SUPPRESS_ISR)
#error "TIM10 ISR not defined by platform"
#endif /* !defined(AT32_TIM10_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM10 */

#if AT32_PWM_USE_TIM11 || defined(__DOXYGEN__)
#if !defined(AT32_TIM11_SUPPRESS_ISR)
#error "TIM11 ISR not defined by platform"
#endif /* !defined(AT32_TIM11_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM11 */

#if AT32_PWM_USE_TIM12 || defined(__DOXYGEN__)
#if !defined(AT32_TIM12_SUPPRESS_ISR)
#error "TIM12 ISR not defined by platform"
#endif /* !defined(AT32_TIM12_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM12 */

#if AT32_PWM_USE_TIM13 || defined(__DOXYGEN__)
#if !defined(AT32_TIM13_SUPPRESS_ISR)
#error "TIM13 ISR not defined by platform"
#endif /* !defined(AT32_TIM13_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM13 */

#if AT32_PWM_USE_TIM14 || defined(__DOXYGEN__)
#if !defined(AT32_TIM14_SUPPRESS_ISR)
#error "TIM14 ISR not defined by platform"
#endif /* !defined(AT32_TIM14_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM14 */

#if AT32_PWM_USE_TIM15 || defined(__DOXYGEN__)
#if !defined(AT32_TIM15_SUPPRESS_ISR)
#error "TIM15 ISR not defined by platform"
#endif /* !defined(AT32_TIM15_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM15 */

#if AT32_PWM_USE_TIM16 || defined(__DOXYGEN__)
#if !defined(AT32_TIM16_SUPPRESS_ISR)
#error "TIM16 ISR not defined by platform"
#endif /* !defined(AT32_TIM16_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM16 */

#if AT32_PWM_USE_TIM17 || defined(__DOXYGEN__)
#if !defined(AT32_TIM17_SUPPRESS_ISR)
#error "TIM17 ISR not defined by platform"
#endif /* !defined(AT32_TIM17_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM17 */

#if AT32_PWM_USE_TIM20 || defined(__DOXYGEN__)
#if !defined(AT32_TIM20_SUPPRESS_ISR)
#error "TIM20 ISR not defined by platform"
#endif /* !defined(AT32_TIM20_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM20 */

#if AT32_PWM_USE_TIM21 || defined(__DOXYGEN__)
#if !defined(AT32_TIM21_SUPPRESS_ISR)
#error "TIM21 ISR not defined by platform"
#endif /* !defined(AT32_TIM21_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM21 */

#if AT32_PWM_USE_TIM22 || defined(__DOXYGEN__)
#if !defined(AT32_TIM22_SUPPRESS_ISR)
#error "TIM22 ISR not defined by platform"
#endif /* !defined(AT32_TIM22_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TIM22 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if AT32_PWM_USE_TIM1
  /* Driver initialization.*/
  pwmObjectInit(&PWMD1);
  PWMD1.channels = AT32_TIM1_CHANNELS;
  PWMD1.tim = AT32_TIM1;
  PWMD1.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM2
  /* Driver initialization.*/
  pwmObjectInit(&PWMD2);
  PWMD2.channels = AT32_TIM2_CHANNELS;
  PWMD2.tim = AT32_TIM2;
  PWMD2.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM3
  /* Driver initialization.*/
  pwmObjectInit(&PWMD3);
  PWMD3.channels = AT32_TIM3_CHANNELS;
  PWMD3.tim = AT32_TIM3;
  PWMD3.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM4
  /* Driver initialization.*/
  pwmObjectInit(&PWMD4);
  PWMD4.channels = AT32_TIM4_CHANNELS;
  PWMD4.tim = AT32_TIM4;
  PWMD4.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM5
  /* Driver initialization.*/
  pwmObjectInit(&PWMD5);
  PWMD5.channels = AT32_TIM5_CHANNELS;
  PWMD5.tim = AT32_TIM5;
  PWMD5.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM8
  /* Driver initialization.*/
  pwmObjectInit(&PWMD8);
  PWMD8.channels = AT32_TIM8_CHANNELS;
  PWMD8.tim = AT32_TIM8;
  PWMD8.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM9
  /* Driver initialization.*/
  pwmObjectInit(&PWMD9);
  PWMD9.channels = AT32_TIM9_CHANNELS;
  PWMD9.tim = AT32_TIM9;
  PWMD9.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM10
  /* Driver initialization.*/
  pwmObjectInit(&PWMD10);
  PWMD10.channels = AT32_TIM10_CHANNELS;
  PWMD10.tim = AT32_TIM10;
  PWMD10.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM11
  /* Driver initialization.*/
  pwmObjectInit(&PWMD11);
  PWMD11.channels = AT32_TIM11_CHANNELS;
  PWMD11.tim = AT32_TIM11;
  PWMD11.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM12
  /* Driver initialization.*/
  pwmObjectInit(&PWMD12);
  PWMD12.channels = AT32_TIM12_CHANNELS;
  PWMD12.tim = AT32_TIM12;
  PWMD12.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM13
  /* Driver initialization.*/
  pwmObjectInit(&PWMD13);
  PWMD13.channels = AT32_TIM13_CHANNELS;
  PWMD13.tim = AT32_TIM13;
  PWMD13.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM14
  /* Driver initialization.*/
  pwmObjectInit(&PWMD14);
  PWMD14.channels = AT32_TIM14_CHANNELS;
  PWMD14.tim = AT32_TIM14;
  PWMD14.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM15
  /* Driver initialization.*/
  pwmObjectInit(&PWMD15);
  PWMD15.channels = AT32_TIM15_CHANNELS;
  PWMD15.tim = AT32_TIM15;
  PWMD15.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM16
  /* Driver initialization.*/
  pwmObjectInit(&PWMD16);
  PWMD16.channels = AT32_TIM16_CHANNELS;
  PWMD16.tim = AT32_TIM16;
  PWMD16.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM17
  /* Driver initialization.*/
  pwmObjectInit(&PWMD17);
  PWMD17.channels = AT32_TIM17_CHANNELS;
  PWMD17.tim = AT32_TIM17;
  PWMD17.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM20
  /* Driver initialization.*/
  pwmObjectInit(&PWMD20);
  PWMD20.channels = AT32_TIM20_CHANNELS;
  PWMD20.tim = AT32_TIM20;
  PWMD20.has_bdtr = true;
#endif

#if AT32_PWM_USE_TIM21
  /* Driver initialization.*/
  pwmObjectInit(&PWMD21);
  PWMD21.channels = AT32_TIM21_CHANNELS;
  PWMD21.tim = AT32_TIM21;
  PWMD21.has_bdtr = false;
#endif

#if AT32_PWM_USE_TIM22
  /* Driver initialization.*/
  pwmObjectInit(&PWMD22);
  PWMD22.channels = AT32_TIM22_CHANNELS;
  PWMD22.tim = AT32_TIM22;
  PWMD22.has_bdtr = false;
#endif
}

/**
 * @brief   Configures and activates the PWM peripheral.
 * @note    Starting a driver that is already in the @p PWM_READY state
 *          disables all the active channels.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_start(PWMDriver *pwmp) {
  uint32_t psc;
  uint32_t ccer;

  if (pwmp->state == PWM_STOP) {
    /* Clock activation and timer reset.*/
#if AT32_PWM_USE_TIM1
    if (&PWMD1 == pwmp) {
      crmEnableTMR1(true);
      crmResetTMR1();
#if !defined(AT32_TIM1_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM1_UP_NUMBER, AT32_PWM_TIM1_IRQ_PRIORITY);
      nvicEnableVector(AT32_TIM1_CC_NUMBER, AT32_PWM_TIM1_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM1CLK)
      pwmp->clock = AT32_TIM1CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM2
    if (&PWMD2 == pwmp) {
      crmEnableTMR2(true);
      crmResetTMR2();
#if !defined(AT32_TIM2_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM2_NUMBER, AT32_PWM_TIM2_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM2CLK)
      pwmp->clock = AT32_TIM2CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM3
    if (&PWMD3 == pwmp) {
      crmEnableTMR3(true);
      crmResetTMR3();
#if !defined(AT32_TIM3_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM3_NUMBER, AT32_PWM_TIM3_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM3CLK)
      pwmp->clock = AT32_TIM3CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM4
    if (&PWMD4 == pwmp) {
      crmEnableTMR4(true);
      crmResetTMR4();
#if !defined(AT32_TIM4_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM4_NUMBER, AT32_PWM_TIM4_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM4CLK)
      pwmp->clock = AT32_TIM4CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM5
    if (&PWMD5 == pwmp) {
      crmEnableTMR5(true);
      crmResetTMR5();
#if !defined(AT32_TIM5_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM5_NUMBER, AT32_PWM_TIM5_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM5CLK)
      pwmp->clock = AT32_TIM5CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM8
    if (&PWMD8 == pwmp) {
      crmEnableTMR8(true);
      crmResetTMR8();
#if !defined(AT32_TIM8_SUPPRESS_ISR)
      nvicEnableVector(AT32_TIM8_UP_NUMBER, AT32_PWM_TIM8_IRQ_PRIORITY);
      nvicEnableVector(AT32_TIM8_CC_NUMBER, AT32_PWM_TIM8_IRQ_PRIORITY);
#endif
#if defined(AT32_TIM8CLK)
      pwmp->clock = AT32_TIM8CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM9
    if (&PWMD9 == pwmp) {
      crmEnableTMR9(true);
      crmResetTMR9();
#if defined(AT32_TIM9CLK)
      pwmp->clock = AT32_TIM9CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM10
    if (&PWMD10 == pwmp) {
      crmEnableTMR10(true);
      crmResetTMR10();
#if defined(AT32_TIM10CLK)
      pwmp->clock = AT32_TIM10CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM11
    if (&PWMD11 == pwmp) {
      crmEnableTMR11(true);
      crmResetTMR11();
#if defined(AT32_TIM11CLK)
      pwmp->clock = AT32_TIM11CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM12
    if (&PWMD12 == pwmp) {
      crmEnableTMR12(true);
      crmResetTMR12();
#if defined(AT32_TIM12CLK)
      pwmp->clock = AT32_TIM12CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM13
    if (&PWMD13 == pwmp) {
      crmEnableTMR13(true);
      crmResetTMR13();
#if defined(AT32_TIM13CLK)
      pwmp->clock = AT32_TIM13CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM14
    if (&PWMD14 == pwmp) {
      crmEnableTMR14(true);
      crmResetTMR14();
#if defined(AT32_TIM14CLK)
      pwmp->clock = AT32_TIM14CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM15
    if (&PWMD15 == pwmp) {
      crmEnableTMR15(true);
      crmResetTMR15();
#if defined(AT32_TIM15CLK)
      pwmp->clock = AT32_TIM15CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM16
    if (&PWMD16 == pwmp) {
      crmEnableTMR16(true);
      crmResetTMR16();
#if defined(AT32_TIM16CLK)
      pwmp->clock = AT32_TIM16CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM17
    if (&PWMD17 == pwmp) {
      crmEnableTMR17(true);
      crmResetTMR17();
#if defined(AT32_TIM17CLK)
      pwmp->clock = AT32_TIM17CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM20
    if (&PWMD20 == pwmp) {
      crmEnableTMR20(true);
      crmResetTMR20();
#if defined(AT32_TIM20CLK)
      pwmp->clock = AT32_TIM20CLK;
#else
      pwmp->clock = AT32_TIMCLK2;
#endif
    }
#endif

#if AT32_PWM_USE_TIM21
    if (&PWMD21 == pwmp) {
      crmEnableTMR21(true);
      crmResetTMR21();
#if defined(AT32_TIM21CLK)
      pwmp->clock = AT32_TIM21CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

#if AT32_PWM_USE_TIM22
    if (&PWMD22 == pwmp) {
      crmEnableTMR22(true);
      crmResetTMR22();
#if defined(AT32_TIM22CLK)
      pwmp->clock = AT32_TIM22CLK;
#else
      pwmp->clock = AT32_TIMCLK1;
#endif
    }
#endif

    /* All channels configured in PWM1 mode with preload enabled and will
       stay that way until the driver is stopped.*/
    pwmp->tim->CCMR1 = AT32_TIM_CCMR1_OC1M(6) | AT32_TIM_CCMR1_OC1PE |
                       AT32_TIM_CCMR1_OC2M(6) | AT32_TIM_CCMR1_OC2PE;
    pwmp->tim->CCMR2 = AT32_TIM_CCMR2_OC3M(6) | AT32_TIM_CCMR2_OC3PE |
                       AT32_TIM_CCMR2_OC4M(6) | AT32_TIM_CCMR2_OC4PE;
#if AT32_TIM_MAX_CHANNELS > 4
    pwmp->tim->CCMR3 = AT32_TIM_CCMR3_OC5M(6) | AT32_TIM_CCMR3_OC5PE |
                       AT32_TIM_CCMR3_OC6M(6) | AT32_TIM_CCMR3_OC6PE;
#endif
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    pwmp->tim->CR1    = 0;                  /* Timer disabled.              */
    pwmp->tim->CCR[0] = 0;                  /* Comparator 1 disabled.       */
    pwmp->tim->CCR[1] = 0;                  /* Comparator 2 disabled.       */
    pwmp->tim->CCR[2] = 0;                  /* Comparator 3 disabled.       */
    pwmp->tim->CCR[3] = 0;                  /* Comparator 4 disabled.       */
#if AT32_TIM_MAX_CHANNELS > 4
    if (pwmp->channels > 4) {
      pwmp->tim->CCXR[0] = 0;               /* Comparator 5 disabled.       */
      pwmp->tim->CCXR[1] = 0;               /* Comparator 6 disabled.       */
    }
#endif
    pwmp->tim->CNT  = 0;                    /* Counter reset to zero.       */
  }

  /* Timer configuration.*/
  psc = (pwmp->clock / pwmp->config->frequency) - 1;
  osalDbgAssert((psc <= 0xFFFF) &&
                ((psc + 1) * pwmp->config->frequency) == pwmp->clock,
                "invalid frequency");
  pwmp->tim->PSC  = psc;
  pwmp->tim->ARR  = pwmp->period - 1;
  pwmp->tim->CR2  = pwmp->config->cr2;

  /* Output enables and polarities setup.*/
  ccer = 0;
  switch (pwmp->config->channels[0].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= AT32_TIM_CCER_CC1P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= AT32_TIM_CCER_CC1E;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[1].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= AT32_TIM_CCER_CC2P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= AT32_TIM_CCER_CC2E;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[2].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= AT32_TIM_CCER_CC3P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= AT32_TIM_CCER_CC3E;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[3].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= AT32_TIM_CCER_CC4P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= AT32_TIM_CCER_CC4E;
    /* Falls through.*/
  default:
    ;
  }
  if (pwmp->has_bdtr) {
    switch (pwmp->config->channels[0].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= AT32_TIM_CCER_CC1NP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= AT32_TIM_CCER_CC1NE;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[1].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= AT32_TIM_CCER_CC2NP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= AT32_TIM_CCER_CC2NE;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[2].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= AT32_TIM_CCER_CC3NP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= AT32_TIM_CCER_CC3NE;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[3].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= AT32_TIM_CCER_CC4NP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= AT32_TIM_CCER_CC4NE;
      /* Falls through.*/
    default:
      ;
    }
  }

  pwmp->tim->CCER  = ccer;
  pwmp->tim->EGR   = AT32_TIM_EGR_UG;      /* Update event.                */
  pwmp->tim->SR    = 0;                     /* Clear pending IRQs.          */
  pwmp->tim->DIER  = pwmp->config->dier &   /* DMA-related DIER settings.   */
                     ~AT32_TIM_DIER_IRQ_MASK;
  if (pwmp->has_bdtr) {
    pwmp->tim->BDTR  = pwmp->config->bdtr | AT32_TIM_BDTR_MOE;
  }
  /* Timer configured and started.*/
  pwmp->tim->CR1   = AT32_TIM_CR1_ARPE | AT32_TIM_CR1_URS |
                     AT32_TIM_CR1_CEN;
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_stop(PWMDriver *pwmp) {

  /* If in ready state then disables the PWM clock.*/
  if (pwmp->state == PWM_READY) {
    pwmp->tim->CR1  = 0;                    /* Timer disabled.              */
    pwmp->tim->DIER = 0;                    /* All IRQs disabled.           */
    pwmp->tim->SR   = 0;                    /* Clear eventual pending IRQs. */
    if (pwmp->has_bdtr) {
      pwmp->tim->BDTR  = 0;
    }

#if AT32_PWM_USE_TIM1
    if (&PWMD1 == pwmp) {
#if !defined(AT32_TIM1_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM1_UP_NUMBER);
      nvicDisableVector(AT32_TIM1_CC_NUMBER);
#endif
      crmDisableTMR1();
    }
#endif

#if AT32_PWM_USE_TIM2
    if (&PWMD2 == pwmp) {
#if !defined(AT32_TIM2_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM2_NUMBER);
#endif
      crmDisableTMR2();
    }
#endif

#if AT32_PWM_USE_TIM3
    if (&PWMD3 == pwmp) {
#if !defined(AT32_TIM3_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM3_NUMBER);
#endif
      crmDisableTMR3();
    }
#endif

#if AT32_PWM_USE_TIM4
    if (&PWMD4 == pwmp) {
#if !defined(AT32_TIM4_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM4_NUMBER);
#endif
      crmDisableTMR4();
    }
#endif

#if AT32_PWM_USE_TIM5
    if (&PWMD5 == pwmp) {
#if !defined(AT32_TIM5_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM5_NUMBER);
#endif
      crmDisableTMR5();
    }
#endif

#if AT32_PWM_USE_TIM8
    if (&PWMD8 == pwmp) {
#if !defined(AT32_TIM8_SUPPRESS_ISR)
      nvicDisableVector(AT32_TIM8_UP_NUMBER);
      nvicDisableVector(AT32_TIM8_CC_NUMBER);
#endif
      crmDisableTMR8();
    }
#endif

#if AT32_PWM_USE_TIM9
    if (&PWMD9 == pwmp) {
      crmDisableTMR9();
    }
#endif

#if AT32_PWM_USE_TIM10
    if (&PWMD10 == pwmp) {
      crmDisableTMR10();
    }
#endif

#if AT32_PWM_USE_TIM11
    if (&PWMD11 == pwmp) {
      crmDisableTMR11();
    }
#endif

#if AT32_PWM_USE_TIM12
    if (&PWMD12 == pwmp) {
      crmDisableTMR12();
    }
#endif

#if AT32_PWM_USE_TIM13
    if (&PWMD13 == pwmp) {
      crmDisableTMR13();
    }
#endif

#if AT32_PWM_USE_TIM14
    if (&PWMD14 == pwmp) {
      crmDisableTMR14();
    }
#endif

#if AT32_PWM_USE_TIM15
    if (&PWMD15 == pwmp) {
      crmDisableTMR15();
    }
#endif

#if AT32_PWM_USE_TIM16
    if (&PWMD16 == pwmp) {
      crmDisableTMR16();
    }
#endif

#if AT32_PWM_USE_TIM17
    if (&PWMD17 == pwmp) {
      crmDisableTMR17();
    }
#endif

#if AT32_PWM_USE_TIM20
    if (&PWMD20 == pwmp) {
      crmDisableTMR20();
    }
#endif

#if AT32_PWM_USE_TIM21
    if (&PWMD21 == pwmp) {
      crmDisableTMR21();
    }
#endif

#if AT32_PWM_USE_TIM22
    if (&PWMD22 == pwmp) {
      crmDisableTMR22();
    }
#endif
  }
}

/**
 * @brief   Enables a PWM channel.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is active using the specified configuration.
 * @note    The function has effect at the next cycle start.
 * @note    Channel notification is not enabled.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 * @param[in] width     PWM pulse width as clock pulses number
 *
 * @notapi
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width) {

  /* Changing channel duty cycle on the fly.*/
#if AT32_TIM_MAX_CHANNELS <= 4
  pwmp->tim->CCR[channel] = width;
#else
  if (channel < 4)
    pwmp->tim->CCR[channel] = width;
  else
    pwmp->tim->CCXR[channel - 4] = width;
#endif
}

/**
 * @brief   Disables a PWM channel and its notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is disabled and its output line returned to the
 *          idle state.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

#if AT32_TIM_MAX_CHANNELS <= 4
  pwmp->tim->CCR[channel] = 0;
  pwmp->tim->DIER &= ~(2 << channel);
#else
  if (channel < 4) {
    pwmp->tim->CCR[channel] = 0;
    pwmp->tim->DIER &= ~(2 << channel);
  }
  else
    pwmp->tim->CCXR[channel - 4] = 0;
#endif
}

/**
 * @brief   Enables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_enable_periodic_notification(PWMDriver *pwmp) {
  uint32_t dier = pwmp->tim->DIER;

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((dier & AT32_TIM_DIER_UIE) == 0) {
    pwmp->tim->SR   = ~AT32_TIM_SR_UIF;
    pwmp->tim->DIER = dier | AT32_TIM_DIER_UIE;
  }
}

/**
 * @brief   Disables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_disable_periodic_notification(PWMDriver *pwmp) {

  pwmp->tim->DIER &= ~AT32_TIM_DIER_UIE;
}

/**
 * @brief   Enables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                         pwmchannel_t channel) {
  uint32_t dier = pwmp->tim->DIER;

#if AT32_TIM_MAX_CHANNELS > 4
  /* Channels 4 and 5 do not support callbacks.*/
  osalDbgAssert(channel < 4, "callback not supported");
#endif

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((dier & (2 << channel)) == 0) {
    pwmp->tim->SR   = ~(2 << channel);
    pwmp->tim->DIER = dier | (2 << channel);
  }
}

/**
 * @brief   Disables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                          pwmchannel_t channel) {

  pwmp->tim->DIER &= ~(2 << channel);
}

/**
 * @brief   Common TIM2...TIM5,TIM9 IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
  uint32_t sr;

  sr  = pwmp->tim->SR;
  sr &= pwmp->tim->DIER & AT32_TIM_DIER_IRQ_MASK;
  pwmp->tim->SR = ~sr;
  if (((sr & AT32_TIM_SR_CC1IF) != 0) &&
      (pwmp->config->channels[0].callback != NULL))
    pwmp->config->channels[0].callback(pwmp);
  if (((sr & AT32_TIM_SR_CC2IF) != 0) &&
      (pwmp->config->channels[1].callback != NULL))
    pwmp->config->channels[1].callback(pwmp);
  if (((sr & AT32_TIM_SR_CC3IF) != 0) &&
      (pwmp->config->channels[2].callback != NULL))
    pwmp->config->channels[2].callback(pwmp);
  if (((sr & AT32_TIM_SR_CC4IF) != 0) &&
      (pwmp->config->channels[3].callback != NULL))
    pwmp->config->channels[3].callback(pwmp);
  if (((sr & AT32_TIM_SR_UIF) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
}

#endif /* HAL_USE_PWM */

/** @} */
