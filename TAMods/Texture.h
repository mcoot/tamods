#pragma once

#include "Utils.h"
#include "Logger.h"
#include "SdkHeaders.h"

namespace Texture
{
	// Print the structure memory
	void printTexture(UTexture *that, bool inherited = false);
	void printTexture2D(UTexture2D *that, bool inherited = false);

	// Clone a texture
	UTexture2D *clone(UTexture2D *tex);

	// Modify a texture
	bool load(UTexture2D *tex);
}

struct TextureData
{
	int SizeX;
	int SizeY;
	int zero;
	unsigned char *pixel_data;
	int line_size;
	int data_size;
	unsigned int *ptr1;
	unsigned int *ptr2;
};

struct FUnknownStruct3
{
	unsigned char *common_ptr1;
	unsigned char *unknown_ptr1;
	unsigned char *common_ptr3;
	unsigned int unknown_int1; // 0x03
	unsigned int unknown_int2; // 0x0c000000
	unsigned int unknown_int3; // 0x02
	unsigned int zeroes[2];
	int SizeX;
	int SizeY;
	unsigned int zeroes2[24];
	int format; // Sometimes 0
	int data_size;
	unsigned char *pixel_data;
	unsigned char unknown_data[172];
};

struct FUnknownStruct1
{
	FUnknownStruct3 *ptr;
	int format;
	unsigned int data_size;
	unsigned char zeroes[12];
	int *common_ptr;
	int flags;
};

struct FUnknownStruct2
{
	unsigned char data[0x30];
};

struct FTextureResource
{
	unsigned char *unknown_ptr1; // Common to all structs
	FTextureResource *self; // Pointer to this struct
	int *prev_self; // Pointer to the self field of the previous FTextureResource
	int *next_prev; // Pointer to the prev field of the next FTextureResource
	int flags; // 1 or something that looks like an address
	unsigned char *unknown_struct1; // FUnknownStruct1 + 4 (wtf)
	unsigned char *unknown_struct2;
	int unknown_int1; // 0xe0000000
	int unknown_int2; // 0xc7efffff
	int unknown_int3; // 0x3f800000
	unsigned char unknown_data1[0x1C]; // 00
	UTexture2D *texture; // Texture containing this Resource
	unsigned char unknown_data2[0xC0];
	unsigned char *unknown_struct1_bis; // Same as unknown_struct1
	unsigned char unknown_data3[0x34];
};
