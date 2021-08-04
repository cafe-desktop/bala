include $(top_srcdir)/Makefile.common

NULL =

SUBDIRS = \
	doclets \
	icons \
	tests \
	$(NULL)

AM_CFLAGS = \
	-DG_LOG_DOMAIN=\"baladoc\" \
	-DPACKAGE_BALADOC_LIBDIR=\"$(pkgdoclibdir)\" \
	-DPACKAGE_VERSION=\"$(VERSION)\" \
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

BUILT_SOURCES = baladoc.bala.stamp

bin_PROGRAMS = baladoc

baladoc_BALASOURCES = \
	girwriter.bala \
	initializerbuilder.bala \
	symbolresolver.bala \
	treebuilder.bala \
	baladoc.bala \
    $(NULL)

baladoc_SOURCES = \
	baladoc.bala.stamp \
	$(baladoc_BALASOURCES:.bala=.c) \
	$(NULL)

baladoc_LDADD = \
	$(top_builddir)/libbaladoc/libbaladoc@PACKAGE_SUFFIX@.la \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/ccode/libbalaccode.la \
	$(top_builddir)/codegen/libbalaccodegen.la \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(GMODULE_LIBS) \
	$(LIBGVC_LIBS) \
	$(NULL)

baladoc.bala.stamp: $(baladoc_BALASOURCES) $(top_srcdir)/bala/libbala@PACKAGE_SUFFIX@.vapi $(top_srcdir)/libbaladoc/baladoc@PACKAGE_SUFFIX@.vapi
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--pkg gmodule-2.0 \
		--pkg gobject-2.0 \
		--pkg libgvc \
		--vapidir $(top_srcdir)/bala --pkg libbala@PACKAGE_SUFFIX@ \
		--vapidir $(top_srcdir)/ccode --pkg ccode \
		--vapidir $(top_srcdir)/codegen --pkg codegen \
		--vapidir $(top_srcdir)/libbaladoc --pkg baladoc@PACKAGE_SUFFIX@ \
		--pkg config \
		$(filter %.bala %.c,$^)
	touch $@

EXTRA_DIST = \
	$(baladoc_BALASOURCES) \
	baladoc.bala.stamp \
	$(NULL)

if ENABLE_UNVERSIONED
install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f baladoc@PACKAGE_SUFFIX@$(EXEEXT) baladoc$(EXEEXT)
endif

MAINTAINERCLEANFILES = \
	$(baladoc_BALASOURCES:.bala=.c) \
	$(NULL)
