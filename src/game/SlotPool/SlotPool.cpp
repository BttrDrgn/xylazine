#include "SlotPool.hpp"
#include "memory.hpp"

extern char*& LoadedTexturePackSlotPool = *reinterpret_cast<char**>(0x008A1CF4);
extern char*& LoadedSolidPackSlotPool = *reinterpret_cast<char**>(0x008A1CF8);
extern char*& LoadedSkinLayerSlotPool = *reinterpret_cast<char**>(0x008A1CFC);
extern char*& LoadedRideInfoSlotPool = *reinterpret_cast<char**>(0x008A1D00);
extern char*& LoadedPartsAnim = *reinterpret_cast<char**>(0x008A32E8);

//THUNK : 0x00440DF0
SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool)
{
	return call<SlotPool* (int, int, const char*, int)>(0x00440DF0)(slot_size, slot_count, debug_name, memory_pool);
}