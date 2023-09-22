#pragma once

class MemoryCard
{
public:
	static MemoryCard* s_pThis;
	char unk_0[0x6C];

	MemoryCard();
	void Init();
};