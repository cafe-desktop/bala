include $(top_srcdir)/Makefile.common

NULL =

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"bala-ccode\" \
	$(COVERAGE_CFLAGS) \
	-I$(top_srcdir)/gee \
	-I$(top_srcdir)/bala \
	$(GLIB_CFLAGS) \
	$(NULL)

BUILT_SOURCES = ccode.bala.stamp

noinst_LTLIBRARIES = \
	libbalaccode.la \
	$(NULL)

libbalaccode_la_BALASOURCES = \
	balaccodeassignment.bala \
	balaccodebinaryexpression.bala \
	balaccodeblock.bala \
	balaccodebreakstatement.bala \
	balaccodecasestatement.bala \
	balaccodecastexpression.bala \
	balaccodecommaexpression.bala \
	balaccodecomment.bala \
	balaccodeconditionalexpression.bala \
	balaccodeconstant.bala \
	balaccodecontinuestatement.bala \
	balaccodedeclaration.bala \
	balaccodedeclarator.bala \
	balaccodedefine.bala \
	balaccodedostatement.bala \
	balaccodeemptystatement.bala \
	balaccodeenum.bala \
	balaccodeenumvalue.bala \
	balaccodeexpression.bala \
	balaccodeexpressionstatement.bala \
	balaccodefile.bala \
	balaccodeforstatement.bala \
	balaccodefragment.bala \
	balaccodefunction.bala \
	balaccodefunctioncall.bala \
	balaccodefunctiondeclarator.bala \
	balaccodeggnucsection.bala \
	balaccodegotostatement.bala \
	balaccodeidentifier.bala \
	balaccodeifstatement.bala \
	balaccodeincludedirective.bala \
	balaccodeinitializerlist.bala \
	balaccodeinvalidexpression.bala \
	balaccodelabel.bala \
	balaccodelinedirective.bala \
	balaccodeifsection.bala \
	balaccodemacroreplacement.bala \
	balaccodememberaccess.bala \
	balaccodemodifiers.bala \
	balaccodenewline.bala \
	balaccodenode.bala \
	balaccodeoncesection.bala \
	balaccodeparameter.bala \
	balaccodeparenthesizedexpression.bala \
	balaccodereturnstatement.bala \
	balaccodestatement.bala \
	balaccodestruct.bala \
	balaccodeswitchstatement.bala \
	balaccodetypedefinition.bala \
	balaccodeunaryexpression.bala \
	balaccodevariabledeclarator.bala \
	balaccodewhilestatement.bala \
	balaccodewriter.bala \
	balaccodeelementaccess.bala \
	$(NULL)

libbalaccode_la_SOURCES = \
	ccode.bala.stamp \
	$(libbalaccode_la_BALASOURCES:.bala=.c) \
	$(NULL)

ccode.vapi ccode.bala.stamp: $(libbalaccode_la_BALASOURCES)
	$(BALA_V)$(BALAC) \
		$(COVERAGE_BALAFLAGS) \
		$(BALAFLAGS) \
		-C \
		--vapidir $(top_srcdir)/vapi --pkg gobject-2.0 \
		--vapidir $(top_srcdir)/gee --pkg gee \
		--vapidir $(top_srcdir)/bala --pkg bala \
		--pkg config \
		--use-header \
		-H balaccode.h \
		--library ccode \
		$^
	touch $@

libbalaccode_la_LIBADD = \
	$(COVERAGE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/bala/libbala@PACKAGE_SUFFIX@.la \
	$(NULL)

EXTRA_DIST = $(libbalaccode_la_BALASOURCES) ccode.vapi ccode.bala.stamp balaccode.h

MAINTAINERCLEANFILES = \
	ccode.vapi \
	balaccode.h \
	$(libbalaccode_la_BALASOURCES:.bala=.c) \
	$(NULL)
