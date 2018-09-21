#include "Mods.h"

namespace GameBalance {
	namespace Items {

		ValueType Property::getType() {
			return type;
		}

		bool Property::apply(PropValue value, ATrDevice* dev) {
			return (value.type == type && applier(value, dev));
		}

	}
}