#include "Texture.h"

static UTexture2D *default_argb_clone = Texture::clone(UObject::FindObject<UTexture2D>("Texture2D EngineMaterials.WeightMapPlaceholderTexture"));

static void printDump(unsigned int *data, int count, const char *name)
{
	Logger::log("%s @ %p", name, data);
	for (int x = 0; x * 0x10 < count; x++)
	{
		Logger::noln("%08x:", (char *)data + x * 0x10 * 4);
		for (int i = 0; i < 0x10 && x * 0x10 + i < count; i++)
			Logger::noln(" %08x", data[x * 0x10 + i]);
		Logger::log("");
	}
}

static void printUntypedBulkData(FUntypedBulkData_Mirror &bulk, const char *name)
{
	static UTexture2D *def = UObject::FindObject<UTexture2D>("Texture2D TribesMenu.LoadingScene.LoadingScene_I2");
	int *intdata = (int *)bulk.VfTable.Dummy;

	Logger::log("%s: (VfTable:%x, BulkData:%x, AttachedAr:%x)", name, bulk.VfTable, bulk.BulkData, bulk.AttachedAr);
	Logger::log("%s NormalElements: (Flags:%d, ElementCount:%d, Offset:%x, SizeOnDisk:%d)", name, bulk.BulkDataFlags, bulk.ElementCount, bulk.BulkDataOffsetInFile, bulk.BulkDataSizeOnDisk);
	Logger::log("%s SavedElements: (Flags:%d, ElementCount:%d, Offset:%x, SizeOnDisk:%d)", name, bulk.SavedBulkDataFlags, bulk.SavedElementCount, bulk.SavedBulkDataOffsetInFile, bulk.SavedBulkDataSizeOnDisk);

	if (bulk.BulkData.Dummy)
	{
		printDump((unsigned int *)bulk.BulkData.Dummy, 10 * 0x10, "Bulk Data");
	}
	//bulk.BulkDataOffsetInFile = ((FTexture2DMipMap *)((int *)def->Mips.Data.Dummy)[0])->Data.BulkDataOffsetInFile;
	if (bulk.VfTable.Dummy && bulk.BulkDataSizeOnDisk)
	{
		return;
		unsigned char *data = ((unsigned char *)bulk.VfTable.Dummy) + bulk.BulkDataOffsetInFile;
		int linesz = 40;
		for (int y = 0; y * linesz < bulk.BulkDataSizeOnDisk; y++)
		{
			Logger::noln("Data[%08x]:", y * linesz);
			for (int i = 0; i < linesz && linesz * y + i < bulk.BulkDataSizeOnDisk; i++)
			{
				Logger::noln(" %02x", data[linesz * y + i]);
				//if ((linesz * y + i) / 2048 < 1024)
				//	data[linesz * y + i] = 0;
			}
			Logger::log("");
		}
	}
}

static void printMips(int mip_ptr, int i)
{
	FTexture2DMipMap *mip = (FTexture2DMipMap *)((int *)mip_ptr)[10 * i + i];

	Logger::log("\tMip#%d Size: (%d, %d)", i, mip->SizeX, mip->SizeY);
	printUntypedBulkData(mip->Data, "\tMip UntypedBulkData");
}

static void printResource(FTextureResource *res)
{
	FUnknownStruct1 *struct1 = (FUnknownStruct1 *)(res->unknown_struct1 - 4);
	TextureData *texdata = (TextureData *)((int ****)struct1->ptr)[-17][0][10];

	Logger::log("Resource: %x, Unknown Pointer: %x, Flags: %d", res, res->unknown_ptr1, res->flags);
	Logger::log("Unknown Structure 1 @ %p: format:%x, data_size:%x, ptr:%p", struct1, struct1->format, struct1->data_size, struct1->ptr);

	printDump((unsigned int *)struct1->ptr - 100, 12 * 0x10, "Main pointer memory");
	printDump(((unsigned int **)struct1->ptr)[-14] - 0x20, 12 * 0x10, "-14");
	printDump(((unsigned int **)struct1->ptr)[-17] - 0x20, 12 * 0x10, "-17");
	printDump(((unsigned int ***)struct1->ptr)[-17][0] - 0x20, 12 * 0x10, "-17[0]");
	printDump(((unsigned int ****)struct1->ptr)[-17][0][4] - 0x20, 12 * 0x10, "-17[0][4]");
	printDump(((unsigned int *****)struct1->ptr)[-17][0][4][0] - 0x20, 12 * 0x10, "-17[0][4][0]");
	printDump(((unsigned int ******)struct1->ptr)[-17][0][4][0][87] - 0x20, 12 * 0x10, "-17[0][4][0][87]");
	printDump(((unsigned int *******)struct1->ptr)[-17][0][4][0][87][59] - 0x20, 12 * 0x10, "LinkedList");
	printDump(((unsigned int ********)struct1->ptr)[-17][0][4][0][87][59][2] - 0x80, 24 * 0x10, "Wrapper");
	//printDump(((unsigned int ****)struct1->ptr)[-17][0][10] - 0x20, 12 * 0x10, "-17[0][10]");
	printDump((unsigned int *)struct1->ptr->pixel_data, 10 * 0x10, "Pixel Data");
}

