/**
  **************************************************************************
  * @file     at32f415.h
  * @brief    at32f415 header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

#ifndef __AT32F415xx_H
#define __AT32F415xx_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__CC_ARM)
 #pragma anon_unions
#endif

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup AT32F415
  * @{
  */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * tip: to avoid modifying this file each time you need to switch between these
  *      devices, you can define the device in your toolchain compiler preprocessor.
  */

#if !defined (AT32F415RCT7)   && !defined (AT32F415RCT7_7) && !defined (AT32F415CCT7)   && \
    !defined (AT32F415CCU7)   && !defined (AT32F415KCU7_4) && !defined (AT32F415RBT7)   && \
    !defined (AT32F415RBT7_7) && !defined (AT32F415CBT7)   && !defined (AT32F415CBU7)   && \
    !defined (AT32F415KBU7_4) && !defined (AT32F415R8T7)   && !defined (AT32F415R8T7_7) && \
    !defined (AT32F415C8T7)   && !defined (AT32F415K8U7_4)

    #error "Please select first the target device used in your application (in at32f415.h file)"
#endif

#if defined (AT32F415RCT7)   || defined (AT32F415RCT7_7) || defined (AT32F415CCT7)   || \
    defined (AT32F415CCU7)   || defined (AT32F415KCU7_4) || defined (AT32F415RBT7)   || \
    defined (AT32F415RBT7_7) || defined (AT32F415CBT7)   || defined (AT32F415CBU7)   || \
    defined (AT32F415KBU7_4) || defined (AT32F415R8T7)   || defined (AT32F415R8T7_7) || \
    defined (AT32F415C8T7)   || defined (AT32F415K8U7_4)

    #define AT32F415xx
#endif

#if defined (AT32F415RCT7)   || defined (AT32F415RCT7_7) || defined (AT32F415RBT7)   || \
    defined (AT32F415RBT7_7) || defined (AT32F415R8T7)   || defined (AT32F415R8T7_7)

    #define AT32F415Rx
#endif

#if defined (AT32F415CCT7)   || defined (AT32F415CCU7)   || defined (AT32F415CBT7)   || \
    defined (AT32F415CBU7)   || defined (AT32F415C8T7)

    #define AT32F415Cx
#endif

#if defined (AT32F415KCU7_4) || defined (AT32F415KBU7_4) || defined (AT32F415K8U7_4)

    #define AT32F415Kx
#endif

#ifndef USE_STDPERIPH_DRIVER
/**
  * @brief comment the line below if you will not use the peripherals drivers.
  * in this case, these drivers will not be included and the application code will
  * be based on direct access to peripherals registers
  */
  #ifdef _RTE_
    #include "RTE_Components.h"
    #ifdef RTE_DEVICE_STDPERIPH_FRAMEWORK
      #define USE_STDPERIPH_DRIVER
    #endif
  #endif
#endif

/**
  * @brief at32f415 standard peripheral library version number
  */
