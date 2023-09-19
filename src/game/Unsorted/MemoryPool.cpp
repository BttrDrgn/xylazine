#include "MemoryPool.hpp"
#include "memory.hpp"

MemoryPool*& MemoryPoolMem = *reinterpret_cast<MemoryPool**>(0x00828218);
MemoryPool**& MemoryPools = *reinterpret_cast<MemoryPool***>(0x00828154);

//Uses this
//THUNK : 0x004402C0
void MemoryPool::Init(void* a2, int a3, const char* a4)
{
    call<void(MemoryPool*, void*, int, const char*)>(0x004402C0)(this, a2, a3, a4);
}