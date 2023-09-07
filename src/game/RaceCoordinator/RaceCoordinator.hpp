#pragma once

class RaceCoordinator
{
public:
	int State;
	void ExecuteQueuedMessages();
	void RCSendMessage(int a2, int a3);
};

extern RaceCoordinator*& pRaceCoordinator;
