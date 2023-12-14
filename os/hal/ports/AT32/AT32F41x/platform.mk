# Required platform files.
PLATFORMSRC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F41x/at32_isr.c \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F41x/hal_lld.c \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F41x/hal_efl_lld.c

# Required include directories.
PLATFORMINC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
                       $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/AT32F41x

# Optional platform files.
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
endif

# Drivers compatible with the platform.
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/DMAv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/GPIOv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/I2Cv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/OTGv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/SPIv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/SYSTICKv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/AT32/LLD/TMRv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)