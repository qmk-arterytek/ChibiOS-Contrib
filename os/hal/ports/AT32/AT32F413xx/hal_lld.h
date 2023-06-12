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
 * @file    AT32F413xx/hal_lld.h
 * @brief   AT32F413xx HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - AT32_LEXTCLK.
 *          - AT32_LEXT_BYPASS (optionally).
 *          - AT32_HEXTCLK.
 *          - AT32_HEXT_BYPASS (optionally).
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "at32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification
 * @{
 */
#define PLATFORM_NAME                          "AT32F413xx"

/**
 * @brief   Sub-family identifier.
 */
#if !defined(AT32F413xx) || defined(__DOXYGEN__)
#define AT32F413xx
#endif
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define AT32_SYSCLK_MAX                        200000000
/**
 * @brief   Maximum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MAX                       25000000

/**
 * @brief   Minimum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MIN                       4000000

/**
 * @brief   Maximum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MAX                       1000000

/**
 * @brief   Minimum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MIN                       32768

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define AT32_PLLIN_MAX                         16000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define AT32_PLLIN_MIN                         2000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define AT32_PLLOUT_MAX                        200000000

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define AT32_PLLOUT_MIN                        4000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define AT32_PCLK1_MAX                         100000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define AT32_PCLK2_MAX                         100000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define AT32_ADCCLK_MAX                        28000000

/**
 * @name    Internal clock sources
 * @{
 */
#define AT32_HICKCLK                           48000000    /**< High speed internal clock. */
#define AT32_LICKCLK                           40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PWC_CTRL register bits definitions
 * @{
 */
#define AT32_PVM_MASK               (7 << 5)    /**< PVM bits mask.             */
#define AT32_PVM_LEV0               (0 << 5)    /**< PVM level 0.               */
#define AT32_PVM_LEV1               (1 << 5)    /**< PVM level 1.               */
#define AT32_PVM_LEV2               (2 << 5)    /**< PVM level 2.               */
#define AT32_PVM_LEV3               (3 << 5)    /**< PVM level 3.               */
#define AT32_PVM_LEV4               (4 << 5)    /**< PVM level 4.               */
#define AT32_PVM_LEV5               (5 << 5)    /**< PVM level 5.               */
#define AT32_PVM_LEV6               (6 << 5)    /**< PVM level 6.               */
#define AT32_PVM_LEV7               (7 << 5)    /**< PVM level 7.               */

/**
 * @name    CRM_CFG register bits definitions
 * @{
 */
#define AT32_SCLKSEL_HICK           (0 << 0)    /**< SYSCLK source is HICK.     */
#define AT32_SCLKSEL_HEXT           (1 << 0)    /**< SYSCLK source is HEXT.     */
#define AT32_SCLKSEL_PLL            (2 << 0)    /**< SYSCLK source is PLL.      */

#define AT32_SCLKSTS_HICK           (0 << 2)    /**< SYSCLK use HICK.           */
#define AT32_SCLKSTS_HEXT           (1 << 2)    /**< SYSCLK use HEXT.           */
#define AT32_SCLKSTS_PLL            (2 << 2)    /**< SYSCLK use PLL.            */

#define AT32_AHBDIV_DIV1            (0 << 4)    /**< SYSCLK divided by 1.       */
#define AT32_AHBDIV_DIV2            (8 << 4)    /**< SYSCLK divided by 2.       */
#define AT32_AHBDIV_DIV4            (9 << 4)    /**< SYSCLK divided by 4.       */
#define AT32_AHBDIV_DIV8            (10 << 4)   /**< SYSCLK divided by 8.       */
#define AT32_AHBDIV_DIV16           (11 << 4)   /**< SYSCLK divided by 16.      */
#define AT32_AHBDIV_DIV64           (12 << 4)   /**< SYSCLK divided by 64.      */
#define AT32_AHBDIV_DIV128          (13 << 4)   /**< SYSCLK divided by 128.     */
#define AT32_AHBDIV_DIV256          (14 << 4)   /**< SYSCLK divided by 256.     */
#define AT32_AHBDIV_DIV512          (15 << 4)   /**< SYSCLK divided by 512.     */

#define AT32_APB1DIV_DIV1           (0 << 8)    /**< HCLK divided by 1.         */
#define AT32_APB1DIV_DIV2           (4 << 8)    /**< HCLK divided by 2.         */
#define AT32_APB1DIV_DIV4           (5 << 8)    /**< HCLK divided by 4.         */
#define AT32_APB1DIV_DIV8           (6 << 8)    /**< HCLK divided by 8.         */
#define AT32_APB1DIV_DIV16          (7 << 8)    /**< HCLK divided by 16.        */

#define AT32_APB2DIV_DIV1           (0 << 11)   /**< HCLK divided by 1.         */
#define AT32_APB2DIV_DIV2           (4 << 11)   /**< HCLK divided by 2.         */
#define AT32_APB2DIV_DIV4           (5 << 11)   /**< HCLK divided by 4.         */
#define AT32_APB2DIV_DIV8           (6 << 11)   /**< HCLK divided by 8.         */
#define AT32_APB2DIV_DIV16          (7 << 11)   /**< HCLK divided by 16.        */

#define AT32_ADCDIV_DIV2            (0 << 14)   /**< PPRE2 divided by 2.        */
#define AT32_ADCDIV_DIV4            (1 << 14)   /**< PPRE2 divided by 4.        */
#define AT32_ADCDIV_DIV6            (2 << 14)   /**< PPRE2 divided by 6.        */
#define AT32_ADCDIV_DIV8            (3 << 14)   /**< PPRE2 divided by 8.        */
#define AT32_ADCDIV_DIV12           ((1 << 14) | (1 << 28))   /**< PPRE2 divided by 12.       */
#define AT32_ADCDIV_DIV16           ((3 << 14) | (1 << 28))   /**< PPRE2 divided by 16.       */

#define AT32_PLLRCS_HICK            (0 << 16)   /**< PLL clock source is HICK.  */
#define AT32_PLLRCS_HEXT            (1 << 16)   /**< PLL clock source is HEXT.  */

#define AT32_PLLHEXTDIV_DIV1        (0 << 17)   /**< HEXT divided by 1.         */
#define AT32_PLLHEXTDIV_DIV2        (1 << 17)   /**< HEXT divided by 2.         */

#define AT32_USBDIV_DIV1P5          (0 << 22)   /**< PLLOUT divided by 1.5.     */
#define AT32_USBDIV_DIV1            (1 << 22)   /**< PLLOUT divided by 1.       */
#define AT32_USBDIV_DIV2P5          (2 << 22)   /**< PLLOUT divided by 2.5.     */
#define AT32_USBDIV_DIV2            (3 << 22)   /**< PLLOUT divided by 2.       */
#define AT32_USBDIV_DIV3P5          (1 << 27)   /**< PLLOUT divided by 3.5.     */
#define AT32_USBDIV_DIV3            ((1 << 27) | (1 << 22))  /**< PLLOUT divided by 3.     */
#define AT32_USBDIV_DIV4            ((1 << 27) | (2 << 22))  /**< PLLOUT divided by 4.     */

#define AT32_CLKOUT_SEL_CFG_MASK    (7 << 24)   /**< MCO CFG MASK.              */
#define AT32_CLKOUT_SEL_MISC_MASK   (1 << 27)   /**< MCO MISC MASK.             */
#define AT32_CLKOUT_SEL_NOCLOCK     (0 << 24)   /**< No clock on MCO pin.       */
#define AT32_CLKOUT_SEL_LICK        (2 << 24)   /**< LICK on MCO pin.           */
#define AT32_CLKOUT_SEL_LEXT        (3 << 24)   /**< LEXT on MCO pin.           */
#define AT32_CLKOUT_SEL_SYSCLK      (4 << 24)   /**< SYSCLK on MCO pin.         */
#define AT32_CLKOUT_SEL_HICK        (5 << 24)   /**< HICK clock on MCO pin.     */
#define AT32_CLKOUT_SEL_HEXT        (6 << 24)   /**< HEXT clock on MCO pin.     */
#define AT32_CLKOUT_SEL_PLLDIV2     (7 << 24)   /**< PLL/2 clock on MCO pin.    */
#define AT32_CLKOUT_SEL_PLLDIV4     (12 << 24)  /**< PLL/4 clock on MCO pin.    */
#define AT32_CLKOUT_SEL_USB         (13 << 24)  /**< USB clock on MCO pin.      */
#define AT32_CLKOUT_SEL_ADC         (14 << 24)  /**< ADC clock on MCO pin.      */

#define AT32_PLLRANGE_LOW           (0 << 31)   /**< PLLOUT lower than 72MHz.   */
#define AT32_PLLRANGE_HIGH          (1 << 31)   /**< PLLOUT higher than 72MHz.  */
/** @} */

/**
 * @name    CRM_BPDC register bits definitions
 * @{
 */
#define AT32_RTCSEL_MASK            (3 << 8)    /**< RTC clock source mask.     */
#define AT32_RTCSEL_NOCLOCK         (0 << 8)    /**< No clock.                  */
#define AT32_RTCSEL_LEXT            (1 << 8)    /**< LEXT used as RTC clock.    */
#define AT32_RTCSEL_LICK            (2 << 8)    /**< LICK used as RTC clock.    */
#define AT32_RTCSEL_HEXTDIV         (3 << 8)    /**< HEXT divided by 128 used as
                                                     RTC clock.                 */
/** @} */

/**
 * @name    MISC register bits definitions
 * @{
 */
#define AT32_USBCLK_SRC_PLL         0
#define AT32_USBCLK_SRC_HICK48      1
/** @} */

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 */
#if !defined(AT32_NO_INIT) || defined(__DOXYGEN__)
#define AT32_NO_INIT                       FALSE
#endif

/**
 * @brief   Enables or disables the programmable voltage detector.
 */
#if !defined(AT32_PVM_ENABLE) || defined(__DOXYGEN__)
#define AT32_PVM_ENABLE                    FALSE
#endif

/**
 * @brief   Sets voltage level for programmable voltage detector.
 */
#if !defined(AT32_PVM) || defined(__DOXYGEN__)
#define AT32_PVM                           AT32_PVM_LEV0
#endif

/**
 * @brief   Enables or disables the HICK clock source.
 */
#if !defined(AT32_HICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_HICK_ENABLED                  TRUE
#endif

/**
 * @brief   Enables or disables the LICK clock source.
 */
#if !defined(AT32_LICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_LICK_ENABLED                  FALSE
#endif

/**
 * @brief   Enables or disables the HEXT clock source.
 */
#if !defined(AT32_HEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_HEXT_ENABLED                  TRUE
#endif

/**
 * @brief   Enables or disables the LEXT clock source.
 */
#if !defined(AT32_LEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_LEXT_ENABLED                  FALSE
#endif
/** @} */

/**
 * @brief   Enables or disables the PLL clock source.
 */
#if !defined(AT32_PLL_ENABLED) || defined(__DOXYGEN__)
#define AT32_PLL_ENABLED                   TRUE
#endif

/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 192MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_SCLKSEL) || defined(__DOXYGEN__)
#define AT32_SCLKSEL                       AT32_SCLKSEL_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 192MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLRCS) || defined(__DOXYGEN__)
#define AT32_PLLRCS                        AT32_PLLRCS_HEXT
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 192MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLHEXTDIV) || defined(__DOXYGEN__)
#define AT32_PLLHEXTDIV                    AT32_PLLHEXTDIV_DIV1
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...64.
 * @note    The default value is calculated for a 192MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLMULT_VALUE) || defined(__DOXYGEN__)
