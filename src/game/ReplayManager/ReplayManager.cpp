#include "ReplayManager.hpp"
#include "memory.hpp"

ReplayManager*& pReplayManager = GET((ReplayManager*)0, 0x008650B8);

//THUNK : 0x00580880
bool ReplayManager::DetectJoylogReplaySnapshot()
{
	return call<bool()>(0x00580880)();
}

//THUNK : 0x0057BE30
void ReplayManager::DoFancyJoylogDebugging(ReplayManager* _this)
{
	call<void(ReplayManager*)>(0x0057BE30)(_this);
}

//THUNK : 0x00581050
void ReplayManager::BeginFrame(ReplayManager* _this)
{
	reinterpret_cast<void(__thiscall*)(ReplayManager*)>(0x00581050)(_this);
}

//THUNK : 0x00578E10
void ReplayManager::EndFrame(ReplayManager* _this)
{
	reinterpret_cast<void(__thiscall*)(ReplayManager*)>(0x00578E10)(_this);
}
