#pragma once

class SlotPool
{
public:
	char padding[5000];
};

extern char*& LoadedTexturePackSlotPool;
extern char*& LoadedSolidPackSlotPool;
extern char*& LoadedSkinLayerSlotPool;
extern char*& LoadedRideInfoSlotPool;
extern char*& LoadedPartsAnim;

SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool);