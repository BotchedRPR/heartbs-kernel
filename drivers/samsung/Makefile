# drivers/samsung/Makefile
#
# Copyright (c) 2010-2019 Samsung Electronics Co., Ltd.
#		http://www.samsung.com/
#
# Licensed under GPLv2

obj-y				:= secure_rmem.o
obj-m				:=
obj-n				:=
obj-				:=

obj-$(CONFIG_SEC_DEBUG)		+= debug/
obj-$(CONFIG_SEC_PM)		+= pm/
obj-$(CONFIG_SEC_MISC)		+= misc/

# Samsung Reset Feature
obj-$(CONFIG_SEC_REBOOT)	+= sec_reboot.o
# Samsung sec sysfs Feature
obj-$(CONFIG_DRV_SAMSUNG)	+= sec_class.o
obj-$(CONFIG_SEC_PARAM)		+= sec_param.o
obj-$(CONFIG_SEC_BOOTSTAT)      += sec_bootstat.o
# obj-$(CONFIG_SEC_PARAM)		+= sec_fmm_lock.o

obj-$(CONFIG_SEC_KEY_NOTIFIER)	+= sec_key_notifier.o
obj-$(CONFIG_SEC_KEY_NOTIFIER)	+= sec_crash_key.o
obj-$(CONFIG_SEC_KEY_NOTIFIER)	+= sec_crash_key_user.o
obj-$(CONFIG_SEC_KEY_NOTIFIER)	+= sec_hard_reset_hook.o

# Samsung Throughput monitoring Feature
obj-$(CONFIG_ARGOS)             += sec_argos.o

# Samsung System Update
#obj-$(CONFIG_SEC_SYSUP)		+= sec_sysup.o
obj-$(CONFIG_SEC_DUMP_SINK)	+= sec_dump_sink.o

