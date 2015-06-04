#pragma once

#include <string>
#include <regex>
#include "Utils.h"
#include "Data.h"

class Loadout
{
public:
	Loadout(const std::smatch &config);
	~Loadout();

public:
	std::string name;
	int class_type;
	int class_id;
	int loadout_nb;
	int equipment[9];
	std::string equip_name[9];
	bool valid;
};
