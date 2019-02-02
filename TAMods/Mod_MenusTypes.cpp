#include "Mod_MenusTypes.h"

namespace ModdedMenuData {

	GameClass::GameClass() : data() {
		clear();
	}

	void GameClass::add_item(int equip_point, int item_id) {
		if (data.find(equip_point) == data.end()) {
			Logger::log("Attempting to load menu data for invalid eqp %d", equip_point);
			return;
		}

		data[equip_point].push_back(item_id);
	}

	void GameClass::clear() {
		for (int i = 0; i < EQP_MAX; ++i) {
			data[i] = std::vector<int>();
		}
	}

	std::vector<int> GameClass::get_equipment(int equip_point) {
		if (data.find(equip_point) == data.end()) {
			Logger::log("Attempting to read menu data for invalid eqp %d", equip_point);
			return std::vector<int>();
		}

		return data[equip_point];
	}

	MenuData::MenuData() {
		std::vector<int> validClasses = {
			CONST_CLASS_TYPE_LIGHT_PATHFINDER,
			CONST_CLASS_TYPE_LIGHT_SENTINEL,
			CONST_CLASS_TYPE_LIGHT_INFILTRATOR,
			CONST_CLASS_TYPE_MEDIUM_SOLDIER,
			CONST_CLASS_TYPE_MEDIUM_RAIDER,
			CONST_CLASS_TYPE_MEDIUM_TECHNICIAN,
			CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT,
			CONST_CLASS_TYPE_HEAVY_DOOMBRINGER,
			CONST_CLASS_TYPE_HEAVY_BRUTE
		};

		for (int class_id : validClasses) {
			data[class_id] = GameClass();
		}
	}

	void MenuData::process_menudata_message(int class_id, std::string kind, std::string category, int item_id, std::string msg_timestamp) {
		std::lock_guard<std::mutex> lock(menuDataMutex);

		// If the timestamp doesn't match, this is a "new" set of menu data and we need to reset
		if (msg_timestamp != timestamp) {
			for (auto& c : data) {
				c.second.clear();
			}
			timestamp = msg_timestamp;
		}

		if (kind == "perkA" || kind == "perkB" || kind == "voices") {
			int eqp = 0;
			if (kind == "perkA") {
				eqp = EQP_PerkA;
			}
			else if (kind == "perkB") {
				eqp = EQP_PerkB;
			}
			else {
				eqp = EQP_Voice;
			}
			// Apply to all classes
			for (auto& c : data) {
				c.second.add_item(eqp, item_id);
			}
			return;
		}

		if (data.find(class_id) == data.end()) {
			Logger::log("Attempting to read menu data (kind %s) for invalid class %d", kind.c_str(), class_id);
			return;
		}

		if (kind == "weapon") {
			if (category == "primary") {
				data[class_id].add_item(EQP_Primary, item_id);
			}
			else if (category == "secondary") {
				data[class_id].add_item(EQP_Secondary, item_id);
			}
		}
		else if (kind == "belt") {
			data[class_id].add_item(EQP_Belt, item_id);
		}
		else if (kind == "packs") {
			data[class_id].add_item(EQP_Pack, item_id);
		}
		else if (kind == "skins") {
			data[class_id].add_item(EQP_Skin, item_id);
		}
	}

	GameClass MenuData::get_class(int class_id) {
		std::lock_guard<std::mutex> lock(menuDataMutex);

		if (data.find(class_id) == data.end()) {
			Logger::log("Attempting to read menu data for invalid class %d", class_id);
			return GameClass();
		}

		return data[class_id];
	}

}

ModdedMenuData::MenuData g_ModdedMenuData;