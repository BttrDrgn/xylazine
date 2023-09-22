#pragma once

enum SlotPoolFlags
{
	SLOTPOOL_FLAG_OVERFLOW_IF_FULL = 1 << 0,
	SLOTPOOL_FLAG_ZERO_ALLOCATED_MEMORY = 1 << 1,
	SLOTPOOL_FLAG_WARN_IF_OVERFLOW = 1 << 2,
	SLOTPOOL_FLAG_WARN_IF_NONEMPTY_DELETE = 1 << 3
};

DEFINE_ENUM_FLAG_OPERATORS(SlotPoolFlags)

struct SlotPoolEntry
{
	SlotPoolEntry* Next;
};

class SlotPool
{
public:
	int unk_0;
	int unk_4;
	SlotPool* NextSlotPool;
	char* DebugName;
	void** FreeSlots;
	SlotPoolFlags Flags;
	int NumAllocatedSlots;
	int MostNumAllocatedSlots;
	int MemoryPool;
	int NumSlots;
	int SlotSize;
	int TotalNumSlots;
	SlotPool* Slots;
	int padding[7];
	
	SlotPool* Malloc();

	static SlotPool* NewSlotPool(int a1, int a2, const char* a3, int a4);
	static void DeleteSlotPool();
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