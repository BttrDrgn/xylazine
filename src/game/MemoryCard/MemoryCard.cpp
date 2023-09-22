#include "MemoryCard.hpp"
#include "memory.hpp"

MemoryCard* MemoryCard::s_pThis = 0;

//DONE : 0x004D9992
MemoryCard::MemoryCard()
{
    *(std::uint32_t*)&this->unk_0[24] = 0;
    this->unk_0[4] = 0;
    *(std::uint32_t*)&this->unk_0[96] = 0;
    *(std::uint32_t*)&this->unk_0[92] = 0;
    *(std::uint32_t*)&this->unk_0[80] = 0;
    this->unk_0[5] = 0;
    this->unk_0[6] = 0;
    this->unk_0[8] = 0;
    *(std::uint32_t*)&this->unk_0[16] = 0;
    this->unk_0[9] = 0;
    this->unk_0[10] = 0;
    this->unk_0[11] = 0;
    this->unk_0[12] = 0;
}

//THUNK : 0x004C5D80
void MemoryCard::Init()
{
    reinterpret_cast<void(__thiscall*)(MemoryCard*)>(0x004C5D80)(this);
}