include $(top_srcdir)/make/shared.am
include $(top_srcdir)/make/checks.am

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh CONTRIBUTING.md sha256sums.txt

SUBDIRS = include .

if ENABLE_CHECKS
SUBDIRS += tests
endif

AM_CFLAGS += -DKERNAUX_ACCESS_PRIVATE

lib_LTLIBRARIES = libkernaux.la

if ENABLE_PKG_CONFIG
pkgconfigdir = @pkgconfdir@
pkgconfig_DATA = libkernaux.pc
endif

##################
# Required files #
##################

libkernaux_la_LDFLAGS = -version-info @PACKAGE_VERSION_SO@

libkernaux_la_SOURCES = \
	src/ctype.c \
	src/errno.c \
	src/kernaux.c \
	src/stdlib.c \
	src/string.c

if ASM_I386
libkernaux_la_SOURCES += \
	src/asm/i386/longjmp.S \
	src/asm/i386/setjmp.S
endif

if ASM_X86_64
libkernaux_la_SOURCES += \
	src/asm/x86_64/longjmp.S \
	src/asm/x86_64/setjmp.S
endif

# TODO: implement setjmp/longjmp for riscv64
