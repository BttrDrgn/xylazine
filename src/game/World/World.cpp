#include "World.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

World*& pCurrentWorld = GET((World*)0, 0x00890080);
int& WorldTimer = GET(INT, 0x0086518C);

//THUNK : 0x0057A0E0
void AdvanceWorldTime()
{
	call<void()>(0x0057A0E0)();
}

//THUNK : 0x005EA2B0
void World::UpdateWorldPaused(World* _this)
{
	call<void(World*)>(0x005EA2B0)(_this);
}

//THUNK : 0x00609CE0
void World::DoTimestep(World* _this, float a2)
{
	reinterpret_cast<void(__thiscall*)(World*, float)>(0x00609CE0)(_this, a2);
}

//THUNK : 0x005EA320
int World::IsWorldPaused(World* a1)
{
	return call<bool(World*)>(0x005EA320)(a1);
}

//Function defs might be wrong
// Hardcoded to 0.008 because this feels most natural to play at
// NIS speeds are incredibly slow because of this
// The camera also moves when pausing due to the world updating still
//TODO : 0x00601A60
double World::GetTimestep(World* _this, float a2)
{
	//Temp fix
	return 0.008;
}