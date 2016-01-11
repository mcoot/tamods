#pragma once

#include <string>
#include <regex>
#include <map>
#include "SdkHeaders.h"

namespace Data
{
	extern std::map<std::string, int> weapons[3][7];
	extern std::map<int, std::string> weapon_id_to_name;
	extern std::map<int, std::string> weapon_id_to_proj_name;
	extern std::map<std::string, int> vehicle_weapons;
	extern std::map<std::string, int> classes;
	extern std::map<std::string, int> crosshairs;
	extern int classes_id[3];
	extern std::map<int, int> class_id_to_nb;
	extern std::string class_type_name[];
	extern std::string equip_type_name[];
}
