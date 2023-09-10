#pragma once

class World
{
public:
	void UpdateWorldPaused();
	void DoTimestep(float a2);
	int IsWorldPaused();
	float GetTimestep(float a2);
};

extern World*& pCurrentWorld;
extern int& WorldTimer;
extern float& RealTimeElapsed;
extern float& WorldTimestep;
extern int& NeedToPrepareWorldTimestep;
extern int& RealTimer;
extern int& dword_8669F4;
extern int& dword_866A14;
extern float& WorldTimeElapsed;
extern int& WorldLoopCounter;



void AdvanceWorldTime();