void Texture::printTexture(UTexture *that, bool inherited)
{
	Logger::log("--------------------------------------------------------------------------------");
	if (!inherited)
		Logger::log("Texture: %s @ %p", that->GetFullName(), that);
	else
		Logger::log("Texture Base");
	Logger::log("SRGB:%d, RGBE:%d", that->SRGB, that->RGBE);
	Logger::log("IsSourceArtUncompressed: %d", that->bIsSourceArtUncompressed);
	Logger::log("Compression: (NoAlpha:%d, None:%d, NoMipmaps:%d, FullDynamicRange:%d, Defer:%d)", that->CompressionNoAlpha, that->CompressionNone, that->CompressionNoMipmaps, that->CompressionFullDynamicRange, that->DeferCompression);
	Logger::log("NeverStream:%d, DitherMipmapAlpha: %d", that->NeverStream, that->bDitherMipMapAlpha);
	Logger::log("PreserveBorder: (r:%d, g:%d, b:%d, a:%d)", that->bPreserveBorderR, that->bPreserveBorderG, that->bPreserveBorderB, that->bPreserveBorderA);
	Logger::log("NoTiling:%d, ForcePVRTC4:%d, AsyncResourceReleaseHasBeenStarted:%d, UseCinematicMipLevels:%d", that->bNoTiling, that->bForcePVRTC4, that->bAsyncResourceReleaseHasBeenStarted, that->bUseCinematicMipLevels);
	Logger::log("UnpackMin: (%.3f, %.3f, %.3f, %.3f), UnpackMax: (%.3f, %.3f, %.3f, %.3f)", that->UnpackMin[0], that->UnpackMin[1], that->UnpackMin[2], that->UnpackMin[3], that->UnpackMax[0], that->UnpackMax[1], that->UnpackMax[2], that->UnpackMax[3]);
	printUntypedBulkData(that->SourceArt, "SourceArt");
	Logger::log("SourceFilePath: %s", Utils::f2std(that->SourceFilePath).c_str());
	Logger::log("SourceFileTimestamp: %s", Utils::f2std(that->SourceFileTimestamp).c_str());
	Logger::log("Resource: %x", that->Resource);
	if (that->Resource.Dummy)
		printResource((FTextureResource *)that->Resource.Dummy);

	Logger::log("");
}

void Texture::printTexture2D(UTexture2D *that, bool inherited)
{
	Logger::log("--------------------------------------------------------------------------------");
	if (!inherited)
		Logger::log("Texture2D: %s @ %p", that->GetFullName(), that);
	else
		Logger::log("Texture2D Base");
	Logger::log("Mips: (data=%08x, num=%d, max=%d)", that->Mips.Data, that->Mips.ArrayNum, that->Mips.ArrayMax);
	if (that->Mips.ArrayNum)
		printMips(that->Mips.Data.Dummy, 0);
	Logger::log("CachedPVRTCMips: (data=%08x, num=%d, max=%d)", that->CachedPVRTCMips.Data, that->CachedPVRTCMips.ArrayNum, that->CachedPVRTCMips.ArrayMax);
	Logger::log("Size: (%d, %d)", that->SizeX, that->SizeY);
	Logger::log("OriginalSize: (%d, %d)", that->OriginalSizeX, that->OriginalSizeY);
	Logger::log("Format: %d", that->Format);
	Logger::log("Address: (%d, %d)", that->AddressX, that->AddressY);
	Logger::log("IsStreamable:%d, HasCancelationPending:%d, HasBeenLoadedFromPersistentArchive:%d, ForceMipLevelsToBeResident:%d, GlobalForceMipLevelsToBeResident:%d", that->bIsStreamable, that->bHasCancelationPending, that->bHasBeenLoadedFromPersistentArchive, that->bForceMiplevelsToBeResident, that->bGlobalForceMipLevelsToBeResident);
	Logger::log("ForceMipLevelsToBeResidentTimestamp: %f", that->ForceMipLevelsToBeResidentTimestamp);
	Logger::log("CacheName: %s", that->TextureFileCacheName.GetName());
	Logger::log("CacheGUID: %x-%x-%x-%x", that->TextureFileCacheGuid.A, that->TextureFileCacheGuid.B, that->TextureFileCacheGuid.C, that->TextureFileCacheGuid.D);
	Logger::log("RequestedMips:%d, ResidentMips:%d", that->RequestedMips, that->ResidentMips);
	Logger::log("SystemMemoryData: (data=%d, size=%d)", that->SystemMemoryData.Data, that->SystemMemoryData.Count);
	Logger::log("StreamableTexturesLink: (elm:%x, next=%x, prev=%x)", that->StreamableTexturesLink.Element, that->StreamableTexturesLink.Next, that->StreamableTexturesLink.PrevLink);
	Logger::log("StreamingIndex: %d, MipTailBaseIdx: %d", that->StreamingIndex, that->MipTailBaseIdx);
	Logger::log("ResourceMem: %x", that->ResourceMem);
	Logger::log("FirstResourceMemMip:%d, Timer: %f", that->FirstResourceMemMip, that->Timer);
	printTexture(that, true);
}