#define AT32_PLLMULT_VALUE                 24
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 192MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_AHBDIV) || defined(__DOXYGEN__)
#define AT32_AHBDIV                        AT32_AHBDIV_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(AT32_APB1DIV) || defined(__DOXYGEN__)
#define AT32_APB1DIV                       AT32_APB1DIV_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(AT32_APB2DIV) || defined(__DOXYGEN__)
#define AT32_APB2DIV                       AT32_APB2DIV_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(AT32_ADCDIV) || defined(__DOXYGEN__)
#define AT32_ADCDIV                        AT32_ADCDIV_DIV4
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_USB_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define AT32_USB_CLOCK_REQUIRED            TRUE
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_USBCLK_SRC) || defined(__DOXYGEN__)
#define AT32_USBCLK_SRC                    AT32_USBCLK_SRC_PLL
#endif

/**
 * @brief   USB prescaler initialization.
 */
#if !defined(AT32_USBDIV) || defined(__DOXYGEN__)
#define AT32_USBDIV                        AT32_USBDIV_DIV4
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(AT32_CLKOUT_SEL) || defined(__DOXYGEN__)
#define AT32_CLKOUT_SEL                    AT32_CLKOUT_SEL_NOCLOCK
#endif

/**
 * @brief   RTC clock source.
 */
