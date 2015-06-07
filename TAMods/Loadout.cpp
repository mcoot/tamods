#include "Loadout.h"

Loadout::Loadout(const std::string &pclass, int pnum, const std::string &pname, Equipment &lo)
{
	std::vector<std::string> config;

	config.push_back("");
	config.push_back(pclass);
	config.push_back("");
	config.push_back(pname);
	config.push_back(lo.primary);
	config.push_back(lo.secondary);
	config.push_back(lo.belt);
	config.push_back(lo.pack);
	config.push_back(lo.perk1);
	config.push_back(lo.perk2);
	init(pnum, config);
}

void Loadout::init(int pnum, const std::vector<std::string> &config)
{
	valid = false;
	if (pnum < 1 || pnum > 9)
	{
		Utils::console("Loadout number must be between 1 and 9 (#%d found)", pnum);
		return;
	}
	loadout_nb = pnum - 1;
	name = config[3];
	if (name.size() == 0)
		name = std::string("LOADOUT ") + std::string(1, 'A' + loadout_nb);
	class_type = Utils::searchMapId(Data::classes, config[1], "class type");
	if (!class_type)
		return;
	class_id = Data::classes_id[--class_type];
	for (size_t i = 0; i < 9; i++)
		equipment[i] = 0;
	for (size_t i = 0; i < 4; i++)
	{
		equip_name[i + 0] = Utils::trim(config[i + 4]);
		equipment[i + 0] = Utils::searchMapId(Data::equipment[class_type][i], equip_name[i + 0],
			Data::class_type_name[class_type] + "'s " + Data::equip_type_name[i + 0]);
	}
	for (size_t i = 0; i < 2; i++)
	{
		equip_name[i + 5] = Utils::trim(config[i + 8]);
		equipment[i + 5] = Utils::searchMapId(Data::perks[i], equip_name[i + 5],
			Data::class_type_name[class_type] + "'s " + Data::equip_type_name[i + 5]);
	}
	valid = true;
}

Loadout::~Loadout()
{
}
