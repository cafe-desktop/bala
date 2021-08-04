include $(top_srcdir)/Makefile.common

NULL =

LOG_COMPILER = $(abs_top_srcdir)/build-aux/testrunner.sh
AM_TESTS_ENVIRONMENT = \
	export EXEEXT=$(EXEEXT); \
	export CFLAGS='$(CFLAGS)'; \
	export CPPFLAGS='$(CPPFLAGS)'; \
	export LDFLAGS='$(LDFLAGS)'; \
	export TEST_CFLAGS='$(TEST_CFLAGS)'; \
	export PACKAGE_SUFFIX='$(PACKAGE_SUFFIX)' \
	export abs_top_srcdir='$(abs_top_srcdir)'; \
	export abs_top_builddir='$(abs_top_builddir)'; \
	export abs_srcdir='$(abs_srcdir)'; \
	export abs_builddir='$(abs_builddir)'; \
	export CC='$(CC)';

TESTS = \
	libbaladoc/errorreporter.bala \
	libbaladoc/markupreader.bala \
	libbaladoc/gtkdoc-scanner.bala \
	libbaladoc/parser-manyrule.bala \
	libbaladoc/parser-oneofrule.bala \
	libbaladoc/parser-sequencerule.bala \
	libbaladoc/parser-optionalrule.bala \
	libbaladoc/parser-stubrule.bala \
	$(NULL)

check-local:
	G_DEBUG=fatal_warnings $(builddir)/driver

AM_CFLAGS = \
	-DPACKAGE_BALADOC_LIBDIR=\"$(libdir)/baladoc@PACKAGE_SUFFIX@\" \
	-DPACKAGE_VERSION=\"$(VERSION)\" \
	-DTOP_SRC_DIR=\"$(abs_top_srcdir)\" \
	-I$(top_srcdir)/libbaladoc/ \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	-I$(top_srcdir)/codegen \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(GMODULE_CFLAGS) \
	$(LIBGVC_CFLAGS) \
	$(NULL)

BUILT_SOURCES = driver.bala.stamp

check_PROGRAMS = driver

driver_BALASOURCES = \
	drivers/driver-test.bala \
	drivers/generic-api-test.bala \
	$(top_srcdir)/baladoc/girwriter.bala \
	$(top_srcdir)/baladoc/initializerbuilder.bala \
	$(top_srcdir)/baladoc/symbolresolver.bala \
	$(top_srcdir)/baladoc/treebuilder.bala \
    $(NULL)

driver_SOURCES = \
	driver.bala.stamp \
	drivers/driver-test.c \
	drivers/generic-api-test.c \
	girwriter.c \
	initializerbuilder.c \
	symbolresolver.c \
	treebuilder.c \
	$(NULL)

driver_LDADD = \
	$(top_builddir)/libbaladoc/libbaladoc@PACKAGE_SUFFIX@.la \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/ccode/libbalaccode.la \
	$(top_builddir)/codegen/libbalaccodegen.la \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(GMODULE_LIBS) \
	$(LIBGVC_LIBS) \
	$(NULL)

driver.bala.stamp: $(driver_BALASOURCES) $(top_srcdir)/bala/libbala@PACKAGE_SUFFIX@.bapi $(top_srcdir)/libbaladoc/baladoc@PACKAGE_SUFFIX@.bapi
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi \
		--pkg gmodule-2.0 \
		--pkg gobject-2.0 \
		--pkg libgvc \
		--bapidir $(top_srcdir)/bala --pkg libbala@PACKAGE_SUFFIX@ \
		--bapidir $(top_srcdir)/ccode --pkg ccode \
		--bapidir $(top_srcdir)/codegen --pkg codegen \
		--bapidir $(top_srcdir)/libbaladoc --pkg baladoc@PACKAGE_SUFFIX@ \
		--pkg config \
		$(filter %.bala %.c,$^)
	touch $@

EXTRA_DIST = \
	driver.bala.stamp \
	$(driver_SOURCES) \
	drivers/api-test.data.bapi \
	drivers/driver-test.bala \
	drivers/generic-api-test.bala \
	libbaladoc/parser-generic-scanner.bala \
	libbaladoc/tests-extra-environment.sh \
	$(TESTS) \
	$(NULL)

MAINTAINERCLEANFILES = \
	driver.bala.stamp \
	$(driver_SOURCES) \
	$(NULL)
