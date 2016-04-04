#pragma once

#include "Config.h"
#include "Utils.h"

namespace stopwatch
{
	void toggle();
	void start();
	void stop();
	void reset();
	void displayTime(const std::string &prestr, float cur_time);
	void printSummary();

	extern bool  flagRecall;
	extern bool  running;
	extern float startTime;
	extern float grabTime;
	extern float capTime;
	extern int   grabHealth;
	extern int   grabSpeed;
}