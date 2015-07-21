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
}
