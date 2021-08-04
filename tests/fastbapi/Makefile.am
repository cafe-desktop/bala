NULL =

check-fastvapi: $(top_builddir)/compiler/balac
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--disable-version-header \
		--vapidir $(top_srcdir)/vapi \
		--fast-vapi fastvapitest.vapi \
		--basedir $(srcdir) \
		$(srcdir)/fastvapitest.bala; \
	tail -n +3 fastvapitest.vapi | diff -wu $(srcdir)/fastvapitest.vapi-expected - || exit 1; \
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--disable-version-header \
		--vapidir $(top_srcdir)/vapi \
		--use-fast-vapi fastvapitest.vapi \
		--basedir $(builddir) \
		$(srcdir)/usefastvapitest.bala || exit 1; \
	rm -f fastvapitest.vapi fastvapitest.c usefastvapitest.c

check: check-fastvapi

EXTRA_DIST = \
	fastvapitest.bala \
	fastvapitest.vapi-expected \
	usefastvapitest.bala \
	$(NULL)

CLEANFILES = \
	fastvapitest.c \
	fastvapitest.vapi \
	usefastvapitest.c \
	$(NULL)
