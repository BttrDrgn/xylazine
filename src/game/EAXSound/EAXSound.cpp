#include "EAXSound.hpp"
#include "memory.hpp"

EAXSound*& g_pEAXSound = *reinterpret_cast<EAXSound**>(0x0082B884);

//THUNK : 0x00486510
void EAXSound::InitializeFromAemsManager()
{
	call<void(EAXSound*)>(0x00486510)(this);
}

//THUNK : 0x00483B40
void EAXSound::Update(float a2)
{
	reinterpret_cast<void(__thiscall*)(EAXSound*, float)>(0x00483B40)(this, a2);
}