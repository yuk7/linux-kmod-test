MODULE_NAME = test

ARCH := $(shell uname -m | sed -e s/i.86/i386/)
CROSS_COMPILE :=
KVER := $(shell uname -r)
KSRC := /lib/modules/$(KVER)/build
PWD = $(shell pwd)
MODDESTDIR := /lib/modules/$(KVER)/kernel/drivers

obj-m += test.o

.PHONY: all modules clean

all: modules

modules:
	make -C $(KSRC) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD)  CONFIG_DEBUG_INFO=y modules

install:
	install -p -m 644 $(MODULE_NAME).ko  $(MODDESTDIR)
	/sbin/depmod -a $(KVER)

uninstall:
	rm -f $(MODDESTDIR)/$(MODULE_NAME).ko
	/sbin/depmod -a $(KVER)

clean:
	make -C $(KSRC) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) clean
