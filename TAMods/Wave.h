//wave.h
//by Jay Tennant 3/4/12
//Wave helper class, to load simple wave files
//win32developer.com
//this code provided free, as in public domain; score!

#ifndef WAVE_H
#define WAVE_H

#include "buildconfig.h"

#include <xaudio2.h>
#include <fstream>

class Wave
{
private:
    WAVEFORMATEX m_wf;
    XAUDIO2_BUFFER m_xa;
    BYTE* m_waveData;
public:
    Wave(const char* szFile = NULL) : m_waveData(NULL) {
        ZeroMemory(&m_wf, sizeof(m_wf));
        ZeroMemory(&m_xa, sizeof(m_xa));

        load(szFile);
    }
    Wave(const Wave& c) : m_waveData(NULL) {
        m_wf = c.m_wf;
        m_xa = c.m_xa;
        if (c.m_waveData)
        {
            m_waveData = new BYTE[m_xa.AudioBytes];
            memcpy(m_waveData, c.m_waveData, m_xa.AudioBytes);
            m_xa.pAudioData = m_waveData;
        }
    }
    ~Wave() {
        if (m_waveData)
            delete[] m_waveData;
        m_waveData = NULL;
    }

    const XAUDIO2_BUFFER* xaBuffer() const { return &m_xa; }
    const WAVEFORMATEX* wf() const { return &m_wf; }
    bool load(const char* szFile) {
        if (szFile == NULL)
            return false;

        std::ifstream inFile(szFile, std::ios::binary | std::ios::in);
        if (inFile.bad())
            return false;

        DWORD dwChunkId = 0, dwFileSize = 0, dwChunkSize = 0, dwExtra = 0;

        //look for 'RIFF' chunk identifier
        inFile.seekg(0, std::ios::beg);
        inFile.read(reinterpret_cast<char*>(&dwChunkId), sizeof(dwChunkId));
        if (dwChunkId != 'FFIR')
        {
            inFile.close();
            return false;
        }
        inFile.seekg(4, std::ios::beg); //get file size
        inFile.read(reinterpret_cast<char*>(&dwFileSize), sizeof(dwFileSize));
        if (dwFileSize <= 16)
        {
            inFile.close();
            return false;
        }
        inFile.seekg(8, std::ios::beg); //get file format
        inFile.read(reinterpret_cast<char*>(&dwExtra), sizeof(dwExtra));
        if (dwExtra != 'EVAW')
        {
            inFile.close();
            return false;
        }

        //look for 'fmt ' chunk id
        bool bFilledFormat = false;
        for (unsigned int i = 12; i < dwFileSize;)
        {
            inFile.seekg(i, std::ios::beg);
            inFile.read(reinterpret_cast<char*>(&dwChunkId), sizeof(dwChunkId));
            inFile.seekg(i + 4, std::ios::beg);
            inFile.read(reinterpret_cast<char*>(&dwChunkSize), sizeof(dwChunkSize));
            if (dwChunkId == ' tmf')
            {
                //I don't know what I was thinking with the following code, but I
                //never did solve it back 6 months, and didn't touch it since; oh well... :S

                //switch(dwChunkSize)
                //{
                //case sizeof(WAVEFORMATEX):
                //    {
                //        inFile.seekg(i + 8, std::ios::beg);
                //        inFile.read(reinterpret_cast<char*>(&m_wf), sizeof(m_wf));
                //    }
                //    break;
                //case sizeof(WAVEFORMATEXTENSIBLE):
                //    {
                //        WAVEFORMATEXTENSIBLE wfe;
                //        inFile.seekg(i + 8, std::ios::beg);
                //        inFile.read(reinterpret_cast<char*>(&wfe), sizeof(wfe));
                //        m_wf = wfe.Format;
                //    }
                //    break;
                //default:
                //    inFile.close();
                //    return;
                //}
                inFile.seekg(i + 8, std::ios::beg);
                inFile.read(reinterpret_cast<char*>(&m_wf), sizeof(m_wf));
                bFilledFormat = true;
                break;
            }
            dwChunkSize += 8; //add offsets of the chunk id, and chunk size data entries
            dwChunkSize += 1;
            dwChunkSize &= 0xfffffffe; //guarantees WORD padding alignment
            i += dwChunkSize;
        }
        if (!bFilledFormat)
        {
            inFile.close();
            return false;
        }

        //look for 'data' chunk id
        bool bFilledData = false;
        for (unsigned int i = 12; i < dwFileSize;)
        {
            inFile.seekg(i, std::ios::beg);
            inFile.read(reinterpret_cast<char*>(&dwChunkId), sizeof(dwChunkId));
            inFile.seekg(i + 4, std::ios::beg);
            inFile.read(reinterpret_cast<char*>(&dwChunkSize), sizeof(dwChunkSize));
            if (dwChunkId == 'atad')
            {
                m_waveData = new BYTE[dwChunkSize];
                inFile.seekg(i + 8, std::ios::beg);
                inFile.read(reinterpret_cast<char*>(m_waveData), dwChunkSize);
                m_xa.AudioBytes = dwChunkSize;
                m_xa.pAudioData = m_waveData;
                m_xa.PlayBegin = 0;
                m_xa.PlayLength = 0;
                bFilledData = true;
                break;
            }
            dwChunkSize += 8; //add offsets of the chunk id, and chunk size data entries
            dwChunkSize += 1;
            dwChunkSize &= 0xfffffffe; //guarantees WORD padding alignment
            i += dwChunkSize;
        }
        if (!bFilledData)
        {
            inFile.close();
            return false;
        }

        inFile.close();
        return true;
    }
};

#endif