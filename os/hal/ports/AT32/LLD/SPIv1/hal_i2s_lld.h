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
 * @file    SPIv1/hal_i2s_lld.h
 * @brief   AT32 I2S subsystem low level driver header.
 *
 * @addtogroup I2S
 * @{
 */

#ifndef HAL_I2S_LLD_H
#define HAL_I2S_LLD_H

#if HAL_USE_I2S || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Static I2S modes
 * @{
 */
#define AT32_I2S_MODE_SLAVE                0
#define AT32_I2S_MODE_MASTER               1
#define AT32_I2S_MODE_RX                   2
#define AT32_I2S_MODE_TX                   4
#define AT32_I2S_MODE_RXTX                 (AT32_I2S_MODE_RX |            \
                                             AT32_I2S_MODE_TX)
/** @} */

/**
 * @name    Mode checks
 * @{
 */
#define AT32_I2S_IS_MASTER(mode)           ((mode) & AT32_I2S_MODE_MASTER)
#define AT32_I2S_RX_ENABLED(mode)          ((mode) & AT32_I2S_MODE_RX)
#define AT32_I2S_TX_ENABLED(mode)          ((mode) & AT32_I2S_MODE_TX)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   I2S1 driver enable switch.
 * @details If set to @p TRUE the support for I2S1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT32_I2S_USE_SPI1) || defined(__DOXYGEN__)
#define AT32_I2S_USE_SPI1                  FALSE
#endif

/**
 * @brief   I2S2 driver enable switch.
 * @details If set to @p TRUE the support for I2S2 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT32_I2S_USE_SPI2) || defined(__DOXYGEN__)
#define AT32_I2S_USE_SPI2                  FALSE
#endif

/**
 * @brief   I2S3 driver enable switch.
 * @details If set to @p TRUE the support for I2S3 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT32_I2S_USE_SPI3) || defined(__DOXYGEN__)
#define AT32_I2S_USE_SPI3                  FALSE
#endif

/**
 * @brief   I2S4 driver enable switch.
 * @details If set to @p TRUE the support for I2S4 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(AT32_I2S_USE_SPI4) || defined(__DOXYGEN__)
#define AT32_I2S_USE_SPI4                  FALSE
#endif

/**
 * @brief   I2S1 mode.
 */
#if !defined(AT32_I2S_SPI1_MODE) || defined(__DOXYGEN__)
#define AT32_I2S_SPI1_MODE                 (AT32_I2S_MODE_MASTER |        \
                                             AT32_I2S_MODE_RX)
#endif

/**
 * @brief   I2S2 mode.
 */
#if !defined(AT32_I2S_SPI2_MODE) || defined(__DOXYGEN__)
#define AT32_I2S_SPI2_MODE                 (AT32_I2S_MODE_MASTER |        \
                                             AT32_I2S_MODE_RX)
#endif

/**
 * @brief   I2S3 mode.
 */
#if !defined(AT32_I2S_SPI3_MODE) || defined(__DOXYGEN__)
#define AT32_I2S_SPI3_MODE                 (AT32_I2S_MODE_MASTER |        \
                                             AT32_I2S_MODE_RX)
#endif

/**
 * @brief   I2S4 mode.
 */
#if !defined(AT32_I2S_SI4_MODE) || defined(__DOXYGEN__)
#define AT32_I2S_SI4_MODE                 (AT32_I2S_MODE_MASTER |        \
                                             AT32_I2S_MODE_RX)
#endif

/**
 * @brief   I2S1 interrupt priority level setting.
 */
#if !defined(AT32_I2S_SPI1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI1_IRQ_PRIORITY         10
#endif

/**
 * @brief   I2S2 interrupt priority level setting.
 */
#if !defined(AT32_I2S_SPI2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI2_IRQ_PRIORITY         10
#endif

/**
 * @brief   I2S3 interrupt priority level setting.
 */
#if !defined(AT32_I2S_SPI3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI3_IRQ_PRIORITY         10
#endif

/**
 * @brief   I2S4 interrupt priority level setting.
 */
#if !defined(AT32_I2S_SI4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SI4_IRQ_PRIORITY         10
#endif

/**
 * @brief   I2S1 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_I2S_SPI1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI1_DMA_PRIORITY         1
#endif

/**
 * @brief   I2S2 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_I2S_SPI2_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI2_DMA_PRIORITY         1
#endif

/**
 * @brief   I2S3 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_I2S_SPI3_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI3_DMA_PRIORITY         1
#endif

/**
 * @brief   I2S4 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_I2S_SPI4_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_I2S_SPI4_DMA_PRIORITY         1
#endif

/**
 * @brief   I2S DMA error hook.
 */
