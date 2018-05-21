#pragma once

#include <sstream>
#include <string>
#include "Config.h"
#include "Utils.h"


//Stats to save
class Stats
{
public:
	Stats();
	~Stats();

	void resetStats();
	void printStats();
	void printTeamStats(bool saveStats);
	void saveStats();
	void saveTeamStats(const char *format, ...);
public:
	int bulletsHit;
	int bulletsFired;
	double accuracy;

	int kills;
	int deaths;
	int assists;
	int midairKills;

	int flagReturns;
	int flagCaps;
	int flagMaxGrabSpeed;
	int flagGrabSpeedAverage;

	int damageDone;
	int damageReceived;
};