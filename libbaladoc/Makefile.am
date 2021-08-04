include $(top_srcdir)/Makefile.common

NULL =

AM_CFLAGS = \
	-DG_LOG_DOMAIN=\"baladoc\" \
	-DPACKAGE_BALADOC_LIBDIR=\"$(libdir)/baladoc@PACKAGE_SUFFIX@\" \
	-DPACKAGE_VERSION=\"$(VERSION)\" \
	$(COVERAGE_CFLAGS) \
	$(LIBGVC_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(GMODULE_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/ccode \
	-I$(top_srcdir)/bala \
	-I$(top_srcdir)/codegen \
	$(NULL)

AM_BALAFLAGS = \
	$(NULL)

BUILT_SOURCES = \
	libbaladoc.bala.stamp \
	baladoc.h \
	$(NULL)

lib_LTLIBRARIES = libbaladoc@PACKAGE_SUFFIX@.la

libbaladoc_la_BALASOURCES = \
	doclet.bala \
	errorreporter.bala \
	filehelper.bala \
	moduleloader.bala \
	settings.bala \
	markupwriter.bala \
	gtkdocmarkupwriter.bala \
	devhelp-markupwriter.bala \
	ctyperesolver.bala \
	gtkdocrenderer.bala \
	documentation/commentscanner.bala \
	documentation/documentation.bala \
	documentation/documentationparser.bala \
	documentation/wiki.bala \
	documentation/wikiscanner.bala \
	documentation/gtkdoccommentparser.bala \
	documentation/gtkdoccommentscanner.bala \
	documentation/gtkdocmarkdownparser.bala \
	documentation/gtkdocmarkdownscanner.bala \
	documentation/importerhelper.bala \
	documentation/girmetadata.bala \
	importer/documentationimporter.bala \
	importer/baladocdocumentationimporter.bala \
	importer/baladocdocumentationimporterscanner.bala \
	importer/girdocumentationimporter.bala \
	importer/internalidregistrar.bala \
	api/sourcecomment.bala \
	api/girsourcecomment.bala \
	api/attribute.bala \
	api/array.bala \
	api/callable.bala \
	api/childsymbolregistrar.bala \
	api/class.bala \
	api/constant.bala \
	api/delegate.bala \
	api/enum.bala \
	api/enumvalue.bala \
	api/errorcode.bala \
	api/errordomain.bala \
	api/field.bala \
	api/interface.bala \
	api/item.bala \
	api/method.bala \
	api/namespace.bala \
	api/node.bala \
	api/nodetype.bala \
	api/ownership.bala \
	api/package.bala \
	api/parameter.bala \
	api/pointer.bala \
	api/property.bala \
	api/propertyaccessor.bala \
	api/signal.bala \
	api/signaturebuilder.bala \
	api/sourcefile.bala \
	api/struct.bala \
	api/symbol.bala \
	api/tree.bala \
	api/typeparameter.bala \
	api/typereference.bala \
	api/typesymbol.bala \
	api/visitor.bala \
	content/block.bala \
	content/blockcontent.bala \
	content/comment.bala \
	content/contentfactory.bala \
	content/contentelement.bala \
	content/contentrenderer.bala \
	content/contentvisitor.bala \
	content/embedded.bala \
	content/headline.bala \
	content/inline.bala \
	content/inlinetaglet.bala \
	content/inlinecontent.bala \
	content/wikilink.bala \
	content/link.bala \
	content/list.bala \
	content/listitem.bala \
	content/page.bala \
	content/paragraph.bala \
	content/warning.bala \
	content/note.bala \
	content/resourcelocator.bala \
	content/run.bala \
	content/sourcecode.bala \
	content/styleattributes.bala \
	content/symbollink.bala \
	content/table.bala \
	content/tablecell.bala \
	content/tablerow.bala \
	content/taglet.bala \
	content/text.bala \
	charts/chart.bala \
	charts/chartfactory.bala \
	charts/hierarchychart.bala \
	charts/simplechartfactory.bala \
	parser/manyrule.bala \
	parser/oneofrule.bala \
	parser/optionalrule.bala \
	parser/parser.bala \
	parser/parsercallback.bala \
	parser/rule.bala \
	parser/scanner.bala \
	parser/sequencerule.bala \
	parser/stubrule.bala \
	parser/token.bala \
	parser/tokentype.bala \
	taglets/tagletdeprecated.bala \
	taglets/tagletinheritdoc.bala \
	taglets/tagletinit.bala \
	taglets/tagletlink.bala \
	taglets/tagletparam.bala \
	taglets/tagletreturn.bala \
	taglets/tagletsee.bala \
	taglets/tagletsince.bala \
	taglets/tagletthrows.bala \
	highlighter/scanner.bala \
	highlighter/codescanner.bala \
	highlighter/xmlscanner.bala \
	highlighter/codetoken.bala \
	highlighter/highlighter.bala \
	html/basicdoclet.bala \
	html/htmlchartfactory.bala \
	html/linkhelper.bala \
	html/cssclassresolver.bala \
	html/htmlmarkupwriter.bala \
	html/htmlrenderer.bala \
	$(NULL)

