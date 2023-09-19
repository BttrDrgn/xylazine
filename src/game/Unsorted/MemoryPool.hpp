#pragma once

struct MemoryPoolOverrideInfo
{
    /* 0x00 */ void* Pool;
    /* 0x04 */ int Address;
    /* 0x08 */ int Size;
    /* 0x0c */ void* Malloc;
    /* 0x10 */ void* Free;
    /* 0x14 */ void* GetAmountFree;
    /* 0x18 */ void* GetLargestFreeBlock;
};

struct MemoryPoolInfo
{
    /* 0x0 */ bool NumberReserved;
    /* 0x4 */ bool TopMeansLargerAddress;
    /* 0x8 */ int OverflowPoolNumber;
    /* 0xc */ MemoryPoolOverrideInfo* OverrideInfo;
};

class MemoryPool
{
public:
	void Init(void* a2, int a3, const char* a4);
};

extern MemoryPool*& MemoryPoolMem;
extern MemoryPool**& MemoryPools;