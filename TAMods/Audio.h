#pragma once
#include <xaudio2.h>

class Audio
{
public:
	void Initialize();
	bool audioAvailable() { return m_audioAvailable; }
	void SuspendAudio();
	void ResumeAudio();

public:
	IXAudio2* MusicEngine;
	IXAudio2* SoundEffectEngine;

protected:
	bool m_audioAvailable = false;
	IXAudio2MasteringVoice* m_musicMasteringVoice;
	IXAudio2MasteringVoice* m_soundEffectMasteringVoice;
};