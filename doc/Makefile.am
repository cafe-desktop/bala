NULL =

SUBDIRS = \
	manual \
	$(NULL)

dist_man_MANS = \
	balac.1 \
	bala-gen-introspect.1 \
	bapigen.1 \
	$(NULL)

if ENABLE_BALADOC
dist_man_MANS += \
	baladoc.1 \
	$(NULL)
endif

EXTRA_DIST = \
	balac.h2m \
	baladoc.h2m \
	bala-gen-introspect.h2m \
	bapigen.h2m \
	$(NULL)

if HAVE_HELP2MAN
if ENABLE_BALADOC
manpages: balac.1 baladoc.1 bala-gen-introspect.1 bapigen.1
else
manpages: balac.1 bala-gen-introspect.1 bapigen.1
endif
	@rm $^
	$(MAKE) $(AM_MAKEFLAGS) $^

balac.1:
	$(HELP2MAN) $(top_builddir)/compiler/balac \
		--include $(srcdir)/balac.h2m \
		--libtool --no-info \
		--output=$@
if ENABLE_BALADOC
baladoc.1:
	$(HELP2MAN) $(top_builddir)/baladoc/baladoc \
		--include $(srcdir)/baladoc.h2m \
		--libtool --no-info \
		--output=$@
endif
bala-gen-introspect.1:
	$(HELP2MAN) $(top_builddir)/gobject-introspection/gen-introspect \
		--include $(srcdir)/bala-gen-introspect.h2m \
		--version-string=$(PACKAGE_VERSION) \
		--libtool --no-info \
		--output=$@
bapigen.1:
	$(HELP2MAN) $(top_builddir)/bapigen/bapigen \
		--include $(srcdir)/bapigen.h2m \
		--libtool --no-info \
		--output=$@
endif

if ENABLE_UNVERSIONED
install-data-hook:
	cd $(DESTDIR)$(man1dir) && $(LN_S) -f balac@PACKAGE_SUFFIX@.1 balac.1
if ENABLE_BALADOC
	cd $(DESTDIR)$(man1dir) && $(LN_S) -f baladoc@PACKAGE_SUFFIX@.1 baladoc.1
endif
	cd $(DESTDIR)$(man1dir) && $(LN_S) -f bala-gen-introspect@PACKAGE_SUFFIX@.1 bala-gen-introspect.1
	cd $(DESTDIR)$(man1dir) && $(LN_S) -f bapigen@PACKAGE_SUFFIX@.1 bapigen.1
endif


if ENABLE_BALADOC
COMMON_BALADOCFLAGS = \
	--force \
	--verbose \
	--private \
	--internal \
	--use-svg-images \
	--bapidir=$(top_builddir)/bapi \
	--pkg config \
	--pkg gmodule-2.0 \
	--directory=internal-apis/ \
	--doclet=$(top_builddir)/baladoc/doclets/html/.libs \
	--doclet-arg "--no-browsable-check" \
	--basedir=internal-apis/ \
	$(NULL)

if HAVE_CGRAPH
COMMON_BALADOCFLAGS += -D WITH_CGRAPH
endif

gee_BALASOURCES = $(top_srcdir)/gee/*.bala
internal-apis/gee: $(gee_BALASOURCES)
	$(AM_V_GEN)$(top_builddir)/baladoc/baladoc \
		$(COMMON_BALADOCFLAGS) \
		--package-name gee \
		--package-version $(PACKAGE_VERSION) \
		--deps \
		$(filter %.bala,$^)
	@touch $@

bala_BALASOURCES = $(top_srcdir)/bala/*.bala
internal-apis/bala: $(bala_BALASOURCES) internal-apis/gee
	$(AM_V_GEN)$(top_builddir)/baladoc/baladoc \
		$(COMMON_BALADOCFLAGS) \
		--package-name bala \
		--package-version $(PACKAGE_VERSION) \
		--bapidir=$(top_builddir)/gee --pkg gee \
		--deps \
		$(filter %.bala,$^)
	@touch $@

ccode_BALASOURCES = $(top_srcdir)/ccode/*.bala
internal-apis/ccode: $(ccode_BALASOURCES) internal-apis/gee
	$(AM_V_GEN)$(top_builddir)/baladoc/baladoc \
		$(COMMON_BALADOCFLAGS) \
		--package-name ccode \
		--package-version $(PACKAGE_VERSION) \
		--bapidir=$(top_builddir)/gee --pkg gee \
		--bapidir=$(top_builddir)/bala --pkg bala \
		--deps \
		$(filter %.bala,$^)
	@touch $@

codegen_BALASOURCES = $(top_srcdir)/codegen/*.bala
internal-apis/codegen: $(codegen_BALASOURCES) internal-apis/bala internal-apis/ccode
	$(AM_V_GEN)$(top_builddir)/baladoc/baladoc\
		$(COMMON_BALADOCFLAGS) \
		--package-name codegen \
		--package-version $(PACKAGE_VERSION) \
		--bapidir=$(top_builddir)/gee --pkg gee \
		--bapidir=$(top_builddir)/bala --pkg bala \
		--bapidir=$(top_builddir)/ccode --pkg ccode \
		--deps \
		$(filter %.bala,$^)
	@touch $@

baladoc_BALASOURCES = $(top_srcdir)/libbaladoc/*.bala $(top_srcdir)/libbaladoc/*/*.bala
internal-apis/baladoc: $(baladoc_BALASOURCES) internal-apis/codegen
	$(AM_V_GEN)$(top_builddir)/baladoc/baladoc\
		$(COMMON_BALADOCFLAGS) \
		--package-name baladoc \
		--package-version $(PACKAGE_VERSION) \
		--bapidir=$(top_srcdir)/bapi --pkg libgvc \
		--bapidir=$(top_builddir)/gee --pkg gee \
		--bapidir=$(top_builddir)/bala --pkg bala \
		--bapidir=$(top_builddir)/ccode --pkg ccode \
		--bapidir=$(top_builddir)/codegen --pkg codegen \
		--deps \
		$(filter %.bala,$^)
	@touch $@

internal-api-docs: internal-apis/gee internal-apis/bala internal-apis/ccode internal-apis/codegen internal-apis/baladoc
endif

clean-local:
	rm -rf $(builddir)/internal-apis
