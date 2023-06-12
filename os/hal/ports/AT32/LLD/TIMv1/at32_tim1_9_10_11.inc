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
 * @file    TIMv1/at32_tim1_9_10_11.inc
 * @brief   Shared TIM1, TIM9, TIM10, TIM11 handler.
 *
 * @addtogroup AT32_TIM1_TIM9_TIM10_TIM11_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TIM1)
#error "AT32_HAS_TIM1 not defined in registry"
#endif

#if !defined(AT32_HAS_TIM9)
#error "AT32_HAS_TIM9 not defined in registry"
#endif

#if !defined(AT32_HAS_TIM10)
#error "AT32_HAS_TIM10 not defined in registry"
#endif

#if !defined(AT32_HAS_TIM11)
#error "AT32_HAS_TIM11 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TIM1)
#define AT32_GPT_USE_TIM1                  FALSE
#endif
#if !defined(AT32_ICU_USE_TIM1)
#define AT32_ICU_USE_TIM1                  FALSE
#endif
#if !defined(AT32_PWM_USE_TIM1)
#define AT32_PWM_USE_TIM1                  FALSE
#endif
#if !defined(AT32_ST_USE_TIM1)
#define AT32_ST_USE_TIM1                   FALSE
#endif

#if !defined(AT32_GPT_USE_TIM9)
#define AT32_GPT_USE_TIM9                  FALSE
#endif
#if !defined(AT32_ICU_USE_TIM9)
#define AT32_ICU_USE_TIM9                  FALSE
#endif
#if !defined(AT32_PWM_USE_TIM9)
#define AT32_PWM_USE_TIM9                  FALSE
#endif
#if !defined(AT32_ST_USE_TIM9)
#define AT32_ST_USE_TIM9                   FALSE
#endif

#if !defined(AT32_GPT_USE_TIM10)
#define AT32_GPT_USE_TIM10                 FALSE
#endif
#if !defined(AT32_ICU_USE_TIM10)
#define AT32_ICU_USE_TIM10                 FALSE
#endif
#if !defined(AT32_PWM_USE_TIM10)
#define AT32_PWM_USE_TIM10                 FALSE
#endif
#if !defined(AT32_ST_USE_TIM10)
#define AT32_ST_USE_TIM10                  FALSE
#endif

#if !defined(AT32_GPT_USE_TIM11)
#define AT32_GPT_USE_TIM11                 FALSE
#endif
#if !defined(AT32_ICU_USE_TIM11)
#define AT32_ICU_USE_TIM11                 FALSE
#endif
#if !defined(AT32_PWM_USE_TIM11)
#define AT32_PWM_USE_TIM11                 FALSE
#endif
#if !defined(AT32_ST_USE_TIM11)
#define AT32_ST_USE_TIM11                  FALSE
#endif

#if AT32_HAS_TIM1 || AT32_HAS_TIM9 || AT32_HAS_TIM10 || AT32_HAS_TIM11

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TIM1_BRK_TIM9_PRIORITY)
#error "AT32_IRQ_TIM1_BRK_TIM9_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TIM1_UP_TIM10_PRIORITY)
#error "AT32_IRQ_TIM1_UP_TIM10_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TIM1_TRGCO_TIM11_PRIORITY)
#error "AT32_IRQ_TIM1_TRGCO_TIM11_PRIORITY not defined in mcuconf.h"
#endif

#if !defined(AT32_IRQ_TIM1_CC_PRIORITY)
#error "AT32_IRQ_TIM1_CC_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TIM1_BRK_TIM9_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TIM1_BRK_TIM9_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TIM1_UP_TIM10_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TIM1_UP_TIM10_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TIM1_TRGCO_TIM11_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TIM1_TRGCO_TIM11_PRIORITY"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TIM1_CC_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TIM1_CC_PRIORITY"
#endif

#endif /* AT32_HAS_TIM1 || AT32_HAS_TIM9 || AT32_HAS_TIM10 || AT32_HAS_TIM11 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tim1_tim9_tim10_tim11_irq_init(void) {
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM9_IS_USED)
  nvicEnableVector(AT32_TIM1_BRK_TIM9_NUMBER,
                   AT32_IRQ_TIM1_BRK_TIM9_PRIORITY);
#endif
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM10_IS_USED)
  nvicEnableVector(AT32_TIM1_UP_TIM10_NUMBER,
                   AT32_IRQ_TIM1_UP_TIM10_PRIORITY);
#endif
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM11_IS_USED)
  nvicEnableVector(AT32_TIM1_TRGCO_TIM11_NUMBER,
                   AT32_IRQ_TIM1_TRGCO_TIM11_PRIORITY);
#endif
#if defined(AT32_TIM1_IS_USED)
  nvicEnableVector(AT32_TIM1_CC_NUMBER,
                   AT32_IRQ_TIM1_CC_PRIORITY);
#endif
}

static inline void tim1_tim9_tim10_tim11_irq_deinit(void) {
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM9_IS_USED)
  nvicDisableVector(AT32_TIM1_BRK_TIM9_NUMBER);
#endif
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM10_IS_USED)
  nvicDisableVector(AT32_TIM1_UP_TIM10_NUMBER);
#endif
#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM11_IS_USED)
  nvicDisableVector(AT32_TIM1_TRGCO_TIM11_NUMBER);
#endif
#if defined(AT32_TIM1_IS_USED)
  nvicDisableVector(AT32_TIM1_CC_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM9_IS_USED)  ||          \
    defined(__DOXYGEN__)
/**
 * @brief   TIM1-BRK, TIM9 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_BRK_TIM9_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TIM9
  gpt_lld_serve_interrupt(&GPTD9);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TIM9
  icu_lld_serve_interrupt(&ICUD9);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TIM9
  pwm_lld_serve_interrupt(&PWMD9);
#endif
#endif
#if 1
#if AT32_ST_USE_TIM9
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM10_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TIM1-UP, TIM10 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_UP_TIM10_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TIM1
  gpt_lld_serve_interrupt(&GPTD1);
#endif
#if AT32_GPT_USE_TIM10
  gpt_lld_serve_interrupt(&GPTD10);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TIM1
  icu_lld_serve_interrupt(&ICUD1);
#endif
#if AT32_ICU_USE_TIM10
  icu_lld_serve_interrupt(&ICUD10);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TIM1
  pwm_lld_serve_interrupt(&PWMD1);
#endif
#if AT32_PWM_USE_TIM10
  pwm_lld_serve_interrupt(&PWMD10);
#endif
#endif
#if 1
#if AT32_ST_USE_TIM1
  st_lld_serve_interrupt();
#endif
#if AT32_ST_USE_TIM10
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TIM1_IS_USED) || defined(AT32_TIM11_IS_USED)  ||         \
    defined(__DOXYGEN__)
/**
 * @brief   TIM1-TRG-COM, TIM11 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_TRGCO_TIM11_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TIM11
  gpt_lld_serve_interrupt(&GPTD11);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TIM11
  icu_lld_serve_interrupt(&ICUD11);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TIM11
  pwm_lld_serve_interrupt(&PWMD11);
#endif
#endif
#if 1
#if AT32_ST_USE_TIM11
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(AT32_TIM1_IS_USED)
/**
 * @brief   TIM1-CC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM1_CC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
  /* Not used by GPT.*/
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TIM1
  icu_lld_serve_interrupt(&ICUD1);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TIM1
  pwm_lld_serve_interrupt(&PWMD1);
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
