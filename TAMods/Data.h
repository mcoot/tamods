#pragma once

#include <string>
#include <regex>
#include <map>
#include "SdkHeaders.h"

namespace Data
{
	extern std::map<std::string, int> equipment[9][4];
	extern std::map<std::string, int> perks[2];
	extern std::map<std::string, int> classes;
	extern std::map<std::string, int> crosshairs;
	extern int classes_id[9];
	extern std::map<int, int> class_id_to_nb;
	extern std::string class_type_name[];
	extern std::string equip_type_name[];
}
