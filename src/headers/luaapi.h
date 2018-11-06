#ifndef __LUAAPI__
#define __LUAAPI__

#include <global.h>
#define exec_lua(A, B) luaL_dostring(A, B)

void expose_func_lua(lua_State* L, char* funcname, lua_CFunction func);
void expose_api_lua(lua_State* L);
int shared_func_lua001(lua_State* L);
int shared_func_lua002(lua_State* L);
int shared_func_lua003(lua_State* L);

#endif