SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export MAKE=${MAKE:-make}
export HOST=i686-elf
export BOOTDIR=/boot
export INCLUDEDIR=/usr/include

export CFLAGS='-O0 -g'
export SYSROOT="$(pwd)/sysroot"
