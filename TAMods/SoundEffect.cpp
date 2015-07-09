#include "SoundEffect.h"

SoundEffect* SoundEffect::Initialize(IXAudio2* masteringEngine, std::string wavFile, float* volume)
{
	const char *profile = getenv("USERPROFILE");

	m_masteringEngine = masteringEngine;
	m_configVolumeVar = volume;

	if (profile)
		m_filePath = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\sounds\\" + wavFile;
	else
		m_filePath = std::string("C:\\") + wavFile;


	m_audioAvailable = CreateVoice();
	return this;
}

void SoundEffect::Reload()
{
	if (m_audioAvailable)
		m_sourceVoice->DestroyVoice();

	m_audioAvailable = CreateVoice();
}

bool SoundEffect::CreateVoice()
{
	// load wave file
	if (!m_soundData.load(m_filePath.c_str()) || m_masteringEngine == nullptr)
		return false;

	// create the source voice, based on loaded wave format
	HRESULT hr = m_masteringEngine->CreateSourceVoice(&m_sourceVoice, m_soundData.wf());
	if (FAILED(hr))
		return false;

	// set volume
	if (m_configVolumeVar)
		m_sourceVoice->SetVolume(*m_configVolumeVar);

	return true;
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

void SoundEffect::SetVolume(float volume)
{
	if (m_audioAvailable)
		m_sourceVoice->SetVolume(volume);
}

void SoundEffect::RefreshVolume()
{
	if (m_audioAvailable && m_configVolumeVar)
		m_sourceVoice->SetVolume(*m_configVolumeVar);
}