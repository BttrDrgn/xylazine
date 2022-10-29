#include "SlotPool.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

char*& LoadedTexturePackSlotPool = *reinterpret_cast<char**>(0x008A1CF4);
char*& LoadedSolidPackSlotPool = *reinterpret_cast<char**>(0x008A1CF8);
char*& LoadedSkinLayerSlotPool = *reinterpret_cast<char**>(0x008A1CFC);
char*& LoadedRideInfoSlotPool = *reinterpret_cast<char**>(0x008A1D00);
char*& LoadedPartsAnim = *reinterpret_cast<char**>(0x008A32E8);
int& TheSlotPoolManager = GET(INT, 0x00828530);
SlotPool*& dword_00828538 = GET((SlotPool*)0, 0x00828538);
SlotPool*& unk_00828534 = GET((SlotPool*)0, 0x00828534);

//THUNK : 0x00440B40
SlotPool* SlotPool::NewSlotPool(int a1, int a2, const char* a3, int a4)
{
    return call<SlotPool*(int, int, const char*, int)>(0x00440B40)(a1, a2, a3, a4);
}

//DONE : 0x00440DF0
SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool)
{
    SlotPool* result; // eax
    SlotPool* v5; // ecx

    result = SlotPool::NewSlotPool((slot_size + 3) & 0xFFFFFFFC, slot_count, debug_name, memory_pool);
    if (result)
    {
        if (TheSlotPoolManager == 1)
        {
            v5 = dword_00828538;
            dword_00828538 = result;
            dword_00828538 = result;
            *(SlotPool**)&result[4] = v5;
            *(_DWORD*)result = *(_DWORD*)&unk_00828534;
        }
    }
    return result;
}