#pragma once

#include <string>
#include <regex>
#include <vector>
#include "Utils.h"
#include "Data.h"

struct Equipment
{
	Equipment(const std::string &pprimary, const std::string &psecondary, const std::string &pbelt, const std::string &ppack, const std::string &pperk1, const std::string &pperk2)
		: primary(pprimary), secondary(psecondary), belt(pbelt), pack(ppack), perk1(pperk1), perk2(pperk2)
	{ }

	// I'm using a static member instead of the constructor here in case we want to add skin & voice to the loadouts later
	// We would need another constructor and luabridge doesn't support multiple constructors
	static Equipment create(const std::string &pprimary, const std::string &psecondary, const std::string &pbelt, const std::string &ppack, const std::string &pperk1, const std::string &pperk2)
	{
		return Equipment(pprimary, psecondary, pbelt, ppack, pperk1, pperk2);
	}

	std::string primary;
	std::string secondary;
	std::string belt;
	std::string pack;
	std::string perk1;
	std::string perk2;
};

class Loadout
{
public:
	Loadout(const std::string &pclass, int pnum, const std::string &pname, Equipment &lo);
	~Loadout();

	void init(int pnum, const std::vector<std::string> &config);

public:
	std::string name;
	int class_type;
	int class_id;
	int loadout_nb;
	int equipment[9];
	std::string equip_name[9];
	bool valid;
};
