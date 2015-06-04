#pragma once

#include <cstdio>
#include <cstdarg>
#include <Windows.h>
#include <string>

namespace Logger
{
	void log(const char *format, ...);
	void quiet();
};
