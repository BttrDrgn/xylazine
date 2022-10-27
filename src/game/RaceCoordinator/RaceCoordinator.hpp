#pragma once

class RaceCoordinator
{
public:
	static void ExecuteQueuedMessages(RaceCoordinator* _this);
	static void RCSendMessage(RaceCoordinator* _this, int a2, int a3);
	char padding[5000];
};

extern RaceCoordinator*& pRaceCoordinator;
