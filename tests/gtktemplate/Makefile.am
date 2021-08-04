NULL =

check-gtktemplate: $(top_builddir)/compiler/balac
	G_DEBUG=fatal-warnings $(top_builddir)/compiler/balac \
		-C \
		--vapidir $(top_srcdir)/vapi \
		--pkg gtk+-3.0 \
		--gresources $(srcdir)/gtktemplate.gresource.xml \
		$(srcdir)/gtktemplate.bala; \
	rm -f gtktemplate.c

check: check-gtktemplate

EXTRA_DIST = \
	gtktemplate.gresource.xml \
	gtktemplate.ui \
	gtktemplate.bala \
	$(NULL)

CLEANFILES = \
	gtktemplate.c \
	$(NULL)
