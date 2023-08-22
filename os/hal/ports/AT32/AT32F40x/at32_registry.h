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
 * @file    AT32F40x/at32_registry.h
 * @brief   AT32F40x capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

#if !defined(AT32F40x)
#error "unsupported or unrecognized AT32F40x member"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(AT32F403ACx) || defined(__DOXYGEN__)
/**
 * @name    AT32F403ACx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_ADC1_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC1_DMA_CHN                   0x00000000
#define AT32_HAS_ADC2                       TRUE
#define AT32_ADC2_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC2_DMA_CHN                   0x00000000
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC3_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(2, 5))
#define AT32_ADC3_DMA_CHN                   0x00000000

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   FALSE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA1_CH1_HANDLER               Vector6C
#define AT32_DMA1_CH2_HANDLER               Vector70
#define AT32_DMA1_CH3_HANDLER               Vector74
#define AT32_DMA1_CH4_HANDLER               Vector78
#define AT32_DMA1_CH5_HANDLER               Vector7C
#define AT32_DMA1_CH6_HANDLER               Vector80
#define AT32_DMA1_CH7_HANDLER               Vector84
#define AT32_DMA1_CH1_NUMBER                11
#define AT32_DMA1_CH2_NUMBER                12
#define AT32_DMA1_CH3_NUMBER                13
#define AT32_DMA1_CH4_NUMBER                14
#define AT32_DMA1_CH5_NUMBER                15
#define AT32_DMA1_CH6_NUMBER                16
#define AT32_DMA1_CH7_NUMBER                17

#define AT32_DMA2_NUM_CHANNELS              7
#define AT32_DMA2_CH1_HANDLER               Vector120
#define AT32_DMA2_CH2_HANDLER               Vector124
#define AT32_DMA2_CH3_HANDLER               Vector128
#define AT32_DMA2_CH45_HANDLER              Vector12C
#define AT32_DMA2_CH67_HANDLER              Vector16C

#define AT32_DMA2_CH1_NUMBER                56
#define AT32_DMA2_CH2_NUMBER                57
#define AT32_DMA2_CH3_NUMBER                58
#define AT32_DMA2_CH45_NUMBER               59
#define AT32_DMA2_CH67_NUMBER               75

#define AT32_DMA2_CH4_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH5_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH6_NUMBER                AT32_DMA2_CH67_NUMBER 
#define AT32_DMA2_CH7_NUMBER                AT32_DMA2_CH67_NUMBER 

#define DMA2_CH4_CMASK                      0x00000C00U
#define DMA2_CH5_CMASK                      0x00000C00U
#define DMA2_CH6_CMASK                      0x00003000U
#define DMA2_CH7_CMASK                      0x00003000U

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXTI attributes.*/
#define AT32_EXTI_NUM_LINES                 20
#define AT32_EXTI_IMR_MASK                  0x00000000U

/* Flash attributes.*/
#if defined(AT32F40xxG)
#define AT32_FLASH_NUMBER_OF_BANKS          2
#else
#define AT32_FLASH_NUMBER_OF_BANKS          1
#endif

#define AT32_FLASH_SECTOR_SIZE              2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#if defined(AT32F40xxG) || defined(AT32F40xxE)
#define AT32_FLASH_SECTORS_PER_BANK         256 /* Maximum, can be redefined.*/
#elif 
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_GPIO_HAS_HDRV                  TRUE

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_RTC                        TRUE
#define AT32_RTC_HAS_SUBSECONDS             FALSE
#define AT32_RTC_IS_CALENDAR                TRUE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       FALSE
#define AT32_HAS_SDIO2                      TRUE
#define AT32_SDC_SDIO2_DMA_STREAM           AT32_DMA_STREAM_ID(2, 5)

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* TIM attributes.*/
#define AT32_TIM_MAX_CHANNELS               4

#define AT32_HAS_TIM1                       TRUE
#define AT32_TIM1_IS_32BITS                 FALSE
#define AT32_TIM1_CHANNELS                  4

#define AT32_HAS_TIM2                       TRUE
#define AT32_TIM2_IS_32BITS                 TRUE
#define AT32_TIM2_CHANNELS                  4

#define AT32_HAS_TIM3                       TRUE
#define AT32_TIM3_IS_32BITS                 FALSE
#define AT32_TIM3_CHANNELS                  4

