#include "RaceStarter.hpp"
#include "memory.hpp"

int& SkipFE = *reinterpret_cast<int*>(0x00864FAC);

//THUNK : 0x004FEF60
void RaceStarter::StartReplayRace()
{
	call<void()>(0x004FEF60)();
}

//THUNK : 0x0053FEB0
void RaceStarter::StartSkipFERace()
{
	call<void()>(0x0053FEB0)();
}