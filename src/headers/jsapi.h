#ifndef __JSAPI__
#define __JSAPI__

#include <global.h>
#define exec_js(A, B) duk_eval_string_noresult(A, B)

void expose_func_js(duk_context* D, char* funcname, int argc, duk_c_function func);
void expose_api_js(duk_context* D);
duk_ret_t shared_func_js001(duk_context* D);
duk_ret_t shared_func_js002(duk_context* D);
duk_ret_t shared_func_js003(duk_context* D);

#endif