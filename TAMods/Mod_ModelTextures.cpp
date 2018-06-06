#include "Mods.h"

bool TrPlayerController_Respawn(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Logger::log("!HOOK! [In hook]");

	ATrPlayerController* that = (ATrPlayerController*)dwCallingObject;
	ATrDevice* firstWeapon = NULL;

	firstWeapon = that->GetDeviceByEquipPoint(2);
	
	if (!firstWeapon) {
		Utils::console("Failed to get weapon");
		Logger::log("!HOOK! Failed to get weapon");
		return false;
	}

	static ATrDevice_SAP20* newWeap;

	if (!newWeap) {
		newWeap = (ATrDevice_SAP20*)Utils::tr_pc->Spawn(ATrDevice_SAP20::StaticClass(), Utils::tr_pc, FName(0), Utils::tr_pc->Location, Utils::tr_pc->Rotation, NULL, 0);
	}

	Logger::log("!HOOK! Spawned newWeap");

	static USkeletalMeshComponent* curMesh;
	static USkeletalMeshComponent* newMesh;

	if (!curMesh) {
		Logger::log("!HOOK! Grabbing curMesh...");
		curMesh = (USkeletalMeshComponent*)(firstWeapon->Mesh);
		Logger::log("!HOOK! Grabbed curMesh");
	}
	if (!newMesh) {
		Logger::log("!HOOK! Grabbing newMesh...");
		newMesh = (USkeletalMeshComponent*)(newWeap->Mesh);
		Logger::log("!HOOK! Grabbed newMesh");
	}

	if (curMesh && newMesh) {
		curMesh->SetSkeletalMesh(newMesh->SkeletalMesh, 1);
		Logger::log("!HOOK! Changed mesh");
		Utils::console("Changed mesh!");
	}
	else {
		Logger::log("!HOOK! Didn't get meshes");
		Utils::console("Failed to grab meshes");
	}

	return false;
}