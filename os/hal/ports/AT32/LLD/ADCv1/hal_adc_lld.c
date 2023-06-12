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
 * @file    AT32F415/hal_adc_lld.c
 * @brief   AT32F415 ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#if AT32_HAS_ADC1
#define ADC1_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC1_DMA_STREAM, AT32_ADC1_DMA_CHN)
#endif

#if AT32_HAS_ADC2
#define ADC2_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC2_DMA_STREAM, AT32_ADC2_DMA_CHN)
#endif

#if AT32_HAS_ADC3
#define ADC3_DMA_CHANNEL                                                    \
  AT32_DMA_GETCHANNEL(AT32_ADC_ADC3_DMA_STREAM, AT32_ADC3_DMA_CHN)
#endif
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief ADC1 driver identifier.*/
#if AT32_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/** @brief ADC2 driver identifier.*/
#if AT32_ADC_USE_ADC2 || defined(__DOXYGEN__)
ADCDriver ADCD2;
#endif

/** @brief ADC3 driver identifier.*/
#if AT32_ADC_USE_ADC3 || defined(__DOXYGEN__)
ADCDriver ADCD3;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Shared ADC DMA ISR service routine.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 * @param[in] flags     pre-shifted content of the ISR register
 */
static void adc_lld_serve_rx_interrupt(ADCDriver *adcp, uint32_t flags) {

  /* DMA errors handling.*/
  if ((flags & AT32_DMA_ISR_TEIF) != 0) {
    /* DMA, this could help only if the DMA tries to access an unmapped
       address space or violates alignment rules.*/
    _adc_isr_error_code(adcp, ADC_ERR_DMAFAILURE);
  }
  else {
    if ((flags & AT32_DMA_ISR_TCIF) != 0) {
      /* Transfer complete processing.*/
      _adc_isr_full_code(adcp);
    }
    else if ((flags & AT32_DMA_ISR_HTIF) != 0) {
      /* Half transfer processing.*/
      _adc_isr_half_code(adcp);
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void) {

#if AT32_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
  ADCD1.adc = ADC1;
  ADCD1.dmastp  = NULL;
  ADCD1.dmamode = AT32_DMA_CR_CHSEL(ADC1_DMA_CHANNEL) |
                  AT32_DMA_CR_PL(AT32_ADC_ADC1_DMA_PRIORITY) |
                  AT32_DMA_CR_MSIZE_HWORD | AT32_DMA_CR_PSIZE_HWORD |
                  AT32_DMA_CR_MINC        | AT32_DMA_CR_TCIE        |
                  AT32_DMA_CR_TEIE;

  /* Temporary activation.*/
  crmEnableADC1(true);
  ADC1->CTRL1 = 0;
  ADC1->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC1->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC1->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC1->CTRL2 = 0;
  crmDisableADC1();
#endif

#if AT32_ADC_USE_ADC2
  /* Driver initialization.*/
  adcObjectInit(&ADCD2);
  ADCD2.adc = ADC2;
  ADCD2.dmastp  = NULL;
  ADCD2.dmamode = AT32_DMA_CR_CHSEL(ADC2_DMA_CHANNEL) |
                  AT32_DMA_CR_PL(AT32_ADC_ADC2_DMA_PRIORITY) |
                  AT32_DMA_CR_MSIZE_HWORD | AT32_DMA_CR_PSIZE_HWORD |
                  AT32_DMA_CR_MINC        | AT32_DMA_CR_TCIE        |
                  AT32_DMA_CR_TEIE;

  /* Temporary activation.*/
  crmEnableADC2(true);
  ADC2->CTRL1 = 0;
  ADC2->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC2->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC2->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC2->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC2->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC2->CTRL2 = 0;
  crmDisableADC2();
#endif

#if AT32_ADC_USE_ADC3
  /* Driver initialization.*/
  adcObjectInit(&ADCD3);
  ADCD3.adc = ADC3;
  ADCD3.dmastp  = NULL;
  ADCD3.dmamode = AT32_DMA_CR_CHSEL(ADC3_DMA_CHANNEL) |
                  AT32_DMA_CR_PL(AT32_ADC_ADC3_DMA_PRIORITY) |
                  AT32_DMA_CR_MSIZE_HWORD | AT32_DMA_CR_PSIZE_HWORD |
                  AT32_DMA_CR_MINC        | AT32_DMA_CR_TCIE        |
                  AT32_DMA_CR_TEIE;

  /* Temporary activation.*/
  crmEnableADC3(true);
  ADC3->CTRL1 = 0;
  ADC3->CTRL2 = ADC_CTRL2_ADCEN;

  /* Reset calibration just to be safe.*/
  ADC3->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCALINIT;
  while ((ADC3->CTRL2 & ADC_CTRL2_ADCALINIT) != 0);

  /* Calibration.*/
  ADC3->CTRL2 = ADC_CTRL2_ADCEN | ADC_CTRL2_ADCAL;
  while ((ADC3->CTRL2 & ADC_CTRL2_ADCAL) != 0);

  /* Return the ADC in low power mode.*/
  ADC3->CTRL2 = 0;
  crmDisableADC3();
#endif
}

/**
 * @brief   Configures and activates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start(ADCDriver *adcp) {

  /* If in stopped state then enables the ADC and DMA clocks.*/
  if (adcp->state == ADC_STOP) {
#if AT32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC1_DMA_STREAM,
                                     AT32_ADC_ADC1_IRQ_PRIORITY,
                                     (at32_dmaisr_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC1->ODT);
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC1_DMAMUX_CHANNEL, AT32_DMAMUX_ADC1);
#endif
      crmEnableADC1(true);
    }
#endif

#if AT32_ADC_USE_ADC2
    if (&ADCD2 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC2_DMA_STREAM,
                                     AT32_ADC_ADC2_IRQ_PRIORITY,
                                     (at32_dmaisr_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC2->ODT);
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC2_DMAMUX_CHANNEL, AT32_DMAMUX_ADC2);
#endif
      crmEnableADC2(true);
    }
