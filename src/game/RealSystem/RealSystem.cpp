#include "RealSystem.hpp"
#include "memory.hpp"

RealSystem::Mutex* &pRealSystemMutex = GET((RealSystem::Mutex*)0, 0x00864EFC);


//THUNK : 0x006F55C7
void RealSystem::Mutex::Create()
{
	//reinterpret_cast<void(__thiscall*)(RealSystem::Mutex*)>(0x006F55C7)(pRealSystemMutex);
}