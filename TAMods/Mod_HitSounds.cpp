#include "Mods.h"

clock_t lastHitSound = 0;
int totalDamage;

SoundEffect g_hitSound;
SoundEffect g_bluePlate;
SoundEffect g_airMail;

void AudioInitialize()
{
	g_audioEngine.Initialize();
	if (g_audioEngine.audioAvailable())
	{
		g_hitSound.Initialize(g_audioEngine.SoundEffectEngine, std::string("hit.wav"), g_config.volumeHitSound);
		g_bluePlate.Initialize(g_audioEngine.SoundEffectEngine, std::string("blueplate.wav"), g_config.volumeBluePlate);
		g_airMail.Initialize(g_audioEngine.SoundEffectEngine, std::string("airmail.wav"), g_config.volumeAirMail);
	}
	else
		Utils::console("Error initializing audio engine");
}

void playHitSound(bool bShieldDamage, int *dmg)
{
	//Utils::console("%d Hit for %d dmg", *t, *dmg);

	if (!g_audioEngine.audioAvailable()
		|| !g_hitSound.audioAvailable()
		|| g_config.hitSoundMode < 1
		|| !dmg 
		|| *dmg <= 0
		|| bShieldDamage)
		return;

	if ((double)(clock() - lastHitSound) < (CLOCKS_PER_SEC*0.05))
		totalDamage += *dmg;
	else
		totalDamage = *dmg;

	lastHitSound = clock();

	float pitch = 1.0f;

	if (g_config.hitSoundMode > 1)
	{
		// high damage --> low pitch
		if (g_config.hitSoundMode == 2)
			pitch = (float)g_config.hitSoundDamageRef / (float)totalDamage;
		// high damage --> high pitch
		else if (g_config.hitSoundMode >= 3)
			pitch = (float)totalDamage / (float)g_config.hitSoundDamageRef;

		if (pitch > g_config.hitSoundPitchMax)
			pitch = g_config.hitSoundPitchMax;
		else if (pitch < g_config.hitSoundPitchMin)
			pitch = g_config.hitSoundPitchMin;
	}

	g_hitSound.Play(pitch);
}

bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.customBluePlateSound && g_audioEngine.audioAvailable() && g_bluePlate.audioAvailable())
	{
		g_bluePlate.Play();
		return true;
	}
	return false;
}

bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.customAirMailSound && g_audioEngine.audioAvailable() && g_airMail.audioAvailable())
	{
		g_airMail.Play();
		return true;
	}
	return false;
}