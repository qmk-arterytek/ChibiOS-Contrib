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
 * @file    SYSTICKv1/hal_st_lld.c
 * @brief   ST Driver subsystem low level driver code.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if (OSAL_ST_RESOLUTION == 32)
#define ST_ARR_INIT                         0xFFFFFFFFU
#else
#define ST_ARR_INIT                         0x0000FFFFU
#endif

#if AT32_ST_USE_TIMER == 2

#if !AT32_HAS_TIM2
#error "TIM2 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM2_IS_32BITS
#error "TIM2 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM2_HANDLER
#define ST_NUMBER                           AT32_TIM2_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR2(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR2_PAUSE
#endif

#elif AT32_ST_USE_TIMER == 3

#if !AT32_HAS_TIM3
#error "TIM3 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM3_IS_32BITS
#error "TIM3 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM3_HANDLER
#define ST_NUMBER                           AT32_TIM3_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR3(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR3_PAUSE

#elif AT32_ST_USE_TIMER == 4

#if !AT32_HAS_TIM4
#error "TIM4 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM4_IS_32BITS
#error "TIM4 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM4_HANDLER
#define ST_NUMBER                           AT32_TIM4_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR4(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR4_PAUSE

#elif AT32_ST_USE_TIMER == 5

#if !AT32_HAS_TIM5
#error "TIM5 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM5_IS_32BITS
#error "TIM5 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM5_HANDLER
#define ST_NUMBER                           AT32_TIM5_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR5(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR5_PAUSE

#elif AT32_ST_USE_TIMER == 9

#if !AT32_HAS_TIM9
#error "TIM9 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM9_IS_32BITS
#error "TIM9 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM9_HANDLER
#define ST_NUMBER                           AT32_TIM9_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR9(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR9_PAUSE

#elif AT32_ST_USE_TIMER == 10

#if !AT32_HAS_TIM10
#error "TIM10 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM10_IS_32BITS
#error "TIM10 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM10_HANDLER
#define ST_NUMBER                           AT32_TIM10_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR10(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR10_PAUSE

#elif AT32_ST_USE_TIMER == 11

#if !AT32_HAS_TIM11
#error "TIM11 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM11_IS_32BITS
#error "TIM11 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM11_HANDLER
#define ST_NUMBER                           AT32_TIM11_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR11(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR11_PAUSE

#elif AT32_ST_USE_TIMER == 12

#if !AT32_HAS_TIM12
#error "TIM12 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM12_IS_32BITS
#error "TIM12 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM12_HANDLER
#define ST_NUMBER                           AT32_TIM12_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR12(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR12_PAUSE

#elif AT32_ST_USE_TIMER == 13

#if !AT32_HAS_TIM13
#error "TIM13 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM13_IS_32BITS
#error "TIM13 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM13_HANDLER
#define ST_NUMBER                           AT32_TIM13_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR13(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR13_PAUSE

#elif AT32_ST_USE_TIMER == 14

#if !AT32_HAS_TIM14
#error "TIM14 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM14_IS_32BITS
#error "TIM14 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM14_HANDLER
#define ST_NUMBER                           AT32_TIM14_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR14(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR14_PAUSE

#elif AT32_ST_USE_TIMER == 15

#if !AT32_HAS_TIM15
#error "TIM15 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM15_IS_32BITS
#error "TIM15 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM15_HANDLER
#define ST_NUMBER                           AT32_TIM15_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR15(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR15_PAUSE

#elif AT32_ST_USE_TIMER == 16

#if !AT32_HAS_TIM16
#error "TIM16 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM16_IS_32BITS
#error "TIM16 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM16_HANDLER
#define ST_NUMBER                           AT32_TIM16_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR16(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR16_PAUSE

#elif AT32_ST_USE_TIMER == 17

#if !AT32_HAS_TIM17
#error "TIM17 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM17_IS_32BITS
#error "TIM17 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM17_HANDLER
#define ST_NUMBER                           AT32_TIM17_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR17(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR17_PAUSE

#elif AT32_ST_USE_TIMER == 21

#if !AT32_HAS_TIM21
#error "TIM21 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM21_IS_32BITS
#error "TIM21 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM21_HANDLER
#define ST_NUMBER                           AT32_TIM21_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR21(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR21_PAUSE

#elif AT32_ST_USE_TIMER == 22

