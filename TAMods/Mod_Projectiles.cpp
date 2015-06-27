#include "Mods.h"

static CustomProjectile *fired_proj = NULL;

bool TrDev_WeaponFiring(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice *that = (ATrDevice *)dwCallingObject;

	if (that) {
		if (that->ShouldRefire()) {
			// Retrieve default object for the projectile that will be fired
			auto it = g_config.wep_id_to_custom_proj.find(that->DBWeaponId);
			if (it == g_config.wep_id_to_custom_proj.end() || !it->second)
				return false;
			fired_proj = it->second;
			fired_proj->default_proj->ProjFlightTemplate = fired_proj->custom_ps;
		}
	}
	return false;
}

bool TrDev_WeaponFiring_POST(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (fired_proj)
	{
		fired_proj->default_proj->ProjFlightTemplate = fired_proj->default_ps;
		fired_proj = NULL;
	}
	return false;
}
