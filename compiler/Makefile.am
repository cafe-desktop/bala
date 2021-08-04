include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"balac\" \
	$(COVERAGE_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	-I$(top_srcdir)/codegen \
	$(GLIB_CFLAGS) \
	-DPACKAGE_DATADIR=\"$(pkgdatadir)\" \
	$(NULL)

BUILT_SOURCES = balac.bala.stamp

bin_PROGRAMS = \
	balac \
	$(NULL)

balac_BALASOURCES = \
	balacompiler.bala \
	$(NULL)

balac_SOURCES = \
	balac.bala.stamp \
	$(balac_BALASOURCES:.bala=.c) \
	$(NULL)

balac.bala.stamp: $(balac_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi --pkg gobject-2.0 \
		--bapidir $(top_srcdir)/gee --pkg gee \
		--bapidir $(top_srcdir)/ccode --pkg ccode \
		--bapidir $(top_srcdir)/bala --pkg bala \
		--bapidir $(top_srcdir)/codegen --pkg codegen \
		--pkg config \
		$^
	@touch $@

balac_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/ccode/libbalaccode.la \
	$(top_builddir)/codegen/libbalaccodegen.la \
	$(NULL)

EXTRA_DIST = $(balac_BALASOURCES) balac.bala.stamp

install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f balac@PACKAGE_SUFFIX@$(EXEEXT) bala@PACKAGE_SUFFIX@$(EXEEXT)
if ENABLE_UNVERSIONED
	cd $(DESTDIR)$(bindir) && $(LN_S) -f balac@PACKAGE_SUFFIX@$(EXEEXT) balac$(EXEEXT)
	cd $(DESTDIR)$(bindir) && $(LN_S) -f bala@PACKAGE_SUFFIX@$(EXEEXT) bala$(EXEEXT)
endif

MAINTAINERCLEANFILES = \
	$(balac_BALASOURCES:.bala=.c) \
	$(NULL)