UTexture2D *Texture::clone(UTexture2D *tex, UTexture2D *out)
{
	// Temporary bug patch
	return NULL;

	if (!out)
	{
		out = (UTexture2D *)malloc(sizeof(UTexture2D));
		memcpy(out, tex, sizeof(UTexture2D));
	}
	if (tex->Resource.Dummy)
	{
		out->Resource.Dummy = (int)malloc(sizeof(FTextureResource));
		FTextureResource *nres = (FTextureResource *)out->Resource.Dummy;
		FTextureResource *res = (FTextureResource *)tex->Resource.Dummy;
		memcpy(nres, res, sizeof(FTextureResource));
		nres->self = nres;

		FUnknownStruct1 *nstruct1 = (FUnknownStruct1 *)malloc(sizeof(FUnknownStruct1));
		FUnknownStruct1 *struct1 = (FUnknownStruct1 *)(res->unknown_struct1 - 4);
		nres->unknown_struct1 = ((unsigned char *)nstruct1) + 4;
		nres->unknown_struct1_bis = nres->unknown_struct1;
		memcpy(nstruct1, struct1, sizeof(FUnknownStruct1));

		// Cloning struct3
		nstruct1->ptr = (FUnknownStruct3 *)((char *)malloc(22 * 4 + sizeof(FUnknownStruct3)) + 22 * 4);
		memcpy(((char *)nstruct1->ptr) - 22 * 4, ((char *)struct1->ptr) - 22 * 4, 22 * 4 + sizeof(FUnknownStruct3));

		// Cloning pixel data
		unsigned char *data = (unsigned char *)malloc(nstruct1->data_size);
		nstruct1->ptr->pixel_data = data;
		memcpy(data, struct1->ptr->pixel_data, struct1->data_size);

		// -14 references
		((int **)nstruct1->ptr)[-14] = ((int *)malloc(7 * 4));
		memcpy(((int **)nstruct1->ptr)[-14], ((int **)struct1->ptr)[-14], 7 * 4);
		((int **)nstruct1->ptr)[-14][7] = (int)nstruct1->ptr - 88;

		// -6 && -7 references
		// Not needed apparently, I left it here in case we need it later and for future reference
		/*
		((int *)nstruct1->ptr)[-6] = (int)nstruct1->ptr - 696;//((int *)malloc(4 * 16 * 10) + 32);
		//memcpy(((int **)nstruct1->ptr)[-6] - 32, ((int **)struct1->ptr)[-6] - 32, 4 * 16 * 10);
		((int **)nstruct1->ptr)[-7] = ((int *)malloc(4 * 16 * 8) + 32);
		memcpy(((int **)nstruct1->ptr)[-7] - 32, ((int **)struct1->ptr)[-7] - 32, 4 * 16 * 8);
		((int **)nstruct1->ptr)[-6][15] = (int)nstruct1->ptr - 88;
		((int **)nstruct1->ptr)[-7][16] = (int)nstruct1->ptr - 88;
		*/

		// -17
		
		((int **)nstruct1->ptr)[-17] = ((int *)malloc(27 * 4));
		memcpy(((int **)nstruct1->ptr)[-17], ((int **)struct1->ptr)[-17], 27 * 4);
		((int **)nstruct1->ptr)[-17][26] = (int)nstruct1->ptr - 88;
		((int **)nstruct1->ptr)[-17][20] = (int)data;
		((int ***)nstruct1->ptr)[-17][0] = ((int *)malloc(32 * 4));
		memcpy(((int ***)nstruct1->ptr)[-17][0], ((int ***)struct1->ptr)[-17][0], 32 * 4);

		((int ****)nstruct1->ptr)[-17][0][4] = ((int *)malloc(16 * 4));
		memcpy(((int ****)nstruct1->ptr)[-17][0][4], ((int ****)struct1->ptr)[-17][0][4], 16 * 4);
		((int *****)nstruct1->ptr)[-17][0][4][0] = ((int *)malloc(128 * 4 + 64 * 4)) - 64;
		memcpy(((int *****)nstruct1->ptr)[-17][0][4][0] - 64, ((int *****)struct1->ptr)[-17][0][4][0] - 64, 64 * 4 + 128 * 4);

		((int ******)nstruct1->ptr)[-17][0][4][0][87] = ((int *)malloc(128 * 4));
		memcpy(((int ******)nstruct1->ptr)[-17][0][4][0][87], ((int ******)struct1->ptr)[-17][0][4][0][87], 128 * 4);
		((int ******)nstruct1->ptr)[-17][0][4][0][88] = ((int ******)nstruct1->ptr)[-17][0][4][0][87];

		NvidiaTextureLL *orig_ll = (NvidiaTextureLL *) (((int *******)struct1->ptr)[-17][0][4][0][87][59]);
		NvidiaTextureLL *ll = (NvidiaTextureLL *)malloc(64 * 4);// 64 * 4
		((int *******)nstruct1->ptr)[-17][0][4][0][87][59] = (int *)ll;
		memcpy(ll, orig_ll, 64 * 4);
		/*ll->prev = orig_ll;
		ll->next = orig_ll->next;
		orig_ll->next->prev = ll;
		orig_ll->next = ll;*/
		
		ll->wrapper = (NvidiaTextureWrapper *)(((int *)malloc(sizeof(NvidiaTextureWrapper))));
		memcpy(((int *)ll->wrapper), ((int *)orig_ll->wrapper), sizeof(NvidiaTextureWrapper));
		ll->wrapper->node = ll;
		ll->wrapper->data = (unsigned int *)data;
		
		Logger::log("Pixel data pointer: %x", struct1->ptr->pixel_data);
		printTexture2D(tex);

		/*
		TextureData *texdata = (TextureData *)malloc(sizeof(TextureData));
		((int ****)nstruct1->ptr)[-17][0][10] = (int *)texdata;
		// This is the line that makes the thing bug
		memcpy(texdata, ((int ****)struct1->ptr)[-17][0][10], sizeof(TextureData));

		texdata->pixel_data = data;*/
	}
	return out;
}

