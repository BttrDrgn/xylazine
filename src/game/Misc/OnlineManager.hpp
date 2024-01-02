#pragma once

class OnlineManager
{
public:
	char unk_0[0x34800];
	void Initialize(int argc, char* argv[]);
	float sub_601A60(float a1);
	bool sub_5F00F0();
	void Update(bool a1);
};

extern OnlineManager* TheOnlineManager;