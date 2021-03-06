ifeq ($(CONFIG_PLATFORM_BRAIN_2019),y)
include $(CONFIG_CUSTOM_PLATFORMS_PATH)/brain_2019/platform.mk
PLATFORM_CLEAN_GOAL+=platform_brain_2019-clean
endif

ifeq ($(CONFIG_PLATFORM_MECANELE_2019),y)
include $(CONFIG_CUSTOM_PLATFORMS_PATH)/mecanele_2019/platform.mk
PLATFORM_CLEAN_GOAL+=platform_mecanele_2019-clean
endif

ifeq ($(CONFIG_PLATFORM_COM_2019),y)
include $(CONFIG_CUSTOM_PLATFORMS_PATH)/com_2019/platform.mk
PLATFORM_CLEAN_GOAL+=platform_com_2019-clean
endif

ifeq ($(CONFIG_PLATFORM_COMEX_2019),y)
include $(CONFIG_CUSTOM_PLATFORMS_PATH)/comex_2019/platform.mk
PLATFORM_CLEAN_GOAL+=platform_comex_2019-clean
endif

ifeq ($(CONFIG_PLATFORM_CANON_2019),y)
include $(CONFIG_CUSTOM_PLATFORMS_PATH)/canon_2019/platform.mk
PLATFORM_CLEAN_GOAL+=platform_canon_2019-clean
endif
