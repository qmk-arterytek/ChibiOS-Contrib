/*
    Copyright (C) 2023 Zhaqian

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
 * @file    AT32F40x/at32_dmamux.h
 * @brief   AT32F40x DMAMUX handler header.
 *
 * @addtogroup AT32F40x_DMAMUX
 * @{
 */

#ifndef AT32_DMAMUX_H
#define AT32_DMAMUX_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    DMAMUX request sources
 * @{
 */
#define AT32_DMAMUX_ADC1          1
#define AT32_DMAMUX_ADC3          3
#define AT32_DMAMUX_DAC1          5
#define AT32_DMAMUX_DAC2          6
#define AT32_DMAMUX_SPI1_RX       9
#define AT32_DMAMUX_SPI1_TX       10
#define AT32_DMAMUX_SPI2_RX       11
#define AT32_DMAMUX_SPI2_TX       12
#define AT32_DMAMUX_SPI3_RX       13
#define AT32_DMAMUX_SPI3_TX       14
#define AT32_DMAMUX_SPI4_RX       15
#define AT32_DMAMUX_SPI4_TX       16
#define AT32_DMAMUX_I2S2EXT_RX    17
#define AT32_DMAMUX_I2S2EXT_TX    18
#define AT32_DMAMUX_I2S3EXT_RX    19
#define AT32_DMAMUX_I2S3EXT_TX    20
#define AT32_DMAMUX_USART1_RX     25
#define AT32_DMAMUX_USART1_TX     26
#define AT32_DMAMUX_USART2_RX     27
#define AT32_DMAMUX_USART2_TX     28
#define AT32_DMAMUX_USART3_RX     29
#define AT32_DMAMUX_USART3_TX     30
#define AT32_DMAMUX_UART4_RX      31
#define AT32_DMAMUX_UART4_TX      32
#define AT32_DMAMUX_UART5_RX      33
#define AT32_DMAMUX_UART5_TX      34
#define AT32_DMAMUX_USART6_RX     35
#define AT32_DMAMUX_USART6_TX     36
#define AT32_DMAMUX_UART7_RX      37
#define AT32_DMAMUX_UART7_TX      38
#define AT32_DMAMUX_UART8_RX      39
#define AT32_DMAMUX_UART8_TX      40
#define AT32_DMAMUX_I2C1_RX       41
#define AT32_DMAMUX_I2C1_TX       42
#define AT32_DMAMUX_I2C2_RX       43
#define AT32_DMAMUX_I2C2_TX       44
#define AT32_DMAMUX_I2C3_RX       45
#define AT32_DMAMUX_I2C3_TX       46
#define AT32_DMAMUX_SDIO1         49
#define AT32_DMAMUX_SDIO2         50
#define AT32_DMAMUX_TIM1_TRIG     53
#define AT32_DMAMUX_TIM1_HALL     54
#define AT32_DMAMUX_TIM1_OVERFLOW 55
#define AT32_DMAMUX_TIM1_CH1      56
#define AT32_DMAMUX_TIM1_CH2      57
#define AT32_DMAMUX_TIM1_CH3      58
#define AT32_DMAMUX_TIM1_CH4      59
#define AT32_DMAMUX_TIM2_TRIG     61
#define AT32_DMAMUX_TIM2_OVERFLOW 63
#define AT32_DMAMUX_TIM2_CH1      64
#define AT32_DMAMUX_TIM2_CH2      65
#define AT32_DMAMUX_TIM2_CH3      66
#define AT32_DMAMUX_TIM2_CH4      67
#define AT32_DMAMUX_TIM3_TRIG     69
#define AT32_DMAMUX_TIM3_OVERFLOW 71
#define AT32_DMAMUX_TIM3_CH1      72
#define AT32_DMAMUX_TIM3_CH2      73
#define AT32_DMAMUX_TIM3_CH3      74
#define AT32_DMAMUX_TIM3_CH4      75
#define AT32_DMAMUX_TIM4_TRIG     77
#define AT32_DMAMUX_TIM4_OVERFLOW 79
#define AT32_DMAMUX_TIM4_CH1      80
#define AT32_DMAMUX_TIM4_CH2      81
#define AT32_DMAMUX_TIM4_CH3      82
#define AT32_DMAMUX_TIM4_CH4      83
#define AT32_DMAMUX_TIM5_TRIG     85
#define AT32_DMAMUX_TIM5_OVERFLOW 87
#define AT32_DMAMUX_TIM5_CH1      88
#define AT32_DMAMUX_TIM5_CH2      89
#define AT32_DMAMUX_TIM5_CH3      90
#define AT32_DMAMUX_TIM5_CH4      91
#define AT32_DMAMUX_TIM6_OVERFLOW 95
#define AT32_DMAMUX_TIM7_OVERFLOW 103
#define AT32_DMAMUX_TIM8_TRIG     109
#define AT32_DMAMUX_TIM8_HALL     110
#define AT32_DMAMUX_TIM8_OVERFLOW 111
#define AT32_DMAMUX_TIM8_CH1      112
#define AT32_DMAMUX_TIM8_CH2      113
#define AT32_DMAMUX_TIM8_CH3      114
#define AT32_DMAMUX_TIM8_CH4      115
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* AT32_DMAMUX_H */

/** @} */
