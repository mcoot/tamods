#include "Mod_MenusTypes.h"

namespace ModdedMenuData {

	static MenuItemKind parseKind(std::string kindStr) {
		if (kindStr == "weapon") return MenuItemKind::WEAPON;
		if (kindStr == "belt") return MenuItemKind::BELT;
		if (kindStr == "packs") return MenuItemKind::PACK;
		if (kindStr == "skins") return MenuItemKind::SKIN;
		if (kindStr == "perkA") return MenuItemKind::PERKA;
		if (kindStr == "perkB") return MenuItemKind::PERKB;
		if (kindStr == "voices") return MenuItemKind::VOICE;

		return MenuItemKind::INVALID;
	}

	static int parseClassId(std::string classStr) {
		if (classStr == "pth") return CONST_CLASS_TYPE_LIGHT_PATHFINDER;
		if (classStr == "sen") return CONST_CLASS_TYPE_LIGHT_SENTINEL;
		if (classStr == "inf") return CONST_CLASS_TYPE_LIGHT_INFILTRATOR;
		if (classStr == "sld") return CONST_CLASS_TYPE_MEDIUM_SOLDIER;
		if (classStr == "rdr") return CONST_CLASS_TYPE_MEDIUM_RAIDER;
		if (classStr == "tcn") return CONST_CLASS_TYPE_MEDIUM_TECHNICIAN;
		if (classStr == "jug") return CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT;
		if (classStr == "dmb") return CONST_CLASS_TYPE_HEAVY_DOOMBRINGER;
		if (classStr == "brt") return CONST_CLASS_TYPE_HEAVY_BRUTE;

		return 0;
	}

	MenuItem::MenuItem(json& j) {
		kind = parseKind(j["kind"]);
		id = j["id"];

		class_id = 0;
		if (kind == MenuItemKind::BELT || kind == MenuItemKind::PACK || kind == MenuItemKind::SKIN || kind == MenuItemKind::WEAPON) {
			class_id = parseClassId(j["class"]);
		}

		category = "";
		if (kind == MenuItemKind::WEAPON) {
			category = j["cat"].get<std::string>();
		}
	}
	
	LoadoutItem::LoadoutItem(json& j) {
		class_id = j["class"];
		loadout_index = j["num"];
		equip_position = j["eqp"];

		json itemJson = j["item"];
		if (itemJson.is_string()) {
			str_val = itemJson.get<std::string>();
		}
		else {
			item_id = itemJson;
		}
	}

}
