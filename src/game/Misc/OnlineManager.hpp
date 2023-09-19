#pragma once

class OnlineManager
{
public:
	char unk_0[0x34800];
	void InitOnline(int argc, char* argv[]);
};

extern OnlineManager* TheOnlineManager;