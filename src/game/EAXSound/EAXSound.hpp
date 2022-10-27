#pragma once

class EAXSound
{
public:
	static void InitializeFromAemsManager(EAXSound* _this);
	static void Update(EAXSound* _this, float a2);
};

extern EAXSound*& g_pEAXSound;