#include "headers/jsapi.h"

void expose_func_js(
    duk_context* D,
    char* funcname,
    int argc,
    duk_c_function func)
{
    duk_push_c_function(D, func, argc);
    duk_put_global_string(D, funcname);
}

void expose_api_js(duk_context* D)
{
    //
    //  Register compiled C Language functions and
    //  Expose them to JavaScript.
    //
    expose_func_js(D, "js001", 1, shared_func_js001);
    expose_func_js(D, "js002", 1, shared_func_js002);
    expose_func_js(D, "js003", 1, shared_func_js003);
}

duk_ret_t shared_func_js001(duk_context* D)
{
    //
    //  Both C and JavaScript can access this function,
    //  However, JavaScript must call it using `js001(arg);`.
    //
    printf("A call to shared_func_js001 was made.\n");
    return 0;
}

duk_ret_t shared_func_js002(duk_context* D)
{
    //
    //  Similarly, JavaScript can only access this by
    //  Calling `js002(arg);`. The name "js002" and the
    //  Expected number of arguments are defined in the
    //  Call to `expose_func_js();` above.
    //
    printf("A call to shared_func_js002 was made.\n");
    return 0;
}

duk_ret_t shared_func_js003(duk_context* D)
{
    //
    //  Filler.
    //
    printf("A call to shared_func_js003 was made.\n");
    return 0;
}