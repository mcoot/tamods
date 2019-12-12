#pragma once

#pragma comment(lib, "winmm")

#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Logger.h"
#include "Utils.h"

namespace Profiler
{
    class Function
    {
    public:
        Function(const std::string &pname)
            : _name(pname), _ncalls(0), _tottime(0)
        {}
        Function()
            : Function("")
        {}

        void setName(const std::string &name) { _name = name; }
        const std::string &getName() const { return _name; }
        int getNCalls() const { return _ncalls; }
        unsigned long getTotalTime() const { return _tottime; }
        unsigned long getTimePerCall() const { return _percall; }
        float getPercentage() const { return _percentage; }


        void enter();
        unsigned long leave();
        void computeTimes();

    private:
        std::string   _name;
        int           _ncalls;
        unsigned long _tottime;
        unsigned long _percall;
        float         _percentage;
        unsigned long _start_time;
    };

    void enterFunction(const std::string &fname);
    void leaveFunction();
    void start();
    void stop();
    void toggle();
    bool isActive();
};
