#pragma once

#define WIN32_LEAN_AND_MEAN 

#define _WIN32_WINNT 0x0603
#include <SDKDDKVer.h>

#include <Windows.h>
#include <mmsystem.h>
#include <stdlib.h>

// Uncomment for release
//#define RELEASE
// Uncomment for T:A server build
//#define SERVER

#define WIN7_COMPATIBLE

// Previously had MODVERSION as a float
// This was used to version Route files, and as a result we keep it around, but only for that purpose
// Needs to be incremented if we ever make an incompatible change to the routefile format
#define ROUTEFILE_VERSION 1.2

#define TAMODS_VERSION "1.2.3"

#define TAMODS_PROTOCOL_VERSION "0.1.0"

#ifdef WIN7_COMPATIBLE
typedef unsigned char byte;
struct IXAudio2 {
    bool meaningless;
};
struct IXAudio2MasteringVoice {
    bool meaningless;
};
struct IXAudio2SourceVoice {
    bool meaningless;
};
struct Wave {
    bool meaningless;
};
#endif