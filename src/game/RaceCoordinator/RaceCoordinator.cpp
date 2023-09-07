#include "RaceCoordinator.hpp"
#include "memory.hpp"

extern RaceCoordinator*& pRaceCoordinator = GET((RaceCoordinator*)0, 0x008900D8);

//THUNK : 0x00600FA0
void RaceCoordinator::ExecuteQueuedMessages()
{
	call<void(RaceCoordinator*)>(0x00600FA0)(this);
}

//THUNK : 0x00601020
void RaceCoordinator::RCSendMessage(int a2, int a3)
{
	reinterpret_cast<void(__thiscall*)(RaceCoordinator*, int, int)>(0x00601020)(this, a2, a3);
}