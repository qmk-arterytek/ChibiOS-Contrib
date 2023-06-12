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
 * @file    AT32F415xx/at32_isr.c
 * @brief   AT32F415xx ISR handler code.
 *
 * @addtogroup AT32F415xx_ISR
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

#define exti_serve_irq(pr, channel) {                                       \
                                                                            \
  if ((pr) & (1U << (channel))) {                                           \
    _pal_isr_code(channel);                                                 \
  }                                                                         \
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (HAL_USE_PAL && (PAL_USE_WAIT || PAL_USE_CALLBACKS)) || defined(__DOXYGEN__)
#if !defined(AT32_DISABLE_EXTI0_HANDLER)
/**
 * @brief   EXTI[0] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI0_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 0);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI1_HANDLER)
/**
 * @brief   EXTI[1] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI1_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 1);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI2_HANDLER)
/**
 * @brief   EXTI[2] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI2_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 2);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 2);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI3_HANDLER)
/**
 * @brief   EXTI[3] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI3_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 3);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 3);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI4_HANDLER)
/**
 * @brief   EXTI[4] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI4_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 4);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 4);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI5_9_HANDLER)
/**
 * @brief   EXTI[5]...EXTI[9] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI5_9_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & ((1U << 5) | (1U << 6) | (1U << 7) | (1U << 8) | (1U << 9));
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 5);
  exti_serve_irq(pr, 6);
  exti_serve_irq(pr, 7);
  exti_serve_irq(pr, 8);
  exti_serve_irq(pr, 9);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI10_15_HANDLER)
/**
 * @brief   EXTI[10]...EXTI[15] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI10_15_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & ((1U << 10) | (1U << 11) | (1U << 12) | (1U << 13) | (1U << 14) | (1U << 15));
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 10);
  exti_serve_irq(pr, 11);
  exti_serve_irq(pr, 12);
  exti_serve_irq(pr, 13);
  exti_serve_irq(pr, 14);
  exti_serve_irq(pr, 15);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI16_HANDLER)
/**
 * @brief   EXTI[16] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI16_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 16);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 16);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI17_HANDLER)
/**
 * @brief   EXTI[17] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI17_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 17);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 17);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI18_HANDLER)
/**
 * @brief   EXTI[18] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI18_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 18);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 18);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI19_HANDLER)
/**
 * @brief   EXTI[19] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI19_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 19);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 19);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI20_HANDLER)
/**
 * @brief   EXTI[20] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI20_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 20);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 20);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI21_HANDLER)
/**
 * @brief   EXTI[21] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI21_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 21);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 21);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if !defined(AT32_DISABLE_EXTI22_HANDLER)
/**
 * @brief   EXTI[22] interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_EXTI22_HANDLER) {
  uint32_t pr;

  OSAL_IRQ_PROLOGUE();

  pr = EXINT->INTSTS & (1U << 22);
  EXINT->INTSTS = pr;

  exti_serve_irq(pr, 22);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#include "at32_tim1_9_10_11.inc"
#include "at32_tim2.inc"
#include "at32_tim3.inc"
#include "at32_tim4.inc"
#include "at32_tim5.inc"

#include "at32_usart1.inc"
#include "at32_usart2.inc"
#include "at32_usart3.inc"
#include "at32_uart4.inc"
#include "at32_uart5.inc"

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enables IRQ sources.
 *
 * @notapi
 */
void irqInit(void) {

#if HAL_USE_PAL
  nvicEnableVector(AT32_EXTI0_NUMBER, AT32_IRQ_EXTI0_PRIORITY);
  nvicEnableVector(AT32_EXTI1_NUMBER, AT32_IRQ_EXTI1_PRIORITY);
  nvicEnableVector(AT32_EXTI2_NUMBER, AT32_IRQ_EXTI2_PRIORITY);
  nvicEnableVector(AT32_EXTI3_NUMBER, AT32_IRQ_EXTI3_PRIORITY);
  nvicEnableVector(AT32_EXTI4_NUMBER, AT32_IRQ_EXTI4_PRIORITY);
  nvicEnableVector(AT32_EXTI5_9_NUMBER, AT32_IRQ_EXTI5_9_PRIORITY);
  nvicEnableVector(AT32_EXTI10_15_NUMBER, AT32_IRQ_EXTI10_15_PRIORITY);
  nvicEnableVector(AT32_EXTI16_NUMBER, AT32_IRQ_EXTI16_PRIORITY);
  nvicEnableVector(AT32_EXTI17_NUMBER, AT32_IRQ_EXTI17_PRIORITY);
  nvicEnableVector(AT32_EXTI18_NUMBER, AT32_IRQ_EXTI18_PRIORITY);
  nvicEnableVector(AT32_EXTI19_NUMBER, AT32_IRQ_EXTI19_PRIORITY);
  nvicEnableVector(AT32_EXTI20_NUMBER, AT32_IRQ_EXTI20_PRIORITY);
  nvicEnableVector(AT32_EXTI21_NUMBER, AT32_IRQ_EXTI21_PRIORITY);
  nvicEnableVector(AT32_EXTI22_NUMBER, AT32_IRQ_EXTI22_PRIORITY);
#endif

  tim1_tim9_tim10_tim11_irq_init();
  tim2_irq_init();
  tim3_irq_init();
  tim4_irq_init();
  tim5_irq_init();

  usart1_irq_init();
  usart2_irq_init();
  usart3_irq_init();
  uart4_irq_init();
  uart5_irq_init();
}

/**
 * @brief   Disables IRQ sources.
 *
 * @notapi
 */
void irqDeinit(void) {

#if HAL_USE_PAL
  nvicDisableVector(AT32_EXTI0_NUMBER);
  nvicDisableVector(AT32_EXTI1_NUMBER);
  nvicDisableVector(AT32_EXTI2_NUMBER);
  nvicDisableVector(AT32_EXTI3_NUMBER);
  nvicDisableVector(AT32_EXTI4_NUMBER);
  nvicDisableVector(AT32_EXTI5_9_NUMBER);
  nvicDisableVector(AT32_EXTI10_15_NUMBER);
  nvicDisableVector(AT32_EXTI16_NUMBER);
  nvicDisableVector(AT32_EXTI17_NUMBER);
  nvicDisableVector(AT32_EXTI18_NUMBER);
  nvicDisableVector(AT32_EXTI19_NUMBER);
  nvicDisableVector(AT32_EXTI20_NUMBER);
  nvicDisableVector(AT32_EXTI21_NUMBER);
  nvicDisableVector(AT32_EXTI22_NUMBER);
#endif

  tim1_tim9_tim10_tim11_irq_deinit();
  tim2_irq_deinit();
  tim3_irq_deinit();
  tim4_irq_deinit();
  tim5_irq_deinit();

  usart1_irq_deinit();
  usart2_irq_deinit();
  usart3_irq_deinit();
  uart4_irq_deinit();
  uart5_irq_deinit();
}

/** @} */
