# Copyright (C) 2026 Uoc Azizah
#
# This file is part of libstdoc.
#
# libstdoc is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# libstdoc is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libstdoc. If not, see <https://www.gnu.org/licenses/>.

AC_INIT([libstdoc], [2.0.0-beta], [uoctamika.codeberg.org@gmail.com])
AM_INIT_AUTOMAKE([foreign subdir-objects silent-rules])
AC_CONFIG_SRCDIR([include/libstdoc.h])
AC_CANONICAL_HOST

AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PROG_CXXCPP
AC_PROG_RANLIB
AM_PROG_AS

AC_LANG([C])
AC_LANG([C++])

AC_CHECK_HEADERS([
stdbool.h
stdnoreturn.h
stddef.h
stdint.h
stdarg.h
stdalign.h
limits.h
float.h
iso646.h
])

AC_MSG_CHECKING([which assembly file to use])
AS_CASE([$host_cpu],
  [x86_64],  [arch_x86_64=true; arch_i686=false; arch_aarch64=false; arch_arm32=false],
  [i?86],    [arch_x86_64=false; arch_i686=true; arch_aarch64=false; arch_arm32=false],
  [aarch64], [arch_x86_64=false; arch_i686=false; arch_aarch64=true; arch_arm32=false],
  [arm*],    [arch_x86_64=false; arch_i686=false; arch_aarch64=false; arch_arm32=true],
  [AC_MSG_ERROR([Unsupported CPU: $host_cpu])]
)

AM_CONDITIONAL([ARCH_X86_64],  [test "$arch_x86_64" = true])
AM_CONDITIONAL([ARCH_I686],    [test "$arch_i686" = true])
AM_CONDITIONAL([ARCH_AARCH64], [test "$arch_aarch64" = true])
AM_CONDITIONAL([ARCH_ARM32],   [test "$arch_arm32" = true])

AC_CONFIG_FILES([GNUmakefile])
AC_OUTPUT
