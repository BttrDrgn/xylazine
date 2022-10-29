#pragma once

class World
{
public:
	static void UpdateWorldPaused(World* _this);
	static void DoTimestep(World* _this, float a2);
	static int IsWorldPaused(World* a1);
	static float GetTimestep(World* _this, float a2);
};

extern World*& pCurrentWorld;
extern int& WorldTimer;
extern float& RealTimeElapsed;
extern float& WorldTimestep;
extern int& NeedToPrepareWorldTimestep;
extern int& RealTimer;
extern int& dword_008669F4;
extern int& dword_00866A14;
extern float& WorldTimeElapsed;
extern int& WorldLoopCounter;



void AdvanceWorldTime();