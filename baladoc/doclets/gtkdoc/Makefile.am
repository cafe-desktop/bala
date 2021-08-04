include $(top_srcdir)/Makefile.common

NULL =

AM_CFLAGS = \
	-DG_LOG_DOMAIN=\"baladoc-gtkdoc\" \
	-DPACKAGE_BALADOC_ICONDIR=\"$(datadir)/baladoc@PACKAGE_SUFFIX@/icons/\" \
	-I$(top_srcdir)/gee/ \
	-I$(top_srcdir)/bala/ \
	-I$(top_srcdir)/libbaladoc/ \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(LIBGVC_CFLAGS) \
	$(NULL)

BUILT_SOURCES = libdoclet.bala.stamp

doclet_LTLIBRARIES = libdoclet.la

docletdir = $(libdir)/baladoc@PACKAGE_SUFFIX@/doclets/gtkdoc

libdoclet_la_LDFLAGS = -module -avoid-version -no-undefined

libdoclet_la_BALASOURCES = \
	commentconverter.bala \
	dbus.bala \
	doclet.bala \
	gcomment.bala \
	generator.bala \
	utils.bala \
	$(NULL)

libdoclet_la_SOURCES = \
	libdoclet.bala.stamp \
	$(libdoclet_la_BALASOURCES:.bala=.c) \
	$(NULL)

libdoclet.bala.stamp: $(libdoclet_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bala --pkg libbala@PACKAGE_SUFFIX@ \
		--bapidir $(top_srcdir)/bapi \
		--bapidir $(top_srcdir)/libbaladoc --pkg baladoc@PACKAGE_SUFFIX@ \
		$(filter %.bala %.c,$^)
	touch $@

libdoclet_la_LIBADD = \
	$(top_builddir)/libbaladoc/libbaladoc@PACKAGE_SUFFIX@.la \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(NULL)

EXTRA_DIST = \
	$(libdoclet_la_BALASOURCES) \
	libdoclet.bala.stamp \
	$(NULL)

MAINTAINERCLEANFILES = \
	$(libdoclet_la_BALASOURCES:.bala=.c) \
	$(NULL)