#if !defined(AT32_RTCSEL) || defined(__DOXYGEN__)
#define AT32_RTCSEL                        AT32_RTCSEL_LICK
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(AT32F413xx_MCUCONF)
#error "Using a wrong mcuconf.h file, AT32F413xx_MCUCONF not defined"
#endif

/*
 * Board files sanity checks.
 */
#if !defined(AT32_LEXTCLK)
#error "AT32_LEXTCLK not defined in board.h"
#endif

#if !defined(AT32_HEXTCLK)
#error "AT32_HEXTCLK not defined in board.h"
#endif

/*
 * HICK related checks.
 */
#if AT32_HICK_ENABLED
#else /* !AT32_HICK_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HICK
#error "HICK not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_USBCLK_SRC == AT32_USBCLK_SRC_HICK48) ||                               \
    (AT32_SCLKSEL == AT32_SCLKSEL_PLL) &&                                        \
    (AT32_PLLRCS == AT32_PLLRCS_HICK)
#error "HICK not enabled, required by AT32_USBCLK_SRC, AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HICK) ||                                 \
    (((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                            \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4)) &&                             \
    (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_CLKOUT_SEL"
#endif

#endif /* !AT32_HICK_ENABLED */

/*
 * HEXT related checks.
 */
#if AT32_HEXT_ENABLED

#if AT32_HEXTCLK == 0
#error "HEXT frequency not defined"
#elif (AT32_HEXTCLK < AT32_HEXTCLK_MIN) || (AT32_HEXTCLK > AT32_HEXTCLK_MAX)
#error "AT32_HEXTCLK outside acceptable range (AT32_HEXTCLK_MIN...AT32_HEXTCLK_MAX)"
#endif

#else /* !AT32_HEXT_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
#error "HEXT not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HEXT)
#error "HEXT not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HEXT) ||                                \
    (((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                           \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4)) &&                            \
    (AT32_PLLRCS == AT32_PLLRCS_HEXT))
#error "HEXT not enabled, required by AT32_CLKOUT_SEL"
#endif

#if (AT32_RTCSEL == AT32_RTCSEL_HEXTDIV)
#error "HEXT not enabled, required by AT32_RTCSEL"
#endif
#endif /* !AT32_HEXT_ENABLED */

#if AT32_LICK_ENABLED
#else /* !AT32_LICK_ENABLED */

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LICK) 
#error "LICK not enabled, required by AT32_CLKOUT_SEL"
#endif
#if HAL_USE_RTC && (AT32_RTCSEL == AT32_RTCSEL_LICK)
#error "LICK not enabled, required by AT32_RTCSEL"
#endif
#endif /* !AT32_LICK_ENABLED */

/* LEXT related checks.*/
#if AT32_LEXT_ENABLED
#if (AT32_LEXTCLK == 0)
#error "impossible to activate LEXT, frequency is zero"
#endif

#if (AT32_LEXTCLK < AT32_LEXTCLK_MIN) || (AT32_LEXTCLK > AT32_LEXTCLK_MAX)
#error "AT32_LEXTCLK outside acceptable range (AT32_LEXTCLK_MIN...AT32_LEXTCLK_MAX)"
#endif
#else /* !AT32_LEXT_ENABLED */
#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LEXT)
#error "LEXT not enabled, required by AT32_CLKOUT_SEL"
#endif
#if AT32_RTCSEL == AT32_RTCSEL_LEXT
#error "LEXT not enabled, required by AT32_RTCSEL"
#endif
#endif /* !AT32_LEXT_ENABLED */

/* PLL activation conditions.*/
#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) ||                                       \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                             \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4) ||                             \
    defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define AT32_ACTIVATE_PLL          TRUE
#else
#define AT32_ACTIVATE_PLL          FALSE
#endif

/* HEXT prescaler setting check.*/
#if (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIV1) &&                                \
    (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIV2)
#error "invalid AT32_PLLHEXTDIV value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
#if ((AT32_PLLMULT_VALUE >= 2) && (AT32_PLLMULT_VALUE <= 15)) ||                \
    defined(__DOXYGEN__)
#define AT32_PLLMULT               ((((AT32_PLLMULT_VALUE - 2) & 0x0F) << 18) | \
                                   (((AT32_PLLMULT_VALUE - 2) & 0x30) << 25))
