#pragma once

#include <mutex>
#include <sstream>
#include <map>

#include <nlohmann/json.hpp>

#include "SdkHeaders.h"
#include "Logger.h"
#include "Utils.h"
#include "Data.h"

using json = nlohmann::json;

namespace ModdedMenuData {

    class GameClass {
    private:
        std::map<int, std::vector<int> > data;
    public:
        GameClass();

        void add_item(int equip_point, int item_id);
        void clear();

        std::vector<int> get_equipment(int equip_point);
    };

    class MenuData {
    private:
        std::mutex menuDataMutex;
        std::string timestamp = "";
        std::map<int, GameClass> data;
    public:
        MenuData();

        void process_menudata_message(int class_id, std::string kind, std::string category, int item_id, std::string msg_timestamp);
        
        GameClass get_class(int class_id);
    };

    struct LoadoutDef {
        std::map<int, int> equips;
        std::string name;
    };

    class LoadoutsData {
    private:
        std::mutex loadoutDataMutex;
        std::map<int, std::vector<LoadoutDef>> data;
    public:
        LoadoutsData();

        void process_loadoutdata_message(int class_id, int loadout_index, int equip_point, int item_id, std::string string_val);

        int get_loadout_item(int class_id, int loadout_index, int equip_point);
        void update_loadout_item(int class_id, int loadout_index, int equip_point, int new_item_id);
        std::string get_loadout_name(int class_id, int loadout_index);
        void update_loadout_name(int class_id, int loadout_index, std::string new_name);
    };

}

extern ModdedMenuData::MenuData g_ModdedMenuData;
extern ModdedMenuData::LoadoutsData g_ModdedLoadoutsData;