#define AT32_HAS_TIM4                       TRUE
#define AT32_TIM4_IS_32BITS                 FALSE
#define AT32_TIM4_CHANNELS                  4

#define AT32_HAS_TIM5                       TRUE
#define AT32_TIM5_IS_32BITS                 TRUE
#define AT32_TIM5_CHANNELS                  4

#define AT32_HAS_TIM6                       TRUE
#define AT32_TIM6_IS_32BITS                 FALSE
#define AT32_TIM6_CHANNELS                  0

#define AT32_HAS_TIM7                       TRUE
#define AT32_TIM7_IS_32BITS                 FALSE
#define AT32_TIM7_CHANNELS                  0

#define AT32_HAS_TIM8                       TRUE
#define AT32_TIM8_IS_32BITS                 FALSE
#define AT32_TIM8_CHANNELS                  4

#define AT32_HAS_TIM9                       TRUE
#define AT32_TIM9_IS_32BITS                 FALSE
#define AT32_TIM9_CHANNELS                  2

#define AT32_HAS_TIM10                      TRUE
#define AT32_TIM10_IS_32BITS                FALSE
#define AT32_TIM10_CHANNELS                 1

#define AT32_HAS_TIM11                      TRUE
#define AT32_TIM11_IS_32BITS                FALSE
#define AT32_TIM11_CHANNELS                 1

#define AT32_HAS_TIM12                      TRUE
#define AT32_TIM12_IS_32BITS                FALSE
#define AT32_TIM12_CHANNELS                 2

#define AT32_HAS_TIM13                      TRUE
#define AT32_TIM13_IS_32BITS                FALSE
#define AT32_TIM13_CHANNELS                 1

#define AT32_HAS_TIM14                      TRUE
#define AT32_TIM14_IS_32BITS                FALSE
#define AT32_TIM14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_HAS_USART2                    TRUE
#define AT32_HAS_USART3                    TRUE
#define AT32_HAS_UART4                     TRUE
#define AT32_HAS_UART5                     TRUE
#define AT32_HAS_USART6                    FALSE
#define AT32_HAS_UART7                     TRUE
#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_HAS_USB                       TRUE
#define AT32_USB_ACCESS_SCHEME_2x16        FALSE
#define AT32_USB_PMA_MAX_SIZE              1280
#define AT32_USB_HAS_BCDR                  FALSE
#define AT32_USB_HAS_CFG                   TRUE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                      TRUE
#define AT32_IWDG_IS_WINDOWED              TRUE

/* FSMC attributes.*/
#define AT32_HAS_XMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
#define AT32_CRC_PROGRAMMABLE              FALSE

#endif /* defined(AT32F403ACx) */

#if defined(AT32F403ARx) || defined(__DOXYGEN__)
/**
 * @name    AT32F403ARx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_ADC1_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC1_DMA_CHN                   0x00000000
#define AT32_HAS_ADC2                       TRUE
#define AT32_ADC2_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC2_DMA_CHN                   0x00000000
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC3_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(2, 5))
#define AT32_ADC3_DMA_CHN                   0x00000000

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   FALSE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA1_CH1_HANDLER               Vector6C
#define AT32_DMA1_CH2_HANDLER               Vector70
#define AT32_DMA1_CH3_HANDLER               Vector74
#define AT32_DMA1_CH4_HANDLER               Vector78
#define AT32_DMA1_CH5_HANDLER               Vector7C
#define AT32_DMA1_CH6_HANDLER               Vector80
#define AT32_DMA1_CH7_HANDLER               Vector84
#define AT32_DMA1_CH1_NUMBER                11
#define AT32_DMA1_CH2_NUMBER                12
#define AT32_DMA1_CH3_NUMBER                13
#define AT32_DMA1_CH4_NUMBER                14
#define AT32_DMA1_CH5_NUMBER                15
#define AT32_DMA1_CH6_NUMBER                16
#define AT32_DMA1_CH7_NUMBER                17

#define AT32_DMA2_NUM_CHANNELS              7
#define AT32_DMA2_CH1_HANDLER               Vector120
#define AT32_DMA2_CH2_HANDLER               Vector124
#define AT32_DMA2_CH3_HANDLER               Vector128
#define AT32_DMA2_CH45_HANDLER              Vector12C
#define AT32_DMA2_CH67_HANDLER              Vector16C

#define AT32_DMA2_CH1_NUMBER                56
#define AT32_DMA2_CH2_NUMBER                57
#define AT32_DMA2_CH3_NUMBER                58
#define AT32_DMA2_CH45_NUMBER               59
#define AT32_DMA2_CH67_NUMBER               75

#define AT32_DMA2_CH4_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH5_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH6_NUMBER                AT32_DMA2_CH67_NUMBER 
#define AT32_DMA2_CH7_NUMBER                AT32_DMA2_CH67_NUMBER 

#define DMA2_CH4_CMASK                      0x00000C00U
#define DMA2_CH5_CMASK                      0x00000C00U
#define DMA2_CH6_CMASK                      0x00003000U
#define DMA2_CH7_CMASK                      0x00003000U

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXTI attributes.*/
#define AT32_EXTI_NUM_LINES                 20
#define AT32_EXTI_IMR_MASK                  0x00000000U

