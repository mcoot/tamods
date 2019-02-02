#pragma once

#include <sstream>
#include <map>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"

using json = nlohmann::json;

namespace ModdedMenuData {

	enum class MenuItemKind {
		INVALID,
		WEAPON,
		BELT,
		PACK,
		SKIN,
		PERKA,
		PERKB,
		VOICE
	};

	struct MenuItem {
	public:
		int id;
		MenuItemKind kind;
		std::string category;
		int class_id;
	public:
		MenuItem() :
			id(0),
			kind(MenuItemKind::INVALID),
			category(""),
			class_id(0)
		{}
		MenuItem(int id, MenuItemKind kind, std::string category, int class_id) : 
			id(id), 
			kind(kind), 
			category(category), 
			class_id(class_id) 
		{}

		MenuItem(json& j);
	};

	struct LoadoutItem {
	public:
		int class_id;
		int loadout_index;
		int equip_position;
		int item_id;
		std::string str_val;
	public:
		LoadoutItem() :
			class_id(0),
			loadout_index(0),
			equip_position(0),
			item_id(0),
			str_val("")
		{}
		LoadoutItem(int class_id, int loadout_index, int equip_point, int item_id) :
			class_id(class_id),
			loadout_index(loadout_index),
			equip_position(equip_point),
			item_id(item_id),
			str_val("")
		{}
		LoadoutItem(int class_id, int loadout_index, int equip_point, std::string str_val) :
			class_id(class_id),
			loadout_index(loadout_index),
			equip_position(equip_point),
			item_id(0),
			str_val(str_val)
		{}

		LoadoutItem(json& j);
	};

}