#include "Lua.h"

Lua             L;

Lua::Lua()
{
	_state = luaL_newstate();
	luaL_openlibs(_state);
	init();
}

Lua::~Lua()
{
}

void            Lua::_pushvar(const char *name, unsigned char val)
{
	lua_pushstring(_state, name);
	lua_pushnumber(_state, val);
	lua_settable(_state, -3);
}

std::string Lua::_error(int ret)
{
	const char    *str;
	std::string out = "";

	if (ret && (str = lua_tostring(_state, -1)))
	{
		out = std::string(str);
		lua_pop(_state, 1);
	}
	return out;
}

std::string Lua::doFile(const std::string &s)
{
	return _error(luaL_dofile(_state, s.c_str()));
}

void            Lua::_printTop()
{
	switch (lua_type(_state, -1))
	{
	case LUA_TNIL:
		printf("nil\n");
		break;
	case LUA_TSTRING:
	case LUA_TNUMBER:
		printf("%s\n", lua_tostring(_state, -1));
		break;
	case LUA_TBOOLEAN:
		printf("%s\n", lua_toboolean(_state, -1) ? "true" : "false");
		break;
	case LUA_TTABLE:
		printf("table: %p\n", lua_topointer(_state, -1));
		break;
	case LUA_TFUNCTION:
		printf("function: %p\n", lua_topointer(_state, -1));
		break;
	case LUA_TUSERDATA:
		printf("userdata: %p\n", lua_topointer(_state, -1));
		break;
	case LUA_TTHREAD:
		printf("thread: %p\n", lua_topointer(_state, -1));
		break;
	case LUA_TLIGHTUSERDATA:
		printf("lightuserdata: %p\n", lua_topointer(_state, -1));
		break;
	}
}

void            Lua::doString(const std::string &s)
{
	int           old = lua_gettop(_state);

	_error(luaL_dostring(_state, s.c_str()));
	if (lua_gettop(_state) != old)
	{
		_printTop();
		lua_pop(_state, 1);
	}
}

void            Lua::doFunc(const std::string &s)
{
	LuaRef        func = getGlobal(_state, s.c_str());

	if (func.isNil())
		return;
	func();
}
