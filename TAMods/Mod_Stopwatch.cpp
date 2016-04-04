#include "Stopwatch.h"

extern Config g_config;

namespace stopwatch
{
	bool flagRecall = false;
	bool running = false;
	float startTime = 0.0f;
	float grabTime = 0.0f;
	float capTime = 0.0f;
	int grabHealth = 0;
	int grabSpeed = -1;
}
void stopwatch::toggle()
{
	if (running)
		stop();
	else
		start();
}

void stopwatch::start()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	if (running)
	{
		displayTime("Restarted - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);
		printSummary();
	}
	else
		running = true;

	startTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
}

void stopwatch::stop()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	if (running)
	{
		displayTime("Stopped - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);
		printSummary();
		startTime = 0;
		running = 0;
	}
}

void stopwatch::reset()
{
	stop();
	running = false;
	startTime = 0;
	capTime = 0.0f;
	grabTime = 0.0f;
	grabHealth = 0;
	grabSpeed = -1;
}

void stopwatch::displayTime(const std::string &prestr, float cur_time)
{
	if (running)
	{
		float time = cur_time - startTime;

		std::string s = Utils::fTime2stopwatch(time);
		Utils::printConsole("Stopwatch: " + prestr + s, Utils::rgba(15, 255, 135, 255));
		if (g_config.stopwatchNotifications)
			Utils::notify(std::string("Stopwatch"), prestr + s);
	}
}

void stopwatch::printSummary()
{
	if (grabTime > 0.0f)
	{
		// Speed and health
		Utils::printConsole("\nSummary\n----------------------------------------\n Flag taken at " + std::to_string(grabSpeed) + " km/h " + std::to_string(grabHealth) + " hp");

		// Time from stopwatch start until grab, only when the stopwatch was started pre-grab
		if (startTime != 0.0f && startTime < grabTime)
			Utils::printConsole(" On route:     " + Utils::fTime2string(grabTime - startTime));

		if (grabTime < capTime)
		{
			// Capture time, only when cap time is available
			Utils::printConsole(" Captured in: " + Utils::fTime2string(capTime - grabTime));

			// Total time, only when the stopwatch was started pre-grab
			if (startTime != 0.0f && startTime < grabTime)
			{
				Utils::printConsole("----------------------------------------");
				Utils::printConsole(" Total:          " + Utils::fTime2string(capTime - startTime));
			}
		}
		Utils::printConsole("===============================");
	}
}
