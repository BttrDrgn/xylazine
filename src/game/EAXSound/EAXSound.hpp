#pragma once

class EAXSound
{
public:
	void InitializeFromAemsManager();
	void Update(float a2);
	void EnterPauseMenu(int a2, bool a3);
	void Destroy();
};

extern EAXSound*& g_pEAXSound;