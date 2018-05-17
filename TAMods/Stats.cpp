#include "Stats.h"

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
	flagMaxGrabSpeed = 0;
	flagGrabSpeedAverage = 0;

	damageDone = 0;
	damageRecieved = 0;
}

void Stats::saveStats() {
	//save stats to file function
}


void Stats::printStats(){
	std::string tempstr = "Shots hit: " + std::to_string(bulletsHit);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Shots fired: " + std::to_string(bulletsFired);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Accuracy: " + std::to_string(accuracy);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	std::string tempstr = "Kills: " + std::to_string(kills);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Deaths: " + std::to_string(deaths);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	double kd = (double)kills /(double)deaths;
	std::string tempstr = "KD: " + std::to_string(kd);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Assists: " + std::to_string(assists);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Midair Kills: " + std::to_string(midairKills);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	std::string tempstr = "Returns: " + std::to_string(flagReturns);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Caps: " + std::to_string(flagCaps);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Highest Grab Speed: " + std::to_string(flagMaxGrabSpeed);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Average Grab Speed: " + std::to_string(flagGrabSpeedAverage);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));

	std::string tempstr = "Damage Output: " + std::to_string(damageDone);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	std::string tempstr = "Damage Recieved: " + std::to_string(damageRecieved);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	resetStats();
}
