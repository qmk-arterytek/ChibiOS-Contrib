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
 * @file    TIMv1/at32_tim3.inc
 * @brief   Shared TIM3 handler.
 *
 * @addtogroup AT32_TIM3_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/
#if !defined(AT32_HAS_TIM3)
#error "AT32_HAS_TIM3 not defined in registry"
#endif

/* Driver checks for robustness, undefined USE macros are defaulted to
   FALSE. This makes this module independent from drivers implementation.*/
#if !defined(AT32_GPT_USE_TIM3)
#define AT32_GPT_USE_TIM3                  FALSE
#endif
#if !defined(AT32_ICU_USE_TIM3)
#define AT32_ICU_USE_TIM3                  FALSE
#endif
#if !defined(AT32_PWM_USE_TIM3)
#define AT32_PWM_USE_TIM3                  FALSE
#endif
#if !defined(AT32_ST_USE_TIM3)
#define AT32_ST_USE_TIM3                   FALSE
#endif

#if AT32_HAS_TIM3

/* Priority settings checks.*/
#if !defined(AT32_IRQ_TIM3_PRIORITY)
#error "AT32_IRQ_TIM3_PRIORITY not defined in mcuconf.h"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_IRQ_TIM3_PRIORITY)
#error "Invalid IRQ priority assigned to AT32_IRQ_TIM3_PRIORITY"
#endif

#endif /* AT32_HAS_TIM3 */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void tim3_irq_init(void) {
#if defined(AT32_TIM3_IS_USED)
  nvicEnableVector(AT32_TIM3_NUMBER, AT32_IRQ_TIM3_PRIORITY);
#endif
}

static inline void tim3_irq_deinit(void) {
#if defined(AT32_TIM3_IS_USED)
  nvicDisableVector(AT32_TIM3_NUMBER);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_TIM3_IS_USED) || defined(__DOXYGEN__)
/**
 * @brief   TIM3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TIM3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

#if HAL_USE_GPT
#if AT32_GPT_USE_TIM3
  gpt_lld_serve_interrupt(&GPTD3);
#endif
#endif
#if HAL_USE_ICU
#if AT32_ICU_USE_TIM3
  icu_lld_serve_interrupt(&ICUD3);
#endif
#endif
#if HAL_USE_PWM
#if AT32_PWM_USE_TIM3
  pwm_lld_serve_interrupt(&PWMD3);
#endif
#endif
#if 1
#if AT32_ST_USE_TIM3
  st_lld_serve_interrupt();
#endif
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
