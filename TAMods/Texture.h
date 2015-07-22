#pragma once

#include "Utils.h"
#include "Logger.h"
#include "SdkHeaders.h"
#include "libpng\png.h"

namespace Texture
{
	struct PNGImage
	{
		int width;
		int height;
		int *data;
	};

	// Print the structure memory
	void printTexture(UTexture *that, bool inherited = false);
	void printTexture2D(UTexture2D *that, bool inherited = false);

	// Clone a texture
	// If out is non NULL, clones tex into out
	// Otherwise just create a new clone
	UTexture2D *clone(UTexture2D *tex, UTexture2D *out = NULL);

	// Modify a texture
	bool update(UTexture2D *tex, const char *path);

	// Create a new texture by cloning and replacing
	UTexture2D *create(const char *path);

	bool readPNG(const char *path, PNGImage *image);
}