/* Flash attributes.*/
#if defined(AT32F40xxG)
#define AT32_FLASH_NUMBER_OF_BANKS          2
#else
#define AT32_FLASH_NUMBER_OF_BANKS          1
#endif

#define AT32_FLASH_SECTOR_SIZE              2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#if defined(AT32F40xxG) || defined(AT32F40xxE)
#define AT32_FLASH_SECTORS_PER_BANK         256 /* Maximum, can be redefined.*/
#elif 
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      FALSE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_GPIO_HAS_HDRV                  TRUE

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_RTC                        TRUE
#define AT32_RTC_HAS_SUBSECONDS             FALSE
#define AT32_RTC_IS_CALENDAR                TRUE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       TRUE
#define AT32_SDC_SDIO_DMA_STREAM            AT32_DMA_STREAM_ID(2, 4)
#define AT32_HAS_SDIO2                      TRUE
#define AT32_SDC_SDIO2_DMA_STREAM           AT32_DMA_STREAM_ID(2, 5)

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* TIM attributes.*/
#define AT32_TIM_MAX_CHANNELS               4

#define AT32_HAS_TIM1                       TRUE
#define AT32_TIM1_IS_32BITS                 FALSE
#define AT32_TIM1_CHANNELS                  4

#define AT32_HAS_TIM2                       TRUE
#define AT32_TIM2_IS_32BITS                 TRUE
#define AT32_TIM2_CHANNELS                  4

#define AT32_HAS_TIM3                       TRUE
#define AT32_TIM3_IS_32BITS                 FALSE
#define AT32_TIM3_CHANNELS                  4

#define AT32_HAS_TIM4                       TRUE
#define AT32_TIM4_IS_32BITS                 FALSE
#define AT32_TIM4_CHANNELS                  4

#define AT32_HAS_TIM5                       TRUE
#define AT32_TIM5_IS_32BITS                 TRUE
#define AT32_TIM5_CHANNELS                  4

#define AT32_HAS_TIM6                       TRUE
#define AT32_TIM6_IS_32BITS                 FALSE
#define AT32_TIM6_CHANNELS                  0

#define AT32_HAS_TIM7                       TRUE
#define AT32_TIM7_IS_32BITS                 FALSE
#define AT32_TIM7_CHANNELS                  0

#define AT32_HAS_TIM8                       TRUE
#define AT32_TIM8_IS_32BITS                 FALSE
#define AT32_TIM8_CHANNELS                  4

#define AT32_HAS_TIM9                       TRUE
#define AT32_TIM9_IS_32BITS                 FALSE
#define AT32_TIM9_CHANNELS                  2

#define AT32_HAS_TIM10                      TRUE
#define AT32_TIM10_IS_32BITS                FALSE
#define AT32_TIM10_CHANNELS                 1

#define AT32_HAS_TIM11                      TRUE
#define AT32_TIM11_IS_32BITS                FALSE
#define AT32_TIM11_CHANNELS                 1

#define AT32_HAS_TIM12                      TRUE
#define AT32_TIM12_IS_32BITS                FALSE
#define AT32_TIM12_CHANNELS                 2

#define AT32_HAS_TIM13                      TRUE
#define AT32_TIM13_IS_32BITS                FALSE
#define AT32_TIM13_CHANNELS                 1

#define AT32_HAS_TIM14                      TRUE
#define AT32_TIM14_IS_32BITS                FALSE
#define AT32_TIM14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_HAS_USART2                    TRUE
#define AT32_HAS_USART3                    TRUE
#define AT32_HAS_UART4                     TRUE
#define AT32_HAS_UART5                     TRUE
#define AT32_HAS_USART6                    TRUE
#define AT32_HAS_UART7                     TRUE
#define AT32_HAS_UART8                     TRUE

