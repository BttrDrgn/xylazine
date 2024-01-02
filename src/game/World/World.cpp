#include "World.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

World*& pCurrentWorld = *reinterpret_cast<World**>(0x00890080);
int& WorldTimer = *reinterpret_cast<int*>(0x0086518C);
int& RealTimer = *reinterpret_cast<int*>(0x008651AC);
int& NeedToPrepareWorldTimestep = *reinterpret_cast<int*>(0x007FB728);
int& WorldLoopCounter = *reinterpret_cast<int*>(0x007FB724);
int& dword_8669F4 = *reinterpret_cast<int*>(0x008669F4);
int& dword_866A14 = *reinterpret_cast<int*>(0x00866A14);
int& dword_0089E834 = *reinterpret_cast<int*>(0x0089E834);
int& dword_0086676C = *reinterpret_cast<int*>(0x0086676C);
int& dword_00869234 = *reinterpret_cast<int*>(0x00869234);
int& dword_007FB720 = *reinterpret_cast<int*>(0x007FB720);
int& dword_00865150 = *reinterpret_cast<int*>(0x00865150);
int& dword_007FB71C = *reinterpret_cast<int*>(0x007FB71C);
bool& byte_00850098 = *reinterpret_cast<bool*>(0x00850098);
bool& byte_00866758 = *reinterpret_cast<bool*>(0x00866758);
float& flt_007875BC = *reinterpret_cast<float*>(0x007875BC);
float& flt_00784250 = *reinterpret_cast<float*>(0x00784250);
float& flt_007A5730 = *reinterpret_cast<float*>(0x007A5730);
float& flt_00784260 = *reinterpret_cast<float*>(0x00784260);
float& flt_007A570C = *reinterpret_cast<float*>(0x007A570C);
float& flt_00784504 = *reinterpret_cast<float*>(0x00784504);
float& flt_00784358 = *reinterpret_cast<float*>(0x00784358);
float& flt_007A5708 = *reinterpret_cast<float*>(0x007A5708);
float& flt_00784264 = *reinterpret_cast<float*>(0x00784264);
float& flt_007A5704 = *reinterpret_cast<float*>(0x007A5704);
float& flt_007A5710 = *reinterpret_cast<float*>(0x007A5710);
float& flt_00865158 = *reinterpret_cast<float*>(0x00865158);
float& flt_00787590 = *reinterpret_cast<float*>(0x00787590);
float& RealTimeElapsed = *reinterpret_cast<float*>(0x00865198);
float& WorldTimestep = *reinterpret_cast<float*>(0x00784268);
float& DisplayLoadTimeStops = *reinterpret_cast<float*>(0x007D7D3C);
float& WorldTimeSeconds = *reinterpret_cast<float*>(0x007FB718);
float& WorldTimeElapsed = *reinterpret_cast<float*>(0x00865154);

//THUNK : 0x0057A0E0
void AdvanceWorldTime()
{
	call<void()>(0x0057A0E0)();
}

//THUNK : 0x005EA2B0
void World::UpdateWorldPaused()
{
	reinterpret_cast<void(__thiscall*)(World*)>(0x005EA2B0)(this);
}

//THUNK : 0x00609CE0
void World::DoTimestep(float a2)
{
	reinterpret_cast<void(__thiscall*)(World*, float)>(0x00609CE0)(this, a2);
}

//THUNK : 0x005EA320
int World::IsWorldPaused()
{
	return reinterpret_cast<int(__thiscall*)(World*)>(0x005EA320)(this);
}

//THUNK : 0x004EC570
void sub_4EC570()
{
    call<void()>(0x004EC570)();
}

//THUNK : 0x005FE4C0
bool sub_5FE4C0(int* a1)
{
    return reinterpret_cast<bool(__thiscall*)(int*)>(0x005FE4C0)(a1);
}

//THUNK : 0x005FE530
bool sub_5FE530(int* a1)
{
    return reinterpret_cast<bool(__thiscall*)(int*)>(0x005FE530)(a1);
}

//THUNK : 0x00401090
float sub_401090(float value, float min, float max)
{
    return call<float(float, float, float)>(0x00401090)(value, min, max);
}

//THUNK : 0x005F9010
void sub_5F9010(_WORD* a1, int a2)
{
    call<void(_WORD*, int)>(0x005F9010)(a1, a2);
}

//Fix the actual PC function, somehow this works fine
//TODO : 0x00601A60
float World::GetTimestep(float a2)
{
	//non matching
	return flt_007A5730 * a2;
}

//THUNK : 0x005F1390
void World::UpdateAIDebugRendering()
{
	reinterpret_cast<void(__thiscall*)(World*)>(0x005F1390)(this);
}