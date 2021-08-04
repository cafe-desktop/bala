dnl vapigen.m4
dnl
dnl Copyright 2012 Evan Nemerson
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

# BAPIGEN_CHECK([VERSION], [API_VERSION], [FOUND_INTROSPECTION], [DEFAULT])
# --------------------------------------
# Check vapigen existence and version
#
# See http://live.gnome.org/Bala/UpstreamGuide for detailed documentation
AC_DEFUN([BAPIGEN_CHECK],
[
  AS_IF([test "x$3" != "xyes"], [
      m4_provide_if([GOBJECT_INTROSPECTION_CHECK], [], [
          m4_provide_if([GOBJECT_INTROSPECTION_REQUIRE], [], [
              AC_MSG_ERROR([[You must call GOBJECT_INTROSPECTION_CHECK or GOBJECT_INTROSPECTION_REQUIRE before using BAPIGEN_CHECK unless using the FOUND_INTROSPECTION argument is "yes"]])
            ])
        ])
    ])

  AC_ARG_ENABLE([bala],
    [AS_HELP_STRING([--enable-bala[=@<:@no/auto/yes@:>@]],[build Bala bindings @<:@default=]ifelse($4,,auto,$4)[@:>@])],,[
      AS_IF([test "x$4" = "x"], [
          enable_bala=auto
        ], [
          enable_bala=$4
        ])
    ])

  AS_CASE([$enable_bala], [no], [enable_bala=no],
      [yes], [
        AS_IF([test "x$3" != "xyes" -a "x$found_introspection" != "xyes"], [
            AC_MSG_ERROR([Bala bindings require GObject Introspection])
          ])
      ], [auto], [
        AS_IF([test "x$3" != "xyes" -a "x$found_introspection" != "xyes"], [
            enable_bala=no
          ])
      ], [
        AC_MSG_ERROR([Invalid argument passed to --enable-bala, should be one of @<:@no/auto/yes@:>@])
      ])

  AS_IF([test "x$2" = "x"], [
      vapigen_pkg_name=vapigen
    ], [
      vapigen_pkg_name=vapigen-$2
    ])
  AS_IF([test "x$1" = "x"], [
      vapigen_pkg="$vapigen_pkg_name"
    ], [
      vapigen_pkg="$vapigen_pkg_name >= $1"
    ])

  PKG_PROG_PKG_CONFIG

  PKG_CHECK_EXISTS([$vapigen_pkg], [
      AS_IF([test "$enable_bala" = "auto"], [
          enable_bala=yes
        ])
    ], [
      AS_CASE([$enable_bala], [yes], [
          AC_MSG_ERROR([$vapigen_pkg not found])
        ], [auto], [
          enable_bala=no
        ])
    ])

  AC_MSG_CHECKING([for vapigen])

  AS_CASE([$enable_bala],
    [yes], [
      BAPIGEN=`$PKG_CONFIG --variable=vapigen $vapigen_pkg_name`
      BAPIGEN_MAKEFILE=`$PKG_CONFIG --variable=datadir $vapigen_pkg_name`/bala/Makefile.vapigen
      AS_IF([test "x$2" = "x"], [
          BAPIGEN_BAPIDIR=`$PKG_CONFIG --variable=vapidir $vapigen_pkg_name`
        ], [
          BAPIGEN_BAPIDIR=`$PKG_CONFIG --variable=vapidir_versioned $vapigen_pkg_name`
        ])
    ])

  AC_MSG_RESULT([$enable_bala])

  AC_SUBST([BAPIGEN])
  AC_SUBST([BAPIGEN_BAPIDIR])
  AC_SUBST([BAPIGEN_MAKEFILE])

  AM_CONDITIONAL(ENABLE_BAPIGEN, test "x$enable_bala" = "xyes")
])
