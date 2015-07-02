#include "SoundEffect.h"

void SoundEffect::Initialize(IXAudio2* masteringEngine, std::string wavFile, float volume)
{
	const char *profile = getenv("USERPROFILE");
	std::string filePath;

	if (profile)
		filePath = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\" + wavFile;
	else
		filePath = std::string("C:\\") + wavFile;


	// load wave file
	if (!m_soundData.load(filePath.c_str()) || masteringEngine == nullptr)
	{
		m_audioAvailable = false;
		return;
	}

	// create the source voice, based on loaded wave format
	HRESULT hr = masteringEngine->CreateSourceVoice(&m_sourceVoice, m_soundData.wf());
	if (FAILED(hr))
	{
		m_audioAvailable = false;
		return;
	}
	// set volume
	m_sourceVoice->SetVolume(volume);

	m_audioAvailable = true;
}

void SoundEffect::Play(float pitch)
{
	if (!m_audioAvailable)
	{
		// Audio is not available so just return
		return;
	}

	m_sourceVoice->Stop();
	m_sourceVoice->FlushSourceBuffers();
	m_sourceVoice->SetFrequencyRatio(pitch);
	m_sourceVoice->SubmitSourceBuffer(m_soundData.xaBuffer());
	m_sourceVoice->Start();
}

void SoundEffect::SetVolume(float Volume)
{
	if (m_audioAvailable)
		m_sourceVoice->SetVolume(Volume);
}