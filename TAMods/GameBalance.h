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

	std::string getValueTypeName(ValueType t);

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
			CAN_ZOOM = 2003,
			RELOAD_SINGLE = 2004,
			RELOAD_APPLICATION_PROPORTION = 2005,

			// Damage / Impact
			DAMAGE = 3000,
			EXPLOSIVE_RADIUS = 3001,
			DIRECT_HIT_MULTIPLIER = 3002,
			IMPACT_MOMENTUM = 3003,
			SELF_IMPACT_MOMENTUM_MULTIPLIER = 3004,
			SELF_IMPACT_EXTRA_Z_MOMENTUM = 3005,
			ENERGY_DRAIN = 3006,
			MAX_DAMAGE_RANGE_PROPORTION = 3007,
			MIN_DAMAGE_RANGE_PROPORTION = 3008,
			MIN_DAMAGE_PROPORTION = 3009,
			BULLET_DAMAGE_RANGE = 3010,
			DAMAGE_AGAINST_ARMOR_MULTIPLIER = 3011,
			DAMAGE_AGAINST_GENERATOR_MULTIPLIER = 3012,
			DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER = 3013,
			DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER = 3014,
			DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER = 3015,
			DAMAGE_AGAINST_BEOWULF_MULTIPLIER = 3016,
			DAMAGE_AGAINST_SHRIKE_MULTIPLIER = 3017,
			DOES_GIB_ON_KILL = 3018,
			GIB_IMPULSE_RADIUS = 3019,
			GIB_STRENGTH = 3020,
			DOES_IMPULSE_FLAG = 3021,

			// Projectile / Tracer
			PROJECTILE_SPEED = 4000,
			PROJECTILE_MAX_SPEED = 4001,
			COLLISION_SIZE = 4002,
			PROJECTILE_INHERITENCE = 4003,
			PROJECTILE_LIFESPAN = 4004,
			PROJECTILE_GRAVITY = 4005,
			PROJECTILE_TERMINAL_VELOCITY = 4006,
			PROJECTILE_BOUNCE_DAMPING = 4007,
			PROJECTILE_MESH_SCALE = 4008,
			PROJECTILE_LIGHT_RADIUS = 4009,
			HITSCAN_RANGE = 4010,

			// Accuracy
			ACCURACY = 5000,
			ACCURACY_LOSS_ON_SHOT = 5001,
			ACCURACY_LOSS_ON_JUMP = 5002,
			ACCURACY_LOSS_ON_WEAPON_SWITCH = 5003,
			ACCURACY_LOSS_MAX = 5004,
			ACCURACY_CORRECTION_RATE = 5005,

		};

		// Actual weapon properties
		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> PropMapping;
		typedef std::map<int, PropMapping> ItemsConfig;

	}

	namespace Classes {
		enum class PropId {
			INVALID = 0,

			// Base Stats
			HEALTH_POOL = 1000,
			ENERGY_POOL = 1001,
			ENERGY_RECHARGE_RATE = 1002,
			JET_ENERGY_COST = 1003,
			REGEN_TIME = 1004,
			REGEN_RATE = 1005,
			LOW_HEALTH_THRESHOLD = 1006,

			// Movement / Skiing
			MASS = 2000,
			GROUND_SPEED = 2001,
			MAX_SKIING_SPEED = 2002,
			MAX_SKI_CONTROL = 2003,
			SKI_CONTROL_PEAK_SPEED = 2004,
			SKI_CONTROL_VARIANCE = 2005,
			SKI_SLOPE_GRAVITY = 2006,
			VEHICLE_SPEED_INHERITENCE = 2007,
			MOMENTUM_DAMPENING_ENABLED = 2008,
			MOMENTUM_DAMPENING_THRESHOLD = 2009,
			MOMENTUM_DAMPENING_PROPORTION = 2010,

			// Jetting / Air Control
			MAX_JETTING_SPEED = 3000,
			AIR_CONTROL_BASE = 3001,
			AIR_CONTROL_MAX = 3002,
			AIR_CONTROL_MIN = 3003,
			AIR_CONTROL_REDUCTION_RANGE_MAX = 3004,
			AIR_CONTROL_REDUCTION_RANGE_MIN = 3005,
			JET_ACCELERATION = 3006,
			INITIAL_JET_ACCELERATION = 3007,
			INITIAL_JET_LENGTH = 3008,
			AIR_SPEED = 3009,

			// Collision
			COLLISION_CYLINDER_RADIUS = 4000,
			COLLISION_CYLINDER_HEIGHT = 4001,

		};

		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> PropMapping;
		typedef std::map<int, PropMapping> ClassesConfig;

	}

	namespace Vehicles {
		enum class PropId {
			INVALID = 0,

			// Base Stats
			HEALTH_POOL = 1000,
			ENERGY_POOL = 1001,
			ENERGY_RECHARGE_RATE = 1002,
			IS_ARMORED = 1003,
			IS_HOMING_TARGET = 1004,
			CAN_CARRY_FLAG_AS_PILOT = 1005,
			CAN_CARRY_FLAG_AS_PASSENGER = 1006,

			// Movement
			MAX_SPEED = 2000,
			MAX_DIVING_SPEED_MULTIPLIER = 2001,
			BOOST_MULTIPLIER = 2002,
			BOOST_ENERGY_COST = 2003,
			BOOST_MIN_USABLE_PROPORTION = 2004,
			MAX_PLAYER_EXIT_SPEED = 2005,
			GRAVITY_SCALE = 2006,

			// Self-Damage
			MAX_CRASH_DAMAGE = 3000,
			MIN_CRASH_DAMAGE = 3001,
			MAX_CRASH_DAMAGE_SPEED = 3002,
			MIN_CRASH_DAMAGE_SPEED = 3003,

			// Ramming
			RAM_MIN_SPEED = 4000,
			RAM_MAX_DAMAGE = 4001,
			RAM_MIN_DAMAGE = 4002,
			RAM_MAX_DAMAGE_SPEED = 4003,
			RAM_MIN_DAMAGE_SPEED = 4004,
			RAM_PLAYER_PUSH_SPEED = 4005,
			RAM_FLAG_PUSH_SPEED = 4006,

		};

		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> PropMapping;
		typedef std::map<int, PropMapping> VehiclesConfig;
	}

	namespace VehicleWeapons {
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
			CAN_ZOOM = 2003,
			RELOAD_SINGLE = 2004,
			RELOAD_APPLICATION_PROPORTION = 2005,
			BURST_SHOT_COUNT = 2006,

			// Damage / Impact
			DAMAGE = 3000,
			EXPLOSIVE_RADIUS = 3001,
			DIRECT_HIT_MULTIPLIER = 3002,
			MOMENTUM_TRANSFER = 3003,

			// Projectile / Tracer
			PROJECTILE_SPEED = 4000,
			PROJECTILE_MAX_SPEED = 4001,
			COLLISION_SIZE = 4002,
			PROJECTILE_INHERITENCE = 4003,
			PROJECTILE_LIFESPAN = 4004,
			PROJECTILE_GRAVITY = 4005,
			PROJECTILE_TERMINAL_VELOCITY = 4006,
			PROJECTILE_MESH_SCALE = 4007,
			PROJECTILE_LIGHT_SCALE = 4008,

			// Accuracy
			ACCURACY = 5000,
			ACCURACY_LOSS_ON_SHOT = 5001,
			ACCURACY_LOSS_ON_JUMP = 5002,
			ACCURACY_LOSS_ON_WEAPON_SWITCH = 5003,
			ACCURACY_LOSS_MAX = 5004,
			ACCURACY_CORRECTION_RATE = 5005,
		};

		extern std::map<PropId, Property> properties;

		typedef std::map<PropId, PropValue> PropMapping;
		typedef std::map<int, PropMapping> VehicleWeaponsConfig;
	}

	// Tracks the original values of changed properties, so they can be reversed on disconnect
	class GameBalanceTracker {
	public:
		Items::ItemsConfig origItemProps;
		Classes::ClassesConfig origClassProps;
		Vehicles::VehiclesConfig origVehicleProps;
		VehicleWeapons::VehicleWeaponsConfig origVehicleWeaponProps;
	public:
		void revert();
	};
}

extern GameBalance::GameBalanceTracker g_gameBalanceTracker;