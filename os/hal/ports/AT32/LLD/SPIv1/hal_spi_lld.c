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
 * @file    SPIv1/hal_spi_lld.c
 * @brief   AT32 SPI  subsystem low level driver source.
 *
 * @addtogroup SPI
 * @{
 */

#include "hal.h"

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SPI1_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI1_RX_DMA_STREAM,                        \
                       AT32_SPI1_RX_DMA_CHN)

#define SPI1_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI1_TX_DMA_STREAM,                        \
                       AT32_SPI1_TX_DMA_CHN)

#define SPI2_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI2_RX_DMA_STREAM,                        \
                       AT32_SPI2_RX_DMA_CHN)

#define SPI2_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI2_TX_DMA_STREAM,                        \
                       AT32_SPI2_TX_DMA_CHN)

#define SPI3_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI3_RX_DMA_STREAM,                        \
                       AT32_SPI3_RX_DMA_CHN)

#define SPI3_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI3_TX_DMA_STREAM,                        \
                       AT32_SPI3_TX_DMA_CHN)

#define SPI4_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI4_RX_DMA_STREAM,                        \
                       AT32_SPI4_RX_DMA_CHN)

#define SPI4_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI4_TX_DMA_STREAM,                        \
                       AT32_SPI4_TX_DMA_CHN)

#define SPI5_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI5_RX_DMA_STREAM,                        \
                       AT32_SPI5_RX_DMA_CHN)

#define SPI5_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI5_TX_DMA_STREAM,                        \
                       AT32_SPI5_TX_DMA_CHN)

#define SPI6_RX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI6_RX_DMA_STREAM,                        \
                       AT32_SPI6_RX_DMA_CHN)

#define SPI6_TX_DMA_CHANNEL                                                 \
  AT32_DMA_GETCHANNEL(AT32_SPI_SPI6_TX_DMA_STREAM,                        \
                       AT32_SPI6_TX_DMA_CHN)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief SPI1 driver identifier.*/
#if AT32_SPI_USE_SPI1 || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/** @brief SPI2 driver identifier.*/
#if AT32_SPI_USE_SPI2 || defined(__DOXYGEN__)
SPIDriver SPID2;
#endif

/** @brief SPI3 driver identifier.*/
#if AT32_SPI_USE_SPI3 || defined(__DOXYGEN__)
SPIDriver SPID3;
#endif

/** @brief SPI4 driver identifier.*/
#if AT32_SPI_USE_SPI4 || defined(__DOXYGEN__)
SPIDriver SPID4;
#endif

/** @brief SPI5 driver identifier.*/
#if AT32_SPI_USE_SPI5 || defined(__DOXYGEN__)
SPIDriver SPID5;
#endif

/** @brief SPI6 driver identifier.*/
#if AT32_SPI_USE_SPI6 || defined(__DOXYGEN__)
SPIDriver SPID6;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void spi_lld_configure(SPIDriver *spip) {

  /* SPI setup.*/
  if (spip->config->slave) {
    spip->spi->CTRL1 = spip->config->cr1 & ~(SPI_CTRL1_MSTEN | SPI_CTRL1_SPIEN);
    spip->spi->CTRL2 = spip->config->cr2 |
                        SPI_CTRL2_DMAREN | SPI_CTRL2_DMATEN;
  }
  else {
    spip->spi->CTRL1 = (spip->config->cr1 | SPI_CTRL1_MSTEN) & ~SPI_CTRL1_SPIEN;
    spip->spi->CTRL2 = spip->config->cr2 | SPI_CTRL2_HWCSOE |
                        SPI_CTRL2_DMAREN | SPI_CTRL2_DMATEN;
  }
}

/**
 * @brief   Stopping the SPI transaction.
 * @note    This is done nicely or by brutally resetting it depending on
 *          the mode and settings.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 */
