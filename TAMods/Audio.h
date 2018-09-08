#pragma once
#include <xaudio2.h>

// Using XAudio 2.7 requires the DirectX SDK
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\comdecl.h>
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\xaudio2.h>
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\xaudio2fx.h>
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\xapofx.h>
//#pragma warning(push)
//#pragma warning( disable : 4005 )
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\x3daudio.h>
//#pragma warning(pop)
//#pragma comment(lib,"x3daudio.lib")
//#pragma comment(lib,"xapofx.lib")

class Audio
{
public:
	void Initialize();
	bool audioAvailable() { return m_audioAvailable; }
	void SuspendAudio();
	void ResumeAudio();

public:
	//IXAudio2* MusicEngine;
	IXAudio2* SoundEffectEngine;

protected:
	bool m_audioAvailable = false;
	//IXAudio2MasteringVoice* m_musicMasteringVoice;
	IXAudio2MasteringVoice* m_soundEffectMasteringVoice;
};