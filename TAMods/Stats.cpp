#include "Stats.h"

Stats g_stats;

Stats::Stats()
{
	resetStats();
}

Stats::~Stats()
{
}

void Stats::resetStats(){
	//Reset counts
	bulletsHit = 0;
}

void Stats::printStats(){
	std::string tempstr =  "Shots hit: " + std::to_string(bulletsHit);
	Utils::printConsole(tempstr, Utils::rgb(0, 255, 255));
	resetStats();
}