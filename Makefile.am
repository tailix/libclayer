include $(top_srcdir)/make/shared.am
include $(top_srcdir)/make/checks.am

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh CONTRIBUTING.md sha256sums.txt src/assert.h

SUBDIRS = include

if WITH_LIBC
# FIXME: after "make clean" libc is not rebuiling
SUBDIRS += libc
endif

SUBDIRS += .

if ENABLE_CHECKS
SUBDIRS += tests
endif

libc/libc.la:
	$(MAKE) $(AM_MAKEFLAGS) -C $(top_builddir)/libc libc.la

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
libkernaux_la_LIBADD =
libkernaux_la_SOURCES = src/runtime.c

########
# libc #
########

if WITH_LIBC
libkernaux_la_LIBADD += libc/libc.la
endif

#######
# ARCH #
#######

if WITH_ARCH_I386
libkernaux_la_SOURCES += src/arch/i386/idt.c
endif

#######
# ASM #
#######

if WITH_ASM
if ASM_I386
libkernaux_la_SOURCES += src/asm/i386.S
endif
if ASM_RISCV64
libkernaux_la_SOURCES += src/asm/riscv64.S
endif
if ASM_X86_64
libkernaux_la_SOURCES += src/asm/x86_64.S
endif
endif
