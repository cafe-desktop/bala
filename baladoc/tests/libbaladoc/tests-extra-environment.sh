BALAFLAGS="\
	-X -D -X TOP_SRC_DIR=\"$abs_top_srcdir\" \
	--pkg libgvc \
	--vapidir $abs_top_srcdir/bala \
	--pkg libbala$PACKAGE_SUFFIX \
	--vapidir $abs_top_srcdir/libbaladoc \
	--pkg baladoc$PACKAGE_SUFFIX \
	--main main \
	-X -L$abs_top_builddir/bala/.libs -X -lbala$PACKAGE_SUFFIX \
	-X -L$abs_top_builddir/libbaladoc/.libs -X -lbaladoc$PACKAGE_SUFFIX \
	-X -I$abs_top_srcdir/gee \
	-X -I$abs_top_srcdir/bala \
	-X -I$abs_top_srcdir/libbaladoc \
	$abs_top_srcdir/baladoc/tests/libbaladoc/parser-generic-scanner.bala \
"
export PKG_CONFIG_PATH=$abs_top_builddir:$abs_top_builddir/libbaladoc
export LD_LIBRARY_PATH=$abs_top_builddir/bala/.libs:$abs_top_builddir/libbaladoc/.libs