#elif ((AT32_PLLMULT_VALUE >= 16) && (AT32_PLLMULT_VALUE <= 64))
#define AT32_PLLMULT               ((((AT32_PLLMULT_VALUE - 1) & 0x0F) << 18) | \
                                   (((AT32_PLLMULT_VALUE - 1) & 0x30) << 25))
#else
#error "invalid AT32_PLLMULT_VALUE value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (AT32_PLLRCS == AT32_PLLRCS_HEXT) || defined(__DOXYGEN__)
#if AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIV1
#define AT32_PLLCLKIN              (AT32_HEXTCLK / 1)
#else
#define AT32_PLLCLKIN              (AT32_HEXTCLK / 2)
#endif
#elif AT32_PLLRCS == AT32_PLLRCS_HICK
#define AT32_PLLCLKIN              (4000000)
#else
#error "invalid AT32_PLLRCS value specified"
#endif

/* PLL input frequency range check.*/
#if (AT32_PLLCLKIN < AT32_PLLIN_MIN) || (AT32_PLLCLKIN > AT32_PLLIN_MAX)
#error "AT32_PLLCLKIN outside acceptable range (AT32_PLLIN_MIN...AT32_PLLIN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define AT32_PLLCLKOUT             (AT32_PLLCLKIN * AT32_PLLMULT_VALUE)

