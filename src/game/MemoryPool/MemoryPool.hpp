#pragma once

class MemoryPool
{
public:
	static void Init(MemoryPool* _this, void* a2, int a3, const char* a4);
};

extern MemoryPool*& MemoryPoolMem;
extern MemoryPool*& MemoryPools;