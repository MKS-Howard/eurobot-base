LIBCOCOBOT_VERSION = 0.1
LIBCOCOBOT_URL = https://github.com/cocobot/libcocobot/archive/$(LIBCOCOBOT_VERSION).tar.gz
LIBCOCOBOT_ARCHIVE = libcocobot-$(LIBCOCOBOT_VERSION).tar.gz
LIBCOCOBOT_GIT_UPSTREAM_URL = git@github.com:cocobot/libcocobot.git

# File path
ifeq ($(CONFIG_LIBCOCOBOT_USE_GIT),y)
LIBCOCOBOT_FILE_PATH=git
else
LIBCOCOBOT_FILE_PATH=mcual-$(LIBCOCOBOT_VERSION)
endif

# Include files
LIBCOCOBOT_INCLUDE_PATH=$(LIBCOCOBOT_FILE_PATH)/include/

LIBCOCOBOT_SRC_FILES= $(LIBCOCOBOT_FILE_PATH)/src/all/console/console.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/all/lcd/lcd.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/all/trajectory/trajectory.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/all/asserv/asserv.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/all/asserv/ramp.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/all/asserv/pid.c

LIBCOCOBOT_TARGET_SRC_FILES= $(LIBCOCOBOT_FILE_PATH)/src/real/position/position.c
LIBCOCOBOT_TARGET_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/real/position/encoders.c

LIBCOCOBOT_SIM_SRC_FILES= $(LIBCOCOBOT_FILE_PATH)/src/sim/position/position.c
LIBCOCOBOT_SIM_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/sim/position/vrep.c

GLOBAL_LDFLAGS+=-lm

$(eval $(call pkg-generic,LIBCOCOBOT))
