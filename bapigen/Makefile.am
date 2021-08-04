include $(top_srcdir)/Makefile.common

NULL =

SUBDIRS = \
	vala-gen-introspect \
	$(NULL)

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"vapigen\" \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/vala \
	-I$(top_srcdir)/gobject-introspection \
	$(NULL)

bin_PROGRAMS = \
	vapigen \
	$(NULL)

noinst_PROGRAMS = \
	vapicheck \
	$(NULL)

BUILT_SOURCES = vapigen.vala.stamp vapicheck.vala.stamp

vapigen_BALASOURCES = \
	valagidlparser.vala \
	valavapigen.vala \
	$(NULL)

vapigen_SOURCES = \
	vapigen.vala.stamp \
	$(vapigen_BALASOURCES:.vala=.c) \
	$(NULL)

vapicheck_BALASOURCES = \
	valavapicheck.vala \
	$(NULL)

vapicheck_SOURCES = \
	vapicheck.vala.stamp \
	$(vapicheck_BALASOURCES:.vala=.c) \
	$(NULL)

vapigen.vala.stamp: $(vapigen_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/vala --pkg vala \
		--vapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

vapicheck.vala.stamp: $(vapicheck_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/vala --pkg vala \
		--vapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

vapigen_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/vala/libvala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

vapicheck_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/vala/libvala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

if ENABLE_UNVERSIONED
makedir = $(datadir)/vala
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
	vapigen.vala.stamp \
	vapicheck.vala.stamp \
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
	$(vapigen_BALASOURCES:.vala=.c) \
	$(vapicheck_BALASOURCES:.vala=.c) \
	$(NULL)
