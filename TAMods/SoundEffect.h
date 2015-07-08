#pragma once
#include <xaudio2.h>
#include "Wave.h"

class SoundEffect
{
public:
	SoundEffect* Initialize(IXAudio2* masteringEngine, std::string wavFile, float* volume);
	void Reload();
	bool audioAvailable() { return m_audioAvailable; };
	void Play(float pitch = 1.0f);
	void Stop();
	void SetVolume(float volume);
	void RefreshVolume();

public:
	std::string m_filePath;

private:
	bool CreateVoice();

protected:
	bool                    m_audioAvailable = false;
	IXAudio2*				m_masteringEngine;
	IXAudio2SourceVoice*    m_sourceVoice;
	Wave					m_soundData;
	float*					m_configVolumeVar;
};