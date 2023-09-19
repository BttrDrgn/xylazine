#include "CarLoader.hpp"
#include "Platform/Platform.hpp"
#include "memory.hpp"

extern CarLoader* TheCarLoader = new CarLoader();

//DONE : 0x00610720
void CarLoader::CreatePermanentPool(int size)
{
    reinterpret_cast<void(__thiscall*)(CarLoader*, int)>(0x00610720)(this, size);

    //void* sponge_instance = bMalloc(size, 0x2000);
    //this->SpongeAllocations[5] = sponge_instance;
    //this->SpongeAllocations[6] = *(void**)size; //?
    //bInitMemoryPool(4, sponge_instance, size, "Cars");
}
