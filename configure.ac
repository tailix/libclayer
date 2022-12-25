############################
# Specify program versions #
############################

AC_PREREQ([2.70])
LT_PREREQ([2.4.6])



##################################
# Initialize Autoconf & Automake #
##################################

AC_INIT([libkernaux],
  m4_normalize(m4_include([VERSION])),
  [https://github.com/tailix/libkernaux/issues],
  [libkernaux],
  [https://github.com/tailix/libkernaux])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/xxxxx.c])
AC_CONFIG_FILES([
  Makefile
  libkernaux.pc
  include/Makefile
  libc/Makefile
  libc/include/Makefile
  tests/Makefile
])

AM_INIT_AUTOMAKE([1.16 subdir-objects])

AC_SUBST([PACKAGE_DESCR], ['Auxiliary library for kernel development'])
AC_SUBST([PACKAGE_VERSION_SO], m4_normalize(m4_include([VERSION_SO])))



###############
# Define args #
###############

dnl Features (enabled by default)
AC_ARG_ENABLE([assert],          AS_HELP_STRING([--disable-assert],         [disable assertions]))
AC_ARG_ENABLE([float],           AS_HELP_STRING([--disable-float],          [disable floating-point arithmetic]))
AC_ARG_ENABLE([werror],          AS_HELP_STRING([--disable-werror],         [disable -Werror]))
 
dnl Features (disabled by default)
AC_ARG_ENABLE([freestanding],    AS_HELP_STRING([--enable-freestanding],    [build for freestanding environment]))
AC_ARG_ENABLE([checks],          AS_HELP_STRING([--enable-checks],          [enable usual tests]))
AC_ARG_ENABLE([checks-all],      AS_HELP_STRING([--enable-checks-all],      [enable all checks]))
AC_ARG_ENABLE([checks-cppcheck], AS_HELP_STRING([--enable-checks-cppcheck], [enable cppcheck]))
AC_ARG_ENABLE([split-libc],      AS_HELP_STRING([--enable-split-libc],      [split off libc]))

dnl Features (with parameter)
AC_ARG_ENABLE([pkg-config],      AS_HELP_STRING([--enable-pkg-config@<:@=PATH@:>@], [install pkg-config files @<:@PATH='${libdir}/pkgconfig'@:>@]))

dnl Packages (disabled by default)
AC_ARG_WITH(  [libc],            AS_HELP_STRING([--with-libc],              [with libc replacement]))



################
# Default args #
################

AC_DEFUN([do_enable_checks_all],
[
if test -z "$enable_checks";          then enable_checks=yes;          fi
if test -z "$enable_checks_cppcheck"; then enable_checks_cppcheck=yes; fi
])
AS_IF([test "$enable_checks_all" = yes], do_enable_checks_all)



##################
# Normalize args #
##################

dnl Features (enabled by default)
AS_IF([test "$enable_assert"          = no ], [enable_assert=no],           [enable_assert=yes])
AS_IF([test "$enable_float"           = no ], [enable_float=no],            [enable_float=yes])
AS_IF([test "$enable_werror"          = no ], [enable_werror=no],           [enable_werror=yes])

dnl Features (disabled by default)
AS_IF([test "$enable_freestanding"    = yes], [enable_freestanding=yes],    [enable_freestanding=no])
AS_IF([test "$enable_checks"          = yes], [enable_checks=yes],          [enable_checks=no])
AS_IF([test "$enable_checks_all"      = yes], [enable_checks_all=yes],      [enable_checks_all=no])
AS_IF([test "$enable_checks_cppcheck" = yes], [enable_checks_cppcheck=yes], [enable_checks_cppcheck=no])
AS_IF([test "$enable_split_libc"      = yes], [enable_split_libc=yes],      [enable_split_libc=no])

dnl Features (with parameter)
AS_IF([test "$enable_pkg_config"      = yes], [enable_pkg_config='${libdir}/pkgconfig'])
AS_IF([test "$enable_pkg_config"      = no ], [enable_pkg_config=''])

dnl Packages (disabled by default)
AS_IF([test "$with_libc"              = yes], [with_libc=yes],              [with_libc=no])



#############
# Test args #
#############

AS_IF([test "$enable_checks"   = yes -a "$enable_freestanding" = yes], AC_MSG_ERROR([can not build freestanding tests]))
AS_IF([test "$enable_checks"   = yes -a "$with_libc"           = yes], AC_MSG_ERROR([can not use package `libc' with tests]))



#########################
# Automake conditionals #
#########################

dnl Architecture
AM_CONDITIONAL([ASM_I386],               [test "$host_cpu" = i386])
AM_CONDITIONAL([ASM_RISCV64],            [test "$host_cpu" = riscv64])
AM_CONDITIONAL([ASM_X86_64],             [test "$host_cpu" = x86_64])

dnl Architecture (additional)
AM_CONDITIONAL([ASM_X86],                [test "$host_cpu" = i386 -o "$host_cpu" = x86_64])

dnl Features (enabled by default)
AM_CONDITIONAL([ENABLE_ASSERT],          [test "$enable_assert"          = yes])
AM_CONDITIONAL([ENABLE_FLOAT],           [test "$enable_float"           = yes])
AM_CONDITIONAL([ENABLE_WERROR],          [test "$enable_werror"          = yes])

dnl Features (disabled by default)
AM_CONDITIONAL([ENABLE_FREESTANDING],    [test "$enable_freestanding"    = yes])
AM_CONDITIONAL([ENABLE_CHECKS],          [test "$enable_checks"          = yes])
AM_CONDITIONAL([ENABLE_CHECKS_CPPCHECK], [test "$enable_checks_cppcheck" = yes])
AM_CONDITIONAL([ENABLE_SPLIT_LIBC],      [test "$enable_split_libc"      = yes])

dnl Features (with parameter)
AM_CONDITIONAL([ENABLE_PKG_CONFIG],      [test ! -z "$enable_pkg_config"])

dnl Packages (disabled by default)
AM_CONDITIONAL([WITH_LIBC],              [test "$with_libc"              = yes])



####################
# Autoconf defines #
####################

dnl Architecture
AS_IF([test "$host_cpu" = i386],              [AC_DEFINE([ASM_I386],               [1], [architecture is i386])])
AS_IF([test "$host_cpu" = riscv64],           [AC_DEFINE([ASM_RISCV64],            [1], [architecture is RISC-V 64-bit])])
AS_IF([test "$host_cpu" = x86_64],            [AC_DEFINE([ASM_X86_64],             [1], [architecture is x86_64])])

dnl Architecture (additional)
AS_IF([test "$host_cpu" = i386],              [AC_DEFINE([ASM_X86],                [1], [architecture is x86])])
AS_IF([test "$host_cpu" = x86_64],            [AC_DEFINE([ASM_X86],                [1], [architecture is x86])])

dnl Features (enabled by default)
AS_IF([test "$enable_assert"          = yes], [AC_DEFINE([ENABLE_ASSERT],          [1], [enabled assertions])])
AS_IF([test "$enable_float"           = yes], [AC_DEFINE([ENABLE_FLOAT],           [1], [enabled floating-point arithmetic])])
AS_IF([test "$enable_werror"          = yes], [AC_DEFINE([ENABLE_WERROR],          [1], [enabled -Werror])])

dnl Features (disabled by default)
AS_IF([test "$enable_freestanding"    = yes], [AC_DEFINE([ENABLE_FREESTANDING],    [1], [build for freestanding environment])])
AS_IF([test "$enable_checks"          = yes], [AC_DEFINE([ENABLE_CHECKS],          [1], [enabled usual tests])])
AS_IF([test "$enable_checks_cppcheck" = yes], [AC_DEFINE([ENABLE_CHECKS_CPPCHECK], [1], [enabled cppcheck])])
AS_IF([test "$enable_split_libc"      = yes], [AC_DEFINE([ENABLE_SPLIT_LIBC],      [1], [split off libc])])

dnl Packages (disabled by default)
AS_IF([test "$with_libc"              = yes], [AC_DEFINE([WITH_LIBC],              [1], [with libc replacement])])



##########################
# Autoconf substitutions #
##########################

dnl Features (with parameter)
AC_SUBST([pkgconfdir], [$enable_pkg_config])



###################
# Set build flags #
###################

AS_IF([test "$enable_freestanding" = yes],
  [CFLAGS="$CFLAGS -nostdlib -ffreestanding -fno-pic -fno-stack-protector "],
  [CFLAGS="$CFLAGS -fpic "])



##############
# Run checks #
##############

AC_LANG([C])
AM_PROG_AS

AC_C_INLINE

AC_HEADER_STDBOOL
AS_IF([test "$enable_checks" = yes -a "$ac_cv_header_stdbool_h" != yes],
  [AC_MSG_ERROR([the header is required])])

AC_CHECK_HEADERS([limits.h stdarg.h stddef.h stdint.h],,
  [AC_MSG_ERROR([the headers are required])])

AS_IF([test "$enable_checks" = yes],
  [AC_CHECK_HEADERS([assert.h setjmp.h stdio.h stdlib.h string.h],,
    [AC_MSG_ERROR([the headers are required])])])

AC_PATH_PROGS([CPPCHECK], [cppcheck], [:])
AS_IF([test "$enable_checks_cppcheck" = yes -a "$CPPCHECK" = ':'],
  [AC_MSG_ERROR([cppcheck is required])])



######################
# Initialize Libtool #
######################

LT_INIT



##########
# Finish #
##########

AC_OUTPUT
