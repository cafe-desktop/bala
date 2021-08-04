include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"bala-ccodegen\" \
	$(COVERAGE_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	$(GLIB_CFLAGS) \
	$(NULL)

BUILT_SOURCES = codegen.bala.stamp

libbalaccodegen_la_LTLIBRARIES = \
	libbalaccodegen.la \
	$(NULL)

libbalaccodegen_ladir = $(pkglibdir)

libbalaccodegen_la_LDFLAGS = \
	-no-undefined \
	-avoid-version \
	$(NULL)

libbalaccodegen_la_BALASOURCES = \
	balaccode.bala \
	balaccodearraymodule.bala \
	balaccodeassignmentmodule.bala \
	balaccodeattribute.bala \
	balaccodebasemodule.bala \
	balaccodecompiler.bala \
	balaccodecontrolflowmodule.bala \
	balaccodedelegatemodule.bala \
	balaccodememberaccessmodule.bala \
	balaccodemethodcallmodule.bala \
	balaccodemethodmodule.bala \
	balaccodestructmodule.bala \
	balaclassregisterfunction.bala \
	balactype.bala \
	balaenumregisterfunction.bala \
	balagasyncmodule.bala \
	balagdbusclientmodule.bala \
	balagdbusmodule.bala \
	balagdbusservermodule.bala \
	balagerrormodule.bala \
	balagirwriter.bala \
	balaglibvalue.bala \
	balagobjectmodule.bala \
	balagtkmodule.bala \
	balagsignalmodule.bala \
	balagtypemodule.bala \
	balagvaluemodule.bala \
	balagvariantmodule.bala \
	balainterfaceregisterfunction.bala \
	balastructregisterfunction.bala \
	balatyperegisterfunction.bala \
	$(NULL)

libbalaccodegen_la_SOURCES = \
	codegen.bala.stamp \
	$(libbalaccodegen_la_BALASOURCES:.bala=.c) \
	$(NULL)

codegen.bapi codegen.bala.stamp: $(libbalaccodegen_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi --pkg gobject-2.0 \
		--bapidir $(top_srcdir)/gee --pkg gee \
		--bapidir $(top_srcdir)/ccode --pkg ccode \
		--bapidir $(top_srcdir)/bala --pkg bala \
		--use-header \
		-H balacodegen.h \
		--library codegen \
		$^
	@touch $@

libbalaccodegen_la_LIBADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/ccode/libbalaccode.la \
	$(NULL)

EXTRA_DIST = $(libbalaccodegen_la_BALASOURCES) codegen.bapi codegen.bala.stamp balacodegen.h

MAINTAINERCLEANFILES = \
	codegen.bapi \
	balacodegen.h \
	$(libbalaccodegen_la_BALASOURCES:.bala=.c) \
	$(NULL)
