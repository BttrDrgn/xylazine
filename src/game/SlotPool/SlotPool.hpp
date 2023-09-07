#pragma once

class SlotPool
{
public:
	static SlotPool* NewSlotPool(int a1, int a2, const char* a3, int a4);
	SlotPool* Malloc();
};

extern SlotPool*& LoadedTexturePackSlotPool;
extern SlotPool*& LoadedSolidPackSlotPool;
extern SlotPool*& LoadedSkinLayerSlotPool;
extern SlotPool*& LoadedRideInfoSlotPool;
extern SlotPool*& LoadedPartsAnim;
extern int& TheSlotPoolManager;
extern SlotPool*& bFileSlotPool;

SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool);