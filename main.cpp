#include "CWrapper.h"
#pragma comment (lib,"lua5.1.lib")
static  struct luaL_Reg stuentlib_f [] = {
	{"create", newStudent},
	{"setName",l_setName},
	{"setAge", l_setAge},
	{"print", l_toString},
	{"getName",l_getName},
	{"getAge", l_getAge},
	{NULL, NULL}
};


void Register(lua_State* L)
{
	lua_newtable(L);
	int methods = lua_gettop(L);

	luaL_newmetatable(L,CSTUDENTLIB);
	int metatable = lua_gettop(L);

	lua_pushstring(L,STUDENTINLUA);
	lua_pushvalue(L,methods);
	lua_settable(L,LUA_GLOBALSINDEX);

	lua_pushliteral(L,"__metatable");
	lua_pushvalue(L,methods);
	lua_settable(L,metatable);

	lua_pushliteral(L,"__index");
	lua_pushvalue(L,methods);
	lua_settable(L,metatable);

	lua_pushliteral(L,"__gc");
	lua_pushcfunction(L,gcStudent);
	lua_settable(L,metatable);

	lua_newtable(L);
	int mt = lua_gettop(L);
	lua_pushliteral(L,"__call");
	lua_pushcfunction(L,newStudent);

	lua_pushliteral(L,"new");
	lua_pushvalue(L,-2);
	lua_settable(L,methods);
	lua_settable(L,mt);
	lua_setmetatable(L,methods);

	for (luaL_Reg* l = stuentlib_f; l->name;l++)
	{
		lua_pushstring(L,l->name);
		lua_pushcfunction(L,l->func);
		lua_settable(L,methods);
	}
	lua_pop(L,2);
}

int main()
{
	lua_State *L = lua_open();
	/* load Lua libraries */
	luaL_openlibs(L);
	Register(L);
	/* run the script */
	luaL_dofile(L,"add.lua");
	lua_close(L);
	system("pause");

	return 0;
}
