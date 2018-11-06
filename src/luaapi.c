#include "headers/luaapi.h"

void expose_func_lua(
    lua_State* L,
    char* funcname,
    lua_CFunction func)
{
    lua_pushcfunction(L, func);
    lua_setglobal(L, funcname);
}

void expose_api_lua(lua_State* L)
{
    //
    //  Now we can register compiled C Language functions and
    //  Expose them to our Lua environment. Note that a predefined
    //  Parameter count is not required. This is done within the
    //  Functions themselves.
    //

    expose_func_lua(L, "lua001", shared_func_lua001);
    expose_func_lua(L, "lua002", shared_func_lua002);
    expose_func_lua(L, "lua003", shared_func_lua003);
}

int shared_func_lua001(lua_State* L)
{
    //
    //  Assign param1 and param2 to the first
    //  Two arguments passed here from Lua.
    //
    double param1 = lua_tonumber(L, 1);
    double param2 = lua_tonumber(L, 2);

    printf(
        "Adding the numbers %f and %f sent from Lua.\n",
        param1,
        param2);

    //
    //  Send the sum of the two numbers back to Lua
    //  And return how many values Lua should expect from
    //  This function.
    //
    lua_pushnumber(L, param1 + param2);
    return 1;
}

int shared_func_lua002(lua_State* L)
{
    lua_pushstring(L, "A call to lua002() in Lua is a call to shared_func_lua002() in C.");
    return 1;
}

int shared_func_lua003(lua_State* L)
{
    lua_pushstring(L, "lua003");
    lua_pushstring(L, "shared_func_lua003");
    return 2;
}