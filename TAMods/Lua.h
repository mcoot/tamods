#pragma once

#include        <iostream>
#include        <string>
#include        "LuaBridge/LuaBridge.h"

extern "C" {
#include        "lua_src/lua.h"
#include        "lua_src/lauxlib.h"
#include        "lua_src/lualib.h"
}

#include "Utils.h"
#include "Logger.h"
#include "Loadout.h"

using namespace luabridge;

class           Lua
{
public:
	Lua();
	~Lua();

private:
	std::string   _error(int ret);
	void          _pushvar(const char *name, unsigned char val);
	void          _printTop();
	void		  _initInputEvents();

public:
	// Located in Config.cpp. Because include hell.
	void          init();

	lua_State     *getState() const { return (_state); }
	std::string   doFile(const std::string &s);
	void          doString(const std::string &s);
	void          doFunc(const std::string &s);
	void          doREPL();

	template<typename T>
	bool setVar(T &var, const char *name)
	{
		LuaRef ref = getGlobal(_state, name);
		if (ref.isNil())
			return false;
		var = ref.cast<T>();
		return true;
	}

private:
	lua_State     *_state;
};
