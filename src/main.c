#include <global.h>
#include <luaapi.h>
#include <jsapi.h>
#include <iohelper.h>

lua_State* L;
duk_context* D;

int main(int argc, char** argv)
{
    consoleInit(NULL);             debugWaitForKey(__FILE__, __LINE__);
    romfsInit();                   debugWaitForKey(__FILE__, __LINE__);

    L = luaL_newstate();           debugWaitForKey(__FILE__, __LINE__);
    D = duk_create_heap_default(); debugWaitForKey(__FILE__, __LINE__);

    expose_api_lua(L);             debugWaitForKey(__FILE__, __LINE__);
    expose_api_js(D);              debugWaitForKey(__FILE__, __LINE__);

    //
    //  When the user calls `jsinterop()` from within JavaScript,
    //  The anonymous function below executes C code, then
    //  Sends back a string confirming C code was executed.
    //
    expose_func_js(D, "jsinterop", 1, ({
        duk_ret_t __fn__(duk_context* D)
        {
            debugWaitForKey(__FILE__, __LINE__);

            //
            //  Assign param1 to the first argument
            //  Passed here from JavaScript.
            //
            char* param1 = duk_to_string(D, 0);      debugWaitForKey(__FILE__, __LINE__);
            // char* param2 = duk_to_string(D, 1);   debugWaitForKey(__FILE__, __LINE__);
            // char* paramN = duk_to_string(D, N-1); debugWaitForKey(__FILE__, __LINE__);

            printf(
                "The following string came from JavaScript: %s\n",
                param1); debugWaitForKey(__FILE__, __LINE__);

            return 0;
        } __fn__;
    }));

    debugWaitForKey(__FILE__, __LINE__);

    //
    //  When the user calls `luainterop()` from within Lua,
    //  The anonymous function below executes C code, then
    //  Sends back a string confirming C code was executed.
    //
    expose_func_lua(L, "luainterop", ({
        int __fn__(lua_State* L)
        {
            debugWaitForKey(__FILE__, __LINE__);
            //
            //  Assign param1 and param2 to the first
            //  Two arguments passed here from Lua.
            //
            double param1 = lua_tonumber(L, 1); debugWaitForKey(__FILE__, __LINE__);
            double param2 = lua_tonumber(L, 2); debugWaitForKey(__FILE__, __LINE__);

            printf(
                "The numbers %f and %f came from Lua.\n",
                param1,
                param2); debugWaitForKey(__FILE__, __LINE__);

            //
            //  Send a string back to Lua
            //
            lua_pushstring(L, "This string came from the C Language.\n");
            debugWaitForKey(__FILE__, __LINE__);

            return 1;
        } __fn__;
    }));

                                         debugWaitForKey(__FILE__, __LINE__);

    char* f1 = reads("romfs:/init.lua"); debugWaitForKey(__FILE__, __LINE__);
    char* f2 = reads("romfs:/init.js");  debugWaitForKey(__FILE__, __LINE__);

    exec_lua(L, f1);                     debugWaitForKey(__FILE__, __LINE__);
    exec_js(D, f2);                      debugWaitForKey(__FILE__, __LINE__);
    exec_lua(L, "onInit()");             debugWaitForKey(__FILE__, __LINE__);
    
    // Program dies after this line...
    // For now, don't call onInit()
    exec_js(D, "onInit();");             debugWaitForKey(__FILE__, __LINE__);

    while (appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        u64 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
        u64 kUp = hidKeysUp(CONTROLLER_P1_AUTO);

        //
        //  It's common for Homebrew apps to utilize the plus button
        //  As a way to quickly terminate the app, so remove it if you
        //  Feel daring.
        //
        if (kDown & KEY_PLUS)
            break;

        exec_lua(L, "onUpdate()");
        exec_js(D, "onUpdate();");

        consoleUpdate(NULL);
    }

    //
    //
    //

    exec_lua(L, "onEnd()");
    exec_js(D, "onEnd();");
    
    lua_close(L);
    duk_destroy_heap(D);

    romfsExit();
    consoleExit(NULL);
    return 0;
}

