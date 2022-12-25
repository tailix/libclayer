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
# test_elf #
############

if WITH_ELF
TESTS += test_elf
test_elf_LDADD = $(top_builddir)/libkernaux.la
test_elf_SOURCES = \
	main.c \
	test_elf.c
endif

##################
# test_free_list #
##################

if WITH_FREE_LIST
TESTS += test_free_list
test_free_list_LDADD = $(top_builddir)/libkernaux.la
test_free_list_SOURCES = \
	main.c \
	test_free_list.c
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

#############
# test_ntoa #
#############

if WITH_NTOA
TESTS += test_ntoa
test_ntoa_LDADD = $(top_builddir)/libkernaux.la
test_ntoa_SOURCES = \
	main.c \
	test_ntoa.c
endif

####################
# test_ntoa_assert #
####################

if ENABLE_ASSERT
if WITH_NTOA
TESTS += test_ntoa_assert
test_ntoa_assert_LDADD = $(top_builddir)/libkernaux.la
test_ntoa_assert_SOURCES = \
	main.c \
	test_ntoa_assert.c
endif
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

####################
# test_units_human #
####################

if WITH_UNITS
TESTS += test_units_human
test_units_human_LDADD = $(top_builddir)/libkernaux.la
test_units_human_SOURCES = \
	main.c \
	test_units_human.c
endif
