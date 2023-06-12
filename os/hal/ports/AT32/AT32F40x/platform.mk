# Required platform files.
PLATFORMSRC_CONTRIB += $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F40x/hal_lld.c \
			                 $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F40x/at32_isr.c \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F40x/hal_efl_lld.c

# Required include directories.
PLATFORMINC_CONTRIB += $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F40x


ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))
endif #ifeq ($(USE_SMART_BUILD), yes)

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/AT32/LLD/GPIOv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/DMAv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/TIMv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/SYSTICKv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/USBv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/ADCv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/I2Cv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/USARTv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/SPIv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)
