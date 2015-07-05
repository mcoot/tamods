#pragma once
#include <xaudio2.h>
#include "Wave.h"

class SoundEffect
{
public:
	SoundEffect* Initialize(IXAudio2* masteringEngine, std::string wavFile, float* volume);
	bool audioAvailable() { return m_audioAvailable; };
	void Play(float pitch = 1.0f);
	void Stop();
	void SetVolume(float volume);
	void RefreshVolume();
protected:
	bool                    m_audioAvailable = false;
	IXAudio2SourceVoice*    m_sourceVoice;
	Wave					m_soundData;
	float*					m_configVolumeVar;
};