/* USB attributes.*/
#define AT32_HAS_USB                       TRUE
#define AT32_USB_ACCESS_SCHEME_2x16        FALSE
#define AT32_USB_PMA_MAX_SIZE              1280
#define AT32_USB_HAS_BCDR                  FALSE
#define AT32_USB_HAS_CFG                   TRUE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                      TRUE
#define AT32_IWDG_IS_WINDOWED              TRUE

/* FSMC attributes.*/
#define AT32_HAS_XMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
#define AT32_CRC_PROGRAMMABLE              FALSE

#endif /* defined(AT32F403ARx) */

#if defined(AT32F403AVx) || defined(__DOXYGEN__)
/**
 * @name    AT32F403AVx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_ADC1_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC1_DMA_CHN                   0x00000000
#define AT32_HAS_ADC2                       TRUE
#define AT32_ADC2_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC2_DMA_CHN                   0x00000000
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC3_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(2, 5))
#define AT32_ADC3_DMA_CHN                   0x00000000

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   FALSE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA1_CH1_HANDLER               Vector6C
#define AT32_DMA1_CH2_HANDLER               Vector70
#define AT32_DMA1_CH3_HANDLER               Vector74
#define AT32_DMA1_CH4_HANDLER               Vector78
#define AT32_DMA1_CH5_HANDLER               Vector7C
#define AT32_DMA1_CH6_HANDLER               Vector80
#define AT32_DMA1_CH7_HANDLER               Vector84
#define AT32_DMA1_CH1_NUMBER                11
#define AT32_DMA1_CH2_NUMBER                12
#define AT32_DMA1_CH3_NUMBER                13
#define AT32_DMA1_CH4_NUMBER                14
#define AT32_DMA1_CH5_NUMBER                15
#define AT32_DMA1_CH6_NUMBER                16
#define AT32_DMA1_CH7_NUMBER                17

#define AT32_DMA2_NUM_CHANNELS              7
#define AT32_DMA2_CH1_HANDLER               Vector120
#define AT32_DMA2_CH2_HANDLER               Vector124
#define AT32_DMA2_CH3_HANDLER               Vector128
#define AT32_DMA2_CH45_HANDLER              Vector12C
#define AT32_DMA2_CH67_HANDLER              Vector16C

#define AT32_DMA2_CH1_NUMBER                56
#define AT32_DMA2_CH2_NUMBER                57
#define AT32_DMA2_CH3_NUMBER                58
#define AT32_DMA2_CH45_NUMBER               59
#define AT32_DMA2_CH67_NUMBER               75

#define AT32_DMA2_CH4_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH5_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH6_NUMBER                AT32_DMA2_CH67_NUMBER 
#define AT32_DMA2_CH7_NUMBER                AT32_DMA2_CH67_NUMBER 

#define DMA2_CH4_CMASK                      0x00000C00U
#define DMA2_CH5_CMASK                      0x00000C00U
#define DMA2_CH6_CMASK                      0x00003000U
#define DMA2_CH7_CMASK                      0x00003000U

/* ETH attributes.*/
#define AT32_HAS_ETH                        FALSE

/* EXTI attributes.*/
#define AT32_EXTI_NUM_LINES                 20
#define AT32_EXTI_IMR_MASK                  0x00000000U

/* Flash attributes.*/
#if defined(AT32F40xxG)
#define AT32_FLASH_NUMBER_OF_BANKS          2
#else
#define AT32_FLASH_NUMBER_OF_BANKS          1
#endif

#define AT32_FLASH_SECTOR_SIZE              2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#if defined(AT32F40xxG) || defined(AT32F40xxE)
#define AT32_FLASH_SECTORS_PER_BANK         256 /* Maximum, can be redefined.*/
#elif 
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      TRUE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_GPIO_HAS_HDRV                  TRUE

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_RTC                        TRUE
#define AT32_RTC_HAS_SUBSECONDS             FALSE
#define AT32_RTC_IS_CALENDAR                TRUE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       TRUE
#define AT32_SDC_SDIO_DMA_STREAM            AT32_DMA_STREAM_ID(2, 4)
#define AT32_HAS_SDIO2                      TRUE
#define AT32_SDC_SDIO2_DMA_STREAM           AT32_DMA_STREAM_ID(2, 5)

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* TIM attributes.*/
#define AT32_TIM_MAX_CHANNELS               4

