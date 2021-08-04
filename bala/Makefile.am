include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"bala\" \
	$(COVERAGE_CFLAGS) \
	-I$(top_srcdir)/gee \
	$(GLIB_CFLAGS) \
	$(GMODULE_CFLAGS) \
	-DPACKAGE_DATADIR=\"$(pkgdatadir)\" \
	$(NULL)

BUILT_SOURCES = bala.bala.stamp $(srcdir)/balaversion.bala

$(srcdir)/balaversion.bala:
	sed -e "s#\@BALA_MAJOR_VERSION\@#$(BALA_MAJOR_VERSION)#g" \
		-e "s#\@BALA_MINOR_VERSION\@#$(BALA_MINOR_VERSION)#g" \
		-e "s#\@BALA_MICRO_VERSION\@#$(BALA_MICRO_VERSION)#g" \
		-e "s#\@API_VERSION\@#$(API_VERSION)#g" \
		-e "s#\@PACKAGE_VERSION\@#$(PACKAGE_VERSION)#g" \
		< $@.in > $@

lib_LTLIBRARIES = \
	libbala@PACKAGE_SUFFIX@.la \
	$(NULL)

libbala_la_BALASOURCES = \
	balaaddressofexpression.bala \
	balaarraycopymethod.bala \
	balaarraycreationexpression.bala \
	balaarraylengthfield.bala \
	balaarraymovemethod.bala \
	balaarrayresizemethod.bala \
	balaarraytype.bala \
	balaassignment.bala \
	balaattribute.bala \
	balabaseaccess.bala \
	balabasicblock.bala \
	balabinaryexpression.bala \
	balablock.bala \
	balabooleanliteral.bala \
	balabooleantype.bala \
	balabreakstatement.bala \
	balacallable.bala \
	balacallabletype.bala \
	balacastexpression.bala \
	balacatchclause.bala \
	balacharacterliteral.bala \
	balaclass.bala \
	balaclasstype.bala \
	balacodecontext.bala \
	balacodegenerator.bala \
	balacodenode.bala \
	balacodevisitor.bala \
	balacodewriter.bala \
	balacomment.bala \
	balagircomment.bala \
	balaconditionalexpression.bala \
	balaconstant.bala \
	balaconstructor.bala \
	balacontinuestatement.bala \
	balacreationmethod.bala \
	baladatatype.bala \
	baladeclarationstatement.bala \
	baladelegate.bala \
	baladelegatedestroyfield.bala \
	baladelegatetargetfield.bala \
	baladelegatetype.bala \
	baladeletestatement.bala \
	baladestructor.bala \
	baladostatement.bala \
	baladynamicmethod.bala \
	baladynamicproperty.bala \
	baladynamicsignal.bala \
	balaelementaccess.bala \
	balaemptystatement.bala \
	balaenum.bala \
	balaenumvalue.bala \
	balaenumvaluetype.bala \
	balaerrorcode.bala \
	balaerrordomain.bala \
	balaerrortype.bala \
	balaexpression.bala \
	balaexpressionstatement.bala \
	balafield.bala \
	balafieldprototype.bala \
	balafloatingtype.bala \
	balaflowanalyzer.bala \
	balaforeachstatement.bala \
	balaforstatement.bala \
	balagirparser.bala \
	balagenericdestroyfield.bala \
	balagenericdupfield.bala \
	balagenerictype.bala \
	balagenieparser.bala \
	balageniescanner.bala \
	balagenietokentype.bala \
	balaifstatement.bala \
	balainitializerlist.bala \
	balaintegerliteral.bala \
	balaintegertype.bala \
	balainterface.bala \
	balainterfacetype.bala \
	balainvalidtype.bala \
	balalambdaexpression.bala \
	balaliteral.bala \
	balalocalvariable.bala \
	balalockable.bala \
	balalockstatement.bala \
	balaloop.bala \
	balamarkupreader.bala \
	balamemberaccess.bala \
	balamemberinitializer.bala \
	balamethod.bala \
	balamethodcall.bala \
	balamethodtype.bala \
	balanamedargument.bala \
	balanamespace.bala \
	balanullliteral.bala \
	balanulltype.bala \
	balaobjectcreationexpression.bala \
	balaobjecttype.bala \
	balaobjecttypesymbol.bala \
	balaparameter.bala \
	balaparser.bala \
	balaphifunction.bala \
	balapointerindirection.bala \
	balapointertype.bala \
	balapostfixexpression.bala \
	balaprofile.bala \
	balapropertyaccessor.bala \
	balaproperty.bala \
	balapropertyprototype.bala \
	balarealliteral.bala \
	balareferencetransferexpression.bala \
	balareferencetype.bala \
	balaregexliteral.bala \
	balareport.bala \
	balareturnstatement.bala \
	balascanner.bala \
	balascope.bala \
	balasemanticanalyzer.bala \
	balasignal.bala \
	balasignaltype.bala \
	balasizeofexpression.bala \
	balasliceexpression.bala \
	balasourcefile.bala \
	balasourcelocation.bala \
	balasourcereference.bala \
	balastatement.bala \
	balastatementlist.bala \
	balastringliteral.bala \
	balastruct.bala \
	balastructvaluetype.bala \
	balasubroutine.bala \
	balaswitchlabel.bala \
	balaswitchsection.bala \
	balaswitchstatement.bala \
	balasymbol.bala \
	balasymbolresolver.bala \
	balatargetvalue.bala \
	balatemplate.bala \
	balathrowstatement.bala \
	balatokentype.bala \
	balatraversevisitor.bala \
	balatrystatement.bala \
	balatuple.bala \
	balatypecheck.bala \
	balatypeofexpression.bala \
	balatypeparameter.bala \
	balatypesymbol.bala \
	balaunaryexpression.bala \
	balaunlockstatement.bala \
	balaunresolvedsymbol.bala \
	balaunresolvedtype.bala \
	balausedattr.bala \
	balausingdirective.bala \
	balavaluetype.bala \
	balavariable.bala \
	balavartype.bala \
	balaversion.bala \
	balaversionattribute.bala \
	balavoidtype.bala \
	balawhilestatement.bala \
	balayieldstatement.bala \
	$(NULL)

