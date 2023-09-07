#pragma once

class ReplayManager
{
public:
	int padding_0[7];
	int unk_28;

	static bool DetectJoylogReplaySnapshot();
	void DoFancyJoylogDebugging();
	void BeginFrame();
	void EndFrame();
};

extern ReplayManager*& pReplayManager;