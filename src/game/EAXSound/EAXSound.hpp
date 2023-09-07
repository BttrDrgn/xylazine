#pragma once

class EAXSound
{
public:
	void InitializeFromAemsManager();
	void Update(float a2);
};

extern EAXSound*& g_pEAXSound;