static msg_t spi_lld_stop_abort(SPIDriver *spip) {

  if (!spip->config->slave) {
    /* Master mode, stopping gracefully.*/

    /* Stopping TX DMA channel.*/
    dmaStreamDisable(spip->dmatx);

    /* Waiting for current frame completion then stop SPI.*/
    while ((spip->spi->STS & SPI_STS_BF) != 0U) {
    }
    spip->spi->CTRL1 &= ~SPI_CTRL1_SPIEN;

    /* Now it is idle, stopping RX DMA channel.*/
    dmaStreamDisable(spip->dmarx);
  }
  else {
    /* Slave mode, this will not be nice.*/

    /* Stopping DMAs.*/
    dmaStreamDisable(spip->dmatx);
    dmaStreamDisable(spip->dmarx);

    /* Resetting SPI, this will stop it for sure and leave it
       in a clean state.*/
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      crmResetSPI1();
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      crmResetSPI2();
    }
#endif

#if AT32_SPI_USE_SPI3
    else if (&SPID3 == spip) {
      crmResetSPI3();
    }
#endif

#if AT32_SPI_USE_SPI4
    else if (&SPID4 == spip) {
      crmResetSPI4();
    }
#endif

#if AT32_SPI_USE_SPI5
    else if (&SPID5 == spip) {
      crmResetSPI5();
    }
#endif

#if AT32_SPI_USE_SPI6
    else if (&SPID6 == spip) {
      crmResetSPI6();
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }

    /* Reconfiguring SPI.*/
    spi_lld_configure(spip);
  }

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Shared end-of-rx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void spi_lld_serve_rx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & (AT32_DMA_ISR_TEIF | AT32_DMA_ISR_DMEIF)) != 0) {
#if defined(AT32_SPI_DMA_ERROR_HOOK)
    /* Hook first, if defined.*/
    AT32_SPI_DMA_ERROR_HOOK(spip);
#endif

    /* Aborting the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
  else if (spip->config->circular) {
    if ((flags & AT32_DMA_ISR_HTIF) != 0U) {
      /* Half buffer interrupt.*/
      __spi_isr_half_code(spip);
    }
    if ((flags & AT32_DMA_ISR_TCIF) != 0U) {
      /* End buffer interrupt.*/
      __spi_isr_full_code(spip);
    }
  }
  else {
    /* Stopping the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Operation finished interrupt.*/
    __spi_isr_complete_code(spip);
  }
}

/**
 * @brief   Shared end-of-tx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void spi_lld_serve_tx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & (AT32_DMA_ISR_TEIF | AT32_DMA_ISR_DMEIF)) != 0) {
#if defined(AT32_SPI_DMA_ERROR_HOOK)
    /* Hook first, if defined.*/
    AT32_SPI_DMA_ERROR_HOOK(spip);
#endif

    /* Aborting the transfer.*/
    (void) spi_lld_stop_abort(spip);

    /* Reporting the failure.*/
    __spi_isr_error_code(spip, HAL_RET_HW_FAILURE);
  }
}

/**
 * @brief   DMA streams allocation.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] rxstream  stream to be allocated for RX
 * @param[in] txstream  stream to be allocated for TX
 * @param[in] priority  streams IRQ priority
 * @return              The operation status.
 */
