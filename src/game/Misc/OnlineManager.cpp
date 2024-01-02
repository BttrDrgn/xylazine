#include "OnlineManager.hpp"
#include "memory.hpp"

extern OnlineManager* TheOnlineManager = new OnlineManager();

//THUNK : 0x005EFE30
void OnlineManager::Initialize(int argc, char* argv[])
{
    reinterpret_cast<void(__thiscall*)(OnlineManager*, int, char**)>(0x005EFE30)(this, argc, argv);
}

//THUNK : 0x00601A60
float OnlineManager::sub_601A60(float a1)
{
    return reinterpret_cast<float(__thiscall*)(float)>(0x00601A60)(a1);
}

//THUNK : 0x005F00F0
bool OnlineManager::sub_5F00F0()
{
    return reinterpret_cast<bool(__thiscall*)()>(0x005F00F0)();
}

//THUNK : 0x0060AEE0
void OnlineManager::Update(bool a1)
{
    reinterpret_cast<void(__thiscall*)(bool)>(0x0060AEE0)(a1);
}