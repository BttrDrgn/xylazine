#pragma once

class SlotPool
{
public:
	int unk_0;
	int unk_4;
	int unk_8;
	int unk_12;
	int unk_16;
	int unk_20;
	int unk_24;
	char unk_28[2500];
	
	SlotPool* Malloc();

	static SlotPool* NewSlotPool(int a1, int a2, const char* a3, int a4);
};

extern SlotPool*& LoadedTexturePackSlotPool;
extern SlotPool*& LoadedSolidPackSlotPool;
extern SlotPool*& LoadedSkinLayerSlotPool;
extern SlotPool*& LoadedRideInfoSlotPool;
extern SlotPool*& LoadedPartsAnim;
extern SlotPool*& bFileSlotPool;
extern SlotPool*& ePolySlotPool;
extern SlotPool*& eModelSlotPool;
extern SlotPool*& TexturePackSlotPool;
extern SlotPool*& eLightMaterialPlatInfoSlotPool;
extern SlotPool*& TextureHeaderSlotPool;
extern SlotPool*& VertexBufferHeaderPool;
extern SlotPool*& eStripSlotPool;
extern SlotPool*& eAnimTextureSlotPool;
extern SlotPool*& eTextureBucketSlotPool;
extern SlotPool*& eDataRenderSlotPool;
extern SlotPool*& AcidActiveGroupSlotPool;
extern SlotPool*& AcidEmitterSlotPool;
extern SlotPool*& SpaceNodeSlotPool;
extern SlotPool*& AnimCtrlSlotPool;
extern SlotPool*& AnimBankSlotPool;
extern SlotPool*& AnimPartSlotPool;
extern SlotPool*& AnimSkelSlotPool;
extern SlotPool*& ResourceFileSlotPool;
extern SlotPool*& EventSlotPool;
extern SlotPool*& EventHandlerSlotPool;
extern SlotPool*& QueuedFileSlotPool;

extern int& TheSlotPoolManager;

SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool);