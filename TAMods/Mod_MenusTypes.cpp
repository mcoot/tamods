#include "Mod_MenusTypes.h"

static std::vector<int> validClasses = {
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

    LoadoutsData::LoadoutsData() {
        for (int class_id : validClasses) {
            data[class_id] = std::vector<LoadoutDef>();
            for (int i = 0; i < 9; ++i) {
                LoadoutDef ldt;
                for (int i = 0; i < EQP_MAX; ++i) {
                    ldt.equips[i] = -1;
                }
                ldt.name = "UNDEFINED";
                data[class_id].push_back(ldt);
            }
        }
    }

    void LoadoutsData::process_loadoutdata_message(int class_id, int loadout_index, int equip_point, int item_id, std::string string_val) {
        if (data.find(class_id) == data.end()) {
            Logger::log("Attempting to load loadout data for invalid class %d", class_id);
            return;
        }
        if (loadout_index < 0 || loadout_index >= 9) {
            Logger::log("Attempting to load loadout data for invalid loadout index %d", loadout_index);
            return;
        }
        if (equip_point != 0 && data[class_id][loadout_index].equips.find(equip_point) == data[class_id][loadout_index].equips.end()) {
            Logger::log("Attempting to load loadout data for invalid equip point %d", equip_point);
            return;
        }

        if (equip_point == 0) {
            data[class_id][loadout_index].name = string_val;
        }
        else {
            // Check if this is encoded perks
            if (equip_point == EQP_Tertiary && item_id > 10000) {
                int perkA = Utils::perks_DecodeA(item_id);
                int perkB = Utils::perks_DecodeB(item_id);

                // Validate these are real perks in case the login server loadouts are old
                // And just remove invalid perks
                if (Data::perk_id_to_name.find(perkA) == Data::perk_id_to_name.end()) {
                    perkA = 0;
                }
                if (Data::perk_id_to_name.find(perkB) == Data::perk_id_to_name.end()) {
                    perkB = 0;
                }

                data[class_id][loadout_index].equips[EQP_PerkA] = perkA;
                data[class_id][loadout_index].equips[EQP_PerkB] = perkB;
            }
            else {
                data[class_id][loadout_index].equips[equip_point] = item_id;
            }    
        }
    }

    int LoadoutsData::get_loadout_item(int class_id, int loadout_index, int equip_point) {
        if (data.find(class_id) == data.end()) {
            Logger::log("Attempting to read loadout data for invalid class %d", class_id);
            return -1;
        }
        if (loadout_index < 0 || loadout_index >= 9) {
            Logger::log("Attempting to read loadout data for invalid loadout index %d", loadout_index);
            return -1;
        }
        if (data[class_id][loadout_index].equips.find(equip_point) == data[class_id][loadout_index].equips.end()) {
            Logger::log("Attempting to read loadout data for invalid equip point %d", equip_point);
            return -1;
        }

        return data[class_id][loadout_index].equips[equip_point];
    }

    void LoadoutsData::update_loadout_item(int class_id, int loadout_index, int equip_point, int new_item_id) {
        if (data.find(class_id) == data.end()) {
            Logger::log("Attempting to read loadout data for invalid class %d", class_id);
            return;
        }
        if (loadout_index < 0 || loadout_index >= 9) {
            Logger::log("Attempting to read loadout data for invalid loadout index %d on class %d", loadout_index, class_id);
            return;
        }
        if (data[class_id][loadout_index].equips.find(equip_point) == data[class_id][loadout_index].equips.end()) {
            Logger::log("Attempting to read loadout data for invalid equip point %d", equip_point);
            return;
        }

        data[class_id][loadout_index].equips[equip_point] = new_item_id;
    }

    std::string LoadoutsData::get_loadout_name(int class_id, int loadout_index) {
        if (data.find(class_id) == data.end()) {
            Logger::log("Attempting to read loadout name for invalid class %d", class_id);
            return "";
        }
        if (loadout_index < 0 || loadout_index >= 9) {
            Logger::log("Attempting to read loadout name for invalid loadout index %d on class %d", loadout_index, class_id);
            return "";
        }

        return data[class_id][loadout_index].name;
    }

    void LoadoutsData::update_loadout_name(int class_id, int loadout_index, std::string new_name) {
        if (data.find(class_id) == data.end()) {
            Logger::log("Attempting to read loadout data for invalid class %d", class_id);
            return;
        }
        if (loadout_index < 0 || loadout_index >= 9) {
            Logger::log("Attempting to read loadout data for invalid loadout index %d", loadout_index);
            return;
        }

        data[class_id][loadout_index].name = new_name;
    }

}

ModdedMenuData::MenuData g_ModdedMenuData;
ModdedMenuData::LoadoutsData g_ModdedLoadoutsData;