libbala@PACKAGE_SUFFIX@_la_SOURCES = \
	bala.bala.stamp \
	$(libbala_la_BALASOURCES:.bala=.c) \
	$(NULL)

balaincludedir = $(includedir)/bala@PACKAGE_SUFFIX@

balainclude_HEADERS = \
	bala.h \
	$(NULL)

bala.bapi bala.bala.stamp: $(libbala_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--bapidir $(top_srcdir)/bapi --pkg gmodule-2.0 --pkg gobject-2.0 \
		--bapidir $(top_srcdir)/gee --pkg gee \
		--pkg config \
		--use-header \
		-H bala.h \
		--library bala \
		$^
	@touch $@

libbala@PACKAGE_SUFFIX@_la_LDFLAGS = \
	-no-undefined \
	$(NULL)

libbala@PACKAGE_SUFFIX@_la_LIBADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(GMODULE_LIBS) \
	$(top_builddir)/gee/libgee.la \
	$(NULL)

bapidir = $(datadir)/bala/bapi
dist_bapi_DATA = libbala@PACKAGE_SUFFIX@.bapi

libbala@PACKAGE_SUFFIX@.bapi: $(top_srcdir)/gee/gee.bapi $(top_srcdir)/bala/bala.bapi
	cat $^ > $@

EXTRA_DIST = $(libbala_la_BALASOURCES) bala.bapi bala.bala.stamp bala.h balaversion.bala.in

MAINTAINERCLEANFILES = \
	bala.bapi \
	bala.h \
	$(libbala_la_BALASOURCES:.bala=.c) \
	$(NULL)
