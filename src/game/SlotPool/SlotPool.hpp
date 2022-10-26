#pragma once

class SlotPool
{
public:
	static SlotPool* NewSlotPool(int a1, int a2, const char* a3, int a4);
	char padding[5000];
};

extern char*& LoadedTexturePackSlotPool;
extern char*& LoadedSolidPackSlotPool;
extern char*& LoadedSkinLayerSlotPool;
extern char*& LoadedRideInfoSlotPool;
extern char*& LoadedPartsAnim;
extern int& TheSlotPoolManager;

SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool);