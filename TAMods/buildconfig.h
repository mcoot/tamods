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

#define MODVERSION 1.1

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