bool Texture::update(UTexture2D *that, const char *path)
{
	// Temporary bug patch
	return false;

	if (!that->Resource.Dummy)
		return false;

	Texture::PNGImage image;
	if (!readPNG(path, &image))
		return false;

	// If the texture is not in the ARGB format (usually DXT1 or DXT5), convert it by cloning an ARGB texture
	if (that->Format != 2 /* PF_A8R8G8B8 */)
		clone(default_argb_clone, that);

	FTextureResource *res = (FTextureResource *)that->Resource.Dummy;
	FUnknownStruct1 *struct1 = (FUnknownStruct1 *)(res->unknown_struct1 - 4);
	TextureData *texdata = (TextureData *)((int ****)struct1->ptr)[-17][0][10];

	that->SizeX = that->OriginalSizeX = struct1->ptr->SizeX = image.width;
	that->SizeY = that->OriginalSizeY = struct1->ptr->SizeY = image.height;
	struct1->data_size = struct1->ptr->data_size = that->SizeX * that->SizeY * 4;

	// TODO: free memory
	struct1->ptr->pixel_data = texdata->pixel_data = (unsigned char *)image.data;
	texdata->SizeX = that->SizeX;
	texdata->SizeY = that->SizeY;
	texdata->line_size = texdata->SizeX * 4;
	texdata->data_size = struct1->data_size;
	return true;
}

UTexture2D *Texture::create(const char *path)
{
	// Temporary bug patch
	return NULL;

	UTexture2D *cloned = clone(default_argb_clone);
	if (!update(cloned, path))
	{
		// TODO: free(cloned);
		return NULL;
	}
	return cloned;
}

bool Texture::readPNG(const char *path, Texture::PNGImage *out)
{
	png_image image;

	memset(&image, 0, sizeof(image));
	image.version = PNG_IMAGE_VERSION;

	if (png_image_begin_read_from_file(&image, path))
	{
		png_bytep buffer;

		image.format = PNG_FORMAT_BGRA;
		buffer = (png_byte *)malloc(PNG_IMAGE_SIZE(image));

		if (buffer != NULL)
		{
			if (png_image_finish_read(&image, NULL, buffer, 0, NULL))
			{
				out->data = (int *)buffer;
				out->width = image.width;
				out->height = image.height;
			}
			else
			{
				Utils::console("PNG error: failed to read %s: %s\n", path, image.message);
				png_image_free(&image);
				return false;
			}
		}
		else
		{
			Utils::console("PNG error: out of memory: %lu bytes\n", (unsigned long)PNG_IMAGE_SIZE(image));
			return false;
		}
	}
	else
	{
		Utils::console("PNG error: couldn't read png %s", path);
		return false;
	}
	return true;
}
