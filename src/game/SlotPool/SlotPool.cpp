#include "SlotPool.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

SlotPool*& LoadedTexturePackSlotPool = *reinterpret_cast<SlotPool**>(0x008A1CF4);
SlotPool*& LoadedSolidPackSlotPool = *reinterpret_cast<SlotPool**>(0x008A1CF8);
SlotPool*& LoadedSkinLayerSlotPool = *reinterpret_cast<SlotPool**>(0x008A1CFC);
SlotPool*& LoadedRideInfoSlotPool = *reinterpret_cast<SlotPool**>(0x008A1D00);
SlotPool*& LoadedPartsAnim = *reinterpret_cast<SlotPool**>(0x008A32E8);
SlotPool*& bFileSlotPool = *reinterpret_cast<SlotPool**>(0x00865104);
SlotPool*& ePolySlotPool = *reinterpret_cast<SlotPool**>(0x0082DA4C);
SlotPool*& eModelSlotPool = *reinterpret_cast<SlotPool**>(0x0082DA88);
SlotPool*& TexturePackSlotPool = *reinterpret_cast<SlotPool**>(0x0082DB0C);
SlotPool*& TextureHeaderSlotPool = *reinterpret_cast<SlotPool**>(0x0087081C);
SlotPool*& VertexBufferHeaderPool = *reinterpret_cast<SlotPool**>(0x00870820);
SlotPool*& eStripSlotPool = *reinterpret_cast<SlotPool**>(0x00870954);
SlotPool*& eAnimTextureSlotPool = *reinterpret_cast<SlotPool**>(0x00870790);
SlotPool*& eTextureBucketSlotPool = *reinterpret_cast<SlotPool**>(0x00870918);
SlotPool*& eDataRenderSlotPool = *reinterpret_cast<SlotPool**>(0x0087091C);
SlotPool*& eLightMaterialPlatInfoSlotPool = *reinterpret_cast<SlotPool**>(0x008708B8);
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

//THUNK : 0x00440D40
SlotPool* SlotPool::Malloc()
{
    return reinterpret_cast<SlotPool*(__thiscall*)(SlotPool*)>(0x00440D40)(this);
}