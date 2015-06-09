#pragma once

#include <sstream>
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
public:
	int bulletsHit;
};