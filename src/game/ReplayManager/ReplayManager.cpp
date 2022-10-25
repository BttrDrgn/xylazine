#include "ReplayManager.hpp"
#include "memory.hpp"


//THUNK : 0x00580880
bool ReplayManager::DetectJoylogReplaySnapshot()
{
	return call<bool()>(0x00580880)();
}