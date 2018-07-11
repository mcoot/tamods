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

	std::vector<std::string> getStatsLines();
	std::string getGameStatsString();
	void resetStats();
	void printStats(bool printstats, bool printteamstats);
	void saveStats(bool savestats, bool saveteamstats);
	void saveStats(FILE *filetoSave, std::string filename, const char *format, ...);
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