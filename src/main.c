#include <global.h>
#include <luaapi.h>
#include <jsapi.h>
#include <iohelper.h>

lua_State* L;
duk_context* D;

char* lua_init_fdata;
char* js_init_fdata;
char* lua_frame_fdata;
char* js_frame_fdata;

int main(int argc, char **argv)
{
    consoleInit(NULL);
    romfsInit();

    L = luaL_newstate();
    D = duk_create_heap_default();

    install_luaapi(L);
    install_jsapi(D);

    //
    //  Exposing anonymous C functions to Duktape on the fly?
    //  Define print2 as a function that takes one argument.
    //
    jsapi_addfunc(D, "print2", 1, ({
        duk_ret_t __fn__(duk_context* dc)
        {
            printf("%s\n", duk_to_string(D, 0));
            return 0;
        } __fn__;
    }));

    lua_init_fdata = freadall("romfs:/init.lua");
    js_init_fdata = freadall("romfs:/init.js");
    lua_frame_fdata = freadall("romfs:/frame.lua");
    js_frame_fdata = freadall("romfs:/frame.js");

    luaL_dostring(L, lua_init_fdata);
    duk_eval_string_noresult(D, js_init_fdata);

    //
    //
    //

    while (appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        u64 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
        u64 kUp = hidKeysUp(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS)
            break;

        if (kDown & KEY_DUP)
            luaL_dostring(L, lua_frame_fdata);

        if (kDown & KEY_DDOWN)
            duk_eval_string_noresult(D, js_frame_fdata);

        consoleUpdate(NULL);
    }

    //
    //
    //

    lua_close(L);
    duk_destroy_heap(D);

    romfsExit();
    consoleExit(NULL);
    return 0;
}

