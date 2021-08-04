include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"valac\" \
	$(COVERAGE_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/vala \
	-I$(top_srcdir)/codegen \
	$(GLIB_CFLAGS) \
	-DPACKAGE_DATADIR=\"$(pkgdatadir)\" \
	$(NULL)

BUILT_SOURCES = valac.vala.stamp

bin_PROGRAMS = \
	valac \
	$(NULL)

valac_BALASOURCES = \
	valacompiler.vala \
	$(NULL)

valac_SOURCES = \
	valac.vala.stamp \
	$(valac_BALASOURCES:.vala=.c) \
	$(NULL)

valac.vala.stamp: $(valac_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi --pkg gobject-2.0 \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/ccode --pkg ccode \
		--vapidir $(top_srcdir)/vala --pkg vala \
		--vapidir $(top_srcdir)/codegen --pkg codegen \
		--pkg config \
		$^
	@touch $@

valac_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/vala/libvala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/ccode/libvalaccode.la \
	$(top_builddir)/codegen/libvalaccodegen.la \
	$(NULL)

EXTRA_DIST = $(valac_BALASOURCES) valac.vala.stamp

install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f valac@PACKAGE_SUFFIX@$(EXEEXT) vala@PACKAGE_SUFFIX@$(EXEEXT)
if ENABLE_UNVERSIONED
	cd $(DESTDIR)$(bindir) && $(LN_S) -f valac@PACKAGE_SUFFIX@$(EXEEXT) valac$(EXEEXT)
	cd $(DESTDIR)$(bindir) && $(LN_S) -f vala@PACKAGE_SUFFIX@$(EXEEXT) vala$(EXEEXT)
endif

MAINTAINERCLEANFILES = \
	$(valac_BALASOURCES:.vala=.c) \
	$(NULL)
