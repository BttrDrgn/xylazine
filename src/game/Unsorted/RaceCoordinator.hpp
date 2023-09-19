#pragma once

enum RCState
{
	RCSTATE_NONE = 0,
	RCSTATE_CAMERA_FLYBY = 1,
	RCSTATE_PRERACE = 2,
	RCSTATE_RACE_IN_PROGRESS = 3,
	RCSTATE_INSTANT_REPLAY = 4,
	RCSTATE_AUTO_REPLAY = 5,
	RCSTATE_PAUSE = 6,
	RCSTATE_POSTRACE = 7,
	RCSTATE_AI_DEMO_MODE = 8,
	RCSTATE_REPLAY_DEMO_MODE = 9,
	NUM_RCSTATES = 10
};

class RaceCoordinator
{
public:
	int State;
	char padding[0x90];

	void ExecuteQueuedMessages();
	void RCSendMessage(int a2, int a3);
};

extern RaceCoordinator*& pRaceCoordinator;
