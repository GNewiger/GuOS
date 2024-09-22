.PHONY: all clean install install-headers install-kernel
OBJECTS:=kernel.o boot.o


all: homeaccounting.kernel

homeaccounting.kernel: kernel.o boot.o linker.ld
	i686-elf-gcc -T linker.ld -ffreestanding -O0 -nostdlib -lgcc 
	grub-file --is-x86-multiboot homeaccounting.kernel

boot.o: boot.s 
	i686-elf-as boot.s -o boot.o

kernel.o: kernel.c include/multiboot.h
	 i686-elf-gcc -c kernel.c -o kernel.o -Iinclude -std=gnu99 -ffreestanding -O0 -Wall -Wextra

clean:
	rm -f homeaccounting.kernel
	rm -f *.o */*.o */*/*.o

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: homeaccounting.kernel
	mkdir -p $(DESTDIR)
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp homeaccounting.kernel $(DESTDIR)$(BOOTDIR)
