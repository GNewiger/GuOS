#!/bin/sh
set -e
. ./iso.sh

qemu-system-i386 -cdrom homeaccounting.iso
