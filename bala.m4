dnl bala.m4
dnl
dnl Copyright 2010 Marc-Andre Lureau
dnl Copyright 2011 Rodney Dawes <dobey.pwns@gmail.com>
dnl
dnl This library is free software; you can redistribute it and/or
dnl modify it under the terms of the GNU Lesser General Public
dnl License as published by the Free Software Foundation; either
dnl version 2.1 of the License, or (at your option) any later version.
dnl
dnl This library is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
dnl Lesser General Public License for more details.
dnl
dnl You should have received a copy of the GNU Lesser General Public
dnl License along with this library; if not, write to the Free Software
dnl Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

# _BALA_CHECK_COMPILE_WITH_ARGS(ARGS, [ACTION-IF-TRUE],
#   [ACTION-IF-FALSE])
# --------------------------------------
# Check that Bala compile with ARGS.
#
AC_DEFUN([_BALA_CHECK_COMPILE_WITH_ARGS],
[AC_REQUIRE([AM_PROG_BALAC])[]dnl

  cat <<_ACEOF >conftest.bala
void main(){}
_ACEOF

  AS_IF([bala_error=`$BALAC $1 -q --cc="${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS}" -o conftest$ac_exeext conftest.bala 2>&1`],
        [$2], [$3])
])

])# _BALA_CHECK_COMPILE_WITH_ARGS

# BALA_CHECK_PACKAGES(PKGS, [ACTION-IF-FOUND],
#   [ACTION-IF-NOT-FOUND])
# --------------------------------------
# Check that PKGS Bala bindings are installed and usable.
#
AC_DEFUN([BALA_CHECK_PACKAGES],
[
  unset bala_pkgs
  unset bala_bindings
  ac_save_ifs="$IFS"; unset IFS
  for bala_pkg in $(echo "$1"); do
      bala_pkgs="${bala_pkgs:+$bala_pkgs }--pkg $bala_pkg"
      bala_bindings="${bala_bindings:+$bala_bindings }$bala_pkg"
  done
  IFS="$ac_save_ifs"
  AC_MSG_CHECKING([for $bala_bindings bala bindings])
  _BALA_CHECK_COMPILE_WITH_ARGS([$bala_pkgs],
    [bala_pkg_exists=yes],
    [bala_pkg_exists=no])

AS_IF([test x${bala_pkg_exists} = xno],[
  ifelse([$3], , [AC_MSG_ERROR([]dnl
[Package requirements were not met: $1

$bala_error

Consider adjusting the XDG_DATA_DIRS environment variable if you
installed bindings in a non-standard prefix.
])],
  [AC_MSG_RESULT([no])
$3])],[
  AC_MSG_RESULT([yes])
  ifelse([$2], , :, [$2])[]dnl
])

])# BALA_CHECK_PACKAGES


# Check for Bala bindings for a package, as well as the pkg-config
# CFLAGS and LIBS for the package. The arguments here work the
# same as those for PKG_CHECK_MODULES, which is called internally.
# As a result, the _CFLAGS, _LIBS, and _BALAFLAGS variables will
# all be declared, rather than only _BALAFLAGS.
#
# BALA_CHECK_MODULES(VARIABLE-PREFIX, MODULES, [ACTION-IF-FOUND],
# [ACTION-IF-NOT-FOUND])
# --------------------------------------------------------------
AC_DEFUN([BALA_CHECK_MODULES],
[
		AC_REQUIRE([AM_PROG_BALAC])dnl
		AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
        AC_REQUIRE([_BALA_CHECK_COMPILE_WITH_ARGS])dnl
		AC_ARG_VAR([$1][_BALAFLAGS], [Bala compiler flags for $1])dnl

        BALA_MODULES="`echo $2 | sed -e 's/ [[=<>]]\+ [[0-9.]]\+//g'`"
        for MODULE in $BALA_MODULES; do
            $1[]_BALAFLAGS="$[]$1[]_BALAFLAGS --pkg $MODULE"
        done

        PKG_CHECK_MODULES([$1], [$2], [$3], [$4])

        pkg_failed=no
		AC_MSG_CHECKING([for $1 bala modules])

        _BALA_CHECK_COMPILE_WITH_ARGS([$1][_BALAFLAGS],
                                      [pkg_failed=yes],
                                      [pkg_failed=no])

		if test $pkg_failed = yes; then
		   AC_MSG_RESULT([no])
		   m4_default([$4], [AC_MSG_ERROR(
							[Package requirements ($2) were not met.])dnl
		   ])
		else
			AC_MSG_RESULT([yes])
			m4_default([$3], [:])
		fi[]dnl
])

# Check whether the Bala API Generator exists in `PATH'. If it is found,
# the variable BAPIGEN is set. Optionally a minimum release number of the
# generator can be requested.
#
# BALA_PROG_BAPIGEN([MINIMUM-VERSION])
# ------------------------------------
AC_DEFUN([BALA_PROG_BAPIGEN],
[AC_PATH_PROG([BAPIGEN], [bapigen], [])
  AS_IF([test -z "$BAPIGEN"],
    [AC_MSG_WARN([No Bala API Generator found. You will not be able to generate .bapi files.])],
    [AS_IF([test -n "$1"],
        [AC_MSG_CHECKING([$BAPIGEN is at least version $1])
         am__bapigen_version=`$BAPIGEN --version | sed 's/Bala API Generator  *//'`
         AS_VERSION_COMPARE([$1], ["$am__bapigen_version"],
           [AC_MSG_RESULT([yes])],
           [AC_MSG_RESULT([yes])],
           [AC_MSG_RESULT([no])
            AC_MSG_ERROR([Bala API Generator $1 not found.])])])])
])