#define AT32_HAS_TIM1                       TRUE
#define AT32_TIM1_IS_32BITS                 FALSE
#define AT32_TIM1_CHANNELS                  4

#define AT32_HAS_TIM2                       TRUE
#define AT32_TIM2_IS_32BITS                 TRUE
#define AT32_TIM2_CHANNELS                  4

#define AT32_HAS_TIM3                       TRUE
#define AT32_TIM3_IS_32BITS                 FALSE
#define AT32_TIM3_CHANNELS                  4

#define AT32_HAS_TIM4                       TRUE
#define AT32_TIM4_IS_32BITS                 FALSE
#define AT32_TIM4_CHANNELS                  4

#define AT32_HAS_TIM5                       TRUE
#define AT32_TIM5_IS_32BITS                 TRUE
#define AT32_TIM5_CHANNELS                  4

#define AT32_HAS_TIM6                       TRUE
#define AT32_TIM6_IS_32BITS                 FALSE
#define AT32_TIM6_CHANNELS                  0

#define AT32_HAS_TIM7                       TRUE
#define AT32_TIM7_IS_32BITS                 FALSE
#define AT32_TIM7_CHANNELS                  0

#define AT32_HAS_TIM8                       TRUE
#define AT32_TIM8_IS_32BITS                 FALSE
#define AT32_TIM8_CHANNELS                  4

#define AT32_HAS_TIM9                       TRUE
#define AT32_TIM9_IS_32BITS                 FALSE
#define AT32_TIM9_CHANNELS                  2

#define AT32_HAS_TIM10                      TRUE
#define AT32_TIM10_IS_32BITS                FALSE
#define AT32_TIM10_CHANNELS                 1

#define AT32_HAS_TIM11                      TRUE
#define AT32_TIM11_IS_32BITS                FALSE
#define AT32_TIM11_CHANNELS                 1

#define AT32_HAS_TIM12                      TRUE
#define AT32_TIM12_IS_32BITS                FALSE
#define AT32_TIM12_CHANNELS                 2

#define AT32_HAS_TIM13                      TRUE
#define AT32_TIM13_IS_32BITS                FALSE
#define AT32_TIM13_CHANNELS                 1

#define AT32_HAS_TIM14                      TRUE
#define AT32_TIM14_IS_32BITS                FALSE
#define AT32_TIM14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_HAS_USART2                    TRUE
#define AT32_HAS_USART3                    TRUE
#define AT32_HAS_UART4                     TRUE
#define AT32_HAS_UART5                     TRUE
#define AT32_HAS_USART6                    TRUE
#define AT32_HAS_UART7                     TRUE
#define AT32_HAS_UART8                     TRUE


/* USB attributes.*/
#define AT32_HAS_USB                       TRUE
#define AT32_USB_ACCESS_SCHEME_2x16        FALSE
#define AT32_USB_PMA_MAX_SIZE              1280
#define AT32_USB_HAS_BCDR                  FALSE
#define AT32_USB_HAS_CFG                   TRUE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                      TRUE
#define AT32_IWDG_IS_WINDOWED              TRUE

/* FSMC attributes.*/
#define AT32_HAS_XMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
#define AT32_CRC_PROGRAMMABLE              FALSE

#endif /* defined(AT32F403AVx) */

#if defined(AT32F407Rx) || defined(AT32F407Vx) || defined(__DOXYGEN__)
/**
 * @name    AT32F407Rx/AT32F407Vx capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                       TRUE
#define AT32_ADC1_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC1_DMA_CHN                   0x00000000
#define AT32_HAS_ADC2                       TRUE
#define AT32_ADC2_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(1, 1))
#define AT32_ADC2_DMA_CHN                   0x00000000
#define AT32_HAS_ADC3                       TRUE
#define AT32_ADC3_DMA_MSK                   (AT32_DMA_STREAM_ID_MSK(2, 5))
#define AT32_ADC3_DMA_CHN                   0x00000000

/* CAN attributes.*/
#define AT32_HAS_CAN1                       TRUE
#define AT32_HAS_CAN2                       TRUE
#define AT32_CAN_MAX_FILTERS                14

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                   TRUE
#define AT32_HAS_DAC1_CH2                   TRUE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                   FALSE
#define AT32_DMA_SUPPORTS_DMAMUX            TRUE
#define AT32_DMA_SUPPORTS_CSELR             FALSE