#if !AT32_HAS_TIM22
#error "TIM22 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TIM22_IS_32BITS
#error "TIM21 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TIM22_HANDLER
#define ST_NUMBER                           AT32_TIM22_NUMBER
#define ST_CLOCK_SRC                        AT32_TIMCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR22(true)
#define ST_ENABLE_STOP()                    DEBUGMCU->CTRL |= DEBUG_CTRL_TMR22_PAUSE

#else
#error "AT32_ST_USE_TIMER specifies an unsupported timer"
#endif

#if 0 /* TODO remove */
#if ST_CLOCK_SRC % OSAL_ST_FREQUENCY != 0
#error "the selected ST frequency is not obtainable because integer rounding"
#endif

#if (ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1 > 0xFFFF
#error "the selected ST frequency is not obtainable because TIM timer prescaler limits"
#endif
#endif

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#define ST_HANDLER                          SysTick_Handler

#if defined(AT32_CORE_CK)
#define SYSTICK_CK                          AT32_CORE_CK
#else
#define SYSTICK_CK                          AT32_HCLK
#endif

#if SYSTICK_CK % OSAL_ST_FREQUENCY != 0
#error "the selected ST frequency is not obtainable because integer rounding"
#endif

#if (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1 > 0xFFFFFF
#error "the selected ST frequency is not obtainable because SysTick timer counter limits"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if !defined(AT32_SYSTICK_SUPPRESS_ISR)
/**
 * @brief   Interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  st_lld_serve_interrupt();

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Free running counter mode.*/
  osalDbgAssert((ST_CLOCK_SRC % OSAL_ST_FREQUENCY) == 0U,
                "clock rounding error");
  osalDbgAssert(((ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1U) < 0x10000,
                "clock prescaler overflow");

  /* Enabling timer clock.*/
  ST_ENABLE_CLOCK();

  /* Enabling the stop mode during debug for this timer.*/
  ST_ENABLE_STOP();

  /* Initializing the counter in free running mode.*/
  AT32_ST_TIM->PSC    = (ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1;
  AT32_ST_TIM->ARR    = ST_ARR_INIT;
  AT32_ST_TIM->CCMR1  = 0;
  AT32_ST_TIM->CCR[0] = 0;
#if ST_LLD_NUM_ALARMS > 1
  AT32_ST_TIM->CCR[1] = 0;
#endif
#if ST_LLD_NUM_ALARMS > 2
  AT32_ST_TIM->CCR[2] = 0;
#endif
#if ST_LLD_NUM_ALARMS > 3
  AT32_ST_TIM->CCR[3] = 0;
#endif
  AT32_ST_TIM->DIER   = 0;
  AT32_ST_TIM->CR2    = 0;
  AT32_ST_TIM->EGR    = (0x1U << 0);
  AT32_ST_TIM->CR1    = (0x1U << 0);

#if !defined(AT32_SYSTICK_SUPPRESS_ISR)
  /* IRQ enabled.*/
  nvicEnableVector(ST_NUMBER, AT32_ST_IRQ_PRIORITY);
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* Periodic systick mode, the Cortex-Mx internal systick timer is used
     in this mode.*/
  SysTick->LOAD = (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;

  /* IRQ enabled.*/
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, AT32_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

/**
 * @brief   IRQ handling code.
 */
void st_lld_serve_interrupt(void) {
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint32_t sr;
  at32_tim_t *timp = AT32_ST_TIM;

  sr  = timp->SR;
  sr &= timp->DIER & AT32_TIM_DIER_IRQ_MASK;
  timp->SR = ~sr;

  if ((sr & (0x1U << 1)) != 0U)
#endif
  {
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
#if ST_LLD_NUM_ALARMS > 1
  if ((sr & TIM_SR_CC2IF) != 0U) {
    if (st_callbacks[1] != NULL) {
      st_callbacks[1](1U);
    }
  }
#endif
#if ST_LLD_NUM_ALARMS > 2
  if ((sr & TIM_SR_CC3IF) != 0U) {
    if (st_callbacks[2] != NULL) {
      st_callbacks[2](2U);
    }
  }
#endif
#if ST_LLD_NUM_ALARMS > 3
  if ((sr & TIM_SR_CC4IF) != 0U) {
    if (st_callbacks[3] != NULL) {
      st_callbacks[3](3U);
    }
  }
#endif
#endif
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */
