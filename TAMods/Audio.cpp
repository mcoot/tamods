#include "Audio.h"

void Audio::Initialize()
{
#ifndef WIN7_COMPATIBLE
    UINT32 flags = 0;

    CoInitializeEx(NULL, COINIT_MULTITHREADED);

    XAudio2Create(&SoundEffectEngine, flags);

    HRESULT hr = SoundEffectEngine->CreateMasteringVoice(&m_soundEffectMasteringVoice);
    if (FAILED(hr))
    {
        // Unable to create an audio device
        m_audioAvailable = false;
        CoUninitialize();
        return;
    }

    //XAudio2Create(&MusicEngine, flags);

    //MusicEngine->CreateMasteringVoice(&m_musicMasteringVoice);

    m_audioAvailable = true;
#endif
}

void Audio::SuspendAudio()
{
#ifndef WIN7_COMPATIBLE
    if (m_audioAvailable)
    {
        //MusicEngine->StopEngine();
        SoundEffectEngine->StopEngine();
    }
#endif
}

void Audio::ResumeAudio()
{
#ifndef WIN7_COMPATIBLE
    if (m_audioAvailable)
    {
        //MusicEngine->StartEngine();
        SoundEffectEngine->StartEngine();
    }
#endif
}