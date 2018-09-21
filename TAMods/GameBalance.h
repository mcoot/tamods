#pragma once

#include "buildconfig.h"

#include <functional>
#include <map>

#include "SdkHeaders.h"

namespace GameBalance {

	namespace Items {

		enum class ValueType {
			BOOLEAN,
			INTEGER,
			FLOAT,
			STRING
		};

		// Tagged union for possible types of an item property
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
			typedef std::function<bool(PropValue, ATrDevice*)> ApplyFunc;
		protected:
			// The allowed type of the value
			ValueType type;
			// Function which applies the given PropValue to a device, returning success
			ApplyFunc applier;
		public:
			Property() :
				type(ValueType::INTEGER),
				applier([](PropValue p, ATrDevice* dev) { return false; })
			{}
			Property(ValueType type, ApplyFunc applier) :
				type(type),
				applier(applier) {}

			ValueType getType();

			// Attempt to apply the given value of this property, returning success
			// Will fail if the value is the wrong type or the applier fails
			bool apply(PropValue value, ATrDevice* dev);
		};

		enum class PropId {
			INVALID = 0,
			CLIP_AMMO = 1000,
			SPARE_AMMO = 1001,
			AMMO_PER_SHOT = 1002,
			LOW_AMMO_CUTOFF = 1003
		};

		// Actual weapon properties
		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> ItemConfig;
		typedef std::map<int, ItemConfig> PropsConfig;

	}

}