/* PLL output frequency range check.*/
#if (AT32_PLLCLKOUT < AT32_PLLOUT_MIN) || (AT32_PLLCLKOUT > AT32_PLLOUT_MAX)
#error "AT32_PLLCLKOUT outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   PLL output clock frequency range.
 */
/* PLL output frequency range check.*/
#if (AT32_PLLCLKOUT <= 72000000)
#define AT32_PLLRANGE              AT32_PLLRANGE_LOW
#elif (AT32_PLLCLKOUT > 72000000)
#define AT32_PLLRANGE              AT32_PLLRANGE_HIGH
#else
#error "invalid AT32_PLLCLKOUT value specified"
#endif

/**
 * @brief   System clock source.
 */
#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) || defined(__DOXYGEN__)
#define AT32_SYSCLK                AT32_PLLCLKOUT
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HICK)
#define AT32_SYSCLK                AT32_HICKCLK
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HEXT)
#define AT32_SYSCLK                AT32_HEXTCLK
#else
#error "invalid AT32_SCLKSEL value specified"
#endif

/* Check on the system clock.*/
#if AT32_SYSCLK > AT32_SYSCLK_MAX
#error "AT32_SYSCLK above maximum rated frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (AT32_AHBDIV == AT32_AHBDIV_DIV1) || defined(__DOXYGEN__)
#define AT32_HCLK                  (AT32_SYSCLK / 1)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV2
#define AT32_HCLK                  (AT32_SYSCLK / 2)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV4
#define AT32_HCLK                  (AT32_SYSCLK / 4)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV8
#define AT32_HCLK                  (AT32_SYSCLK / 8)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV16
#define AT32_HCLK                  (AT32_SYSCLK / 16)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV64
#define AT32_HCLK                  (AT32_SYSCLK / 64)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV128
#define AT32_HCLK                  (AT32_SYSCLK / 128)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV256
#define AT32_HCLK                  (AT32_SYSCLK / 256)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV512
#define AT32_HCLK                  (AT32_SYSCLK / 512)
#else
#error "invalid AT32_AHBDIV value specified"
#endif

/* AHB frequency check.*/
#if AT32_HCLK > AT32_SYSCLK_MAX
#error "AT32_HCLK exceeding maximum frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK1                 (AT32_HCLK / 1)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV2
#define AT32_PCLK1                 (AT32_HCLK / 2)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV4
#define AT32_PCLK1                 (AT32_HCLK / 4)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV8
#define AT32_PCLK1                 (AT32_HCLK / 8)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV16
#define AT32_PCLK1                 (AT32_HCLK / 16)
#else
#error "invalid AT32_APB1DIV value specified"
#endif

