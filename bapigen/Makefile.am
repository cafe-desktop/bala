include $(top_srcdir)/Makefile.common

NULL =

SUBDIRS = \
	bala-gen-introspect \
	$(NULL)

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"bapigen\" \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	-I$(top_srcdir)/gobject-introspection \
	$(NULL)

bin_PROGRAMS = \
	bapigen \
	$(NULL)

noinst_PROGRAMS = \
	bapicheck \
	$(NULL)

BUILT_SOURCES = bapigen.bala.stamp bapicheck.bala.stamp

bapigen_BALASOURCES = \
	balagidlparser.bala \
	balabapigen.bala \
	$(NULL)

bapigen_SOURCES = \
	bapigen.bala.stamp \
	$(bapigen_BALASOURCES:.bala=.c) \
	$(NULL)

bapicheck_BALASOURCES = \
	balabapicheck.bala \
	$(NULL)

bapicheck_SOURCES = \
	bapicheck.bala.stamp \
	$(bapicheck_BALASOURCES:.bala=.c) \
	$(NULL)

bapigen.bala.stamp: $(bapigen_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi \
		--bapidir $(top_srcdir)/gee --pkg gee \
		--bapidir $(top_srcdir)/bala --pkg bala \
		--bapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

bapicheck.bala.stamp: $(bapicheck_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi \
		--bapidir $(top_srcdir)/gee --pkg gee \
		--bapidir $(top_srcdir)/bala --pkg bala \
		--bapidir $(top_srcdir)/gobject-introspection --pkg gidl \
		--pkg config \
		$^
	@touch $@

bapigen_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

bapicheck_LDADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/gobject-introspection/libgidl.la \
	$(NULL)

if ENABLE_UNVERSIONED
makedir = $(datadir)/bala
make_DATA = Makefile.bapigen

aclocaldir = $(datadir)/aclocal
aclocal_DATA = bapigen.m4
endif

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = bapigen@PACKAGE_SUFFIX@.pc

bapigen@PACKAGE_SUFFIX@.pc: bapigen.pc
	cp $< $@

EXTRA_DIST = \
	$(bapigen_BALASOURCES) \
	$(bapicheck_BALASOURCES) \
	Makefile.bapigen \
	bapigen.m4 \
	bapigen.bala.stamp \
	bapicheck.bala.stamp \
	$(NULL)

CLEANFILES = \
	bapigen@PACKAGE_SUFFIX@.pc
	$(NULL)

if ENABLE_UNVERSIONED
install-exec-hook:
	cd $(DESTDIR)$(bindir) && $(LN_S) -f bapigen@PACKAGE_SUFFIX@$(EXEEXT) bapigen$(EXEEXT)

install-data-hook:
	cd $(DESTDIR)$(pkgconfigdir) && $(LN_S) -f bapigen@PACKAGE_SUFFIX@.pc bapigen.pc
endif

MAINTAINERCLEANFILES = \
	$(bapigen_BALASOURCES:.bala=.c) \
	$(bapicheck_BALASOURCES:.bala=.c) \
	$(NULL)
