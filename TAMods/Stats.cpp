#include "Stats.h"
#include <iomanip>
#include <iostream>

Stats g_stats;

static FILE *_statsFile = NULL;
static FILE *_gameStatsFile = NULL;



Stats::Stats()
{
	resetStats();
}

Stats::~Stats()
{
}

void Stats::resetStats() {
	//Reset counts
	bulletsHit = 0;
	bulletsFired = 0;
	accuracy = 0;

	kills = 0;
	deaths = 0;
	assists = 0;
	midairKills = 0;

	flagReturns = 0;
	flagCaps = 0;
	flagGrabs = 0;
	flagMaxGrabSpeed = 0;

	slayers = 0;

	damageDone = 0;
	damageReceived = 0;

	jitter = 0;
}

void Stats::saveStats(FILE *filetoSave, std::string filename, const char *format, ...) {
	//save stats to file function
	if (!filetoSave)
	{
		filetoSave = fopen(std::string(Utils::getConfigDir() + filename).c_str(), "a");
	}

	if (!filetoSave)
		return;

	char buff[256];
	va_list args;

	va_start(args, format);
	vsprintf(buff, format, args);
	va_end(args);
	fprintf(filetoSave, "%s\n", buff);
	fflush(filetoSave);
}

void Stats::cleanup()
{
	if (!_gameStatsFile) {}
	else {
		fclose(_gameStatsFile);
	}
	if (!_statsFile) {}
	else {
		fclose(_statsFile);
	}
	return;
}

void Stats::updateMaxSpeed(int currentSpeed) {
	flagGrabs++;
	if (currentSpeed > flagMaxGrabSpeed) flagMaxGrabSpeed = currentSpeed;
}


std::vector<std::string> Stats::getStatsString()
{
	std::vector<std::string> data;

	if (bulletsFired == 0) accuracy = bulletsHit / 1;
	else accuracy = bulletsHit / bulletsFired;

	double kd = 0;

	if (deaths == 0) kd = kills / 1; 
	else kd = kills / deaths;
	std::string stats[statsAmount];

	data.push_back("Shots hit: " + std::to_string((int)bulletsHit));
	data.push_back("Shots fired: " + std::to_string((int)bulletsFired));
	std::stringstream accuracyStream;
	accuracyStream << std::fixed << std::setprecision(2) << accuracy;
	data.push_back("Accuracy: " + accuracyStream.str());
	data.push_back("Kills: " + std::to_string((int)kills));
	data.push_back("Deaths: " + std::to_string((int)deaths));

	std::stringstream kdStream;
	kdStream << std::fixed << std::setprecision(2) << kd;

	data.push_back("KD: " + kdStream.str());
	data.push_back("Assists: " + std::to_string(assists));
	data.push_back("Midair Kills: " + std::to_string(midairKills));
	data.push_back("Returns: " + std::to_string(flagReturns));
	data.push_back("Caps: " + std::to_string(flagCaps));
	data.push_back("Flag Grabs: " + std::to_string(flagGrabs));
	data.push_back("Highest Grab Speed: " + std::to_string(flagMaxGrabSpeed));
	data.push_back("Slayers: " + std::to_string(slayers));
	data.push_back("Damage Output: " + std::to_string(damageDone));
	return data;
}


void Stats::printStats(bool savestats, bool saveteamstats, bool printstats, bool printteamstats) {
	if (printstats) {
		int maxPing = Utils::tr_pc->PlayerReplicationInfo->StatPingMax;
		int minPing = Utils::tr_pc->PlayerReplicationInfo->StatPingMin;
		jitter = maxPing - minPing;

		Utils::printConsole("\n============Player Stats============\n", Utils::rgb(0, 255, 255));
		std::vector<std::string> stats = getStatsString();
		for (int i = 0; i < statsAmount; i++) {
			std::string tempString = stats[i];
			Utils::printConsole(tempString, Utils::rgb(255, 255, 255));
		}

		Logger::log("Save stats?");
		if (savestats) {
			Logger::log("Save stats");
			for (int i = 0; i < statsAmount; i++) {
				char * tempChar = new char[statsAmount + 1];
				std::string tempString = stats[i];
				std::strcpy(tempChar, tempString.c_str());
				Logger::log(tempChar);
				Logger::log(tempString.c_str());
				saveStats(_statsFile, "TAModsStats.csv", tempChar);
			}
		}

		Utils::printConsole("Max Ping: " + std::to_string(maxPing), Utils::rgb(255, 255, 255));
		Utils::printConsole("Min Ping: " + std::to_string(minPing), Utils::rgb(255, 255, 255));

		Utils::printConsole("Jitter: " + std::to_string(jitter), Utils::rgb(255, 255, 255));
		Utils::printConsole("=================================\n", Utils::rgb(0, 255, 255));
	}

	if (printteamstats) {

		std::vector<ATrPlayerReplicationInfo *> pris;
		std::string mapName = Utils::f2std(Utils::tr_pc->WorldInfo->GetURLMap());

		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		{
			for (int i = 0; i < Utils::tr_pc->WorldInfo->GRI->PRIArray.Count; i++)
			{
				if (Utils::tr_pc->WorldInfo->GRI->PRIArray.Data[i] &&
					((ATrPlayerReplicationInfo *)Utils::tr_pc->WorldInfo->GRI->PRIArray.GetStd(i))->m_Rank)
				{
					pris.push_back((ATrPlayerReplicationInfo *)Utils::tr_pc->WorldInfo->GRI->PRIArray.GetStd(i));
				}
			}

			std::string playersBE;
			std::string playersDS;
			for (size_t i = 0; i < pris.size(); i++)
			{
				ATrPlayerReplicationInfo &pri = *(ATrPlayerReplicationInfo *)pris.at(i);

				unsigned char team = pri.GetTeamNum();

				std::string playerName = Utils::f2std(pri.PlayerName);

				if (team == 0)
					playersBE += "," + playerName;
				else if (team == 1)
					playersDS += "," + playerName;

			}

			Utils::printConsole("============Game Stats============\n", Utils::rgb(0, 255, 255));
			std::string teamStatsString[2];
			//BE Score,Player1,Player2,Player3,Player4,Player5,Player6,Player7
			//DS Score,Player1,Player2,Player3,Player4,Player5,Player6,Player7
			teamStatsString[0] = mapName + "," + std::to_string(getGameData::score(0)) + playersBE;
			teamStatsString[1] = mapName + "," + std::to_string(getGameData::score(1)) + playersDS;

			for (int i = 0; i < 2; i++) Utils::printConsole(teamStatsString[i], Utils::rgb(255, 255, 255));

			Utils::printConsole("==================================\n", Utils::rgb(0, 255, 255));
			if (saveteamstats) {
				for (int i = 0; i < 2; i++) {
					char * tempChar = new char[2 + 1];
					std::strcpy(tempChar, teamStatsString[i].c_str());
					saveStats(_gameStatsFile, "TAModsGameStats.csv", tempChar);
				}
			}
		}
	}
}