#define __AT32F415_LIBRARY_VERSION_MAJOR    (0x02) /*!< [31:24] major version */
#define __AT32F415_LIBRARY_VERSION_MIDDLE   (0x00) /*!< [23:16] middle version */
#define __AT32F415_LIBRARY_VERSION_MINOR    (0x09) /*!< [15:8]  minor version */
#define __AT32F415_LIBRARY_VERSION_RC       (0x00) /*!< [7:0]  release candidate */
#define __AT32F415_LIBRARY_VERSION          ((__AT32F415_LIBRARY_VERSION_MAJOR << 24)  | \
                                             (__AT32F415_LIBRARY_VERSION_MIDDLE << 16) | \
                                             (__AT32F415_LIBRARY_VERSION_MINOR << 8)   | \
                                             (__AT32F415_LIBRARY_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief configuration of the cortex-m4 processor and core peripherals
  */
#define __CM4_REV                 0x0001U  /*!< core revision r0p1                           */
#define __MPU_PRESENT             1        /*!< mpu present                                  */
#define __NVIC_PRIO_BITS          4        /*!< at32 uses 4 bits for the priority levels     */
#define __Vendor_SysTickConfig    0        /*!< set to 1 if different systick config is used */
#define __FPU_PRESENT             0U       /*!< fpu present                                  */

/**
  * @brief at32f415 interrupt number definition, according to the selected device
  *        in @ref Library_configuration_section
  */
typedef enum IRQn
{
    /******  cortex-m4 processor exceptions numbers ***************************************************/
    Reset_IRQn                  = -15,    /*!< 1 reset vector, invoked on power up and warm reset   */
    NonMaskableInt_IRQn         = -14,    /*!< 2 non maskable interrupt                             */
    HardFault_IRQn              = -13,    /*!< 3 hard fault, all classes of fault                   */
    MemoryManagement_IRQn       = -12,    /*!< 4 cortex-m4 memory management interrupt              */
    BusFault_IRQn               = -11,    /*!< 5 cortex-m4 bus fault interrupt                      */
    UsageFault_IRQn             = -10,    /*!< 6 cortex-m4 usage fault interrupt                    */
    SVCall_IRQn                 = -5,     /*!< 11 cortex-m4 sv call interrupt                       */
    DebugMonitor_IRQn           = -4,     /*!< 12 cortex-m4 debug monitor interrupt                 */
    PendSV_IRQn                 = -2,     /*!< 14 cortex-m4 pend sv interrupt                       */
    SysTick_IRQn                = -1,     /*!< 15 cortex-m4 system tick interrupt                   */

    /******  at32 specific interrupt numbers *********************************************************/
    WWDT_IRQn                   = 0,      /*!< window watchdog timer interrupt                      */
    PVM_IRQn                    = 1,      /*!< pvm through exint line detection interrupt           */
    TAMP_STAMP_IRQn             = 2,      /*!< tamper and timestamp interrupts through the exint line */
    ERTC_WKUP_IRQn              = 3,      /*!< ertc wakeup through the exint line                   */
    FLASH_IRQn                  = 4,      /*!< flash global interrupt                               */
    CRM_IRQn                    = 5,      /*!< crm global interrupt                                 */
    EXINT0_IRQn                 = 6,      /*!< external line0 interrupt                             */
    EXINT1_IRQn                 = 7,      /*!< external line1 interrupt                             */
    EXINT2_IRQn                 = 8,      /*!< external line2 interrupt                             */
    EXINT3_IRQn                 = 9,      /*!< external line3 interrupt                             */
    EXINT4_IRQn                 = 10,     /*!< external line4 interrupt                             */
    DMA1_Channel1_IRQn          = 11,     /*!< dma1 channel 1 global interrupt                      */
    DMA1_Channel2_IRQn          = 12,     /*!< dma1 channel 2 global interrupt                      */
    DMA1_Channel3_IRQn          = 13,     /*!< dma1 channel 3 global interrupt                      */
    DMA1_Channel4_IRQn          = 14,     /*!< dma1 channel 4 global interrupt                      */
    DMA1_Channel5_IRQn          = 15,     /*!< dma1 channel 5 global interrupt                      */
    DMA1_Channel6_IRQn          = 16,     /*!< dma1 channel 6 global interrupt                      */
    DMA1_Channel7_IRQn          = 17,     /*!< dma1 channel 7 global interrupt                      */

    ADC1_IRQn                   = 18,     /*!< adc1 global interrupt                                */
    CAN1_TX_IRQn                = 19,     /*!< can1 tx interrupts                                   */
    CAN1_RX0_IRQn               = 20,     /*!< can1 rx0 interrupts                                  */
    CAN1_RX1_IRQn               = 21,     /*!< can1 rx1 interrupt                                   */
    CAN1_SE_IRQn                = 22,     /*!< can1 se interrupt                                    */
    EXINT9_5_IRQn               = 23,     /*!< external line[9:5] interrupts                        */
    TMR1_BRK_TMR9_IRQn          = 24,     /*!< tmr1 brake interrupt                                 */
    TMR1_OVF_TMR10_IRQn         = 25,     /*!< tmr1 overflow interrupt                              */
    TMR1_TRG_HALL_TMR11_IRQn    = 26,     /*!< tmr1 trigger and hall interrupt                      */
    TMR1_CH_IRQn                = 27,     /*!< tmr1 channel interrupt                               */
    TMR2_GLOBAL_IRQn            = 28,     /*!< tmr2 global interrupt                                */
    TMR3_GLOBAL_IRQn            = 29,     /*!< tmr3 global interrupt                                */
    TMR4_GLOBAL_IRQn            = 30,     /*!< tmr4 global interrupt                                */
    I2C1_EVT_IRQn               = 31,     /*!< i2c1 event interrupt                                 */
    I2C1_ERR_IRQn               = 32,     /*!< i2c1 error interrupt                                 */
    I2C2_EVT_IRQn               = 33,     /*!< i2c2 event interrupt                                 */
    I2C2_ERR_IRQn               = 34,     /*!< i2c2 error interrupt                                 */
    SPI1_IRQn                   = 35,     /*!< spi1 global interrupt                                */
    SPI2_IRQn                   = 36,     /*!< spi2 global interrupt                                */
    USART1_IRQn                 = 37,     /*!< usart1 global interrupt                              */
    USART2_IRQn                 = 38,     /*!< usart2 global interrupt                              */
    USART3_IRQn                 = 39,     /*!< usart3 global interrupt                              */
    EXINT15_10_IRQn             = 40,     /*!< external line[15:10] interrupts                      */
    ERTCAlarm_IRQn              = 41,     /*!< ertc alarm through exint line interrupt              */
    OTGFS1_WKUP_IRQn            = 42,     /*!< otgfs1 wakeup from suspend through exint line interrupt */
    SDIO1_IRQn                  = 49,     /*!< sdio1 global interrupt                               */
    TMR5_GLOBAL_IRQn            = 50,     /*!< tmr5 global interrupt                                */
    UART4_IRQn                  = 52,     /*!< uart4 global interrupt                               */
    UART5_IRQn                  = 53,     /*!< uart5 global interrupt                               */
    DMA2_Channel1_IRQn          = 56,     /*!< dma2 channel 1 global interrupt                      */
    DMA2_Channel2_IRQn          = 57,     /*!< dma2 channel 2 global interrupt                      */
    DMA2_Channel3_IRQn          = 58,     /*!< dma2 channel 3 global interrupt                      */
    DMA2_Channel4_5_IRQn        = 59,     /*!< dma2 channel 4 and channel 5 global interrupt        */
    OTGFS1_IRQn                 = 67,     /*!< otgfs1 global interrupt                              */
    CMP1_IRQn                   = 70,     /*!< comparator1 global interrupt                         */
    CMP2_IRQn                   = 71,     /*!< comparator2 global interrupt                         */
    DMA2_Channel6_7_IRQn        = 75,     /*!< dma2 channel 6 and channel 7 global interrupt        */

} IRQn_Type;

/**
  * @}
  */

#include "core_cm4.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */

typedef int32_t  INT32;
typedef int16_t  INT16;
typedef int8_t   INT8;
typedef uint32_t UINT32;
typedef uint16_t UINT16;
typedef uint8_t  UINT8;

typedef int32_t  s32;
typedef int16_t  s16;
typedef int8_t   s8;

typedef const int32_t sc32;   /*!< read only */
typedef const int16_t sc16;   /*!< read only */
typedef const int8_t  sc8;    /*!< read only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;    /*!< read only */
typedef __I int16_t vsc16;    /*!< read only */
typedef __I int8_t  vsc8;     /*!< read only */

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< read only */
typedef const uint16_t uc16;  /*!< read only */
typedef const uint8_t  uc8;   /*!< read only */

typedef __IO uint32_t vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;   /*!< read only */
typedef __I uint16_t vuc16;   /*!< read only */
typedef __I uint8_t  vuc8;    /*!< read only */

/**
  * @brief flag status
  */
typedef enum {RESET = 0, SET = !RESET} flag_status;

/**
  * @brief confirm state
  */
// typedef enum {FALSE = 0, TRUE = !FALSE} confirm_state;

/**
  * @brief error status
  */
typedef enum {ERROR = 0, SUCCESS = !ERROR} error_status;

/**
  * @}
  */

/** @addtogroup Exported_macro
  * @{
  */

#define REG8(addr)                       *(volatile uint8_t *)(addr)
#define REG16(addr)                      *(volatile uint16_t *)(addr)
#define REG32(addr)                      *(volatile uint32_t *)(addr)

#define MAKE_VALUE(reg_offset, bit_num)  (uint32_t)(((reg_offset) << 16) | (bit_num & 0x1F))

#define PERIPH_REG(periph_base, value)   REG32((periph_base + (value >> 16)))
#define PERIPH_REG_BIT(value)            (0x1U << (value & 0x1F))

/**
  * @}
  */
/******************  Bit definition for CRM_CTRL register  *****************/
#define CRM_CTRL_HICKEN                  (0x1U << 0)
#define CRM_CTRL_HICKSTBL                (0x1U << 1)
#define CRM_CTRL_HICKTRIM                (0x3FU << 2)
#define CRM_CTRL_HEXTEN                  (0x1U << 16)
#define CRM_CTRL_HEXTSTBL                (0x1U << 17)
#define CRM_CTRL_HEXTBYPS                (0x1U << 18)
#define CRM_CTRL_CFDEN                   (0x1U << 19)
#define CRM_CTRL_PLLEN                   (0x1U << 24)
#define CRM_CTRL_PLLSTBL                 (0x1U << 25)

/******************  Bit definition for CRM_CFG register  ******************/
#define CRM_CFG_SCLKSEL                  (0x3U << 0)
#define CRM_CFG_SCLK_HICK                (0x0U << 0)
#define CRM_CFG_SCLK_HEXT                (0x1U << 0)
#define CRM_CFG_SCLK_PLL                 (0x2U << 0)
#define CRM_CFG_SCLKSTS                  (0x3U << 2)
#define CRM_CFG_SCLKSTS_HICK             (0x0U << 2)
#define CRM_CFG_SCLKSTS_HEXT             (0x1U << 2)
#define CRM_CFG_SCLKSTS_PLL              (0x2U << 2)

/*****************  Bit definition for CRM_APB2RST register  ***************/
#define CRM_APB2RST_IOMUXRST             (0x1U << 0)
#define CRM_APB2RST_EXINTRST             (0x1U << 1)
#define CRM_APB2RST_GPIOARST             (0x1U << 2)
#define CRM_APB2RST_GPIOBRST             (0x1U << 3)
#define CRM_APB2RST_GPIOCRST             (0x1U << 4)
#define CRM_APB2RST_GPIODRST             (0x1U << 5)
#define CRM_APB2RST_GPIOFRST             (0x1U << 7)
#define CRM_APB2RST_ADC1RST              (0x1U << 9)
#define CRM_APB2RST_TMR1RST              (0x1U << 11)
#define CRM_APB2RST_SPI1RST              (0x1U << 12)
#define CRM_APB2RST_USART1RST            (0x1U << 14)
#define CRM_APB2RST_TMR9RST              (0x1U << 19)
#define CRM_APB2RST_TMR10RST             (0x1U << 20)
#define CRM_APB2RST_TMR11RST             (0x1U << 21)

/*****************  Bit definition for CRM_APB1RST register  ***************/
#define CRM_APB1RST_TMR2RST              (0x1U << 0)
#define CRM_APB1RST_TMR3RST              (0x1U << 1)
#define CRM_APB1RST_TMR4RST              (0x1U << 2)
#define CRM_APB1RST_TMR5RST              (0x1U << 3)
#define CRM_APB1RST_CMPRST               (0x1U << 9)
#define CRM_APB1RST_WWDTRST              (0x1U << 11)
#define CRM_APB1RST_SPI2RST              (0x1U << 14)
#define CRM_APB1RST_USART2RST            (0x1U << 17)
#define CRM_APB1RST_USART3RST            (0x1U << 18)
#define CRM_APB1RST_UART4RST             (0x1U << 19)
#define CRM_APB1RST_UART5RST             (0x1U << 20)
#define CRM_APB1RST_I2C1RST              (0x1U << 21)
#define CRM_APB1RST_I2C2RST              (0x1U << 22)
#define CRM_APB1RST_CANRST               (0x1U << 25)
#define CRM_APB1RST_PWCRST               (0x1U << 28)

/******************  Bit definition for CRM_AHBEN register  ****************/
#define CRM_AHBEN_DMA1EN                 (0x1U << 0)
#define CRM_AHBEN_DMA2EN                 (0x1U << 1)
#define CRM_AHBEN_SRAMEN                 (0x1U << 2)
#define CRM_AHBEN_FLASHEN                (0x1U << 4)
#define CRM_AHBEN_CRCEN                  (0x1U << 6)
#define CRM_AHBEN_SDIO1EN                (0x1U << 10)
#define CRM_AHBEN_OTGFS1EN               (0x1U << 12)

/*****************  Bit definition for CRM_APB2EN register  ****************/
#define CRM_APB2EN_IOMUXEN               (0x1U << 0)
#define CRM_APB2EN_GPIOAEN               (0x1U << 2)
#define CRM_APB2EN_GPIOBEN               (0x1U << 3)
#define CRM_APB2EN_GPIOCEN               (0x1U << 4)
#define CRM_APB2EN_GPIODEN               (0x1U << 5)
#define CRM_APB2EN_GPIOFEN               (0x1U << 7)
#define CRM_APB2EN_ADC1EN                (0x1U << 9)
#define CRM_APB2EN_TMR1EN                (0x1U << 11)
#define CRM_APB2EN_SPI1EN                (0x1U << 12)
#define CRM_APB2EN_USART1EN              (0x1U << 14)
#define CRM_APB2EN_TMR9EN                (0x1U << 19)
#define CRM_APB2EN_TMR10EN               (0x1U << 20)
#define CRM_APB2EN_TMR11EN               (0x1U << 21)

/*****************  Bit definition for CRM_APB1EN register  ****************/
#define CRM_APB1EN_TMR2EN                (0x1U << 0)
#define CRM_APB1EN_TMR3EN                (0x1U << 1)
#define CRM_APB1EN_TMR4EN                (0x1U << 2)
#define CRM_APB1EN_TMR5EN                (0x1U << 3)
#define CRM_APB1EN_CMPEN                 (0x1U << 9)
#define CRM_APB1EN_WWDTEN                (0x1U << 11)
#define CRM_APB1EN_SPI2EN                (0x1U << 14)
#define CRM_APB1EN_USART2EN              (0x1U << 17)
#define CRM_APB1EN_USART3EN              (0x1U << 18)
#define CRM_APB1EN_UART4EN               (0x1U << 19)
#define CRM_APB1EN_UART5EN               (0x1U << 20)
#define CRM_APB1EN_I2C1EN                (0x1U << 21)
#define CRM_APB1EN_I2C2EN                (0x1U << 22)
#define CRM_APB1EN_CANEN                 (0x1U << 25)
#define CRM_APB1EN_PWCEN                 (0x1U << 28)

/******************  Bit definition for CRM_BPDC register  *****************/
#define CRM_BPDC_LEXTEN                  (0x1U << 0)
#define CRM_BPDC_LEXTSTBL                (0x1U << 1)
#define CRM_BPDC_LEXTBYPS                (0x1U << 2)
#define CRM_BPDC_ERTCSEL                 (0x3U << 8)
#define CRM_BPDC_ERTCSEL_LEXT            (0x1U << 8)
#define CRM_BPDC_ERTCSEL_LICK            (0x2U << 8)
#define CRM_BPDC_ERTCSEL_HEXT_128        (0x3U << 8)
#define CRM_BPDC_ERTCEN                  (0x1U << 15)
#define CRM_BPDC_BDRST                   (0x1U << 16)

/******************  Bit definition for CRM_CTRLSTS register  **************/
#define CRM_CTRLSTS_LICKEN               (0x1U << 0)
#define CRM_CTRLSTS_LICKSTBL             (0x1U << 1)
#define CRM_CTRLSTS_RSTFC                (0x1U << 24)
#define CRM_CTRLSTS_NRSTF                (0x1U << 26)
#define CRM_CTRLSTS_PORRSTF              (0x1U << 27)
#define CRM_CTRLSTS_SWRSTF               (0x1U << 28)
#define CRM_CTRLSTS_WDTRSTF              (0x1U << 29)
#define CRM_CTRLSTS_WWDTRSTF             (0x1U << 30)
#define CRM_CTRLSTS_LPRSTF               (0x1U << 31)

/******************  Bit definition for CRM_AHBRST register  ***************/
#define CRM_AHBRST_OTGFS1RST             (0x1U << 12)

/******************  Bit definition for CRM_PLL register  ******************/
#define CRM_PLL_FREF                     (0x7U << 24)
#define CRM_PLL_FREF_4M                  (0x0U << 24)
#define CRM_PLL_FREF_6M                  (0x1U << 24)
#define CRM_PLL_FREF_8M                  (0x2U << 24)
#define CRM_PLL_FREF_12M                 (0x3U << 24)
#define CRM_PLL_FREF_16M                 (0x4U << 24)
#define CRM_PLL_FREF_25M                 (0x5U << 24)
#define CRM_PLL_PLLCFGEN                 (0x1U << 31)

/******************  Bit definition for CRM_MISC1 register  ****************/
#define CRM_MISC1_CLKFMC_SRC             (0x1U << 20)
#define CRM_MISC1_HICKDIV                (0x1U << 25)

/******************  Bit definition for CRM_OTG_EXTCTRL register  **********/
#define CRM_OTG_EXTCTRL_USBDIV_RST       (0x1U << 30)
#define CRM_OTG_EXTCTRL_EP3_RMPEN        (0x1U << 31)

/******************  Bit definition for CRM_MISC2 register  ****************/
#define CRM_MISC2_AUTO_STEP_EN           (0x3U << 4)
#define CRM_MISC2_HICK_TO_USB            (0x1U << 8)
#define CRM_MISC2_HICK_TO_SCLK           (0x1U << 9)

/******************  Bit definition for PWC_CTRL register  *****************/
#define PWC_CTRL_PVMEN                   (0x1U << 4)
#define PWC_CTRL_BPWEN                   (0x1U << 8)

/******************  Bit definition for FLASH_STS register  ****************/
#define FLASH_STS_OBF                    (0x1U << 0)
#define FLASH_STS_PRGMERR                (0x1U << 2)
#define FLASH_STS_EPPERR                 (0x1U << 4)
#define FLASH_STS_ODF                    (0x1U << 5)

/******************  Bit definition for FLASH_CTRL register  ***************/
#define FLASH_CTRL_FPRGM                 (0x1U << 0)
#define FLASH_CTRL_SECERS                (0x1U << 1)
#define FLASH_CTRL_BANKERS               (0x1U << 2)
#define FLASH_CTRL_USDPRGM               (0x1U << 4)
#define FLASH_CTRL_USDERS                (0x1U << 5)
#define FLASH_CTRL_ERSTR                 (0x1U << 6)
#define FLASH_CTRL_OPLK                  (0x1U << 7)

/******************  Bit definition for TMR_IDEN register  ****************/
#define TMR_IDEN_OVFIEN                  (0x1U << 0)
#define TMR_IDEN_C1IEN                   (0x1U << 1)
#define TMR_IDEN_C2IEN                   (0x1U << 2)
#define TMR_IDEN_C3IEN                   (0x1U << 3)
#define TMR_IDEN_C4IEN                   (0x1U << 4)
#define TMR_IDEN_TIEN                    (0x1U << 6)
#define TMR_IDEN_OVFDEN                  (0x1U << 8)
#define TMR_IDEN_C1DEN                   (0x1U << 9)
#define TMR_IDEN_C2DEN                   (0x1U << 10)
#define TMR_IDEN_C3DEN                   (0x1U << 11)
#define TMR_IDEN_C4DEN                   (0x1U << 12)
#define TMR_IDEN_TDEN                    (0x1U << 14)

/******************  Bit definition for DMA_CxCTRL register  **************/
#define DMA_CTRL_CHEN                    (0x1U << 0)
#define DMA_CTRL_FDTIEN                  (0x1U << 1)
#define DMA_CTRL_HDTIEN                  (0x1U << 2)
#define DMA_CTRL_DTERRIEN                (0x1U << 3)
#define DMA_CTRL_DTD                     (0x1U << 4)
#define DMA_CTRL_LM                      (0x1U << 5)
#define DMA_CTRL_PINCM                   (0x1U << 6)
#define DMA_CTRL_MINCM                   (0x1U << 7)
#define DMA_CTRL_PWIDTH                  (0x3U << 8)
#define DMA_CTRL_PWIDTH_8BITS            (0x0U << 8)
#define DMA_CTRL_PWIDTH_16BITS           (0x1U << 8)
#define DMA_CTRL_PWIDTH_32BITS           (0x2U << 8)
#define DMA_CTRL_MWIDTH                  (0x3U << 10)
#define DMA_CTRL_MWIDTH_8BITS            (0x0U << 10)
#define DMA_CTRL_MWIDTH_16BITS           (0x1U << 10)
#define DMA_CTRL_MWIDTH_32BITS           (0x2U << 10)
#define DMA_CTRL_CHPL                    (0x3U << 12)
#define DMA_CTRL_CHPL_LOW                (0x0U << 12)
#define DMA_CTRL_CHPL_MID                (0x1U << 12)
#define DMA_CTRL_CHPL_HIGH               (0x2U << 12)
#define DMA_CTRL_CHPL_HIGHEST            (0x3U << 12)
#define DMA_CTRL_M2M                     (0x1U << 14)

/******************  Bit definition for DMA_SRC_SEL1 register  *************/
#define DMA_SRC_SEL1_DMA_FLEX_EN         (0x1U << 24)

/******************  Bit definition for ADC_CTRL1 register  ***************/
#define ADC_CTRL1_SQEN                   (0x1U << 8)

/******************  Bit definition for ADC_CTRL2 register  ***************/
#define ADC_CTRL2_ADCEN                  (0x1U << 0)
#define ADC_CTRL2_RPEN                   (0x1U << 1)
#define ADC_CTRL2_ADCAL                  (0x1U << 2)
#define ADC_CTRL2_ADCALINIT              (0x1U << 3)
#define ADC_CTRL2_OCDMAEN                (0x1U << 8)
#define ADC_CTRL2_PCTEN                  (0x1U << 15)
#define ADC_CTRL2_OCTEN                  (0x1U << 20)

/******************  Bit definition for I2C_CTRL1 register  ***************/
#define I2C_CTRL1_I2CEN                  (0x1U << 0)
#define I2C_CTRL1_PERMODE                (0x1U << 1)
#define I2C_CTRL1_SMBMODE                (0x1U << 3)
#define I2C_CTRL1_GENSTART               (0x1U << 8)
#define I2C_CTRL1_GENSTOP                (0x1U << 9)
#define I2C_CTRL1_ACKEN                  (0x1U << 10)
#define I2C_CTRL1_RESET                  (0x1U << 15)

/******************  Bit definition for I2C_CTRL2 register  ***************/
#define I2C_CTRL2_CLKFREQ                (0xFFU << 0)
#define I2C_CTRL2_ERRIEN                 (0x1U << 8)
#define I2C_CTRL2_EVTIEN                 (0x1U << 9)
#define I2C_CTRL2_DMAEN                  (0x1U << 11)
#define I2C_CTRL2_DMAEND                 (0x1U << 12)

/******************  Bit definition for I2C_STS1 register  ****************/
#define I2C_STS1_STARTF                  (0x1U << 0)
#define I2C_STS1_ADDR7F                  (0x1U << 1)
#define I2C_STS1_TDC                     (0x1U << 2)
#define I2C_STS1_ADDRHF                  (0x1U << 3)
#define I2C_STS1_STOPF                   (0x1U << 4)
#define I2C_STS1_TDBE                    (0x1U << 7)
#define I2C_STS1_BUSERR                  (0x1U << 8)
#define I2C_STS1_ARLOST                  (0x1U << 9)
#define I2C_STS1_ACKFAIL                 (0x1U << 10)
#define I2C_STS1_OUF                     (0x1U << 11)
#define I2C_STS1_PECERR                  (0x1U << 12)
#define I2C_STS1_TMOUT                   (0x1U << 14)
#define I2C_STS1_ALERTF                  (0x1U << 15)

/******************  Bit definition for I2C_STS2 register  ****************/
#define I2C_STS2_TRMODE                  (0x1U << 0)
#define I2C_STS2_BUSYF                   (0x1U << 1)
#define I2C_STS2_DIRF                    (0x1U << 2)

/******************  Bit definition for I2C_CLKCTRL register  *************/
#define I2C_CLKCTRL_SPEED                (0xFFFU << 0)
#define I2C_CLKCTRL_DUTYMODE             (0x1U << 14)
#define I2C_CLKCTRL_SPEEDMODE            (0x1U << 15)

/*******************  Bit definition for USART_STS register  **************/
#define USART_STS_PERR                   (0x1U << 0)                   
#define USART_STS_FERR                   (0x1U << 1)                   
#define USART_STS_NERR                   (0x1U << 2)                   
#define USART_STS_ROERR                  (0x1U << 3)                   
#define USART_STS_IDLEF                  (0x1U << 4)                  
#define USART_STS_RDBF                   (0x1U << 5)
#define USART_STS_TDC                    (0x1U << 6)
#define USART_STS_TDBE                   (0x1U << 7)
#define USART_STS_BFF                    (0x1U << 8)
#define USART_STS_CTSCF                  (0x1U << 9)

/*******************  Bit definition for USART_DT register  ***************/
#define USART_DT_DT                      (0x1FF << 0)

/******************  Bit definition for USART_CTRL1 register  *************/
#define USART_CTRL1_SBF                  (0x1U << 0)
#define USART_CTRL1_RM                   (0x1U << 1)
#define USART_CTRL1_REN                  (0x1U << 2)
#define USART_CTRL1_TEN                  (0x1U << 3)
#define USART_CTRL1_IDLEIEN              (0x1U << 4)
#define USART_CTRL1_RDBFIEN              (0x1U << 5)
#define USART_CTRL1_TDCIEN               (0x1U << 6)
#define USART_CTRL1_TDBEIEN              (0x1U << 7)
#define USART_CTRL1_PERRIEN              (0x1U << 8)
#define USART_CTRL1_PSEL                 (0x1U << 9)
#define USART_CTRL1_PEN                  (0x1U << 10)
#define USART_CTRL1_WUM                  (0x1U << 11)
#define USART_CTRL1_DBN                  (0x1U << 12)
#define USART_CTRL1_UEN                  (0x1U << 13)

/******************  Bit definition for USART_CTRL2 register  *************/
#define USART_CTRL2_ID                   (0xFU << 0)
#define USART_CTRL2_BFBN                 (0x1U << 5)
#define USART_CTRL2_BFIEN                (0x1U << 6)
#define USART_CTRL2_LBCP                 (0x1U << 8)
#define USART_CTRL2_CLKPHA               (0x1U << 9)
#define USART_CTRL2_CLKPOL               (0x1U << 10)
#define USART_CTRL2_CLKEN                (0x1U << 11)
#define USART_CTRL2_STOPBN               (0x3U << 12)
#define USART_CTRL2_STOP_0               (0x1U << 12)           
#define USART_CTRL2_STOP_1               (0x1U << 13)  
#define USART_CTRL2_STOPBN_1_BITS        (0x0U << 12)
#define USART_CTRL2_STOPBN_0P5_BITS      (0x1U << 12)
#define USART_CTRL2_STOPBN_2_BITS        (0x2U << 12)
#define USART_CTRL2_STOPBN_1P5_BITS      (0x3U << 12)
#define USART_CTRL2_LINEN                (0x1U << 14)

/******************  Bit definition for USART_CTRL3 register  *************/
#define USART_CTRL3_ERRIEN               (0x1U << 0)
#define USART_CTRL3_IRDAEN               (0x1U << 1)
#define USART_CTRL3_IRDALP               (0x1U << 2)
#define USART_CTRL3_SLBEN                (0x1U << 3)
#define USART_CTRL3_SCNACKEN             (0x1U << 4)
#define USART_CTRL3_SCMEN                (0x1U << 5)
#define USART_CTRL3_DMAREN               (0x1U << 6)
#define USART_CTRL3_DMATEN               (0x1U << 7)
#define USART_CTRL3_RTSEN                (0x1U << 8)
#define USART_CTRL3_CTSEN                (0x1U << 9)
#define USART_CTRL3_CTSCFIEN             (0x1U << 10)

/*******************  Bit definition for SPI_CTRL1 register  **************/
#define SPI_CTRL1_CLKPHA                 (0x1U << 0)
#define SPI_CTRL1_CLKPOL                 (0x1U << 1)
#define SPI_CTRL1_MSTEN                  (0x1U << 2)
#define SPI_CTRL1_MDIV                   (0x7U << 3)
#define SPI_CTRL1_MDIV_2                 (0x0U << 3)
#define SPI_CTRL1_MDIV_4                 (0x1U << 3)
#define SPI_CTRL1_MDIV_8                 (0x2U << 3)
#define SPI_CTRL1_MDIV_16                (0x3U << 3)
#define SPI_CTRL1_MDIV_32                (0x4U << 3)
#define SPI_CTRL1_MDIV_64                (0x5U << 3)
#define SPI_CTRL1_MDIV_128               (0x6U << 3)
#define SPI_CTRL1_MDIV_256               (0x7U << 3)
#define SPI_CTRL1_MDIV_512               (0x0U << 3)
#define SPI_CTRL1_MDIV_1024              (0x1U << 3)
#define SPI_CTRL1_SPIEN                  (0x1U << 6)
#define SPI_CTRL1_LTF                    (0x1U << 7)
#define SPI_CTRL1_SWCSIL                 (0x1U << 8)
#define SPI_CTRL1_SWCSEN                 (0x1U << 9)
#define SPI_CTRL1_ORA                    (0x1U << 10)
#define SPI_CTRL1_FBN                    (0x1U << 11)
#define SPI_CTRL1_NTC                    (0x1U << 12)
#define SPI_CTRL1_CCEN                   (0x1U << 13)
#define SPI_CTRL1_SLBTD                  (0x1U << 14)
#define SPI_CTRL1_SLBEN                  (0x1U << 15)

/*******************  Bit definition for SPI_CTRL2 register  **************/
#define SPI_CTRL2_DMAREN                 (0x1U << 0)
#define SPI_CTRL2_DMATEN                 (0x1U << 1)
#define SPI_CTRL2_HWCSOE                 (0x1U << 2)
#define SPI_CTRL2_ERRIE                  (0x1U << 5)
#define SPI_CTRL2_RDBFIE                 (0x1U << 6)
#define SPI_CTRL2_TDBEIE                 (0x1U << 7)
#define SPI_CTRL2_MDIV                   (0x1U << 8)
#define SPI_CTRL2_MDIV_512_1024          (0x1U << 8)

/*******************  Bit definition for SPI_STS register  ********************/
#define SPI_STS_RDBF                     (0x1U << 0)
#define SPI_STS_TDBE                     (0x1U << 1)
#define SPI_STS_ACS                      (0x1U << 2)
#define SPI_STS_TUERR                    (0x1U << 3)
#define SPI_STS_CCERR                    (0x1U << 4)
#define SPI_STS_MMERR                    (0x1U << 5)
#define SPI_STS_ROERR                    (0x1U << 6)
#define SPI_STS_BF                       (0x1U << 7)

/*******************  Bit definition for SPI_I2SCTRL register  *****************/
#define SPI_I2SCTRL_I2SCBN               (0x1U << 0)
#define SPI_I2SCTRL_I2SDBN               (0x3U << 1)
#define SPI_I2SCTRL_I2SDBN_16BITS        (0x0U << 1)
#define SPI_I2SCTRL_I2SDBN_24BITS        (0x1U << 1)
#define SPI_I2SCTRL_I2SDBN_32BITS        (0x2U << 1)
#define SPI_I2SCTRL_I2SDBN_NONE          (0x3U << 1)
#define SPI_I2SCTRL_I2SCLKPOL            (0x1U << 3)
#define SPI_I2SCTRL_STDSEL               (0x3U << 4)
#define SPI_I2SCTRL_STDSEL_PHILIPS       (0x0U << 4)
#define SPI_I2SCTRL_STDSEL_MSB           (0x1U << 4)
#define SPI_I2SCTRL_STDSEL_LSB           (0x2U << 4)
#define SPI_I2SCTRL_STDSEL_PCM           (0x3U << 4)
#define SPI_I2SCTRL_PCMFSSEL             (0x1U << 7)
#define SPI_I2SCTRL_OPERSEL              (0x3U << 8)
#define SPI_I2SCTRL_OPERSEL_ST           (0x0U << 8)
#define SPI_I2SCTRL_OPERSEL_SR           (0x1U << 8)
#define SPI_I2SCTRL_OPERSEL_HT           (0x2U << 8)
#define SPI_I2SCTRL_OPERSEL_HR           (0x3U << 8)
#define SPI_I2SCTRL_I2SEN                (0x1U << 10)
#define SPI_I2SCTRL_I2SMSEL              (0x1U << 11)

/*******************  Bit definition for SPI_I2SCLKP register  ************/
#define SPI_I2SCLKP_I2SDIV_1             (0xFFU << 0)
#define SPI_I2SCLKP_I2SODD               (0x1U << 8)
#define SPI_I2SCLKP_I2SMCLKOE            (0x1U << 9)
#define SPI_I2SCLKP_I2SDIV_2             (0x3U << 10)

/******************  Bit definition for IOMUX_REMAP register  *************/
#define IOMUX_REMAP_SPI1_MUX                ((0x1U << 0) | (0x1U << 31))
#define IOMUX_REMAP_SPI1_MUX_0              (0x1U << 0)   
#define IOMUX_REMAP_SPI1_MUX_1              (0x1U << 31)
#define IOMUX_REMAP_SPI1_MUX_NOREMAP        (0x0U << 0)     /*!< CS/PA4,SCK/PA5,MISO/PA6,MOSI/PA7,MCK/PB0   */
#define IOMUX_REMAP_SPI1_MUX_FULLREMAP      (0x1U << 0)     /*!< CS/PA15,SCK/PB3,MISO/PB4,MOSI/PB5,MCK/PB6  */
#define IOMUX_REMAP_I2C1_MUX                (0x1U << 1)     /*!< SCL/PB8,SDA/PB9 SMBA/PB5                   */
#define IOMUX_REMAP_USART1_MUX              (0x1U << 2)     /*!< TX/PB6,RX/PB7                              */
#define IOMUX_REMAP_USART3_MUX              (0x3U << 4)     
#define IOMUX_REMAP_USART3_MUX_NOREMAP      (0x0U << 4)     /*!< TX/PB10,RX/PB11,CK/PB12,CTS/PB13,RTS/PB14  */
#define IOMUX_REMAP_USART3_MUX_PARTIALREMAP (0x1U << 4)     /*!< TX/PC10,RX/PC11,CK/PC12,CTS/PB13,RTS/PB14  */
#define IOMUX_REMAP_USART3_MUX_FULLREMAP    (0x2U << 4)     /*!< TX/PA7,RX/PA6,CK/PA5,CTS/PB1,RTS/PB0       */
#define IOMUX_REMAP_TMR1_MUX                (0x3U << 6)
#define IOMUX_REMAP_TMR1_MUX_NOREMAP        (0x0U << 6)     /*!< EXT/PA12,CH1/PA8,CH2/PA9,CH3/PA10,CH4/PA11,BRK/PB12,CH1C/PB13,CH2C/PB14,CH3C/PB15*/
#define IOMUX_REMAP_TMR1_MUX_FULLREMAP      (0x1U << 6)     /*!< EXT/PA12,CH1/PA8,CH2/PA9,CH3/PA10,CH4/PA11,BRK/PA6,CH1C/PA7,CH2C/PB0,CH3C/PB1*/
#define IOMUX_REMAP_TMR2_MUX                (0x3U << 8)     
#define IOMUX_REMAP_TMR2_MUX_NOREMAP        (0x0U << 8)     /*!< CH1/EXT/PA0,CH2/PA1,CH3/PA2,CH4/PA3 */
#define IOMUX_REMAP_TMR2_MUX_PARTIALREMAP1  (0x1U << 8)     /*!< CH1/EXT/PA15,CH2/PB3,CH3/PA2,CH4/PA3 */
#define IOMUX_REMAP_TMR2_MUX_PARTIALREMAP2  (0x2U << 8)     /*!< CH1/EXT/PA0,CH2/PA1,CH3/PB10,CH4/PB1 */
#define IOMUX_REMAP_TMR2_MUX_FULLREMAP      (0x3U << 8)     /*!< CH1/EXT/PA15,CH2/PB3,CH3/PB10,CH4/PB11 */
#define IOMUX_REMAP_TMR3_MUX                (0x3U << 10)
#define IOMUX_REMAP_TMR3_MUX_NOREMAP        (0x0U << 10)    /*!< CH1/PA6,CH2/PA7,CH3/PB0,CH4/PB1 */
#define IOMUX_REMAP_TMR3_MUX_PARTIALREMAP   (0x2U << 10)    /*!< CH1/PB4,CH2/PB5,CH3/PB0,CH4/PB1 */
#define IOMUX_REMAP_TMR3_MUX_FULLREMAP      (0x3U << 10)    /*!< CH1/PC6,CH2/PC7,CH3/PC8,CH4/PC9 */
#define IOMUX_REMAP_CAN_MUX                 (0x3U << 13)    
#define IOMUX_REMAP_CAN_MUX_NOREMAP         (0x0U << 13)    /*!< RX/PA11,TX/PA12 */
#define IOMUX_REMAP_CAN_MUX_FULLREMAP       (0x2U << 13)    /*!< RX/PB8,TX/PB9 */
#define IOMUX_REMAP_PD01_MUX                (0x1U << 15)    /*!< Port D0/Port D1 mapping on HEXT_IN/HEXT_OUT */
#define IOMUX_REMAP_TMR5CH4_MUX             (0x1U << 16)    /*!< TIM5 Channel4 Internal Remap */
#define IOMUX_REMAP_ADC1_ETP_MUX            (0x1U << 17)    /*!< ADC 1 External Trigger Injected Conversion remapping */
#define IOMUX_REMAP_ADC1_ETO_MUX            (0x1U << 18)    /*!< ADC 1 External Trigger Regular Conversion remapping */
#define IOMUX_REMAP_SWJTAG_MUX              (0x7U << 24)  
#define IOMUX_REMAP_SWJTAG_MUX_RESET        (0x0U << 24)    /*!< Full SWJ (JTAG-DP + SW-DP) : Reset State */
#define IOMUX_REMAP_SWJTAG_MUX_NOJNTRST     (0x1U << 24)    /*!< Full SWJ (JTAG-DP + SW-DP) but without JNTRST */
#define IOMUX_REMAP_SWJTAG_MUX_JTAGDISABLE  (0x2U << 24)    /*!< JTAG-DP Disabled and SW-DP Enabled */
#define IOMUX_REMAP_SWJTAG_MUX_DISABLE      (0x4U << 24)    /*!< JTAG-DP Disabled and SW-DP Disabled */

/******************  Bit definition for IOMUX_REMAP2 register  ************/
#define IOMUX_REMAP2_CMP_MUX                (0x3U << 26)
#define IOMUX_REMAP2_CMP_MUX_NOREMAP        (0x0U << 26)    /*!< CMP1_OUT/PA0,CMP2_OUT/PA2 */
#define IOMUX_REMAP2_CMP_MUX_PARTIALREMAP2  (0x1U << 26)    /*!< CMP1_OUT/PA6,CMP2_OUT/PA7 */
#define IOMUX_REMAP2_CMP_MUX_FULLREMAP      (0x2U << 26)    /*!< CMP1_OUT/PA11,CMP2_OUT/PA12 */

/******************  Bit definition for IOMUX_REMAP3 register  ************/
#define IOMUX_REMAP3_TMR9_GMUX              (0xFU << 0)
#define IOMUX_REMAP3_TMR9_GMUX_NOREMAP      (0x0U << 0)     /*!< TMR9 CH1/PA2 CH2/PA3 */
#define IOMUX_REMAP3_TMR9_GMUX_FULLREMAP    (0x2U << 0)     /*!< TMR9 CH1/PB14 CH2/PB15 */
#define IOMUX_REMAP3_TMR10_GMUX             (0xFU << 4)
#define IOMUX_REMAP3_TMR10_GMUX_NOREMAP     (0x0U << 4)     /*!< TMR10 CH1/PB8 */
#define IOMUX_REMAP3_TMR10_GMUX_FULLREMAP   (0x2U << 4)     /*!< TMR10 CH1/PA6 */
#define IOMUX_REMAP3_TMR11_GMUX             (0xFU << 8)
#define IOMUX_REMAP3_TMR11_GMUX_NOREMAP     (0x0U << 8)     /*!< TMR11 CH1/PB9 */
#define IOMUX_REMAP3_TMR11_GMUX_FULLREMAP   (0x2U << 8)     /*!< TMR11 CH1/PA7 */

/******************  Bit definition for IOMUX_REMAP4 register  ************/
#define IOMUX_REMAP4_TMR1_GMUX               (0xFU << 0)
#define IOMUX_REMAP4_TMR1_GMUX_NOREMAP       (0x0U << 0)    /*!< TMR1 EXT/PA12,CH1/PA8,CH2/PA9,CH3/PA10,CH4/PA11,BRK/PB12,CH1C/PB13,CH2C/PB14,CH3C/PB15 */
#define IOMUX_REMAP4_TMR1_GMUX_PARTIALREMAP1 (0x1U << 0)    /*!< TMR1 EXT/PA12,CH1/PA8,CH2/PA9,CH3/PA10,CH4/PA11,BRK/PA6,CH1C/PA7,CH2C/PB0,CH3C/PB1 */
#define IOMUX_REMAP4_TMR1_GMUX_FULLREMAP     (0x2U << 0)    /*!< TMR1 EXT/PA0,CH1/PC6,CH2/PC7,CH3/PC8,CH4/PC9,BRK/PA6,CH1C/PA7,CH2C/PB0,CH3C/PB1 */
#define IOMUX_REMAP4_TMR2_GMUX               (0x7U << 4)
#define IOMUX_REMAP4_TMR2_GMUX_NOREMAP       (0x0U << 4)    /*!< TMR2 CH1_EXT/PA0 CH2/PA1 CH3/PA2 CH4/PA3 */
#define IOMUX_REMAP4_TMR2_GMUX_PARTIALREMAP1 (0x1U << 4)    /*!< TMR2 CH1_EXT/PA15 CH2/PB3 CH3/PA2 CH4/PA3 */
#define IOMUX_REMAP4_TMR2_GMUX_PARTIALREMAP2 (0x2U << 4)    /*!< TMR2 CH1_EXT/PA0 CH2/PA1 CH3/PB10 CH4/PB11 */
#define IOMUX_REMAP4_TMR2_GMUX_FULLREMAP     (0x3U << 4)    /*!< TMR2 CH1_EXT/PA15 CH2/PB3 CH3/PB10 CH4/PB11 */
#define IOMUX_REMAP4_TMR3_GMUX               (0xFU << 8)
#define IOMUX_REMAP4_TMR3_GMUX_NOREMAP       (0x0U << 8)    /*!< TMR3 CH1/PA6 CH2/PA7 CH3/PB0 CH4/PB1 */
#define IOMUX_REMAP4_TMR3_GMUX_PARTIALREMAP  (0x2U << 8)    /*!< TMR3 CH1/PB4 CH2/PB5 CH3/PB0 CH4/PB1 */
#define IOMUX_REMAP4_TMR3_GMUX_FULLREMAP     (0x3U << 8)    /*!< TMR3 CH1/PC6 CH2/PC7 CH3/PC8 CH4/PC9 */
#define IOMUX_REMAP4_TMR5_GMUX               (0x7U << 16)
#define IOMUX_REMAP4_TMR5_GMUX_NOREMAP       (0x0U << 16)   /*!< TMR5 CH1/PA0 CH2/PA1 CH3/PA2 CH4/PA3 */
#define IOMUX_REMAP4_TMR5_GMUX_FULLREMAP     (0x1U << 16)   /*!< TMR5 CH1/PF4 CH2/PF5 CH3/PA2 CH4/PA3 */
#define IOMUX_REMAP4_TMR5CH4_GMUX            (0x1U << 19)
#define IOMUX_REMAP4_TMR5CH4_GMUX_NOREMAP    (0x0U << 19)   /*!< TMR5 CH4/PA3 */
#define IOMUX_REMAP4_TMR5CH4_GMUX_FULLREMAP  (0x1U << 19)   /*!< TMR5 CH4/LICK */

/******************  Bit definition for IOMUX_REMAP5 register  ************/
#define IOMUX_REMAP5_I2C1_GMUX               (0xFU << 4)
#define IOMUX_REMAP5_I2C1_GMUX_NOREMAP       (0x0U << 4)    /*!< SCL/PB6,SDA/PB7 SMBA/PB5 */
#define IOMUX_REMAP5_I2C1_GMUX_PARTIALREMAP  (0x1U << 4)    /*!< SCL/PB8,SDA/PB9 SMBA/PB5 */
#define IOMUX_REMAP5_I2C1_GMUX_FULLREMAP     (0x2U << 4)    /*!< SCL/PF6,SDA/PF7 SMBA/PB5 */
#define IOMUX_REMAP5_I2C2_GMUX               (0xFU << 8)
#define IOMUX_REMAP5_I2C2_GMUX_NOREMAP       (0x0U << 8)    /*!< SCL/PB10,SDA/PB11 SMBA/PB12 */
#define IOMUX_REMAP5_I2C2_GMUX_PARTIALREMAP1 (0x1U << 8)    /*!< SCL/PA8,SDA/PC9 SMBA/PA9 */
#define IOMUX_REMAP5_I2C2_GMUX_PARTIALREMAP2 (0x2U << 8)    /*!< SCL/PA8,SDA/PB4 SMBA/PA9 */
#define IOMUX_REMAP5_I2C2_GMUX_FULLREMAP     (0x3U << 8)    /*!< SCL/PF6,SDA/PF7 SMBA/PA9 */
#define IOMUX_REMAP5_SPI1_GMUX               (0xFU << 16)
#define IOMUX_REMAP5_SPI1_GMUX_NOREMAP       (0x0U << 16)   /*!< CS/PA4,SCK/PA5,MISO/PA6,MOSI/PA7,MCK/PB0 */
#define IOMUX_REMAP5_SPI1_GMUX_FULLREMAP     (0x1U << 16)   /*!< CS/PA15,SCK/PB3,MISO/PB4,MOSI/PB5,MCK/PB6 */
#define IOMUX_REMAP5_SPI2_GMUX               (0xFU << 20)
#define IOMUX_REMAP5_SPI2_GMUX_NOREMAP       (0x0U << 20)   /*!< CS/PB12,SCK/PB13,MISO/PB14,MOSI/PB15,MCK/PB0 */
#define IOMUX_REMAP5_SPI2_GMUX_FULLREMAP     (0x1U << 20)   /*!< CS/PA15,SCK/PB3,MISO/PB4,MOSI/PB5,MCK/PC7 */

/******************  Bit definition for IOMUX_REMAP6 register  ************/
#define IOMUX_REMAP6_CAN1_GMUX                (0xFU << 0)
#define IOMUX_REMAP6_CAN1_GMUX_NOREMAP        (0x0U << 0)    /*!< RX/PA11,TX/PA12 */
#define IOMUX_REMAP6_CAN1_GMUX_FULLREMAP      (0x2U << 0)    /*!< RX/PB8,TX/PB9   */
#define IOMUX_REMAP6_SDIO1_GMUX               (0xFU << 8)
#define IOMUX_REMAP6_SDIO1_GMUX_NOREMAP       (0x0U << 8)    /*!< D0/PC8 D1/PC9 D2/PC10 D3/PC11 D4/PB8 D5/PB9 D6/PC6 D7/PC7 CK/PC12 CMD/PD2 */
#define IOMUX_REMAP6_SDIO1_GMUX_PARTIALREMAP1 (0x4U << 8)    /*!< D0/PC0 D1/PC1 D2/PC2 D3/PC3 D4/PA4 D5/PA5 D6/PA6 D7/PA7 CK/PC4 CMD/PC5 */
#define IOMUX_REMAP6_SDIO1_GMUX_PARTIALREMAP2 (0x5U << 8)    /*!< D0/PA4 D1/PA5 D2/PA6 D3/PA7 CK/PC4 CMD/PC5 */
#define IOMUX_REMAP6_SDIO1_GMUX_PARTIALREMAP3 (0x6U << 8)    /*!< D0/PC0 D1/PC1 D2/PC2 D3/PC3 D4/PA4 D5/PA5 D6/PA6 D7/PA7 CK/PA2 CMD/PA3 */
#define IOMUX_REMAP6_SDIO1_GMUX_FULLREMAP     (0x7U << 8)    /*!< D0/PA4 D1/PA5 D2/PA6 D3/PA7 CK/PA2 CMD/PA3 */
#define IOMUX_REMAP6_USART1_GMUX              (0xFU << 16)
#define IOMUX_REMAP6_USART1_GMUX_NOREMAP      (0x0U << 16)   /*!< TX/PA9 RX/PA10  */
#define IOMUX_REMAP6_USART1_GMUX_FULLREMAP    (0x1U << 16)   /*!< TX/PB6 RX/PB7   */
#define IOMUX_REMAP6_USART3_GMUX              (0xFU << 24)
#define IOMUX_REMAP6_USART3_GMUX_NOREMAP      (0x0U << 24)   /*!< TX/PB10,RX/PB11,CK/PB12,CTS/PB13,RTS/PB14  */
#define IOMUX_REMAP6_USART3_GMUX_PARTIALREMAP (0x1U << 24)   /*!< TX/PC10,RX/PC11,CK/PC12,CTS/PB13,RTS/PB14  */
#define IOMUX_REMAP6_USART3_GMUX_FULLREMAP    (0x2U << 24)   /*!< TX/PA7,RX/PA6,CK/PA5,CTS/PB1,RTS/PB0  */
#define IOMUX_REMAP6_UART4_GMUX               (0xFU << 28)
#define IOMUX_REMAP6_UART4_GMUX_NOREMAP       (0x0U << 28)   /*!< TX/PC10 RX/PC11  */
#define IOMUX_REMAP6_UART4_GMUX_FULLREMAP     (0x2U << 28)   /*!< TX/PF4 RX/PF5    */

/******************  Bit definition for IOMUX_REMAP7 register  ************/
#define IOMUX_REMAP7_ADC1_ETP_GMUX            (0x1U << 4)
#define IOMUX_REMAP7_ADC1_ETP_GMUX_NOREMAP    (0x0U << 4)    
#define IOMUX_REMAP7_ADC1_ETP_GMUX_FULLREMAP  (0x1U << 4)    /*!< ADC1 抢占转换外部触发连接到 TMR1 通道 4 */
#define IOMUX_REMAP7_ADC1_ETO_GMUX            (0x1U << 5)
#define IOMUX_REMAP7_ADC1_ETO_GMUX_NOREMAP    (0x0U << 5)    /*!< ADC1 普通转换外部触发连接到 EXINT11 */
#define IOMUX_REMAP7_ADC1_ETO_GMUX_FULLREMAP  (0x1U << 5)    /*!< ADC1 普通转换外部触发连接到 TMR1_TRGO */
#define IOMUX_REMAP7_SWJTAG_GMUX              (0x7U << 16)  
#define IOMUX_REMAP7_SWJTAG_GMUX_RESET        (0x0U << 16)   /*!< Full SWJ (JTAG-DP + SW-DP) : Reset State */
#define IOMUX_REMAP7_SWJTAG_GMUX_NOJNTRST     (0x1U << 16)   /*!< Full SWJ (JTAG-DP + SW-DP) but without JNTRST */
#define IOMUX_REMAP7_SWJTAG_GMUX_JTAGDISABLE  (0x2U << 16)   /*!< JTAG-DP Disabled and SW-DP Enabled */
#define IOMUX_REMAP7_SWJTAG_GMUX_DISABLE      (0x4U << 16)   /*!< JTAG-DP Disabled and SW-DP Disabled */
#define IOMUX_REMAP7_PD01_GMUX                (0x1U << 20)   /*!< Port D0/Port D1 mapping on HEXT_IN/HEXT_OUT */
#define IOMUX_REMAP7_PD01_GMUX_NOREMAP        (0x0U << 20)   /*!< NO REMAP */
#define IOMUX_REMAP7_PD01_GMUX_FULLREMAP      (0x1U << 20)   /*!< Port D0/Port D1 mapping on HEXT_IN/HEXT_OUT */

/******************  Bit definition for DEBUG_CTRL register  **************/
#define DEBUG_CTRL_SLEEP                 (0x1U << 0)
#define DEBUG_CTRL_DEEPSLEEP             (0x1U << 1)
#define DEBUG_CTRL_STANDBY               (0x1U << 2)
#define DEBUG_CTRL_WDT_PAUSE             (0x1U << 8)
#define DEBUG_CTRL_WWDT_PAUSE            (0x1U << 9)
#define DEBUG_CTRL_TMR1_PAUSE            (0x1U << 10)
#define DEBUG_CTRL_TMR2_PAUSE            (0x1U << 11)
#define DEBUG_CTRL_TMR3_PAUSE            (0x1U << 12)
#define DEBUG_CTRL_TMR4_PAUSE            (0x1U << 13)
#define DEBUG_CTRL_CAN1_PAUSE            (0x1U << 14)
#define DEBUG_CTRL_I2C1_SMBUS_TIMEOUT    (0x1U << 15)
#define DEBUG_CTRL_I2C2_SMBUS_TIMEOUT    (0x1U << 16)
#define DEBUG_CTRL_TMR5_PAUSE            (0x1U << 18)
#define DEBUG_CTRL_TMR9_PAUSE            (0x1U << 28)
#define DEBUG_CTRL_TMR10_PAUSE           (0x1U << 29)
#define DEBUG_CTRL_TMR11_PAUSE           (0x1U << 30)

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE                       ((uint32_t)0x08000000)
#define SPIM_FLASH_BASE                  ((uint32_t)0x08400000)
#define USD_BASE                         ((uint32_t)0x1FFFF800)
#define SRAM_BASE                        ((uint32_t)0x20000000)
#define PERIPH_BASE                      ((uint32_t)0x40000000)
#define DEBUG_BASE                       ((uint32_t)0xE0042000)

#define APB1PERIPH_BASE                  (PERIPH_BASE + 0x00000)
#define APB2PERIPH_BASE                  (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE                   (PERIPH_BASE + 0x20000)

/* apb1 bus base address */
#define TMR2_BASE                        (APB1PERIPH_BASE + 0x0000)
#define TMR3_BASE                        (APB1PERIPH_BASE + 0x0400)
#define TMR4_BASE                        (APB1PERIPH_BASE + 0x0800)
#define TMR5_BASE                        (APB1PERIPH_BASE + 0x0C00)
#define CMP_BASE                         (APB1PERIPH_BASE + 0x2400)
#define ERTC_BASE                        (APB1PERIPH_BASE + 0x2800)
#define WWDT_BASE                        (APB1PERIPH_BASE + 0x2C00)
#define WDT_BASE                         (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE                        (APB1PERIPH_BASE + 0x3800)
#define USART2_BASE                      (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE                      (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE                       (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE                       (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE                        (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE                        (APB1PERIPH_BASE + 0x5800)
#define CAN1_BASE                        (APB1PERIPH_BASE + 0x6400)
#define PWC_BASE                         (APB1PERIPH_BASE + 0x7000)
/* apb2 bus base address */
#define IOMUX_BASE                       (APB2PERIPH_BASE + 0x0000)
#define EXINT_BASE                       (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE                       (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE                       (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE                       (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE                       (APB2PERIPH_BASE + 0x1400)
#define GPIOF_BASE                       (APB2PERIPH_BASE + 0x1C00)
#define ADC1_BASE                        (APB2PERIPH_BASE + 0x2400)
#define TMR1_BASE                        (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE                        (APB2PERIPH_BASE + 0x3000)
#define USART1_BASE                      (APB2PERIPH_BASE + 0x3800)
#define TMR9_BASE                        (APB2PERIPH_BASE + 0x4C00)
#define TMR10_BASE                       (APB2PERIPH_BASE + 0x5000)
#define TMR11_BASE                       (APB2PERIPH_BASE + 0x5400)
#define SDIO1_BASE                       (APB2PERIPH_BASE + 0x8000)
/* ahb bus base address */
#define DMA1_BASE                        (AHBPERIPH_BASE + 0x0000)
#define DMA1_CHANNEL1_BASE               (AHBPERIPH_BASE + 0x0008)
#define DMA1_CHANNEL2_BASE               (AHBPERIPH_BASE + 0x001C)
#define DMA1_CHANNEL3_BASE               (AHBPERIPH_BASE + 0x0030)
#define DMA1_CHANNEL4_BASE               (AHBPERIPH_BASE + 0x0044)
#define DMA1_CHANNEL5_BASE               (AHBPERIPH_BASE + 0x0058)
#define DMA1_CHANNEL6_BASE               (AHBPERIPH_BASE + 0x006C)
#define DMA1_CHANNEL7_BASE               (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE                        (AHBPERIPH_BASE + 0x0400)
#define DMA2_CHANNEL1_BASE               (AHBPERIPH_BASE + 0x0408)
#define DMA2_CHANNEL2_BASE               (AHBPERIPH_BASE + 0x041C)
#define DMA2_CHANNEL3_BASE               (AHBPERIPH_BASE + 0x0430)
#define DMA2_CHANNEL4_BASE               (AHBPERIPH_BASE + 0x0444)
#define DMA2_CHANNEL5_BASE               (AHBPERIPH_BASE + 0x0458)
#define DMA2_CHANNEL6_BASE               (AHBPERIPH_BASE + 0x046C)
#define DMA2_CHANNEL7_BASE               (AHBPERIPH_BASE + 0x0480)
#define CRM_BASE                         (AHBPERIPH_BASE + 0x1000)
#define FLASH_REG_BASE                   (AHBPERIPH_BASE + 0x2000)
#define CRC_BASE                         (AHBPERIPH_BASE + 0x3000)
#define OTGFS1_BASE                      (PERIPH_BASE + 0x10000000)

#define FLASHSIZE_BASE                   ((uint32_t)0x1FFFF7E0U)    /*!< FLASH Size register base address */
#define UID_BASE                         ((uint32_t)0x1FFFF7E8U)    /*!< Unique device ID register base address */

/**
  * @}
  */
/**
  * @brief type define exint register all
  */
typedef struct
{

  /**
    * @brief exint inten register, offset:0x00
    */
  __IO uint32_t INTEN;

  /**
    * @brief exint evten register, offset:0x04
    */
  __IO uint32_t EVTEN;

  /**
    * @brief exint polcfg1 register, offset:0x08
    */
  __IO uint32_t POLCFG1;

  /**
    * @brief exint polcfg2 register, offset:0x0C
    */
  __IO uint32_t POLCFG2;

  /**
    * @brief exint swtrg register, offset:0x10
    */
  __IO uint32_t SWTRG;

  /**
    * @brief exint intsts register, offset:0x14
    */
  __IO uint32_t INTSTS;

} EXINT_TypeDef;

/**
  * @brief type define crm register all
  */
typedef struct
{
  /**
    * @brief crm ctrl register, offset:0x00
    */
  __IO uint32_t CTRL;

  /**
    * @brief crm cfg register, offset:0x04
    */
  __IO uint32_t CFG;

  /**
    * @brief crm clkint register, offset:0x08
    */
  __IO uint32_t CLKINT;

  /**
    * @brief crm apb2rst register, offset:0x0C
    */
  __IO uint32_t APB2RST;
  
  /**
    * @brief crm apb1rst register, offset:0x10
    */
  __IO uint32_t APB1RST;
    
  /**
    * @brief crm ahben register, offset:0x14
    */
  __IO uint32_t AHBEN;

  /**
    * @brief crm apb2en register, offset:0x18
    */
  __IO uint32_t APB2EN;

  /**
    * @brief crm apb1en register, offset:0x1C
    */
  __IO uint32_t APB1EN;
  
  /**
    * @brief crm bpdc register, offset:0x20
    */
  __IO uint32_t BPDC;
  
  /**
    * @brief crm ctrlsts register, offset:0x24
    */
  __IO uint32_t CTRLSTS;

  /**
    * @brief crm ahbrst register, offset:0x28
    */
  __IO uint32_t AHBRST;

  /**
    * @brief crm pll register, offset:0x2C
    */
  __IO uint32_t PLL;

  /**
    * @brief crm misc1 register, offset:0x30
    */
  __IO uint32_t MISC1;

  /**
    * @brief crm reserved2 register, offset:0x40~0x34
    */
  __IO uint32_t RESERVED2[4];

  /**
    * @brief crm otg_extctrl register, offset:0x44
    */
  __IO uint32_t OTG_EXTCTRL;

  /**
    * @brief crm reserved3 register, offset:0x50~0x48
    */
  __IO uint32_t RESERVED3[3];

  /**
    * @brief crm misc2 register, offset:0x54
    */
  __IO uint32_t MISC2;

} CRM_TypeDef;

/**
  * @brief type define pwc register all
  */
typedef struct
{
  /**
    * @brief pwc ctrl register, offset:0x00
    */
  __IO uint32_t CTRL;

  /**
    * @brief pwc ctrlsts register, offset:0x04
    */
  __IO uint32_t CTRLSTS;

} PWC_TypeDef;

/**
  * @brief type define flash register all
  */
typedef struct
{
  /**
    * @brief flash psr register, offset:0x00
    */
  __IO uint32_t PSR;

  /**
    * @brief flash unlock register, offset:0x04
    */
  __IO uint32_t UNLOCK;

  /**
    * @brief flash usd unlock register, offset:0x08
    */
  __IO uint32_t USD_UNLOCK;

  /**
    * @brief flash sts register, offset:0x0C
    */
  __IO uint32_t STS;

  /**
    * @brief flash ctrl register, offset:0x10
    */
  __IO uint32_t CTRL;

  /**
    * @brief flash addr register, offset:0x14
    */
  __IO uint32_t ADDR;

  /**
    * @brief flash reserved1 register, offset:0x18
    */
  __IO uint32_t RESERVED1;

  /**
    * @brief flash usd register, offset:0x1C
    */
  __IO uint32_t USD;

  /**
    * @brief flash epps register, offset:0x20
    */
  __IO uint32_t EPPS;

  /**
    * @brief flash reserved2 register, offset:0x70~0x24
    */
  __IO uint32_t RESERVED2[20];

  /**
    * @brief flash slib_sts0 register, offset:0x74
    */
  __IO uint32_t SLIB_STS0;

  /**
    * @brief flash slib_sts1 register, offset:0x78
    */
  __IO uint32_t SLIB_STS1;

  /**
    * @brief flash slib_pwd_clr register, offset:0x7C
    */
  __IO uint32_t SLIB_PWD_CLR;

  /**
    * @brief flash slib_misc_sts register, offset:0x80
    */
  __IO uint32_t SLIB_MISC_STS;

  /**
    * @brief flash crc_addr register, offset:0x84
    */
  __IO uint32_t CRC_ADDR;

  /**
    * @brief flash crc_ctrl register, offset:0x88
    */
  __IO uint32_t CRC_CTRL;

  /**
    * @brief flash crc_chkr register, offset:0x8C
    */
  __IO uint32_t CRC_CHKR;

  /**
    * @brief flash reserved3 register, offset:0x15C~0x90
    */
  __IO uint32_t RESERVED3[52];

  /**
    * @brief flash slib_set_pwd register, offset:0x160
    */
  __IO uint32_t SLIB_SET_PWD;

  /**
    * @brief flash slib_set_range register, offset:0x164
    */
  __IO uint32_t SLIB_GET_RANGE;

  /**
    * @brief flash em_slib_set register, offset:0x168
    */
  __IO uint32_t EM_SLIB_SET;

  /**
    * @brief flash btm_mode_set register, offset:0x16C
    */
  __IO uint32_t BTM_MODE_SET;

  /**
    * @brief flash slib_unlock register, offset:0x170
    */
  __IO uint32_t SLIB_UNLOCK;

} FLASH_TypeDef;

/**
  * @brief type define gpio register all
  */
typedef struct
{
  /**
    * @brief gpio cfglr register, offset:0x00
    */
  __IO uint32_t CFGLR;

  /**
    * @brief gpio cfghr register, offset:0x04
    */
  __IO uint32_t CFGHR;

  /**
    * @brief gpio idt register, offset:0x08
    */
  __IO uint32_t IDT;

  /**
    * @brief gpio odt register, offset:0x0C
    */
  __IO uint32_t ODT;

  /**
    * @brief gpio scr register, offset:0x10
    */
  __IO uint32_t SCR;

  /**
    * @brief gpio clr register, offset:0x14
    */
  __IO uint32_t CLR;
  /**
    * @brief gpio wpr register, offset:0x18
    */
  __IO uint32_t WPR;

} GPIO_TypeDef;

/**
  * @brief type define iomux register all
  */
typedef struct
{
  /**
    * @brief mux event control register, offset:0x00
    */
  __IO uint32_t EVTOUT;

  /**
    * @brief iomux remap register, offset:0x04
    */
  __IO uint32_t REMAP;

  /**
    * @brief mux external interrupt configuration register 1-3, offset:0x08
    */
  __IO uint32_t EXINTC[4];

  /**
    * @brief iomux reserved1 register, offset:0x18
    */
  __IO uint32_t RESERVED1;

  /**
    * @brief iomux remap register 2, offset:0x1C
    */
  __IO uint32_t REMAP2;

  /**
    * @brief iomux remap register 3, offset:0x20
    */
  __IO uint32_t REMAP3;

  /**
    * @brief iomux remap register 4, offset:0x24
    */
  __IO uint32_t REMAP4;

  /**
    * @brief iomux remap register 5, offset:0x28
    */
  __IO uint32_t REMAP5;

  /**
    * @brief iomux remap register 6, offset:0x2C
    */
  __IO uint32_t REMAP6;

  /**
    * @brief iomux remap register 7, offset:0x30
    */
  __IO uint32_t REMAP7;

  /**
    * @brief iomux remap register 8, offset:0x34
    */
  __IO uint32_t REMAP8;
} IOMUX_TypeDef;

/**
  * @brief type define tmr register all
  */
typedef struct
{
  /**
    * @brief tmr ctrl1 register, offset:0x00
    */
  __IO uint32_t CTRL1;

  /**
    * @brief tmr ctrl2 register, offset:0x04
    */
  __IO uint32_t CTRL2;

  /**
    * @brief tmr smc register, offset:0x08
    */
  __IO uint32_t STCTRL;

  /**
    * @brief tmr die register, offset:0x0C
    */
  __IO uint32_t IDEN;

  /**
    * @brief tmr ists register, offset:0x10
    */
  __IO uint32_t ISTS;

  /**
    * @brief tmr eveg register, offset:0x14
    */
  __IO uint32_t SWEVT;

  /**
    * @brief tmr ccm1 register, offset:0x18
    */
  __IO uint32_t CM1;

  /**
    * @brief tmr ccm2 register, offset:0x1C
    */
  __IO uint32_t CM2;

  /**
    * @brief tmr cce register, offset:0x20
    */
  __IO  uint32_t CCTRL;

  /**
    * @brief tmr cnt register, offset:0x24
    */
  __IO uint32_t CVAL;

  /**
    * @brief tmr div, offset:0x28
    */
  __IO uint32_t DIV;

  /**
    * @brief tmr pr register, offset:0x2C
    */
  __IO  uint32_t PR;

  /**
    * @brief tmr rpr register, offset:0x30
    */
  __IO uint32_t RPR;

  /**
    * @brief tmr c1dt register, offset:0x34
    */
  __IO uint32_t C1DT;


  /**
    * @brief tmr c2dt register, offset:0x38
    */
  __IO uint32_t C2DT;

  /**
    * @brief tmr c3dt register, offset:0x3C
    */
  __IO uint32_t C3DT;

  /**
    * @brief tmr c4dt register, offset:0x40
    */
  __IO uint32_t C4DT;

  /**
    * @brief tmr brk register, offset:0x44
    */
  __IO uint32_t BRK;

  /**
    * @brief tmr dmactrl register, offset:0x48
    */
  __IO uint32_t DMACTRL;

  /**
    * @brief tmr dmadt register, offset:0x4C
    */
  __IO uint32_t DMADT;

} TMR_TypeDef;

/**
  * @brief type define debug register all
  */
typedef struct
{
  /**
    * @brief debug idcode register, offset:0x00
    */
  __IO uint32_t IDCODE;

  /**
    * @brief debug ctrl register, offset:0x04
    */
  __IO uint32_t CTRL;

} DEBUG_TypeDef;

/**
  * @brief type define dma register
  */
typedef struct
{
  /**
    * @brief dma sts register, offset:0x00
    */
  __IO uint32_t STS;

  /**
    * @brief dma clr register, offset:0x04
    */
  __IO uint32_t CLR;

  /**
    * @brief reserved, offset:0x08~0x9C
    */
  __IO uint32_t RESERVED1[38];

  /**
    * @brief dma src_sel0 register, offset:0xA0
    */
  __IO uint32_t SRC_SEL0;

  /**
    * @brief dma src_sel1 register, offset:0xA4
    */
  __IO uint32_t SRC_SEL1;
} DMA_TypeDef;

/**
  * @brief type define dma channel register all
  */
typedef struct
{
  /**
    * @brief dma ctrl register, offset:0x08+20*(x-1) x=1...7
    */
  __IO uint32_t CTRL;

  /**
    * @brief dma dtcnt register, offset:0x0C+20*(x-1) x=1...7
    */
  __IO uint32_t DTCNT;

  /**
    * @brief dma cpba register, offset:0x10+20*(x-1) x=1...7
    */
  __IO uint32_t PADDR;

  /**
    * @brief dma cmba register, offset:0x14+20*(x-1) x=1...7
    */
  __IO uint32_t MADDR;
} DMA_Channel_TypeDef;

/**
  * @brief type define adc register all
  */
typedef struct
{
  /**
    * @brief adc sts register, offset:0x00
    */
  __IO uint32_t STS;

  /**
    * @brief adc ctrl1 register, offset:0x04
    */  
   __IO uint32_t CTRL1;

   /**
    * @brief adc ctrl2 register, offset:0x08
    */
  __IO uint32_t CTRL2;

  /**
  * @brief adc spt1 register, offset:0x0C
  */
  __IO uint32_t SPT1;

  /**
  * @brief adc spt2 register, offset:0x10
  */
  __IO uint32_t SPT2;

  /**
  * @brief adc pcdto1 register, offset:0x14
  */
  __IO uint32_t PCDTO1;

  /**
  * @brief adc pcdto2 register, offset:0x18
  */
  __IO uint32_t PCDTO2;

  /**
  * @brief adc pcdto3 register, offset:0x1C
  */
  __IO uint32_t PCDTO3;

  /**
  * @brief adc pcdto4 register, offset:0x20
  */
  __IO uint32_t PCDTO4;

  /**
  * @brief adc vmhb register, offset:0x24
  */
  __IO uint32_t VMHB;

  /**
  * @brief adc vmlb register, offset:0x28
  */
  __IO uint32_t VMLB;

  /**
  * @brief adc osq1 register, offset:0x2C
  */
  __IO uint32_t OSQ1;

  /**
  * @brief adc osq2 register, offset:0x30
  */
  __IO uint32_t OSQ2;

  /**
  * @brief adc osq3 register, offset:0x34
  */
  __IO uint32_t OSQ3;

  /**
  * @brief adc psq register, offset:0x38
  */
  __IO uint32_t PSQ;

  /**
  * @brief adc pdt1 register, offset:0x3C
  */
  __IO uint32_t PDT1;

  /**
  * @brief adc pdt2 register, offset:0x40
  */
  __IO uint32_t PDT2;

  /**
  * @brief adc pdt3 register, offset:0x44
  */
  __IO uint32_t PDT3;

  /**
  * @brief adc pdt4 register, offset:0x48
  */
  __IO uint32_t PDT4;

  /**
  * @brief adc odt register, offset:0x4C
  */
  __IO uint32_t ODT;

} ADC_TypeDef;

/**
  * @brief type define i2c register all
  */
typedef struct
{
  /**
    * @brief i2c ctrl1 register, offset:0x00
    */
  __IO uint32_t CTRL1;

  /**
    * @brief i2c ctrl2 register, offset:0x04
    */
  __IO uint32_t CTRL2;

  /**
    * @brief i2c oaddr1 register, offset:0x08
    */
  __IO uint32_t OADDR1;

  /**
    * @brief i2c oaddr2 register, offset:0x0C
    */
  __IO uint32_t OADDR2;
  /**
    * @brief i2c dt register, offset:0x10
    */
  __IO uint32_t DT;

  /**
    * @brief i2c sts1 register, offset:0x14
    */
  __IO uint32_t STS1;

  /**
    * @brief i2c sts2 register, offset:0x18
    */
  __IO uint32_t STS2;

  /**
    * @brief i2c clkctrl register, offset:0x1C
    */
  __IO uint32_t CLKCTRL;

  /**
    * @brief i2c tmrise register, offset:0x20
    */
  __IO uint32_t TMRISE;

} I2C_TypeDef;


/**
  * @brief type define usart register all
  */
typedef struct
{
  /**
    * @brief usart sts register, offset:0x00
    */
  __IO uint32_t STS;

  /**
    * @brief usart dt register, offset:0x04
    */
  __IO uint32_t DT;

  /**
    * @brief usart baudr register, offset:0x08
    */
  __IO uint32_t BAUDR;

  /**
    * @brief usart ctrl1 register, offset:0x0C
    */
  __IO uint32_t CTRL1;

  /**
    * @brief usart ctrl2 register, offset:0x10
    */
  __IO uint32_t CTRL2;

  /**
    * @brief usart ctrl3 register, offset:0x14
    */
  __IO uint32_t CTRL3;

  /**
    * @brief usart gdiv register, offset:0x18
    */
  __IO uint32_t GDIV;

} USART_TypeDef;

/**
  * @brief type define spi register all
  */
typedef struct
{

  /**
    * @brief spi ctrl1 register, offset:0x00
    */
  __IO uint32_t CTRL1;

  /**
    * @brief spi ctrl2 register, offset:0x04
    */
  __IO uint32_t CTRL2;

  /**
    * @brief spi sts register, offset:0x08
    */
  __IO uint32_t STS;

  /**
    * @brief spi dt register, offset:0x0C
    */
  __IO uint32_t DT;

  /**
    * @brief spi cpoly register, offset:0x10
    */
  __IO uint32_t CPOLY;

  /**
    * @brief spi rcrc register, offset:0x14
    */
  __IO uint32_t RCRC;
  /**
    * @brief spi tcrc register, offset:0x18
    */
  __IO uint32_t TCRC;

  /**
    * @brief spi i2sctrl register, offset:0x1C
    */
  __IO uint32_t I2SCTRL;

  /**
    * @brief spi i2sclk register, offset:0x20
    */
  __IO uint32_t I2SCLK;

} SPI_TypeDef;

/**
  * @}
  */
#define EXINT                             ((EXINT_TypeDef *) EXINT_BASE)
#define CRM                               ((CRM_TypeDef *) CRM_BASE)
#define PWC                               ((PWC_TypeDef *) PWC_BASE)
#define FLASH                             ((FLASH_TypeDef *) FLASH_REG_BASE)
#define GPIOA                             ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                             ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                             ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                             ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOF                             ((GPIO_TypeDef *) GPIOF_BASE)
#define IOMUX                             ((IOMUX_TypeDef *) IOMUX_BASE)
#define TMR1                              ((TMR_TypeDef *) TMR1_BASE)
#define TMR2                              ((TMR_TypeDef *) TMR2_BASE)
#define TMR3                              ((TMR_TypeDef *) TMR3_BASE)
#define TMR4                              ((TMR_TypeDef *) TMR4_BASE)
#define TMR5                              ((TMR_TypeDef *) TMR5_BASE)
#define TMR9                              ((TMR_TypeDef *) TMR9_BASE)
#define TMR10                             ((TMR_TypeDef *) TMR10_BASE)
#define TMR11                             ((TMR_TypeDef *) TMR11_BASE)
#define DEBUGMCU                          ((DEBUG_TypeDef *) DEBUG_BASE)
#define DMA1                              ((DMA_TypeDef *) DMA1_BASE)
#define DMA2                              ((DMA_TypeDef *) DMA2_BASE)
#define DMA1_Channel1                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL1_BASE)
#define DMA1_Channel2                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL2_BASE)
#define DMA1_Channel3                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL3_BASE)
#define DMA1_Channel4                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL4_BASE)
#define DMA1_Channel5                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL5_BASE)
#define DMA1_Channel6                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL6_BASE)
#define DMA1_Channel7                     ((DMA_Channel_TypeDef *) DMA1_CHANNEL7_BASE)
#define DMA2_Channel1                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL1_BASE)
#define DMA2_Channel2                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL2_BASE)
#define DMA2_Channel3                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL3_BASE)
#define DMA2_Channel4                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL4_BASE)
#define DMA2_Channel5                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL5_BASE)
#define DMA2_Channel6                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL6_BASE)
#define DMA2_Channel7                     ((DMA_Channel_TypeDef *) DMA2_CHANNEL7_BASE)
#define ADC1                              ((ADC_TypeDef *) ADC1_BASE)
#define I2C1                              ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                              ((I2C_TypeDef *) I2C2_BASE)
#define USART1                            ((USART_TypeDef *) USART1_BASE)
#define USART2                            ((USART_TypeDef *) USART2_BASE)
#define USART3                            ((USART_TypeDef *) USART3_BASE)
#define UART4                             ((USART_TypeDef *) UART4_BASE)
#define UART5                             ((USART_TypeDef *) UART5_BASE)
#define SPI1                              ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                              ((SPI_TypeDef *) SPI2_BASE)

/**
  * @}
  */
#define FLASH_UNLOCK_KEY1                ((uint32_t)0x45670123)   /*!< flash operation unlock order key1 */
#define FLASH_UNLOCK_KEY2                ((uint32_t)0xCDEF89AB)   /*!< flash operation unlock order key2 */
#define FAP_RELIEVE_KEY                  ((uint16_t)0x00A5)       /*!< flash fap relieve key val */
#define FAP_HIGH_LEVEL_KEY               ((uint16_t)0x00CC)       /*!< flash fap high level enable key val */
#define SLIB_UNLOCK_KEY                  ((uint32_t)0xA35F6D24)   /*!< flash slib operation unlock order key */

#define FLASH_OBF_FLAG                   ((uint32_t)0x00000001)   /*!< flash operate busy flag */
#define FLASH_ODF_FLAG                   ((uint32_t)0x00000020)   /*!< flash operate done flag */
#define FLASH_PRGMERR_FLAG               ((uint32_t)0x00000004)   /*!< flash program error flag */
#define FLASH_EPPERR_FLAG                ((uint32_t)0x00000010)   /*!< flash erase/program protection error flag */
#define FLASH_USDERR_FLAG                ((uint32_t)0x40000001)   /*!< flash user system data error flag */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
