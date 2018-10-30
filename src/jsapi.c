#include "headers/jsapi.h"

duk_ret_t jsapi_print(duk_context* D)
{
    printf("%s\n", duk_to_string(D, 0));
    return 0;
}

int install_jsapi(duk_context* D)
{
    duk_push_c_function(D, jsapi_print, 1);
    duk_put_global_string(D, "print");
    return 0;
}

int jsapi_addfunc(duk_context* D, char* funcname, int argc, duk_c_function func)
{
    duk_push_c_function(D, func, argc);
    duk_put_global_string(D, funcname);
    return 0;
}