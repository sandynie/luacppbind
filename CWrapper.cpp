#include "CWrapper.h"
#include <iostream>
using std::cout;
using std::endl;

int l_getAge(lua_State* L)
{
	RegType* pStu = (RegType*)lua_touserdata(L,1);  
	luaL_argcheck(L,pStu != NULL, 1," invalid user data");
	lua_settop(L,0);
	lua_pushnumber(L,pStu->pStudent->getAge());
	return 1;

}


int l_getName(lua_State* L)
{
	RegType* pStu = (RegType*)lua_touserdata(L,1);  
	luaL_argcheck(L,pStu != NULL, 1," invalid user data");
	lua_settop(L,0);
	lua_pushstring(L,pStu->pStudent->getName().c_str());
	return 1;
}

int l_setAge(lua_State * L)
{
	RegType* pStu = (RegType*)lua_touserdata(L,1);  
	luaL_argcheck(L,pStu != NULL, 1," invalid user data");
	luaL_checktype(L,-1,LUA_TNUMBER);
	int age = lua_tonumber(L,-1);
	pStu->pStudent->setAge(age);
	return 0;
}

int l_setName(lua_State * L)
{
	RegType* pStu = (RegType*)lua_touserdata(L,1);  
	luaL_argcheck(L,pStu != NULL, 1," invalid user data");
	luaL_checktype(L,-1,LUA_TSTRING);
	string sname = lua_tostring(L,-1);
	pStu->pStudent->setName(sname);
	return 0;
}

int l_toString(lua_State* L)
{
	RegType* pStu = (RegType*)lua_touserdata(L,1);  
	luaL_argcheck(L,pStu != NULL, 1," invalid user data");
	pStu->pStudent->toString();
	return 0;
}

static void stackDump(lua_State* L){
	cout<<"\nbegin dump lua stack"<<endl;
	int i = 0;
	int top = lua_gettop(L);
	for (i = 1; i <= top; ++i) {
		int t = lua_type(L, i);
		switch (t) {
			case LUA_TSTRING:
				{
					printf("'%s' ", lua_tostring(L, i));
				}
				break;
			case LUA_TBOOLEAN:
				{
					printf(lua_toboolean(L, i) ? "true " : "false ");
				}break;
			case LUA_TNUMBER:
				{
					printf("%g ", lua_tonumber(L, i));
				}
				break;
			default:
				{
					printf("%s ", lua_typename(L, t));
				}
				break;
		}
	}
	cout<<"\nend dump lua stack"<<endl;
}

int newStudent(lua_State* L)
{
	CStudent * pStuent = new CStudent();
	RegType * ud = static_cast<RegType*>(lua_newuserdata(L,sizeof(RegType)));
	ud->pStudent = pStuent;
	luaL_getmetatable(L,CSTUDENTLIB);
	lua_setmetatable(L,-2);
	return 1;
}


int gcStudent(lua_State* L)
{
	RegType* ud = static_cast<RegType*>(lua_touserdata(L,-1));
	luaL_argcheck(L,ud != NULL, 1," invalid user data");
	delete ud->pStudent;
	return 0;
}