#if !defined(AT32_I2S_DMA_ERROR_HOOK) || defined(__DOXYGEN__)
#define AT32_I2S_DMA_ERROR_HOOK(i2sp)      osalSysHalt("DMA failure")
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if AT32_I2S_USE_SPI1 && !AT32_SPI1_SUPPORTS_I2S
#error "SPI1 does not support I2S mode"
#endif

#if AT32_I2S_USE_SPI2 && !AT32_SPI2_SUPPORTS_I2S
#error "SPI2 does not support I2S mode"
#endif

#if AT32_I2S_USE_SPI3 && !AT32_SPI3_SUPPORTS_I2S
#error "SPI3 does not support I2S mode"
#endif

#if AT32_I2S_USE_SPI4 && !AT32_SPI4_SUPPORTS_I2S
#error "SPI4 does not support I2S mode"
#endif

#if AT32_I2S_RX_ENABLED(AT32_I2S_SPI1_MODE) &&                            \
    AT32_I2S_TX_ENABLED(AT32_I2S_SPI1_MODE)
#error "I2S1 RX and TX mode not supported in this driver implementation"
#endif

#if AT32_I2S_RX_ENABLED(AT32_I2S_SPI2_MODE) &&                            \
    AT32_I2S_TX_ENABLED(AT32_I2S_SPI2_MODE)
#error "I2S2 RX and TX mode not supported in this driver implementation"
#endif

#if AT32_I2S_RX_ENABLED(AT32_I2S_SPI3_MODE) &&                            \
    AT32_I2S_TX_ENABLED(AT32_I2S_SPI3_MODE)
#error "I2S3 RX and TX mode not supported in this driver implementation"
#endif

#if AT32_I2S_RX_ENABLED(AT32_I2S_SPI4_MODE) &&                            \
    AT32_I2S_TX_ENABLED(AT32_I2S_SPI4_MODE)
#error "I2S4 RX and TX mode not supported in this driver implementation"
#endif

#if AT32_I2S_USE_SPI1 && !AT32_HAS_SPI1
#error "SPI1 not present in the selected device"
#endif

#if AT32_I2S_USE_SPI2 && !AT32_HAS_SPI2
#error "SPI2 not present in the selected device"
#endif

#if AT32_I2S_USE_SPI3 && !AT32_HAS_SPI3
#error "SPI3 not present in the selected device"
#endif

#if AT32_I2S_USE_SPI4 && !AT32_HAS_SPI4
#error "SPI4 not present in the selected device"
#endif

#if !AT32_I2S_USE_SPI1 && !AT32_I2S_USE_SPI2 && !AT32_I2S_USE_SPI3 && !AT32_I2S_USE_SPI4
#error "I2S driver activated but no SPI peripheral assigned"
#endif

#if AT32_I2S_USE_SPI1 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2S_SPI1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI1"
#endif

#if AT32_I2S_USE_SPI2 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2S_SPI2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI2"
#endif

#if AT32_I2S_USE_SPI3 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2S_SPI3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI3"
#endif

#if AT32_I2S_USE_SPI4 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_I2S_SPI4_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI4"
#endif

#if AT32_I2S_USE_SPI1 &&                                                   \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2S_SPI1_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SPI1"
#endif

#if AT32_I2S_USE_SPI2 &&                                                   \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2S_SPI2_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SPI2"
#endif

#if AT32_I2S_USE_SPI3 &&                                                   \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2S_SPI3_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SPI3"
#endif

#if AT32_I2S_USE_SPI4 &&                                                   \
    !AT32_DMA_IS_VALID_PRIORITY(AT32_I2S_SPI4_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SPI4"
#endif

/* The following checks are only required when there is a DMA able to
   reassign streams to different channels.*/
#if AT32_ADVANCED_DMA
/* Check on the presence of the DMA streams settings in mcuconf.h.*/
#if AT32_I2S_USE_SPI1 && (!defined(AT32_I2S_SPI1_RX_DMA_STREAM) ||        \
                           !defined(AT32_I2S_SPI1_TX_DMA_STREAM))
#error "SPI1 DMA streams not defined"
#endif

