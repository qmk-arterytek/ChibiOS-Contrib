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
 * @file    AT32F402/at32_registry.h
 * @brief   AT32F402 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

#if defined(AT32F402KB)
#define AT32F402K_MD

#elif defined(AT32F402KC)
#define AT32F402K_HD

#elif defined(AT32F402CB)
#define AT32F402C_MD

#elif defined(AT32F402CC)
#define AT32F402C_HD

#elif defined(AT32F402RB)
#define AT32F402R_MD

#elif defined(AT32F402RC)
#define AT32F402R_HD

#else
#error "unsupported or unrecognized AT32F402 member"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(AT32F402K_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402K MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOFEN)

#define AT32_HAS_GPIOC                     FALSE
#define AT32_HAS_GPIOD                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402K_MD) */

#if defined(AT32F402K_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402K HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOFEN)

#define AT32_HAS_GPIOC                     FALSE
#define AT32_HAS_GPIOD                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      FALSE

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402K_HD) */

#if defined(AT32F402C_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402C MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIOFEN)

#define AT32_HAS_GPIOD                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402C_MD) */

#if defined(AT32F402C_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402C HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIOFEN)

#define AT32_HAS_GPIOD                     FALSE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     FALSE

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402C_HD) */

#if defined(AT32F402R_MD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402R MD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             1024U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIODEN |           \
                                            CRM_AHBEN1_GPIOFEN)

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     TRUE
#define AT32_UART_UART8_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART8_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402R_MD) */

#if defined(AT32F402R_HD) || defined(__DOXYGEN__)
/**
 * @name    AT32F402R HD capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_ADC_ADC1_DMA_STREAM           AT32_DMA_STREAM_ID_ANY

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_CAN_MAX_FILTERS               14

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  TRUE
#define AT32_DMA_SUPPORTS_DMAMUX           TRUE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA2_NUM_CHANNELS             7

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               22
#define AT32_EXINT_INTEN_MASK              0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         1
#define AT32_FLASH_SECTOR_SIZE             2048U

#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        128 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOF                     TRUE
#define AT32_GPIO_EN_MASK                  (CRM_AHBEN1_GPIOAEN |           \
                                            CRM_AHBEN1_GPIOBEN |           \
                                            CRM_AHBEN1_GPIOCEN |           \
                                            CRM_AHBEN1_GPIODEN |           \
                                            CRM_AHBEN1_GPIOFEN)

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* ERTC attributes.*/
#define AT32_HAS_ERTC                      TRUE
#define AT32_ERTC_HAS_SUBSECONDS           TRUE
#define AT32_ERTC_HAS_PERIODIC_WAKEUPS     TRUE
#define AT32_ERTC_NUM_ALARMS               2
#define AT32_ERTC_STORAGE_SIZE             80

/* QUADSPI attributes.*/
#define AT32_HAS_QUADSPI1                  TRUE
#define AT32_WSPI_QUADSPI1_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* SDIO attributes.*/
#define AT32_HAS_SDIO                      FALSE

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI1_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID_ANY

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

#define AT32_HAS_TMR5                      FALSE

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART5                     TRUE
#define AT32_UART_UART5_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART5_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_USART6                    TRUE
#define AT32_UART_USART6_RX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY
#define AT32_UART_USART6_TX_DMA_STREAM     AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART7                     TRUE
#define AT32_UART_UART7_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART7_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

#define AT32_HAS_UART8                     TRUE
#define AT32_UART_UART8_RX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY
#define AT32_UART_UART8_TX_DMA_STREAM      AT32_DMA_STREAM_ID_ANY

/* USB attributes.*/
#define AT32_OTG_STEPPING                  2

#define AT32_HAS_OTG1                      TRUE
#define AT32_OTG1_ENDPOINTS                8

#define AT32_HAS_OTG2                      FALSE

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               TRUE
/** @} */
#endif /* defined(AT32F402R_HD) */

#endif /* AT32_REGISTRY_H */

/** @} */
