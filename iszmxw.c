/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_iszmxw.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "Cal.h"

typedef void (*ptr_fun)(Infor *in); //

/* If you declare any globals in php_iszmxw.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(iszmxw)
*/

/* True global resources - no need for thread safety here */
static int le_iszmxw;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("iszmxw.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_iszmxw_globals, iszmxw_globals)
    STD_PHP_INI_ENTRY("iszmxw.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_iszmxw_globals, iszmxw_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_iszmxw_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_iszmxw_compiled)
{
    char *arg = NULL;
    int arg_len, len;
    char *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE)
    {
        return;
    }

    len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "iszmxw", arg);
    RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ php_iszmxw_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_iszmxw_init_globals(zend_iszmxw_globals *iszmxw_globals)
{
	iszmxw_globals->global_value = 0;
	iszmxw_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(iszmxw)
{
    /* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(iszmxw)
{
    /* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(iszmxw)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(iszmxw)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(iszmxw)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "iszmxw support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ iszmxw_functions[]
 *
 * Every user visible function must have an entry in iszmxw_functions[].
 */
const zend_function_entry iszmxw_functions[] = {
    PHP_FE(confirm_iszmxw_compiled, NULL) /* For testing, remove later. */
    PHP_FE(bcm_cal, NULL)                 /* bcm_cal */
    PHP_FE_END                            /* Must be the last line in iszmxw_functions[] */
};
/* }}} */

/* {{{ iszmxw_module_entry
 */
zend_module_entry iszmxw_module_entry = {
    STANDARD_MODULE_HEADER,
    "iszmxw",
    iszmxw_functions,
    PHP_MINIT(iszmxw),
    PHP_MSHUTDOWN(iszmxw),
    PHP_RINIT(iszmxw),     /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(iszmxw), /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(iszmxw),
    PHP_ISZMXW_VERSION,
    STANDARD_MODULE_PROPERTIES};
/* }}} */

#ifdef COMPILE_DL_ISZMXW
ZEND_GET_MODULE(iszmxw)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
Infor infor;
/**
 * bcm_cal
 * */
PHP_FUNCTION(bcm_cal)
{
    void *handle;
    char *error;
    int isage;
    int isgender;
    double isheight;
    double isweight;
    double isresistance;
    int result;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llddd", &isage, &isgender, &isheight, &isweight, &isresistance) == FAILURE)
    {
        return;
    }

    infor.age = isage;
    infor.height = isheight;
    infor.weight = isweight;
    infor.resistance = isresistance;
    if (isgender == 1)
    {
        infor.gender = MALE;
    }
    else
    {
        infor.gender = FEMALE;
    }

    handle = dlopen("libbcm.so", RTLD_NOW);
    if (!handle)
    {
        printf("dlopen error !!!\r\n");
        exit(1);
    }
    dlerror();
    ptr_fun pf = (ptr_fun)dlsym(handle, "BCM_Cal");
    if (dlerror() != NULL)
    {
        printf("dlsym error!!!\r\n");
        exit(1);
    }
    pf(&infor);
    array_init(return_value);
    add_assoc_double(return_value, "BMI", infor.BMI);           // BMI 体格指数
    add_assoc_double(return_value, "PBF", infor.PBF);           // PBF体脂肪率
    add_assoc_double(return_value, "VFA", infor.VFA);           // VFA内脏脂肪指数
    add_assoc_double(return_value, "PBW", infor.PBW);           // PBW体水分率
    add_assoc_double(return_value, "SM", infor.SM);             // SM骨骼肌
    add_assoc_double(return_value, "BMC", infor.BMC);           // 骨矿含量
    add_assoc_double(return_value, "BMR", infor.BMR);           // 基础代谢
    add_assoc_double(return_value, "Protein", infor.Protein);   // 蛋白质
    add_assoc_double(return_value, "TBW", infor.TBW);           //总水分重量
    add_assoc_double(return_value, "Minerals", infor.Minerals); //无机盐
    add_assoc_double(return_value, "BFM", infor.BFM);           //脂肪重量
    add_assoc_double(return_value, "FFM", infor.FFM);           //去脂体重
    add_assoc_double(return_value, "BodyAge", infor.BodyAge);   //身体年龄
    add_assoc_double(return_value, "TotalScore", infor.TotalScore); //综合评分
    dlclose(handle); //关闭调用动态库句柄
}
