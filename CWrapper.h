#ifndef _CWRAPPER_H
#define _CWRAPPER_H
extern "C"{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};
#include "CStudent.h"
static const char* CSTUDENTLIB = "CStudentLib";
static const char*  STUDENTINLUA = "Student";
typedef struct{
	CStudent*  pStudent;
}RegType;
int l_setName(lua_State * L);

int l_setAge(lua_State * L);

int l_getName(lua_State* L);

int l_getAge(lua_State* L);

int l_toString(lua_State* L);


void stackDump(lua_State* L);

int newStudent(lua_State* L);

int gcStudent(lua_State* L);

#endif
