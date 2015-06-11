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
public:
	int bulletsHit;
};