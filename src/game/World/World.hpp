#pragma once

class World
{
public:
	static void UpdateWorldPaused(World* _this);
	static void DoTimestep(World* _this, float a2);
	static int World::IsWorldPaused(World* a1);
	static double World::GetTimestep(World* _this, float a2);
};

extern World*& pCurrentWorld;
extern int& WorldTimer;

void AdvanceWorldTime();