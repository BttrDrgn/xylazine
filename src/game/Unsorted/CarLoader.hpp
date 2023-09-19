#pragma once

#include "Platform/Platform.hpp"
#include "types.hpp"

class CarLoader
{
public:
	/* 0x000 */ void* pCallback;
	/* 0x004 */ std::uint32_t Param;
	/* 0x008 */ eLoadingMode LoadingMode;
	/* 0x00c */ int InFrontEndFlag;
	/* 0x010 */ int TwoPlayerFlag;
	/* 0x014 */ int LoadingInProgress;
	/* 0x018 */ float StartLoadingTime;
	/* 0x01c */ int NumLoadedRideInfos;
	/* 0x020 */ int NumAllocatedRideInfos;
	/* 0x024 */ int MayNeedDefragmentation;
	/* 0x028 */ bList* LoadedSolidPackList;
	/* 0x030 */ bList* LoadedTexturePackList;
	/* 0x038 */ bList* LoadedSkinLayerList;
	/* 0x040 */ bList* LoadedWheelList;
	/* 0x048 */ bList* LoadedSkinList;
	/* 0x050 */ bList* LoadedCarList;
	/* 0x058 */ bList* LoadedRideInfoList;
	/* 0x060 */ void* MemoryPoolMem;
	/* 0x064 */ int MemoryPoolSize;
	/* 0x068 */ int NumSpongeAllocations;
	/* 0x06c */ void* SpongeAllocations[16];
	/* 0x0ac */ int NumLoadingSkinLayers;
	/* 0x0b0 */ bList* LoadingSkinLayers[512];

	void CreatePermanentPool(int size);
};

extern CarLoader* TheCarLoader;