#define AT32_DMA1_NUM_CHANNELS              7
#define AT32_DMA1_CH1_HANDLER               Vector6C
#define AT32_DMA1_CH2_HANDLER               Vector70
#define AT32_DMA1_CH3_HANDLER               Vector74
#define AT32_DMA1_CH4_HANDLER               Vector78
#define AT32_DMA1_CH5_HANDLER               Vector7C
#define AT32_DMA1_CH6_HANDLER               Vector80
#define AT32_DMA1_CH7_HANDLER               Vector84
#define AT32_DMA1_CH1_NUMBER                11
#define AT32_DMA1_CH2_NUMBER                12
#define AT32_DMA1_CH3_NUMBER                13
#define AT32_DMA1_CH4_NUMBER                14
#define AT32_DMA1_CH5_NUMBER                15
#define AT32_DMA1_CH6_NUMBER                16
#define AT32_DMA1_CH7_NUMBER                17

#define AT32_DMA2_NUM_CHANNELS              7
#define AT32_DMA2_CH1_HANDLER               Vector120
#define AT32_DMA2_CH2_HANDLER               Vector124
#define AT32_DMA2_CH3_HANDLER               Vector128
#define AT32_DMA2_CH45_HANDLER              Vector12C
#define AT32_DMA2_CH67_HANDLER              Vector16C

#define AT32_DMA2_CH1_NUMBER                56
#define AT32_DMA2_CH2_NUMBER                57
#define AT32_DMA2_CH3_NUMBER                58
#define AT32_DMA2_CH45_NUMBER               59
#define AT32_DMA2_CH67_NUMBER               75

#define AT32_DMA2_CH4_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH5_NUMBER                AT32_DMA2_CH45_NUMBER
#define AT32_DMA2_CH6_NUMBER                AT32_DMA2_CH67_NUMBER 
#define AT32_DMA2_CH7_NUMBER                AT32_DMA2_CH67_NUMBER 

#define DMA2_CH4_CMASK                      0x00000C00U
#define DMA2_CH5_CMASK                      0x00000C00U
#define DMA2_CH6_CMASK                      0x00003000U
#define DMA2_CH7_CMASK                      0x00003000U

/* ETH attributes.*/
#define AT32_HAS_ETH                        TRUE

/* EXTI attributes.*/
#define AT32_EXTI_NUM_LINES                 20
#define AT32_EXTI_IMR_MASK                  0x00000000U

/* Flash attributes.*/
#if defined(AT32F40xxG)
#define AT32_FLASH_NUMBER_OF_BANKS          2
#else
#define AT32_FLASH_NUMBER_OF_BANKS          1
#endif

#define AT32_FLASH_SECTOR_SIZE              2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#if defined(AT32F40xxG) || defined(AT32F40xxE)
#define AT32_FLASH_SECTORS_PER_BANK         256 /* Maximum, can be redefined.*/
#elif 
#define AT32_FLASH_SECTORS_PER_BANK         128 /* Maximum, can be redefined.*/
#endif
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                      TRUE
#define AT32_HAS_GPIOB                      TRUE
#define AT32_HAS_GPIOC                      TRUE
#define AT32_HAS_GPIOD                      TRUE
#define AT32_HAS_GPIOE                      TRUE
#define AT32_HAS_GPIOF                      FALSE
#define AT32_HAS_GPIOG                      FALSE
#define AT32_GPIO_HAS_HDRV                  TRUE

/* I2C attributes.*/
#define AT32_HAS_I2C1                       TRUE
#define AT32_HAS_I2C2                       TRUE
#define AT32_HAS_I2C3                       TRUE

/* RTC attributes.*/
#define AT32_HAS_RTC                        TRUE
#define AT32_RTC_HAS_SUBSECONDS             FALSE
#define AT32_RTC_IS_CALENDAR                TRUE

/* SDIO attributes.*/
#define AT32_HAS_SDIO                       TRUE
#define AT32_SDC_SDIO_DMA_STREAM            AT32_DMA_STREAM_ID(2, 4)
#define AT32_HAS_SDIO2                      TRUE
#define AT32_SDC_SDIO2_DMA_STREAM           AT32_DMA_STREAM_ID(2, 5)

