HOST=i686-elf
HOSTARCH=i386

CFLAGS?=-O2 -g

PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lgcc

KERNEL_OBJS=\
boot.o \
kernel.o \

OBJS=\
crti.o \
crtbegin.o \
$(KERNEL_OBJS) \
crtend.o \
crtn.o \

LINK_LIST=\
$(LDFLAGS) \
crti.o \
crtbegin.o \
$(KERNEL_OBJS) \
$(LIBS) \
crtend.o \
crtn.o \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .s

all: homeaccounting.kernel

homeaccounting.kernel: $(OBJS) linker.ld
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot homeaccounting.kernel

crtbegin.o crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)

.s.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

clean:
	rm -f homeaccounting.kernel
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: homeaccounting.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp homeaccounting.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)
