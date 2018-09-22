#include "Mods.h"

namespace GameBalance {
	ValueType Property::getType() {
		return type;
	}

	bool Property::apply(PropValue value, UObject* obj) {
		return (value.type == type && applier(value, obj));
	}
}