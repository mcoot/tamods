#pragma once

#include <sstream>
#include <string>
#include "Config.h"
#include "Utils.h"

const int statsAmount = 14;

//Stats to save
class Stats
{
public:
	Stats();
	~Stats();

	std::vector<std::string> Stats::getStatsString();
	void resetStats();
	void printStats(bool savestats, bool saveteamstats, bool printstats, bool printteamstats);
	void saveStats(FILE *filetoSave, std::string filename, const char *format, ...);
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