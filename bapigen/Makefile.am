include $(top_srcdir)/Makefile.common

NULL =

SUBDIRS = \
	bala-gen-introspect \
	$(NULL)

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"vapigen\" \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	-I$(top_srcdir)/gobject-introspection \
	$(NULL)

bin_PROGRAMS = \
	vapigen \
	$(NULL)

noinst_PROGRAMS = \
	vapicheck \
	$(NULL)

BUILT_SOURCES = vapigen.bala.stamp vapicheck.bala.stamp

vapigen_BALASOURCES = \
	balagidlparser.bala \
	balavapigen.bala \
	$(NULL)

vapigen_SOURCES = \
	vapigen.bala.stamp \
	$(vapigen_BALASOURCES:.bala=.c) \
	$(NULL)

vapicheck_BALASOURCES = \
	balavapicheck.bala \
	$(NULL)

vapicheck_SOURCES = \
	vapicheck.bala.stamp \
	$(vapicheck_BALASOURCES:.bala=.c) \
	$(NULL)

vapigen.bala.stamp: $(vapigen_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/bala --pkg bala \
		--vapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

vapicheck.bala.stamp: $(vapicheck_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/bala --pkg bala \
		--vapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

vapigen_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

vapicheck_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

if ENABLE_UNVERSIONED
makedir = $(datadir)/bala
make_DATA = Makefile.vapigen

aclocaldir = $(datadir)/aclocal
aclocal_DATA = vapigen.m4
endif

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = vapigen@PACKAGE_SUFFIX@.pc

vapigen@PACKAGE_SUFFIX@.pc: vapigen.pc
	cp $< $@

EXTRA_DIST = \
	$(vapigen_BALASOURCES) \
	$(vapicheck_BALASOURCES) \
	Makefile.vapigen \
	vapigen.m4 \
	vapigen.bala.stamp \
	vapicheck.bala.stamp \
	$(NULL)

CLEANFILES = \
	vapigen@PACKAGE_SUFFIX@.pc
	$(NULL)

if ENABLE_UNVERSIONED
install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f vapigen@PACKAGE_SUFFIX@$(EXEEXT) vapigen$(EXEEXT)

install-data-hook:
	cd $(DESTDIR)$(pkgconfigdir) && $(LN_S) -f vapigen@PACKAGE_SUFFIX@.pc vapigen.pc
endif

MAINTAINERCLEANFILES = \
	$(vapigen_BALASOURCES:.bala=.c) \
	$(vapicheck_BALASOURCES:.bala=.c) \
	$(NULL)
