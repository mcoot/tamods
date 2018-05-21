#include "Stats.h"

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
	flagMaxGrabSpeed = 0;
	flagGrabSpeedAverage = 0;

	damageDone = 0;
	damageReceived = 0;
}

void Stats::saveStats(const char *format, ...) {
	//save stats to file function
	if (!_statsFile)
	{
		const char *profile = getenv("USERPROFILE");
		std::string directory;
		if (profile)
			directory = std::string(profile) + "\\Documents\\";
		else
			directory = std::string("C:\\");
		_statsFile = fopen(std::string(directory + "TAModsStats.csv").c_str(), "a");
	}

	if (!_statsFile)
		return;

	char buff[256];
	va_list args;

	va_start(args, format);
	vsprintf(buff, format, args);
	va_end(args);
	fprintf(_statsFile, "%s\n", buff);
	fflush(_statsFile);
}

void Stats::saveTeamStats(const char *format, ...) {
	if (!_gameStatsFile)
	{
		const char *profile = getenv("USERPROFILE");
		std::string directory;
		if (profile)
			directory = std::string(profile) + "\\Documents\\";
		else
			directory = std::string("C:\\");
		_gameStatsFile = fopen(std::string(directory + "TAModsGameStats.csv").c_str(), "a");
	}

	if (!_gameStatsFile)
		return;

	char buff[256];
	va_list args;

	va_start(args, format);
	vsprintf(buff, format, args);
	va_end(args);
	fprintf(_gameStatsFile, "%s\n", buff);
	fflush(_gameStatsFile);

}

void Stats::cleanup()
{
	if (!_gameStatsFile) {}
	else {
		fclose(_gameStatsFile);
	}
	if (!_statsFile) {}
	else {
		fclose(_gameStatsFile);
	}
	return;
}

void Stats::printStats(){
	std::string tempstr;
	tempstr = "Shots hit: " + std::to_string(bulletsHit);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Shots fired: " + std::to_string(bulletsFired);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Accuracy: " + std::to_string(accuracy);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	tempstr = "Kills: " + std::to_string(kills);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Deaths: " + std::to_string(deaths);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	double kd = (double)kills /(double)deaths;
	tempstr = "KD: " + std::to_string(kd);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Assists: " + std::to_string(assists);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Midair Kills: " + std::to_string(midairKills);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	tempstr = "Returns: " + std::to_string(flagReturns);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Caps: " + std::to_string(flagCaps);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Highest Grab Speed: " + std::to_string(flagMaxGrabSpeed);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Average Grab Speed: " + std::to_string(flagGrabSpeedAverage);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	tempstr = "Damage Output: " + std::to_string(damageDone);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	tempstr = "Damage Received: " + std::to_string(damageReceived);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	resetStats();
}
void Stats::printTeamStats(bool saveStats) {
	//BE Score,Player1,Player2,Player3,Player4,Player5,Player6,Player7
	//DS Score,Player1,Player2,Player3,Player4,Player5,Player6,Player7

	std::string tempstr;

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

		tempstr = mapName + "," + std::to_string(getGameData::score(0)) + playersBE + "\n" + mapName + "," + std::to_string(getGameData::score(1)) + playersDS;

		Utils::printConsole(tempstr);
		if (saveStats) {
			char * tempChar = new char[tempstr.length() + 1];
			std::strcpy(tempChar, tempstr.c_str());
			saveTeamStats(tempChar);
		}
	}

}
