include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"bala\" \
	$(COVERAGE_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(NULL)

BUILT_SOURCES = gee.bala.stamp

noinst_LTLIBRARIES = \
	libgee.la \
	$(NULL)

libgee_la_BALASOURCES = \
	arraylist.bala \
	collection.bala \
	hashmap.bala \
	hashset.bala \
	iterable.bala \
	mapiterator.bala \
	iterator.bala \
	list.bala \
	map.bala \
	set.bala \
	timsort.bala \
	$(NULL)

libgee_la_SOURCES = \
	gee.bala.stamp \
	$(libgee_la_BALASOURCES:.bala=.c) \
	$(NULL)

geeincludedir = $(includedir)/bala@PACKAGE_SUFFIX@

geeinclude_HEADERS = \
	balagee.h \
	$(NULL)

gee.vapi gee.bala.stamp: $(libgee_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi --pkg gobject-2.0 \
		--use-header \
		-H balagee.h \
		--library gee \
		$^
	@touch $@

libgee_la_LIBADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(NULL)

EXTRA_DIST = $(libgee_la_BALASOURCES) gee.vapi gee.bala.stamp balagee.h

MAINTAINERCLEANFILES = \
	gee.vapi \
	balagee.h \
	$(libgee_la_BALASOURCES:.bala=.c) \
	$(NULL)
