NULL =

check-girwriter: $(top_builddir)/compiler/balac
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--disable-version-header \
		--bapidir $(top_srcdir)/bapi \
		--pkg gio-2.0 \
		--gir GirTest-1.0.gir \
		--library girtest \
		--shared-library girtest \
		$(srcdir)/girtest.bala; \
	tail -n +3 girtest.bapi | diff -wu $(srcdir)/girtest.bapi-expected - || exit 1; \
	tail -n +3 GirTest-1.0.gir | diff -wu $(srcdir)/GirTest-1.0.gir-expected - || exit 1;
if HAVE_G_IR_COMPILER
	$(G_IR_COMPILER) -o GirTest-1.0.typelib GirTest-1.0.gir;
endif
	rm -f girtest.bapi girtest.c;
	G_DEBUG=fatal-warnings $(top_builddir)/bapigen/bapigen \
		--bapidir $(top_srcdir)/bapi \
		--pkg gio-2.0 \
		--library girtest \
		--metadatadir $(srcdir) \
		GirTest-1.0.gir; \
	tail -n +3 girtest.bapi | diff -wu $(srcdir)/girtest.bapigen-expected - || exit 1;
	rm -f GirTest-1.0.gir GirTest-1.0.typelib girtest.bapi;

check: check-girwriter

EXTRA_DIST = \
	girtest.bala \
	girtest.bapi-expected \
	girtest.bapigen-expected \
	GirTest-1.0.gir-expected \
	GirTest-1.0.metadata \
	$(NULL)

CLEANFILES = \
	girtest.c \
	girtest.bapi \
	GirTest-1.0.gir \
	GirTest-1.0.typelib \
	$(NULL)