#if AT32_I2S_USE_SPI2 && (!defined(AT32_I2S_SPI2_RX_DMA_STREAM) ||        \
                           !defined(AT32_I2S_SPI2_TX_DMA_STREAM))
#error "SPI2 DMA streams not defined"
#endif

#if AT32_I2S_USE_SPI3 && (!defined(AT32_I2S_SPI3_RX_DMA_STREAM) ||        \
                           !defined(AT32_I2S_SPI3_TX_DMA_STREAM))
#error "SPI3 DMA streams not defined"
#endif

#if AT32_I2S_USE_SPI4 && (!defined(AT32_I2S_SPI4_RX_DMA_STREAM) ||        \
                           !defined(AT32_I2S_SPI4_TX_DMA_STREAM))
#error "SPI4 DMA streams not defined"
#endif

/* Check on the validity of the assigned DMA channels.*/
#if AT32_I2S_USE_SPI1 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI1_RX_DMA_STREAM, AT32_SPI1_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI1 RX"
#endif

#if AT32_I2S_USE_SPI1 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI1_TX_DMA_STREAM, AT32_SPI1_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI1 TX"
#endif

#if AT32_I2S_USE_SPI2 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI2_RX_DMA_STREAM, AT32_SPI2_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI2 RX"
#endif

#if AT32_I2S_USE_SPI2 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI2_TX_DMA_STREAM, AT32_SPI2_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI2 TX"
#endif

#if AT32_I2S_USE_SPI3 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI3_RX_DMA_STREAM, AT32_SPI3_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI3 RX"
#endif

#if AT32_I2S_USE_SPI3 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI3_TX_DMA_STREAM, AT32_SPI3_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI3 TX"
#endif

#if AT32_I2S_USE_SPI4 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI4_RX_DMA_STREAM, AT32_SPI4_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI4 RX"
#endif

#if AT32_I2S_USE_SPI4 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_I2S_SPI4_TX_DMA_STREAM, AT32_SPI4_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI4 TX"
#endif
#endif /* AT32_ADVANCED_DMA */

#if !defined(AT32_DMA_REQUIRED)
#define AT32_DMA_REQUIRED
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Low level fields of the I2S driver structure.
 */
#define i2s_lld_driver_fields                                               \
  /* Pointer to the SPIx registers block.*/                                 \
  SPI_TypeDef               *spi;                                           \
  /* Calculated part of the I2SCFGR register.*/                             \
  uint16_t                  cfg;                                            \
  /* Receive DMA stream or @p NULL.*/                                       \
  const at32_dma_stream_t  *dmarx;                                         \
  /* Transmit DMA stream or @p NULL.*/                                      \
  const at32_dma_stream_t  *dmatx;                                         \
  /* RX DMA mode bit mask.*/                                                \
  uint32_t                  rxdmamode;                                      \
  /* TX DMA mode bit mask.*/                                                \
  uint32_t                  txdmamode

/**
 * @brief   Low level fields of the I2S configuration structure.
 */
#define i2s_lld_config_fields                                               \
  /* Configuration of the I2SCFGR register.                                 \
     NOTE: See the AT32 reference manual, this register is used for        \
           the I2S configuration, the following bits must not be            \
           specified because handled directly by the driver:                \
           - I2SMOD                                                         \
           - I2SE                                                           \
           - I2SCFG                                                         \
   */                                                                       \
  int16_t                   i2scfgr;                                        \
  /* Configuration of the I2SPR register.                                   \
     NOTE: See the AT32 reference manual, this register is used for        \
           the I2S clock setup.*/                                           \
  int16_t                   i2spr

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_I2S_USE_SPI1 && !defined(__DOXYGEN__)
extern I2SDriver I2SD1;
#endif

#if AT32_I2S_USE_SPI2 && !defined(__DOXYGEN__)
extern I2SDriver I2SD2;
#endif

#if AT32_I2S_USE_SPI3 && !defined(__DOXYGEN__)
extern I2SDriver I2SD3;
#endif

#if AT32_I2S_USE_SPI4 && !defined(__DOXYGEN__)
extern I2SDriver I2SD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void i2s_lld_init(void);
  void i2s_lld_start(I2SDriver *i2sp);
  void i2s_lld_stop(I2SDriver *i2sp);
  void i2s_lld_start_exchange(I2SDriver *i2sp);
  void i2s_lld_stop_exchange(I2SDriver *i2sp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_I2S */

#endif /* HAL_I2S_LLD_H */

/** @} */
