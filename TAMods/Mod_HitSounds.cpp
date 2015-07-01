#include "Mods.h"

IXAudio2* g_engine;
IXAudio2MasteringVoice* g_master;

class SoundCue
{
	IXAudio2SourceVoice* pVoice;
	Wave buffer;
public:
	int create(std::string wavFile, float fVolume = 1.0f);
	bool destroy();
	int play(float pitch = 1.0f);
	int setVolume(float fVolume);
};

int SoundCue::create(std::string wavFile, float fVolume)
{
	const char *profile = getenv("USERPROFILE");
	std::string filePath;

	if (profile)
		filePath = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\" + wavFile;
	else
		filePath = std::string("C:\\") + wavFile;


	//load a wave file
	if (!buffer.load(filePath.c_str()))
		return -1;
	//create the source voice, based on loaded wave format
	if (FAILED(g_engine->CreateSourceVoice(&pVoice, buffer.wf())))
		return -2;
	//start consuming audio in the source voice
	if (FAILED(pVoice->Start()))
		return -3;
	//set volume
	if (FAILED(pVoice->SetVolume(fVolume)))
		return -4;

	return 1;
}

bool SoundCue::destroy()
{

}

int SoundCue::play(float pitch)
{
	if (FAILED(pVoice->SetFrequencyRatio(pitch)))
		return -1;
	if (FAILED(pVoice->SubmitSourceBuffer(buffer.xaBuffer())))
		return -2;

	return 1;
}

int SoundCue::setVolume(float fVolume)
{
	if (FAILED(pVoice->SetVolume(fVolume)))
		return -1;
	else
		return 1;
}

SoundCue hitSound, bluePlate, airMail;

int XAudio2Init()
{
	//must call this for COM
	if (FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
		return -1;

	//create the engine
	if (FAILED(XAudio2Create(&g_engine)))
	{
		CoUninitialize();
		return -2;
	}

	//create the mastering voice
	if (FAILED(g_engine->CreateMasteringVoice(&g_master)))
	{
		g_engine->Release();
		CoUninitialize();
		return -3;
	}

	hitSound.create("hit.wav", g_config.volumeHitSound);
	bluePlate.create("blueplate.wav", g_config.volumeBluePlate);
	airMail.create("airmail.wav", g_config.volumeAirMail);

	return 1;
}

void playHitSound(clock_t *t, bool bShieldDamage, int *dmg)
{
	/*
		TODO:
		- somehow count overall shotgun damage and splash on multiple enemies
		- play sounds async or use more voices
	*/
	//Utils::console("%d Hit for %d dmg", *t, *dmg);

	if (g_config.hitSoundMode < 1
		|| !dmg 
		|| *dmg <= 0
		|| bShieldDamage
		|| (double)(*t - g_config.lastDamageNumberShowEventTime) < (CLOCKS_PER_SEC*0.05))
		return;

	float pitch = 1.0f;

	if (g_config.hitSoundMode > 1)
	{
		// high damage --> low pitch
		if (g_config.hitSoundMode == 2)
			pitch = (float)g_config.hitSoundDamageRef / (float)*dmg;
		// high damage --> high pitch
		else if (g_config.hitSoundMode >= 3)
			pitch = (float)*dmg / (float)g_config.hitSoundDamageRef;

		if (pitch > g_config.hitSoundPitchMax)
			pitch = g_config.hitSoundPitchMax;
		else if (pitch < g_config.hitSoundPitchMin)
			pitch = g_config.hitSoundPitchMin;
	}

	hitSound.play(pitch);
}

bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.customBluePlateSound)
	{
		bluePlate.play();
		return true;
	}
	return false;
}

bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.customAirMailSound)
	{
		airMail.play();
		return true;
	}
	return false;
}