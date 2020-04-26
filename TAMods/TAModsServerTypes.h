#pragma once

#include <sstream>
#include <map>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"
#include "GameBalance.h"

using json = nlohmann::json;

#define DCSRV_MSG_KIND_INVALID 0x0

#define DCSRV_MSG_KIND_PLAYER_CONNECTION 0x1000
#define DCSRV_MSG_KIND_GAME_BALANCE_DETAILS 0x1001
#define DCSRV_MSG_KIND_STATE_UPDATE 0x1002
#define DCSRV_MSG_KIND_MESSAGE_TO_CLIENT 0x1003
#define DCSRV_MSG_KIND_ROLE_LOGIN 0x1004
#define DCSRV_MSG_KIND_EXECUTE_COMMAND 0x1005

namespace TAModsServer {

    long long netIdToLong(FUniqueNetId id);
    FUniqueNetId longToNetId(long long id);

    class Message {
    public:
        virtual short getMessageKind() {
            return DCSRV_MSG_KIND_INVALID;
        }

        virtual void toJson(json& j) {}
        virtual bool fromJson(const json& j) {
            return false;
        }

        bool isInvalidMessage() {
            return getMessageKind() == DCSRV_MSG_KIND_INVALID;
        }
    };

    class PlayerConnectionMessage : public Message {
    public:
        FUniqueNetId uniquePlayerId;
        std::string protocolVersion;
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_PLAYER_CONNECTION;
        }

        void toJson(json& j) {
            j["player_unique_id"] = netIdToLong(uniquePlayerId);
            j["protocol_version"] = protocolVersion;
        }

