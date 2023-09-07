#include "OnlineManager.hpp"
#include "memory.hpp"

extern OnlineManager* TheOnlineManager = new OnlineManager();

//THUNK : 0x005EFE30
void OnlineManager::InitOnline(int argc, char* argv[])
{
    reinterpret_cast<void(__thiscall*)(OnlineManager*, int, char**)>(0x005EFE30)(this, argc, argv);
}
