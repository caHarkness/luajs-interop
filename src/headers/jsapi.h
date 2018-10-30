#ifndef __JSAPI__
#define __JSAPI__

#include <global.h>

duk_ret_t jsapi_print(duk_context* D);
int install_jsapi(duk_context* D);
int jsapi_addfunc(duk_context* D, char* funcname, int argc, duk_c_function func);

#endif