        bool fromJson(const json& j) {
            auto& it = j.find("player_unique_id");
            if (it == j.end()) return false;
            uniquePlayerId = longToNetId(j["player_unique_id"]);

            it = j.find("protocol_version");
            if (it == j.end()) return false;
            protocolVersion = j["protocol_version"].get<std::string>();

            return true;
        }
    };

    class GameBalanceDetailsMessage : public Message {
    public:
        GameBalance::ReplicatedSettings replicatedSettings;
        GameBalance::Items::ItemsConfig itemProperties;
        GameBalance::Items::DeviceValuesConfig deviceValueProperties;
        GameBalance::Classes::ClassesConfig classProperties;
        GameBalance::Vehicles::VehiclesConfig vehicleProperties;
        GameBalance::VehicleWeapons::VehicleWeaponsConfig vehicleWeaponProperties;
    private:
        void addPropValToJson(json& j, int propId, GameBalance::PropValue val) {
            switch (val.type) {
            case GameBalance::ValueType::BOOLEAN:
                j[std::to_string(propId)] = val.valBool;
                break;
            case GameBalance::ValueType::INTEGER:
                j[std::to_string(propId)] = val.valInt;
                break;
            case GameBalance::ValueType::FLOAT:
                j[std::to_string(propId)] = val.valFloat;
                break;
            case GameBalance::ValueType::STRING:
                j[std::to_string(propId)] = val.valString;
                break;
            }
        }

        // Doesn't in integer type PropValues, since it's not possible to know if it ought to be a float or integer type
        bool readAnyPropVal(const json& j, GameBalance::PropValue& ret) {
            if (j.is_boolean()) {
                ret = GameBalance::PropValue::fromBool(j.get<bool>());
            }
            else if (j.is_number()) {
                ret = GameBalance::PropValue::fromFloat(j.get<float>());
            }
            else if (j.is_string()) {
                ret = GameBalance::PropValue::fromString(j.get<std::string>());
            }
            else {
                return false;
            }

            return true;
        }

        bool readPropValFromJson(const json& j, GameBalance::ValueType expectedType, GameBalance::PropValue& ret) {
            switch (expectedType) {
            case GameBalance::ValueType::BOOLEAN:
                if (!j.is_boolean()) {
                    return false;
                }
                ret = GameBalance::PropValue::fromBool(j.get<bool>());
                break;
            case GameBalance::ValueType::INTEGER:
                if (!j.is_number_integer()) {
                    return false;
                }
                ret = GameBalance::PropValue::fromInt(j.get<int>());
                break;
            case GameBalance::ValueType::FLOAT:
                if (!j.is_number()) {
                    return false;
                }
                ret = GameBalance::PropValue::fromFloat(j.get<float>());
                break;
            case GameBalance::ValueType::STRING:
                if (!j.is_string()) {
                    return false;
                }
                ret = GameBalance::PropValue::fromString(j.get<std::string>());
                break;
            }
            return true;
        }

        bool readReplicatedSettings(json& j, GameBalance::ReplicatedSettings& ret) {
            for (json::iterator it = j.begin(); it != j.end(); ++it) {
                GameBalance::PropValue propVal;
                if (!readAnyPropVal(*it, propVal)) {
                    Logger::log("Unable to read replicated setting value for %s", it.key());
                    continue;
                }

                ret[it.key()] = propVal;
            }
            return true;
        }

        template <typename IdType>
        bool readPropConfig(json& j, std::map<IdType, GameBalance::Property>& propDefs, std::map<int, std::map<IdType, GameBalance::PropValue> >& ret) {
            for (json::iterator elem_it = j.begin(); elem_it != j.end(); ++elem_it) {
                std::map<IdType, GameBalance::PropValue> curElemConfig;

                int elemId;
                try {
                    elemId = std::stoi(elem_it.key());
                }
                catch (std::invalid_argument&) {
                    return false;
                }

                json curElem = j[elem_it.key()];
                for (json::iterator prop_it = curElem.begin(); prop_it != curElem.end(); ++prop_it) {

                    IdType propId;
                    try {
                        propId = (IdType)std::stoi(prop_it.key());
                    }
                    catch (std::invalid_argument&) {
                        return false;
                    }

                    auto& propDefIt = propDefs.find(propId);
                    if (propDefIt == propDefs.end()) {
                        // Ignore unknown property IDs
                        continue;
                    }

                    GameBalance::PropValue propVal;
                    if (!readPropValFromJson(*prop_it, propDefIt->second.getType(), propVal)) {
                        Logger::log("Unable to read item prop config for propId %d on elem %d: wrong type (should be %s)",
                            propId, elemId,
                            GameBalance::getValueTypeName(propDefIt->second.getType()).c_str());
                        continue;
                    }

                    curElemConfig[propId] = propVal;
                }
                ret[elemId] = curElemConfig;
            }
            return true;
        }

        bool readValueModConfig(json& j, GameBalance::Items::DeviceValuesConfig& ret) {
            for (json::iterator elem_it = j.begin(); elem_it != j.end(); ++elem_it) {
                int elemId;
                try {
                    elemId = std::stoi(elem_it.key());
                }
                catch (std::invalid_argument&) {
                    return false;
                }

                std::vector<GameBalance::DeviceValueMod> currentItemMods;
                json curElem = j[elem_it.key()];
                for (json::iterator mod_it = curElem.begin(); mod_it != curElem.end(); ++mod_it) {
                    json curValueModJson = *mod_it;
                    // Each element in the array should just have one item defining a mod
                    json::iterator curModIt = mod_it->begin();
                    if (curModIt == mod_it->end()) {
                        return false;
                    }
                    int valueModType;
                    try {
                        valueModType = std::stoi(curModIt.key());
                    }
                    catch (std::invalid_argument&) {
                        return false;
                    }
                    json curModValue = curModIt.value();
                    if (!curModValue.is_number()) {
                        // Value mod values should be numbers
                        return false;
                    }
                    float val = curModIt.value().get<float>();

                    GameBalance::DeviceValueMod mod;
                    mod.modType = valueModType;
                    mod.value = val;

                    currentItemMods.push_back(mod);
                }
                ret[elemId] = currentItemMods;
            }

            return true;
        }
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_GAME_BALANCE_DETAILS;
        }

        void toJson(json& j) {
            json jReplicatedSettings = json::object();
            json jItemProps = json::object();
            json jDeviceValueProps = json::object();
            json jClassProps = json::object();
            json jVehicleProps = json::object();
            json jVehicleWeaponProps = json::object();

            for (auto& s : replicatedSettings) {
                switch (s.second.type) {
                case GameBalance::ValueType::BOOLEAN:
                    jReplicatedSettings[s.first] = s.second.valBool;
                    break;
                case GameBalance::ValueType::INTEGER:
                    jReplicatedSettings[s.first] = s.second.valInt;
                    break;
                case GameBalance::ValueType::FLOAT:
                    jReplicatedSettings[s.first] = s.second.valFloat;
                    break;
                case GameBalance::ValueType::STRING:
                    jReplicatedSettings[s.first] = s.second.valString;
                    break;
                }
            }
            j["replicated_settings"] = jReplicatedSettings;

            for (auto& item : itemProperties) {
                json curItem;
                for (auto& prop : item.second) {
                    addPropValToJson(curItem, (int)prop.first, prop.second);
                }
                jItemProps[std::to_string(item.first)] = curItem;
            }
            j["item_properties"] = jItemProps;

            for (auto& item : deviceValueProperties) {
                json curItem = json::array();
                for (auto& valueMod : item.second) {
                    json curValueMod;
                    curValueMod[std::to_string(valueMod.modType)] = valueMod.value;
                    curItem.push_back(curValueMod);
                }
                jDeviceValueProps[std::to_string(item.first)] = curItem;
            }
            j["device_value_properties"] = jDeviceValueProps;

            for (auto& item : classProperties) {
                json curItem;
                for (auto& prop : item.second) {
                    addPropValToJson(curItem, (int)prop.first, prop.second);
                }
                jClassProps[std::to_string(item.first)] = curItem;
            }
            j["class_properties"] = jClassProps;

            for (auto& item : vehicleProperties) {
                json curItem;
                for (auto& prop : item.second) {
                    addPropValToJson(curItem, (int)prop.first, prop.second);
                }
                jVehicleProps[std::to_string(item.first)] = curItem;
            }
            j["vehicle_properties"] = jVehicleProps;

            for (auto& item : vehicleWeaponProperties) {
                json curItem;
                for (auto& prop : item.second) {
                    addPropValToJson(curItem, (int)prop.first, prop.second);
                }
                jVehicleWeaponProps[std::to_string(item.first)] = curItem;
            }
            j["vehicle_weapon_properties"] = jVehicleWeaponProps;
        }

        bool fromJson(const json& j) {
            itemProperties.clear();
            deviceValueProperties.clear();
            classProperties.clear();
            vehicleProperties.clear();
            vehicleWeaponProperties.clear();

            auto& repSettingsIt = j.find("replicated_settings");
            if (repSettingsIt == j.end()) {
                return false;
            }
            json repSettingsJson = j["replicated_settings"];

            auto& itemPropsIt = j.find("item_properties");
            if (itemPropsIt == j.end()) {
                return false;
            }
            json itemProps = j["item_properties"];

            auto& deviceValuePropsIt = j.find("device_value_properties");
            if (deviceValuePropsIt == j.end()) {
                return false;
            }
            json deviceValueProps = j["device_value_properties"];

            auto& classPropsIt = j.find("class_properties");
            if (classPropsIt == j.end()) {
                return false;
            }
            json classProps = j["class_properties"];

            auto& vehiclePropsIt = j.find("vehicle_properties");
            if (vehiclePropsIt == j.end()) {
                return false;
            }
            json vehicleProps = j["vehicle_properties"];

            auto& vehicleWeaponPropsIt = j.find("vehicle_weapon_properties");
            if (vehicleWeaponPropsIt == j.end()) {
                return false;
            }
            json vehicleWeaponProps = j["vehicle_weapon_properties"];

            if (!readReplicatedSettings(repSettingsJson, replicatedSettings)) {
                return false;
            }

            if (!readPropConfig(itemProps, GameBalance::Items::properties, itemProperties)) {
                return false;
            }
            if (!readValueModConfig(deviceValueProps, deviceValueProperties)) {
                return false;
            }
            if (!readPropConfig(classProps, GameBalance::Classes::properties, classProperties)) {
                return false;
            }
            if (!readPropConfig(vehicleProps, GameBalance::Vehicles::properties, vehicleProperties)) {
                return false;
            }
            if (!readPropConfig(vehicleWeaponProps, GameBalance::VehicleWeapons::properties, vehicleWeaponProperties)) {
                return false;
            }

            return true;
        }
    };

    class StateUpdateMessage : public Message {
    public:
        float playerPing;
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_STATE_UPDATE;
        }

        void toJson(json& j) {
            j["player_ping"] = playerPing;
        }

        bool fromJson(const json& j) {
            auto& it = j.find("player_ping");
            if (it == j.end()) return false;
            playerPing = j["player_ping"];

            return true;
        }
    };

    class MessageToClientMessage : public Message {
    public:
        struct ConsoleMsgDetails {
            std::string message;
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
        struct IngameMsgDetails {
            bool doShow;
            std::string message;
            float time;
            int priority;
        };
    public:
        std::vector<ConsoleMsgDetails> consoleMessages;
        IngameMsgDetails ingameMessage;
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_MESSAGE_TO_CLIENT;
        }

        void toJson(json& j) {
            j["console_messages"] = json::array();
            for (auto& msg : consoleMessages) {
                json curMsg = json::object();
                curMsg["message"] = msg.message;
                curMsg["r"] = msg.r;
                curMsg["g"] = msg.g;
                curMsg["b"] = msg.b;
                curMsg["a"] = msg.a;
                j["console_messages"].push_back(curMsg);
            }

            j["ingame_message"] = json::object();
            j["ingame_message"]["do_show"] = ingameMessage.doShow;
            j["ingame_message"]["message"] = ingameMessage.message;
            j["ingame_message"]["time"] = ingameMessage.time;
            j["ingame_message"]["priority"] = ingameMessage.priority;
        }

        bool fromJson(const json& j) {
            if (j.find("console_messages") == j.end()) return false;

            json consoleMessagesJson = j["console_messages"];
            if (!consoleMessagesJson.is_array()) return false;
            for (auto& elem : consoleMessagesJson) {
                if (elem.find("message") == elem.end()) return false;
                if (elem.find("r") == elem.end()) return false;
                if (elem.find("g") == elem.end()) return false;
                if (elem.find("b") == elem.end()) return false;
                if (elem.find("a") == elem.end()) return false;

                ConsoleMsgDetails details;
                details.message = elem["message"].get<std::string>();
                details.r = elem["r"].get<unsigned char>();
                details.g = elem["g"].get<unsigned char>();
                details.b = elem["b"].get<unsigned char>();
                details.a = elem["a"].get<unsigned char>();

                consoleMessages.push_back(details);
            }

            if (j.find("ingame_message") == j.end()) return false;
            json ingameMessageJson = j["ingame_message"];

            if (!ingameMessageJson.is_object()) return false;
            if (ingameMessageJson.find("do_show") == ingameMessageJson.end()) return false;

            ingameMessage.doShow = ingameMessageJson["do_show"].get<bool>();
            if (ingameMessage.doShow) {
                if (ingameMessageJson.find("message") == ingameMessageJson.end()) return false;
                if (ingameMessageJson.find("time") == ingameMessageJson.end()) return false;
                if (ingameMessageJson.find("priority") == ingameMessageJson.end()) return false;

                ingameMessage.message = ingameMessageJson["message"].get<std::string>();
                ingameMessage.time = ingameMessageJson["time"].get<float>();
                ingameMessage.priority = ingameMessageJson["priority"].get<int>();
            }


            return true;
        }
    };

    class RoleLoginMessage : public Message {
    public:
        std::string role;
        std::string password;
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_ROLE_LOGIN;
        }

        void toJson(json& j) {
            j["role"] = role;
            j["password"] = password;
        }

        bool fromJson(const json& j) {
            if (j.find("role") == j.end()) return false;
            role = j["role"].get<std::string>();

            if (j.find("password") == j.end()) return false;
            password = j["password"].get<std::string>();

            return true;
        }
    };

    class ExecuteCommandMessage : public Message {
    public:
        bool rawLua;
        std::string commandString;
    public:
        short getMessageKind() override {
            return DCSRV_MSG_KIND_EXECUTE_COMMAND;
        }

        void toJson(json& j) {
            j["raw_lua"] = rawLua;
            j["command_string"] = commandString;
        }

        bool fromJson(const json& j) {
            if (j.find("raw_lua") == j.end()) return false;
            rawLua = j["raw_lua"].get<bool>();

            if (j.find("command_string") == j.end()) return false;
            commandString = j["command_string"].get<std::string>();

            return true;
        }
    };

}