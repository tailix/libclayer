include $(top_srcdir)/make/shared.am
include $(top_srcdir)/make/checks.am

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh sha256sums.txt

SUBDIRS = include .

if ENABLE_CHECKS
SUBDIRS += tests
endif

lib_LTLIBRARIES =

if ENABLE_LIBCLAYER
lib_LTLIBRARIES += libclayer.la
libclayer_la_SOURCES = $(common_sources)
endif

if ENABLE_LIBC
lib_LTLIBRARIES += libc.la
libc_la_SOURCES = $(common_sources)
libc_la_CFLAGS = $(AM_CFLAGS) -DLIBCLAYER_NOPREFIX
endif

if ENABLE_PKG_CONFIG
pkgconfigdir = @pkgconfdir@
pkgconfig_DATA = libclayer.pc
endif

##################
# Required files #
##################

common_sources = \
	src/ctype.c \
	src/errno.c \
	src/libclayer.c \
	src/stdlib.c \
	src/string.c

if ASM_I386
common_sources += \
	src/asm/i386/longjmp.S \
	src/asm/i386/setjmp.S
endif

if ASM_X86_64
common_sources += \
	src/asm/x86_64/longjmp.S \
	src/asm/x86_64/setjmp.S
endif

# TODO: implement setjmp/longjmp for riscv64