/* APB1 frequency check.*/
#if AT32_PCLK1 > AT32_PCLK1_MAX
#error "AT32_PCLK1 exceeding maximum frequency (AT32_PCLK1_MAX)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK2                 (AT32_HCLK / 1)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV2
#define AT32_PCLK2                 (AT32_HCLK / 2)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV4
#define AT32_PCLK2                 (AT32_HCLK / 4)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV8
#define AT32_PCLK2                 (AT32_HCLK / 8)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV16
#define AT32_PCLK2                 (AT32_HCLK / 16)
#else
#error "invalid AT32_APB2DIV value specified"
#endif

/* APB2 frequency check.*/
#if AT32_PCLK2 > AT32_PCLK2_MAX
#error "AT32_PCLK2 exceeding maximum frequency (AT32_PCLK2_MAX)"
#endif

/**
 * @brief   RTC clock.
 */
#if (AT32_RTCSEL == AT32_RTCSEL_NOCLOCK) || defined(__DOXYGEN__)
#define AT32_RTCCLK                0
#elif AT32_RTCSEL == AT32_RTCSEL_LEXT
#define AT32_RTCCLK                AT32_LEXTCLK
#elif AT32_RTCSEL == AT32_RTCSEL_LICK
#define AT32_RTCCLK                AT32_LICKCLK
#elif AT32_RTCSEL == AT32_RTCSEL_HEXTDIV
#define AT32_RTCCLK                (AT32_HEXTCLK / 128)
#else
#error "invalid AT32_RTCSEL value specified"
#endif

/**
 * @brief   ADC frequency.
 */
#if (AT32_ADCDIV == AT32_ADCDIV_DIV2) || defined(__DOXYGEN__)
#define AT32_ADCCLK                (AT32_PCLK2 / 2)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV4
#define AT32_ADCCLK                (AT32_PCLK2 / 4)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV6
#define AT32_ADCCLK                (AT32_PCLK2 / 6)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV8
#define AT32_ADCCLK                (AT32_PCLK2 / 8)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV12
#define AT32_ADCCLK                (AT32_PCLK2 / 12)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV16
#define AT32_ADCCLK                (AT32_PCLK2 / 16)
#else
#error "invalid AT32_ADCDIV value specified"
#endif

/* ADC frequency check.*/
#if AT32_ADCCLK > AT32_ADCCLK_MAX
#error "AT32_ADCCLK exceeding maximum frequency (AT32_ADCCLK_MAX)"
#endif

/**
 * @brief   USB frequency.
 */
#if (AT32_USBCLK_SRC == AT32_USBCLK_SRC_HICK48) || defined(__DOXYGEN__)
#define AT32_USBCLK                48000000
#elif (AT32_USBCLK_SRC == AT32_USBCLK_SRC_PLL) 
#if (AT32_USBDIV == AT32_USBDIV_DIV1P5) || defined(__DOXYGEN__)
#define AT32_USBCLK                ((AT32_PLLCLKOUT * 2) / 3)
#elif (AT32_USBDIV == AT32_USBDIV_DIV1)
#define AT32_USBCLK                (AT32_PLLCLKOUT / 1)
#elif (AT32_USBDIV == AT32_USBDIV_DIV2P5)
#define AT32_USBCLK                ((AT32_PLLCLKOUT * 2) / 5)
#elif (AT32_USBDIV == AT32_USBDIV_DIV2)
#define AT32_USBCLK                (AT32_PLLCLKOUT / 2)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3P5)
#define AT32_USBCLK                ((AT32_PLLCLKOUT * 2) / 7)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3)
#define AT32_USBCLK                (AT32_PLLCLKOUT / 3)
#elif (AT32_USBDIV == AT32_USBDIV_DIV4)
#define AT32_USBCLK                (AT32_PLLCLKOUT / 4)
#else
#error "invalid AT32_USBDIV value specified"
#endif
#else
#error "invalid AT32_USBCLK_SRC value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5 clock.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TIMCLK1               (AT32_PCLK1 * 1)
#else
#define AT32_TIMCLK1               (AT32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 9, 10, 11 clock.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TIMCLK2               (AT32_PCLK2 * 1)
#else
#define AT32_TIMCLK2               (AT32_PCLK2 * 2)
#endif

/* Various helpers.*/
#include "nvic.h"
#include "mpu_v7m.h"
#include "at32_isr.h"
#include "at32_crm.h"
#include "at32_dma.h"
#include "at32_tim.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void at32_clock_init(void);
  void at32_clock_reset(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */
/** @} */
