#pragma once

#include "buildconfig.h"

#include <cstdio>
#include <cstdarg>
#include <string>

namespace Logger
{
    void log(const char *format, ...);
    void noln(const char *format, ...);

    void quiet();
    bool isQuiet();
    void cleanup();
};
