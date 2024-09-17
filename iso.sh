#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/homeaccounting.kernel isodir/boot/homeaccounting.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "homeaccounting" {
	multiboot /boot/homeaccounting.kernel
}
EOF
grub-mkrescue -o homeaccounting.iso isodir
