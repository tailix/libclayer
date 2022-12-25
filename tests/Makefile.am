include $(top_srcdir)/make/shared.am

CLEANFILES =
TESTS =
noinst_PROGRAMS = $(TESTS)

##################
# test_arch_i386 #
##################

if WITH_ARCH_I386
TESTS += test_arch_i386
test_arch_i386_LDADD = $(top_builddir)/libkernaux.la
test_arch_i386_SOURCES = \
	main.c \
	test_arch_i386.c
endif
