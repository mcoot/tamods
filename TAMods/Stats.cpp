#include "Stats.h"
#include <iomanip>
#include <iostream>
#include <ctime>

Stats g_stats;

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

void Stats::saveStats(bool savestats, bool saveteamstats) {
	std::ofstream f;
	if (savestats) {
		f.open("TAModsStats.csv", std::ios::out | std::ios::app);
		std::vector<std::string> statsLines = getStatsLines();
		for (std::string s : statsLines) {
			f << s;
			f << std::endl;
		}
		f.close();
	}

	if (saveteamstats) {
		f.open("TribesMatchStats.csv", std::ios::out | std::ios::app);
		f << getGameStatsString();
		f << std::endl;
		f.close();
	}
}

//void Stats::saveStats(FILE *filetoSave, std::string filename, const char *format, ...) {
//	//save stats to file function
//	if (!filetoSave)
//	{
//		filetoSave = fopen(std::string(Utils::getConfigDir() + filename).c_str(), "a");
//	}
//
//	if (!filetoSave)
//		return;
//
//	char buff[256];
//	va_list args;
//
//	va_start(args, format);
//	vsprintf(buff, format, args);
//	va_end(args);
//	fprintf(filetoSave, "%s\n", buff);
//	fflush(filetoSave);
//}

void Stats::updateMaxSpeed(int currentSpeed) {
	flagGrabs++;
	if (currentSpeed > flagMaxGrabSpeed) flagMaxGrabSpeed = currentSpeed;
}


std::vector<std::string> Stats::getStatsLines()
{
	std::vector<std::string> data;

	if (bulletsFired == 0) accuracy = bulletsHit / 1;
	else accuracy = bulletsHit / bulletsFired;

	double kd = 0;

	if (deaths == 0) kd = kills / 1; 
	else kd = kills / deaths;

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

std::string Stats::getGameStatsString() 
{
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

		std::string teamStatsString;

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

		//Date, Map Name, Blood Eagle Score, BE Player1, BE Player2, BE Player3, BE Player4, BE Player5, BE Player6, BE Player7, Diamond Sword Score, DS Player1, DS Player2, DS Player3, DS Player4, DS Player5, DS Player6, DS Player7
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%Y-%m-%d %H-%M");
		std::string locaTime = oss.str();

		teamStatsString = locaTime + "," + mapName + "," + std::to_string(getGameData::score(0)) + playersBE + "," + std::to_string(getGameData::score(1)) + playersDS;
		return teamStatsString;
	}
	return "";
}

void Stats::printStats(bool printstats, bool printteamstats) {
	if (printstats) {
		if (!Utils::tr_pc || !Utils::tr_pc->PlayerReplicationInfo) {
			Utils::console("Failed to print stats - could not access player controller");
			return;
		}

		int maxPing = Utils::tr_pc->PlayerReplicationInfo->StatPingMax;
		int minPing = Utils::tr_pc->PlayerReplicationInfo->StatPingMin;
		jitter = maxPing - minPing;

		Utils::printConsole("\n============Player Stats============\n", Utils::rgb(0, 255, 255));
		std::vector<std::string> stats = getStatsLines();
		for (size_t i = 0; i < stats.size(); i++) {
			std::string tempString = stats[i];
			Utils::printConsole(tempString, Utils::rgb(255, 255, 255));
		}

		//Logger::log("Save stats?");
		//if (savestats) {
		//	Logger::log("Save stats");
		//	for (int i = 0; i < stats.size(); i++) {
		//		char * tempChar = new char[statsAmount + 1];
		//		std::string tempString = stats[i];
		//		std::strcpy(tempChar, tempString.c_str());
		//		Logger::log(tempChar);
		//		Logger::log(tempString.c_str());
		//		saveStats(_statsFile, "TAModsStats.csv", tempChar);
		//	}
		//}

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
			std::string teamStatsString;

			//Date, Map Name, Blood Eagle Score, BE Player1, BE Player2, BE Player3, BE Player4, BE Player5, BE Player6, BE Player7, Diamond Sword Score, DS Player1, DS Player2, DS Player3, DS Player4, DS Player5, DS Player6, DS Player7
			auto t = std::time(nullptr);
			auto tm = *std::localtime(&t);

			std::ostringstream oss;
			oss << std::put_time(&tm, "%Y-%m-%d %H-%M");
			std::string locaTime = oss.str();

			teamStatsString = locaTime + "," + mapName + "," + std::to_string(getGameData::score(0)) + playersBE + "," + std::to_string(getGameData::score(1)) + playersDS;

			Utils::printConsole(teamStatsString, Utils::rgb(255, 255, 255));

			Utils::printConsole("==================================\n", Utils::rgb(0, 255, 255));
			//if (saveteamstats) {
			//	char * tempChar = new char[2 + 1];
			//	std::strcpy(tempChar, teamStatsString.c_str());
			//	saveStats(_gameStatsFile, "TribesMatchStats.csv", tempChar);
			//}
		}
	}
}
