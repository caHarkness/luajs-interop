#include "headers/luaapi.h"

int install_luaapi(lua_State* L)
{
    luaL_openlibs(L);
    return 0;
}