static msg_t spi_lld_get_dma(SPIDriver *spip, uint32_t rxstream,
                             uint32_t txstream, uint32_t priority) {

  spip->dmarx = dmaStreamAllocI(rxstream, priority,
                                (at32_dmaisr_t)spi_lld_serve_rx_interrupt,
                                (void *)spip);
  if (spip->dmarx == NULL) {
    return HAL_RET_NO_RESOURCE;
  }

  spip->dmatx = dmaStreamAllocI(txstream, priority,
                                (at32_dmaisr_t)spi_lld_serve_tx_interrupt,
                                (void *)spip);
  if (spip->dmatx == NULL) {
    dmaStreamFreeI(spip->dmarx);
    return HAL_RET_NO_RESOURCE;
  }

  return HAL_RET_SUCCESS;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if AT32_SPI_USE_SPI1
  spiObjectInit(&SPID1);
  SPID1.spi       = SPI1;
  SPID1.dmarx     = NULL;
  SPID1.dmatx     = NULL;
  SPID1.rxdmamode = AT32_DMA_CR_CHSEL(SPI1_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID1.txdmamode = AT32_DMA_CR_CHSEL(SPI1_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif

#if AT32_SPI_USE_SPI2
  spiObjectInit(&SPID2);
  SPID2.spi       = SPI2;
  SPID2.dmarx     = NULL;
  SPID2.dmatx     = NULL;
  SPID2.rxdmamode = AT32_DMA_CR_CHSEL(SPI2_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID2.txdmamode = AT32_DMA_CR_CHSEL(SPI2_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif

#if AT32_SPI_USE_SPI3
  spiObjectInit(&SPID3);
  SPID3.spi       = SPI3;
  SPID3.dmarx     = NULL;
  SPID3.dmatx     = NULL;
  SPID3.rxdmamode = AT32_DMA_CR_CHSEL(SPI3_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI3_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID3.txdmamode = AT32_DMA_CR_CHSEL(SPI3_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI3_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif

#if AT32_SPI_USE_SPI4
  spiObjectInit(&SPID4);
  SPID4.spi       = SPI4;
  SPID4.dmarx     = NULL;
  SPID4.dmatx     = NULL;
  SPID4.rxdmamode = AT32_DMA_CR_CHSEL(SPI4_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI4_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID4.txdmamode = AT32_DMA_CR_CHSEL(SPI4_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI4_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif

#if AT32_SPI_USE_SPI5
  spiObjectInit(&SPID5);
  SPID5.spi       = SPI5;
  SPID5.dmarx     = NULL;
  SPID5.dmatx     = NULL;
  SPID5.rxdmamode = AT32_DMA_CR_CHSEL(SPI5_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI5_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID5.txdmamode = AT32_DMA_CR_CHSEL(SPI5_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI5_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif

#if AT32_SPI_USE_SPI6
  spiObjectInit(&SPID6);
  SPID6.spi       = SPI6;
  SPID6.dmarx     = NULL;
  SPID6.dmatx     = NULL;
  SPID6.rxdmamode = AT32_DMA_CR_CHSEL(SPI6_RX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI6_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_P2M |
                    AT32_DMA_CR_TCIE |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
  SPID6.txdmamode = AT32_DMA_CR_CHSEL(SPI6_TX_DMA_CHANNEL) |
                    AT32_DMA_CR_PL(AT32_SPI_SPI6_DMA_PRIORITY) |
                    AT32_DMA_CR_DIR_M2P |
                    AT32_DMA_CR_DMEIE |
                    AT32_DMA_CR_TEIE;
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_start(SPIDriver *spip) {
  msg_t msg;

  /* Resetting TX pattern source.*/
  spip->txsource = (uint32_t)AT32_SPI_FILLER_PATTERN;

  /* If in stopped state then enables the SPI and DMA clocks.*/
  if (spip->state == SPI_STOP) {
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI1_RX_DMA_STREAM,
                            AT32_SPI_SPI1_TX_DMA_STREAM,
                            AT32_SPI_SPI1_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI1(true);
      crmResetSPI1();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI1_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI1_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI1_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI1_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI2_RX_DMA_STREAM,
                            AT32_SPI_SPI2_TX_DMA_STREAM,
                            AT32_SPI_SPI2_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI2(true);
      crmResetSPI2();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI2_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI2_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI2_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI2_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI3
    else if (&SPID3 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI3_RX_DMA_STREAM,
                            AT32_SPI_SPI3_TX_DMA_STREAM,
                            AT32_SPI_SPI3_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI3(true);
      crmResetSPI3();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI3_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI3_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI3_TX_DMAMUX_CHANNEL,AT32_DMAMUX_SPI3_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI4
    else if (&SPID4 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI4_RX_DMA_STREAM,
                            AT32_SPI_SPI4_TX_DMA_STREAM,
                            AT32_SPI_SPI4_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI4(true);
      crmResetSPI4();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI4_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI4_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI4_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI4_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI5
    else if (&SPID5 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI5_RX_DMA_STREAM,
                            AT32_SPI_SPI5_TX_DMA_STREAM,
                            AT32_SPI_SPI5_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI5(true);
      crmResetSPI5();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI5_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI5_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI5_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI5_TX);
#endif
    }
#endif

#if AT32_SPI_USE_SPI6
    else if (&SPID6 == spip) {
      msg = spi_lld_get_dma(spip,
                            AT32_SPI_SPI6_RX_DMA_STREAM,
                            AT32_SPI_SPI6_TX_DMA_STREAM,
                            AT32_SPI_SPI6_IRQ_PRIORITY);
      if (msg != HAL_RET_SUCCESS) {
        return msg;
      }
      crmEnableSPI6(true);
      crmResetSPI6();
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(spip->dmarx, AT32_SPI_SPI6_RX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI6_RX);
      dmaSetRequestSource(spip->dmatx, AT32_SPI_SPI6_TX_DMAMUX_CHANNEL, AT32_DMAMUX_SPI6_TX);
#endif
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }

    /* DMA setup.*/
    dmaStreamSetPeripheral(spip->dmarx, &spip->spi->DT);
    dmaStreamSetPeripheral(spip->dmatx, &spip->spi->DT);
  }

  /* Configuration-specific DMA setup.*/
  if ((spip->config->cr1 & SPI_CTRL1_FBN) == 0) {
    /* Frame width is 8 bits or smaller.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CR_SIZE_MASK) |
                      AT32_DMA_CR_PSIZE_BYTE | AT32_DMA_CR_MSIZE_BYTE;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CR_SIZE_MASK) |
                      AT32_DMA_CR_PSIZE_BYTE | AT32_DMA_CR_MSIZE_BYTE;
  }
  else {
    /* Frame width is larger than 8 bits.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CR_SIZE_MASK) |
                      AT32_DMA_CR_PSIZE_HWORD | AT32_DMA_CR_MSIZE_HWORD;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CR_SIZE_MASK) |
                      AT32_DMA_CR_PSIZE_HWORD | AT32_DMA_CR_MSIZE_HWORD;
  }

  if (spip->config->circular) {
    spip->rxdmamode |= (AT32_DMA_CR_CIRC | AT32_DMA_CR_HTIE);
    spip->txdmamode |= (AT32_DMA_CR_CIRC | AT32_DMA_CR_HTIE);
  }
  else {
    spip->rxdmamode &= ~(AT32_DMA_CR_CIRC | AT32_DMA_CR_HTIE);
    spip->txdmamode &= ~(AT32_DMA_CR_CIRC | AT32_DMA_CR_HTIE);
  }

  /* SPI setup.*/
  spi_lld_configure(spip);

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_stop(SPIDriver *spip) {

  /* If in ready state then disables the SPI clock.*/
  if (spip->state == SPI_READY) {

    /* Just in case this has been called uncleanly.*/
    (void) spi_lld_stop_abort(spip);

    /* SPI cleanup.*/
    spip->spi->CTRL1  = 0;
    spip->spi->CTRL2  = 0;

    /* DMA channels release.*/
    dmaStreamFreeI(spip->dmatx);
    dmaStreamFreeI(spip->dmarx);
    spip->dmarx = NULL;
    spip->dmatx = NULL;

    /* Clock shutdown.*/
    if (false) {
    }

#if AT32_SPI_USE_SPI1
    else if (&SPID1 == spip) {
      crmDisableSPI1();
    }
#endif

#if AT32_SPI_USE_SPI2
    else if (&SPID2 == spip) {
      crmDisableSPI2();
    }
#endif

#if AT32_SPI_USE_SPI3
    else if (&SPID3 == spip) {
      crmDisableSPI3();
    }
#endif

#if AT32_SPI_USE_SPI4
    else if (&SPID4 == spip) {
      crmDisableSPI4();
    }
#endif

#if AT32_SPI_USE_SPI5
    else if (&SPID5 == spip) {
      crmDisableSPI5();
    }
#endif

#if AT32_SPI_USE_SPI6
    else if (&SPID6 == spip) {
      crmDisableSPI6();
    }
#endif

    else {
      osalDbgAssert(false, "invalid SPI instance");
    }
  }
}

#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
/**
 * @brief   Asserts the slave select signal and prepares for transfers.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_select(SPIDriver *spip) {

  /* No implementation on AT32.*/
}

/**
 * @brief   Deasserts the slave select signal.
 * @details The previously selected peripheral is unselected.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_unselect(SPIDriver *spip) {

  /* No implementation on AT32.*/
}
#endif

/**
 * @brief   Ignores data on the SPI bus.
 * @details This synchronous function performs the transmission of a series of
 *          idle words on the SPI bus and ignores the received data.
 * @pre     In order to use this function the option @p SPI_USE_SYNCHRONIZATION
 *          must be enabled.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be ignored
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_ignore(SPIDriver *spip, size_t n) {

  osalDbgAssert(n < 65536, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &spip->rxsink);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, &spip->txsource);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Exchanges data on the SPI bus.
 * @details This asynchronous function starts a simultaneous transmit/receive
 *          operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 * @param[out] rxbuf    the pointer to the receive buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_exchange(SPIDriver *spip, size_t n,
                       const void *txbuf, void *rxbuf) {

  osalDbgAssert(n < 65536, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode | AT32_DMA_CR_MINC);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CR_MINC);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Sends data over the SPI bus.
 * @details This asynchronous function starts a transmit operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to send
 * @param[in] txbuf     the pointer to the transmit buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  osalDbgAssert(n < 65536, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &spip->rxsink);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CR_MINC);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Receives data from the SPI bus.
 * @details This asynchronous function starts a receive operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to receive
 * @param[out] rxbuf    the pointer to the receive buffer
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  osalDbgAssert(n < 65536, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode | AT32_DMA_CR_MINC);

  dmaStreamSetMemory0(spip->dmatx, &spip->txsource);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);

  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;

  return HAL_RET_SUCCESS;
}

/**
 * @brief   Aborts the ongoing SPI operation, if any.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[out] sizep    pointer to the counter of frames not yet transferred
 *                      or @p NULL
 * @return              The operation status.
 *
 * @notapi
 */
msg_t spi_lld_stop_transfer(SPIDriver *spip, size_t *sizep) {
  msg_t msg;

  /* Stopping everything.*/
  msg = spi_lld_stop_abort(spip);

  if (sizep != NULL) {
    *sizep = dmaStreamGetTransactionSize(spip->dmarx);
  }

  return msg;
}

/**
 * @brief   Exchanges one frame using a polled wait.
 * @details This synchronous function exchanges one frame using a polled
 *          synchronization method. This function is useful when exchanging
 *          small amount of data on high speed channels, usually in this
 *          situation is much more efficient just wait for completion using
 *          polling than suspending the thread waiting for an interrupt.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] frame     the data frame to send over the SPI bus
 * @return              The received data frame from the SPI bus.
 */
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {

  /* Enabling SPI for the exchange.*/
  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;

  spip->spi->DT = frame;
  while ((spip->spi->STS & SPI_STS_RDBF) == 0U);
  frame = spip->spi->DT;

  /* Disabling SPI and done.*/
  spip->spi->CTRL1 &= ~SPI_CTRL1_SPIEN;

  return frame;
}

#endif /* HAL_USE_SPI */

/** @} */
