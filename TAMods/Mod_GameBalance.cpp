#include "Mods.h"

GameBalance::GameBalanceTracker g_gameBalanceTracker;

static void applyItemProperties(GameBalance::Items::ItemsConfig& cfg) {
	for (auto& item : cfg) {
		auto& wepit = Data::weapon_id_to_weapon_class.find(item.first);
		if (wepit == Data::weapon_id_to_weapon_class.end()) {
			Logger::log("Unable to set weapon property; invalid weapon id %d", item.first);
			continue;
		}

		if (!wepit->second || !wepit->second->Default || !wepit->second->Default->IsA(ATrDevice::StaticClass())) {
			Logger::log("Unable to set weapon property; failed to get default weapon for id %d", item.first);
			continue;
		}

		for (auto& prop : item.second) {
			auto& it = GameBalance::Items::properties.find(prop.first);
			if (it == GameBalance::Items::properties.end()) {
				// Non-existent property, fail
				Logger::log("Unable to set weapon property; invalid property id %d", prop.first);
				continue;
			}

			GameBalance::PropValue oldVal;
			it->second.get(wepit->second->Default, oldVal);

			g_gameBalanceTracker.recordItemProp(item.first, prop.first, oldVal);
			it->second.apply(prop.second, wepit->second->Default);
		}
	}
}

namespace GameBalance {

	ValueType Property::getType() {
		return type;
	}

	bool Property::apply(PropValue value, UObject* obj) {
		return (value.type == type && applier(value, obj));
	}

	bool Property::get(UObject* obj, PropValue& ret) {
		return getter(obj, ret);
	}

	// Record a change
	void GameBalanceTracker::recordItemProp(int itemId, Items::PropId propId, PropValue val) {
		auto& item_it = origItemProps.find(itemId);
		if (item_it == origItemProps.end()) {
			origItemProps[itemId] = Items::PropMapping();
		}

		auto& prop_it = origItemProps[itemId].find(propId);
		if (prop_it != origItemProps[itemId].end()) {
			// Only want to record the *original* value, do not overwrite
			return;
		}

		origItemProps[itemId][propId] = val;
	}

	// Revert modified game balance changes back to their defaults
	void GameBalanceTracker::revert() {
		applyItemProperties(origItemProps);
	}
}

void TAModsServer::Client::handle_GameBalanceDetailsMessage(const json& j) {
	GameBalanceDetailsMessage msg;

	if (!msg.fromJson(j)) {
		Logger::log("Failed to parse game balance details from server: %s", j.dump().c_str());
		return;
	}

	applyItemProperties(msg.itemProperties);
}