#include "SlotPool.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

char*& LoadedTexturePackSlotPool = *reinterpret_cast<char**>(0x008A1CF4);
char*& LoadedSolidPackSlotPool = *reinterpret_cast<char**>(0x008A1CF8);
char*& LoadedSkinLayerSlotPool = *reinterpret_cast<char**>(0x008A1CFC);
char*& LoadedRideInfoSlotPool = *reinterpret_cast<char**>(0x008A1D00);
char*& LoadedPartsAnim = *reinterpret_cast<char**>(0x008A32E8);
int& TheSlotPoolManager = GET(INT, 0x00828530);
int& dword_00828538 = GET(INT, 0x00828538);
char*& unk_00828534 = GET(CHAR_PTR, 0x00828534);

//THUNK : 0x00440B40
SlotPool* SlotPool::NewSlotPool(int a1, int a2, const char* a3, int a4)
{
    return call<SlotPool*(int, int, const char*, int)>(0x00440B40)(a1, a2, a3, a4);
}

//DONE : 0x00440DF0
SlotPool* bNewSlotPool(int slot_size, int slot_count, const char* debug_name, int memory_pool)
{
    SlotPool* result;
    int v5;

    result = SlotPool::NewSlotPool((slot_size + 3) & 0xFFFFFFFC, slot_count, debug_name, memory_pool);
    if (result)
    {
        if (TheSlotPoolManager == 1)
        {
            v5 = dword_00828538;
            *(_DWORD*)dword_00828538 = (_DWORD)result;
            dword_00828538 = (int)result;
            *(_DWORD*)&result->padding[4] = v5;
            *(_DWORD*)result->padding = (_DWORD)&unk_00828534;
        }
    }
    return result;
}