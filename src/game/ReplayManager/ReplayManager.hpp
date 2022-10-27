#pragma once

class ReplayManager
{
public:
	static bool DetectJoylogReplaySnapshot();
	static void DoFancyJoylogDebugging(ReplayManager* _this);
	static void BeginFrame(ReplayManager* _this);
	static void EndFrame(ReplayManager* _this);
	char padding[5000];
};

extern ReplayManager*& pReplayManager;