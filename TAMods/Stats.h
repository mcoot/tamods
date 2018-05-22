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
	void saveStats(const char *format, ...);
	void saveTeamStats(const char *format, ...);
	void static cleanup();
	void updateMaxSpeed(int currentSpeed);
public:
	double bulletsHit;
	double bulletsFired;
	double accuracy;

	double kills;
	double deaths;
	int assists;
	int midairKills;

	int flagReturns;
	int flagCaps;
	int flagGrabs;
	int flagMaxGrabSpeed;

	int slayers;

	int damageDone;
	int damageReceived;

	int jitter;
};