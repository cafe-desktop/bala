NULL =

check-fastbapi: $(top_builddir)/compiler/balac
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--disable-version-header \
		--bapidir $(top_srcdir)/bapi \
		--fast-bapi fastbapitest.bapi \
		--basedir $(srcdir) \
		$(srcdir)/fastbapitest.bala; \
	tail -n +3 fastbapitest.bapi | diff -wu $(srcdir)/fastbapitest.bapi-expected - || exit 1; \
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--disable-version-header \
		--bapidir $(top_srcdir)/bapi \
		--use-fast-bapi fastbapitest.bapi \
		--basedir $(builddir) \
		$(srcdir)/usefastbapitest.bala || exit 1; \
	rm -f fastbapitest.bapi fastbapitest.c usefastbapitest.c

check: check-fastbapi

EXTRA_DIST = \
	fastbapitest.bala \
	fastbapitest.bapi-expected \
	usefastbapitest.bala \
	$(NULL)

CLEANFILES = \
	fastbapitest.c \
	fastbapitest.bapi \
	usefastbapitest.c \
	$(NULL)
