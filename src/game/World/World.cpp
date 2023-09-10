#include "World.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

World*& pCurrentWorld = GET((World*)0, 0x00890080);
int& WorldTimer = GET(INT, 0x0086518C);
float& WorldTimeSeconds = GET(FLOAT, 0x007FB718);
int& RealTimer = GET(INT, 0x008651AC);
int& NeedToPrepareWorldTimestep = GET(INT, 0x007FB728);
float& WorldTimeElapsed = GET(FLOAT, 0x00865154);
int& WorldLoopCounter = GET(INT, 0x007FB724);
int& dword_8669F4 = GET(INT, 0x008669F4);
int& dword_866A14 = GET(INT, 0x00866A14);
int& dword_0089E834 = GET(INT, 0x0089E834);
int& dword_0086676C = GET(INT, 0x0086676C);
int& dword_00869234 = GET(INT, 0x00869234);
int& dword_007FB720 = GET(INT, 0x007FB720);
int& dword_00865150 = GET(INT, 0x00865150);
int& dword_007FB71C = GET(INT, 0x007FB71C);
bool& byte_00850098 = GET(BOOL, 0x00850098);
bool& byte_00866758 = GET(BOOL, 0x00866758);
float& flt_007875BC = GET(FLOAT, 0x007875BC);
float& flt_00784250 = GET(FLOAT, 0x00784250);
float& flt_007A5730 = GET(FLOAT, 0x007A5730);
float& flt_00784260 = GET(FLOAT, 0x00784260);
float& flt_007A570C = GET(FLOAT, 0x007A570C);
float& flt_00784504 = GET(FLOAT, 0x00784504);
float& flt_00784358 = GET(FLOAT, 0x00784358);
float& flt_007A5708 = GET(FLOAT, 0x007A5708);
float& flt_00784264 = GET(FLOAT, 0x00784264);
float& flt_007A5704 = GET(FLOAT, 0x007A5704);
float& flt_007A5710 = GET(FLOAT, 0x007A5710);
float& flt_00865158 = GET(FLOAT, 0x00865158);
float& flt_00787590 = GET(FLOAT, 0x00787590);
float& RealTimeElapsed = GET(FLOAT, 0x00865198);
float& WorldTimestep = GET(FLOAT, 0x00784268);
float& DisplayLoadTimeStops = GET(FLOAT, 0x007D7D3C);

//THUNK : 0x0057A0E0
void AdvanceWorldTime()
{
#if 0
	call<void()>(0x0057A0E0)();
#else
    double v0; // st7
    int v1; // [esp+0h] [ebp-4h]

    NeedToPrepareWorldTimestep = 1;
    if (WorldTimeElapsed != DisplayLoadTimeStops)
    {
        v0 = flt_00865158 + WorldTimeElapsed;
        v1 = (unsigned __int64)(flt_00787590 * v0);
        dword_007FB720 += v1;
        dword_00865150 = v1;
        dword_007FB71C = dword_007FB720;
        flt_00865158 = v0 - (double)v1 * flt_007875BC;
        WorldTimer += (unsigned __int64)(WorldTimeElapsed * flt_00784264 + flt_00784260);
        WorldTimeElapsed = 0.0;
        ++WorldLoopCounter;
        WorldTimeSeconds = (double)WorldTimer * WorldTimestep;
    }
#endif
}

//THUNK : 0x005EA2B0
void World::UpdateWorldPaused()
{
	call<void(World*)>(0x005EA2B0)(this);
}

//THUNK : 0x00609CE0
void World::DoTimestep(float a2)
{
	reinterpret_cast<void(__thiscall*)(World*, float)>(0x00609CE0)(this, a2);
}

//THUNK : 0x005EA320
int World::IsWorldPaused()
{
	return call<bool(World*)>(0x005EA320)(this);
}

//THUNK : 0x004EC570
void sub_004EC570()
{
    call<void()>(0x004EC570)();
}

//THUNK : 0x005FE4C0
bool sub_005FE4C0(int* a1)
{
    return reinterpret_cast<bool(__thiscall*)(int*)>(0x005FE4C0)(a1);
}

//THUNK : 0x005FE530
bool sub_005FE530(int* a1)
{
    return reinterpret_cast<bool(__thiscall*)(int*)>(0x005FE530)(a1);
}

//THUNK : 0x00401090
float sub_00401090(float value, float min, float max)
{
    return call<float(float, float, float)>(0x00401090)(value, min, max);
}

//THUNK : 0x005F9010
void sub_005F9010(_WORD* a1, int a2)
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