/* SPI attributes.*/
#define AT32_HAS_SPI1                       TRUE
#define AT32_SPI1_SUPPORTS_I2S              TRUE
#define AT32_SPI1_I2S_FULLDUPLEX            FALSE

#define AT32_HAS_SPI2                       TRUE
#define AT32_SPI2_SUPPORTS_I2S              TRUE
#define AT32_SPI2_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI3                       TRUE
#define AT32_SPI3_SUPPORTS_I2S              TRUE
#define AT32_SPI3_I2S_FULLDUPLEX            TRUE

#define AT32_HAS_SPI4                       TRUE
#define AT32_SPI4_SUPPORTS_I2S              TRUE
#define AT32_SPI4_I2S_FULLDUPLEX            FALSE

/* TIM attributes.*/
#define AT32_TIM_MAX_CHANNELS               4

#define AT32_HAS_TIM1                       TRUE
#define AT32_TIM1_IS_32BITS                 FALSE
#define AT32_TIM1_CHANNELS                  4

#define AT32_HAS_TIM2                       TRUE
#define AT32_TIM2_IS_32BITS                 TRUE
#define AT32_TIM2_CHANNELS                  4

#define AT32_HAS_TIM3                       TRUE
#define AT32_TIM3_IS_32BITS                 FALSE
#define AT32_TIM3_CHANNELS                  4

#define AT32_HAS_TIM4                       TRUE
#define AT32_TIM4_IS_32BITS                 FALSE
#define AT32_TIM4_CHANNELS                  4

#define AT32_HAS_TIM5                       TRUE
#define AT32_TIM5_IS_32BITS                 TRUE
#define AT32_TIM5_CHANNELS                  4

#define AT32_HAS_TIM6                       TRUE
#define AT32_TIM6_IS_32BITS                 FALSE
#define AT32_TIM6_CHANNELS                  0

#define AT32_HAS_TIM7                       TRUE
#define AT32_TIM7_IS_32BITS                 FALSE
#define AT32_TIM7_CHANNELS                  0

#define AT32_HAS_TIM8                       TRUE
#define AT32_TIM8_IS_32BITS                 FALSE
#define AT32_TIM8_CHANNELS                  4

#define AT32_HAS_TIM9                       TRUE
#define AT32_TIM9_IS_32BITS                 FALSE
#define AT32_TIM9_CHANNELS                  2

#define AT32_HAS_TIM10                      TRUE
#define AT32_TIM10_IS_32BITS                FALSE
#define AT32_TIM10_CHANNELS                 1

#define AT32_HAS_TIM11                      TRUE
#define AT32_TIM11_IS_32BITS                FALSE
#define AT32_TIM11_CHANNELS                 1

#define AT32_HAS_TIM12                      TRUE
#define AT32_TIM12_IS_32BITS                FALSE
#define AT32_TIM12_CHANNELS                 2

#define AT32_HAS_TIM13                      TRUE
#define AT32_TIM13_IS_32BITS                FALSE
#define AT32_TIM13_CHANNELS                 1

#define AT32_HAS_TIM14                      TRUE
#define AT32_TIM14_IS_32BITS                FALSE
#define AT32_TIM14_CHANNELS                 1

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_HAS_USART2                    TRUE
#define AT32_HAS_USART3                    TRUE
#define AT32_HAS_UART4                     TRUE
#define AT32_HAS_UART5                     TRUE
#define AT32_HAS_USART6                    TRUE
#define AT32_HAS_UART7                     TRUE
#define AT32_HAS_UART8                     TRUE


/* USB attributes.*/
#define AT32_HAS_USB                       TRUE
#define AT32_USB_ACCESS_SCHEME_2x16        FALSE
#define AT32_USB_PMA_MAX_SIZE              1280
#define AT32_USB_HAS_BCDR                  FALSE
#define AT32_USB_HAS_CFG                   TRUE

/* IWDG attributes.*/
#define AT32_HAS_IWDG                      TRUE
#define AT32_IWDG_IS_WINDOWED              TRUE

/* FSMC attributes.*/
#define AT32_HAS_XMC                       TRUE

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
#define AT32_CRC_PROGRAMMABLE              FALSE

#endif /* defined(AT32F407Rx) || defined(AT32F407Vx) */
#endif /* AT32_REGISTRY_H */

/** @} */
