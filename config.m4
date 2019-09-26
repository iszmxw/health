dnl $Id$
dnl config.m4 for extension iszmxw

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(iszmxw, for iszmxw support,
dnl Make sure that the comment is aligned:
[  --with-iszmxw             Include iszmxw support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(iszmxw, whether to enable iszmxw support,
dnl Make sure that the comment is aligned:
dnl [  --enable-iszmxw           Enable iszmxw support])

if test "$PHP_ISZMXW" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-iszmxw -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/iszmxw.h"  # you most likely want to change this
  dnl if test -r $PHP_ISZMXW/$SEARCH_FOR; then # path given as parameter
  dnl   ISZMXW_DIR=$PHP_ISZMXW
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for iszmxw files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ISZMXW_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ISZMXW_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the iszmxw distribution])
  dnl fi

  dnl # --with-iszmxw -> add include path
  dnl PHP_ADD_INCLUDE($ISZMXW_DIR/include)

  dnl # --with-iszmxw -> check for lib and symbol presence
  dnl LIBNAME=iszmxw # you may want to change this
  dnl LIBSYMBOL=iszmxw # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ISZMXW_DIR/$PHP_LIBDIR, ISZMXW_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ISZMXWLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong iszmxw lib version or lib not found])
  dnl ],[
  dnl   -L$ISZMXW_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ISZMXW_SHARED_LIBADD)

  PHP_NEW_EXTENSION(iszmxw, iszmxw.c, $ext_shared)
fi
