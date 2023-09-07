#pragma once

class MemoryPool
{
public:
	void Init(void* a2, int a3, const char* a4);
};

extern MemoryPool*& MemoryPoolMem;
extern MemoryPool*& MemoryPools;