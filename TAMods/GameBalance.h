#pragma once

#include "buildconfig.h"

#include <functional>
#include <map>

#include "Logger.h"
#include "SdkHeaders.h"
#include "Utils.h"

namespace GameBalance {

	enum class ValueType {
		BOOLEAN,
		INTEGER,
		FLOAT,
		STRING
	};

	// Tagged union for possible types of a property
	class PropValue {
	public:
		ValueType type;

		// The value (an anonymous union)
		union {
			bool valBool;
			int valInt;
			float valFloat;
			std::string valString;
		};

		PropValue() : type(ValueType::INTEGER), valInt(0) {}

		// Constructors for constructing from any valid type
		PropValue(const PropValue& other) : type(other.type) {
			operator=(other);
		}
		PropValue(bool val) : type(ValueType::BOOLEAN), valBool(val) {}
		PropValue(int val) : type(ValueType::INTEGER), valInt(val) {}
		PropValue(float val) : type(ValueType::FLOAT), valFloat(val) {}
		PropValue(std::string val) : type(ValueType::STRING), valString(val) {}
		~PropValue() {}

		PropValue& operator=(const PropValue& other) {
			switch (other.type) {
			case ValueType::BOOLEAN:
				valBool = other.valBool;
				break;
			case ValueType::INTEGER:
				valInt = other.valInt;
				break;
			case ValueType::FLOAT:
				valFloat = other.valFloat;
				break;
			case ValueType::STRING:
				valString = other.valString;
				break;
			}
			type = other.type;

			return *this;
		}

		// Static methods for constructing from a specific type
		static PropValue fromBool(bool val) { return PropValue(val); }
		static PropValue fromInt(int val) { return PropValue(val); }
		static PropValue fromFloat(float val) { return PropValue(val); }
		static PropValue fromString(std::string val) { return PropValue(val); }

	};

	class Property {
	public:
		typedef std::function<bool(PropValue, UObject*)> ApplyFunc;
		typedef std::function<bool(UObject*, PropValue&)> GetFunc;
	protected:
		// The allowed type of the value
		ValueType type;
		// Function which applies the given PropValue to an object, returning success
		ApplyFunc applier;
		// Function which returns the current value of the Prop from an object
		GetFunc getter;
	public:
		Property() :
			type(ValueType::INTEGER),
			applier([](PropValue p, UObject* obj) { return false; }),
			getter([](UObject* obj, PropValue& ret) { return false; })
		{}
		Property(ValueType type, ApplyFunc applier, GetFunc getter) :
			type(type),
			applier(applier),
			getter(getter)
		{}

		ValueType getType();

		// Attempt to apply the given value of this property, returning success
		// Will fail if the value is the wrong type or the applier fails
		bool apply(PropValue value, UObject* obj);
		// Attempt to retrieve the value of this property from the given object, returning success
		bool get(UObject* obj, PropValue& ret);
	};

	namespace Items {

		enum class PropId {
			INVALID = 0,

			// Ammo
			CLIP_AMMO = 1000,
			SPARE_AMMO = 1001,
			AMMO_PER_SHOT = 1002,
			LOW_AMMO_CUTOFF = 1003,

			// Reload / Firing
			RELOAD_TIME = 2000,
			FIRE_INTERVAL = 2001,
			HOLD_TO_FIRE = 2002,

			// Damage
			DAMAGE = 3000,
			EXPLOSIVE_RADIUS = 3001
		};

		// Actual weapon properties
		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> PropMapping;
		typedef std::map<int, PropMapping> ItemsConfig;

	}

	// Tracks the original values of changed properties, so they can be reversed on disconnect
	class GameBalanceTracker {
		Items::ItemsConfig origItemProps;
	public:
		void recordItemProp(int itemId, Items::PropId propId, PropValue val);
		void revert();
	};
}

extern GameBalance::GameBalanceTracker g_gameBalanceTracker;