#endif

#if AT32_ADC_USE_ADC3
    if (&ADCD3 == adcp) {
      adcp->dmastp = dmaStreamAllocI(AT32_ADC_ADC3_DMA_STREAM,
                                     AT32_ADC_ADC3_IRQ_PRIORITY,
                                     (at32_dmaisr_t)adc_lld_serve_rx_interrupt,
                                     (void *)adcp);
      osalDbgAssert(adcp->dmastp != NULL, "unable to allocate stream");
      dmaStreamSetPeripheral(adcp->dmastp, &ADC3->ODT);
#if AT32_DMA_SUPPORTS_DMAMUX && AT32_DMA_USE_DMAMUX
      dmaSetRequestSource(adcp->dmastp, AT32_ADC_ADC3_DMAMUX_CHANNEL, AT32_DMAMUX_ADC3);
#endif
      crmEnableADC3(true);
    }
#endif
    /* ADC setup, the calibration procedure has already been performed
       during initialization.*/
    adcp->adc->CTRL1 = 0;
    adcp->adc->CTRL2 = 0;
  }
}

/**
 * @brief   Deactivates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop(ADCDriver *adcp) {

  /* If in ready state then disables the ADC clock.*/
  if (adcp->state == ADC_READY) {
#if AT32_ADC_USE_ADC1
    if (&ADCD1 == adcp) {
      ADC1->CTRL1 = 0;
      ADC1->CTRL2 = 0;

      dmaStreamFreeI(adcp->dmastp);
      adcp->dmastp = NULL;

      crmDisableADC1();
    }
#endif

#if AT32_ADC_USE_ADC2
    if (&ADCD2 == adcp) {
      ADC2->CTRL1 = 0;
      ADC2->CTRL2 = 0;

      dmaStreamFreeI(adcp->dmastp);
      adcp->dmastp = NULL;

      crmDisableADC2();
    }
#endif

#if AT32_ADC_USE_ADC3
    if (&ADCD3 == adcp) {
      ADC3->CTRL1 = 0;
      ADC3->CTRL2 = 0;

      dmaStreamFreeI(adcp->dmastp);
      adcp->dmastp = NULL;

      crmDisableADC3();
    }
#endif
  }
}

/**
 * @brief   Starts an ADC conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start_conversion(ADCDriver *adcp) {
  uint32_t mode, cr2;
  const ADCConversionGroup *grpp = adcp->grpp;

  /* DMA setup.*/
  mode = adcp->dmamode;
  if (grpp->circular) {
    mode |= AT32_DMA_CR_CIRC;
    if (adcp->depth > 1) {
      /* If circular buffer depth > 1, then the half transfer interrupt
         is enabled in order to allow streaming processing.*/
      mode |= AT32_DMA_CR_HTIE;
    }
  }
  dmaStreamSetMemory0(adcp->dmastp, adcp->samples);
  dmaStreamSetTransactionSize(adcp->dmastp, (uint32_t)grpp->num_channels *
                                            (uint32_t)adcp->depth);
  dmaStreamSetMode(adcp->dmastp, mode);
  dmaStreamEnable(adcp->dmastp);

  /* ADC setup.*/
  adcp->adc->CTRL1 = grpp->cr1 | ADC_CTRL1_SQEN;
  cr2 = grpp->cr2 | ADC_CTRL2_OCDMAEN | ADC_CTRL2_ADCEN;
  if ((cr2 & (ADC_CTRL2_OCTEN | ADC_CTRL2_PCTEN)) == 0)
    cr2 |= ADC_CTRL2_RPEN;
  adcp->adc->CTRL2 = grpp->cr2 | cr2;
  adcp->adc->SPT1  = grpp->smpr1;
  adcp->adc->SPT2  = grpp->smpr2;
  adcp->adc->OSQ1  = grpp->sqr1;
  adcp->adc->OSQ2  = grpp->sqr2;
  adcp->adc->OSQ3  = grpp->sqr3;

  /* ADC start by writing ADC_CTRL2_ADCEN a second time.*/
  adcp->adc->CTRL2 = cr2;
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp) {

  dmaStreamDisable(adcp->dmastp);
  adcp->adc->CTRL2 = 0;
}

#endif /* HAL_USE_ADC */

/** @} */
