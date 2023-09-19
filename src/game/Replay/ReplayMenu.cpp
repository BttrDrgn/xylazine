#include "ReplayMenu.hpp"
#include "memory.hpp"

ReplayMenu*& gReplayMenu = *reinterpret_cast<ReplayMenu**>(0x008363EC);

//THUNK :  
void ReplayMenu::ServiceLoading()
{
	call<void(ReplayMenu*)>(0x004C10B0)(this);
}