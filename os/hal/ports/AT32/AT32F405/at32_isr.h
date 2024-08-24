/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    AT32F405/at32_isr.h
 * @brief   AT32F405 ISR handler header.
 *
 * @addtogroup AT32F405_ISR
 * @{
 */

#ifndef AT32_ISR_H
#define AT32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISRs suppressed in standard drivers
 * @{
 */
#define AT32_TMR1_SUPPRESS_ISR
#define AT32_TMR2_SUPPRESS_ISR
#define AT32_TMR3_SUPPRESS_ISR
#define AT32_TMR4_SUPPRESS_ISR
#define AT32_TMR6_SUPPRESS_ISR
#define AT32_TMR7_SUPPRESS_ISR
#define AT32_TMR9_SUPPRESS_ISR
#define AT32_TMR10_SUPPRESS_ISR
#define AT32_TMR11_SUPPRESS_ISR
#define AT32_TMR13_SUPPRESS_ISR
#define AT32_TMR14_SUPPRESS_ISR

#define AT32_USART1_SUPPRESS_ISR
#define AT32_USART2_SUPPRESS_ISR
#define AT32_USART3_SUPPRESS_ISR
#define AT32_UART4_SUPPRESS_ISR
#define AT32_UART5_SUPPRESS_ISR
#define AT32_USART6_SUPPRESS_ISR
#define AT32_UART7_SUPPRESS_ISR
#define AT32_UART8_SUPPRESS_ISR
/** @} */

/**
 * @name    ISR names and numbers remapping
 * @{
 */
/*
 * ADC unit.
 */
#define AT32_ADC1_HANDLER            Vector88

#define AT32_ADC1_NUMBER             18

/*
 * CAN unit.
 */
#define AT32_CAN1_TX_HANDLER         Vector8C
#define AT32_CAN1_RX0_HANDLER        Vector90
#define AT32_CAN1_RX1_HANDLER        Vector94
#define AT32_CAN1_SE_HANDLER         Vector98

#define AT32_CAN1_TX_NUMBER          19
#define AT32_CAN1_RX0_NUMBER         20
#define AT32_CAN1_RX1_NUMBER         21
#define AT32_CAN1_SE_NUMBER          22

/*
 * DMA units.
 */
#define AT32_DMA1_CH1_HANDLER        Vector6C
#define AT32_DMA1_CH2_HANDLER        Vector70
#define AT32_DMA1_CH3_HANDLER        Vector74
#define AT32_DMA1_CH4_HANDLER        Vector78
#define AT32_DMA1_CH5_HANDLER        Vector7C
#define AT32_DMA1_CH6_HANDLER        Vector80
#define AT32_DMA1_CH7_HANDLER        Vector84

#define AT32_DMA1_CH1_NUMBER         11
#define AT32_DMA1_CH2_NUMBER         12
#define AT32_DMA1_CH3_NUMBER         13
#define AT32_DMA1_CH4_NUMBER         14
#define AT32_DMA1_CH5_NUMBER         15
#define AT32_DMA1_CH6_NUMBER         16
#define AT32_DMA1_CH7_NUMBER         17

#define AT32_DMA2_CH1_HANDLER        Vector120
#define AT32_DMA2_CH2_HANDLER        Vector124
#define AT32_DMA2_CH3_HANDLER        Vector128
#define AT32_DMA2_CH4_HANDLER        Vector12C
#define AT32_DMA2_CH5_HANDLER        Vector130
#define AT32_DMA2_CH6_HANDLER        Vector150
#define AT32_DMA2_CH7_HANDLER        Vector154

#define AT32_DMA2_CH1_NUMBER         56
#define AT32_DMA2_CH2_NUMBER         57
#define AT32_DMA2_CH3_NUMBER         58
#define AT32_DMA2_CH4_NUMBER         59
#define AT32_DMA2_CH5_NUMBER         60
#define AT32_DMA2_CH6_NUMBER         68
#define AT32_DMA2_CH7_NUMBER         69

#define AT32_DMAMUX_HANDLER          Vector1B8

#define AT32_DMAMUX_NUMBER           94

/*
 * ERTC unit.
 */
#define AT32_ERTC_TAMP_STAMP_HANDLER Vector48
#define AT32_ERTC_WKUP_HANDLER       Vector4C
#define AT32_ERTC_ALARM_HANDLER      VectorE4

#define AT32_ERTC_TAMP_STAMP_NUMBER  2
#define AT32_ERTC_WKUP_NUMBER        3
#define AT32_ERTC_ALARM_NUMBER       41

#define AT32_ERTC_ALARM_EXINT        17
#define AT32_ERTC_TAMP_STAMP_EXINT   21
#define AT32_ERTC_WKUP_EXINT         22
#define AT32_ERTC_IRQ_ENABLE() do {                                         \
  nvicEnableVector(AT32_ERTC_TAMP_STAMP_NUMBER, AT32_IRQ_EXINT21_PRIORITY); \
  nvicEnableVector(AT32_ERTC_WKUP_NUMBER, AT32_IRQ_EXINT22_PRIORITY);       \
  nvicEnableVector(AT32_ERTC_ALARM_NUMBER, AT32_IRQ_EXINT17_PRIORITY);      \
} while (false)

/*
 * EXINT units.
 */
#define AT32_EXINT0_HANDLER          Vector58
#define AT32_EXINT1_HANDLER          Vector5C
#define AT32_EXINT2_HANDLER          Vector60
#define AT32_EXINT3_HANDLER          Vector64
#define AT32_EXINT4_HANDLER          Vector68
#define AT32_EXINT5_9_HANDLER        Vector9C
#define AT32_EXINT10_15_HANDLER      VectorE0
#define AT32_EXINT16_HANDLER         Vector44  /* Note: same as PVM_IRQn        */
#define AT32_EXINT17_HANDLER         VectorE4  /* Note: same as ERTCAlarm_IRQn  */
#define AT32_EXINT18_HANDLER         VectorE8  /* Note: same as OTGFS_WKUP_IRQn */
#define AT32_EXINT20_HANDLER         Vector170 /* Note: same as OTGHS_WKUP_IRQn */
#define AT32_EXINT21_HANDLER         Vector48  /* Note: same as TAMPER_IRQn     */
#define AT32_EXINT22_HANDLER         Vector4C  /* Note: same as ERTC_WKUP_IRQn  */

#define AT32_EXINT0_NUMBER           6
#define AT32_EXINT1_NUMBER           7
#define AT32_EXINT2_NUMBER           8
#define AT32_EXINT3_NUMBER           9
#define AT32_EXINT4_NUMBER           10
#define AT32_EXINT5_9_NUMBER         23
#define AT32_EXINT10_15_NUMBER       40
#define AT32_EXINT16_NUMBER          1         /* Note: same as PVM_IRQn        */
#define AT32_EXINT17_NUMBER          41        /* Note: same as ERTCAlarm_IRQn  */
#define AT32_EXINT18_NUMBER          42        /* Note: same as OTGFS_WKUP_IRQn */
#define AT32_EXINT20_NUMBER          76        /* Note: same as OTGHS_WKUP_IRQn */
#define AT32_EXINT21_NUMBER          2         /* Note: same as TAMPER_IRQn     */
#define AT32_EXINT22_NUMBER          3         /* Note: same as ERTC_WKUP_IRQn  */

/*
 * I2C units.
 */
#define AT32_I2C1_EVENT_HANDLER      VectorBC
#define AT32_I2C1_ERROR_HANDLER      VectorC0
#define AT32_I2C2_EVENT_HANDLER      VectorC4
#define AT32_I2C2_ERROR_HANDLER      VectorC8
#define AT32_I2C3_EVENT_HANDLER      Vector160
#define AT32_I2C3_ERROR_HANDLER      Vector164

#define AT32_I2C1_EVENT_NUMBER       31
#define AT32_I2C1_ERROR_NUMBER       32
#define AT32_I2C2_EVENT_NUMBER       33
#define AT32_I2C2_ERROR_NUMBER       34
#define AT32_I2C3_EVENT_NUMBER       72
#define AT32_I2C3_ERROR_NUMBER       73

/*
 * OTG units.
 */
#define AT32_OTG1_HANDLER            Vector14C
#define AT32_OTG2_HANDLER            Vector174
#define AT32_OTG2_EP1_OUT_HANDLER    Vector168
#define AT32_OTG2_EP1_IN_HANDLER     Vector16C

#define AT32_OTG1_NUMBER             67
#define AT32_OTG2_NUMBER             77
#define AT32_OTG2_EP1_OUT_NUMBER     74
#define AT32_OTG2_EP1_IN_NUMBER      75

/*
 * QUADSPI unit.
 */
#define AT32_QUADSPI1_HANDLER        Vector1B0

#define AT32_QUADSPI1_NUMBER         92

/*
 * TMR units.
 */
#define AT32_TMR1_BRK_TMR9_HANDLER   VectorA0
#define AT32_TMR1_OVF_TMR10_HANDLER  VectorA4
#define AT32_TMR1_HALL_TMR11_HANDLER VectorA8
#define AT32_TMR1_CH_HANDLER         VectorAC
#define AT32_TMR2_HANDLER            VectorB0
#define AT32_TMR3_HANDLER            VectorB4
#define AT32_TMR4_HANDLER            VectorB8
#define AT32_TMR6_HANDLER            Vector118
#define AT32_TMR7_HANDLER            Vector11C
#define AT32_TMR13_HANDLER           VectorF0
#define AT32_TMR14_HANDLER           VectorF4

#define AT32_TMR1_BRK_TMR9_NUMBER    24
#define AT32_TMR1_OVF_TMR10_NUMBER   25
#define AT32_TMR1_HALL_TMR11_NUMBER  26
#define AT32_TMR1_CH_NUMBER          27
#define AT32_TMR2_NUMBER             28
#define AT32_TMR3_NUMBER             29
#define AT32_TMR4_NUMBER             30
#define AT32_TMR6_NUMBER             54
#define AT32_TMR7_NUMBER             55
#define AT32_TMR13_NUMBER            44
#define AT32_TMR14_NUMBER            45

/* Aliases.*/
#define AT32_TMR9_HANDLER            VectorA0
#define AT32_TMR10_HANDLER           VectorA4
#define AT32_TMR11_HANDLER           VectorA8

#define AT32_TMR9_NUMBER             24
#define AT32_TMR10_NUMBER            25
#define AT32_TMR11_NUMBER            26

/*
 * USART units.
 */
#define AT32_USART1_HANDLER          VectorD4
#define AT32_USART2_HANDLER          VectorD8
#define AT32_USART3_HANDLER          VectorDC
#define AT32_UART4_HANDLER           Vector110
#define AT32_UART5_HANDLER           Vector114
#define AT32_USART6_HANDLER          Vector15C
#define AT32_UART7_HANDLER           Vector188
#define AT32_UART8_HANDLER           Vector18C

#define AT32_USART1_NUMBER           37
#define AT32_USART2_NUMBER           38
#define AT32_USART3_NUMBER           39
#define AT32_UART4_NUMBER            52
#define AT32_UART5_NUMBER            53
#define AT32_USART6_NUMBER           71
#define AT32_UART7_NUMBER            82
#define AT32_UART8_NUMBER            83

/*
 * ACC unit.
 */
#define AT32_ACC_HANDLER             Vector1DC

#define AT32_ACC_NUMBER              103
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
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* AT32_ISR_H */

/** @} */