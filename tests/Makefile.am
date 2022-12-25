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

############
# test_mbr #
############

if WITH_MBR
TESTS += test_mbr
test_mbr_LDADD = $(top_builddir)/libkernaux.la
test_mbr_SOURCES = \
	main.c \
	test_mbr.c
endif

############
# test_pfa #
############

if WITH_PFA
TESTS += test_pfa
test_pfa_LDADD = $(top_builddir)/libkernaux.la
test_pfa_SOURCES = \
	main.c \
	test_pfa.c
endif

###################
# test_pfa_assert #
###################

if ENABLE_ASSERT
if WITH_PFA
TESTS += test_pfa_assert
test_pfa_assert_LDADD = $(top_builddir)/libkernaux.la
test_pfa_assert_SOURCES = \
	main.c \
	test_pfa_assert.c
endif
endif
