#include "Audio.h"

Audio g_audioEngine;

void Audio::Initialize()
{
	UINT32 flags = 0;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	XAudio2Create(&MusicEngine, flags);

	HRESULT hr = MusicEngine->CreateMasteringVoice(&m_musicMasteringVoice);
	if (FAILED(hr))
	{
		// Unable to create an audio device
		m_audioAvailable = false;
		CoUninitialize();
		return;
	}

	XAudio2Create(&SoundEffectEngine, flags);

	SoundEffectEngine->CreateMasteringVoice(&m_soundEffectMasteringVoice);

	m_audioAvailable = true;
}

void Audio::SuspendAudio()
{
	if (m_audioAvailable)
	{
		MusicEngine->StopEngine();
		SoundEffectEngine->StopEngine();
	}
}

void Audio::ResumeAudio()
{
	if (m_audioAvailable)
	{
		MusicEngine->StartEngine();
		SoundEffectEngine->StartEngine();
	}
}