libbaladoc@PACKAGE_SUFFIX@_la_SOURCES = \
	libbaladoc.bala.stamp \
	$(libbaladoc_la_BALASOURCES:.bala=.c) \
	gvc-compat.c \
	$(NULL)

baladoc@PACKAGE_SUFFIX@.vapi baladoc.h: libbaladoc.bala.stamp
libbaladoc.bala.stamp: $(libbaladoc_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		--basedir $(srcdir) \
		--directory $(builddir) \
		-C \
		--use-header \
		-H baladoc.h \
		--library baladoc \
		--vapi baladoc@PACKAGE_SUFFIX@.vapi \
		--vapidir $(top_srcdir)/vapi --pkg gmodule-2.0 \
		--vapidir $(top_srcdir)/vapi --pkg libgvc \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/bala --pkg bala \
		--vapidir $(top_srcdir)/ccode --pkg ccode \
		--vapidir $(top_srcdir)/codegen --pkg codegen \
		--pkg config \
		$(filter %.bala %.c,$^)
	touch $@

libbaladoc@PACKAGE_SUFFIX@_la_LDFLAGS = \
	-no-undefined \
	$(NULL)

libbaladoc@PACKAGE_SUFFIX@_la_LIBADD = \
	$(COVERAGE_LIBS) \
	$(LIBGVC_LIBS) \
	$(GLIB_LIBS) \
	$(GMODULE_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(top_builddir)/codegen/libbalaccodegen.la \
	$(NULL)

libbaladocincludedir = $(includedir)/baladoc@PACKAGE_SUFFIX@
libbaladocinclude_HEADERS = \
	baladoc.h \
	$(NULL)

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = baladoc@PACKAGE_SUFFIX@.pc

baladoc@PACKAGE_SUFFIX@.pc: baladoc.pc
	cp $< $@

vapidir = $(datadir)/bala/vapi
dist_vapi_DATA = baladoc@PACKAGE_SUFFIX@.vapi
nodist_vapi_DATA = baladoc@PACKAGE_SUFFIX@.deps

baladoc@PACKAGE_SUFFIX@.deps: baladoc.deps
	cp $< $@

EXTRA_DIST = \
	$(libbaladoc_la_BALASOURCES) \
	libbaladoc.bala.stamp \
	baladoc.deps.in \
	baladoc.pc.in \
	$(NULL)

CLEANFILES = \
	baladoc@PACKAGE_SUFFIX@.deps \
	baladoc@PACKAGE_SUFFIX@.pc \
	$(NULL)

MAINTAINERCLEANFILES = \
	baladoc.deps \
	baladoc.pc \
	baladoc.vapi \
	baladoc.h \
	$(libbaladoc_la_BALASOURCES:.bala=.c) \
	$(NULL)

