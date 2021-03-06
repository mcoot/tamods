#pragma once

#include "buildconfig.h"

#include <string>
#ifndef WIN7_COMPATIBLE
#include <xaudio2.h>
#endif
#include <algorithm> // std::replace
#ifndef WIN7_COMPATIBLE
#include "Wave.h"
#endif

class SoundEffect
{
public:
    SoundEffect* Initialize(IXAudio2* masteringEngine, std::string* filePath, float* volume);
    void Reload();
    bool audioAvailable() { return m_audioAvailable; };
    bool CurrentlyPlaying();
    void Play(float pitch = 1.0f);
    void Stop();
    void SetVolume(float volume);
    void RefreshVolume();

public:
    std::string  m_basePath;
    std::string* m_filePath;

private:
    bool CreateVoice();

protected:
    bool                 m_audioAvailable = false;
    IXAudio2*            m_masteringEngine;
    IXAudio2SourceVoice* m_sourceVoice;
    Wave                 m_soundData;
    float*               m_configVolumeVar;
};