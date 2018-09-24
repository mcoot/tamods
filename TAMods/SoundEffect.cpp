#include "SoundEffect.h"
#include "Utils.h"

SoundEffect* SoundEffect::Initialize(IXAudio2* masteringEngine, std::string* filePath, float* volume)
{
#ifndef WIN7_COMPATIBLE
	m_masteringEngine = masteringEngine;
	m_filePath = filePath;
	m_configVolumeVar = volume;
	m_basePath = Utils::getConfigDir();
	m_audioAvailable = CreateVoice();
#endif
	return this;
}

void SoundEffect::Reload()
{
#ifndef WIN7_COMPATIBLE
	if (m_audioAvailable)
		m_sourceVoice->DestroyVoice();

	m_audioAvailable = CreateVoice();
#endif
}

bool SoundEffect::CreateVoice()
{
#ifndef WIN7_COMPATIBLE
	std::string fullPath;

	if (!m_filePath->empty())
		fullPath = m_basePath + *m_filePath;

	// load wave file
	if (!m_soundData.load(fullPath.c_str()) || m_masteringEngine == nullptr)
		return false;

	// create the source voice, based on loaded wave format
	HRESULT hr = m_masteringEngine->CreateSourceVoice(&m_sourceVoice, m_soundData.wf());
	if (FAILED(hr))
		return false;

	// set volume
	if (m_configVolumeVar)
		m_sourceVoice->SetVolume(*m_configVolumeVar);
#endif
	return true;
}

void SoundEffect::Play(float pitch)
{
#ifndef WIN7_COMPATIBLE
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
#endif
}

void SoundEffect::Stop()
{
#ifndef WIN7_COMPATIBLE
	if (!m_audioAvailable)
	{
		// Audio is not available so just return
		return;
	}
	m_sourceVoice->Stop();
	m_sourceVoice->FlushSourceBuffers();
#endif
}

void SoundEffect::SetVolume(float volume)
{
#ifndef WIN7_COMPATIBLE
	if (m_audioAvailable)
		m_sourceVoice->SetVolume(volume);
#endif
}

void SoundEffect::RefreshVolume()
{
#ifndef WIN7_COMPATIBLE
	if (m_audioAvailable && m_configVolumeVar)
		m_sourceVoice->SetVolume(*m_configVolumeVar);
#endif
}

bool SoundEffect::CurrentlyPlaying()
{
#ifndef WIN7_COMPATIBLE
	XAUDIO2_VOICE_STATE state;
	m_sourceVoice->GetState(&state);

	if (m_audioAvailable && state.BuffersQueued > 0)
		return true;
	else
		return false;
#endif
}