#pragma once

#include <string>
#include "SdkHeaders.h"

namespace ParticleModuleHelper
{
	// Copy every FRawDistributionVector and FRawDistributionFloat based on the module class
	void copyModuleTArrays(UParticleModule *&out, UParticleModule *&in);
	// Copy a module based on the class, copies distribution vectors too
	void copyModule(UParticleModule *&out, UParticleModule *&in);
}
