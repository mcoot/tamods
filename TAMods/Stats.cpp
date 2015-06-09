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
	Utils::console("Shots hit: ", bulletsHit);
}