#pragma once

class EAXSound
{
public:
	static void InitializeFromAemsManager(EAXSound* _this);
};

extern EAXSound*& g_pEAXSound;