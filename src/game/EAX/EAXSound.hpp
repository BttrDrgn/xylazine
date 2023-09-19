#pragma once

typedef enum eSNDPAUSE_REASON
{
	ePAUSE_ERROR = -1,
	eSNDPAUSE_PAUSEMENU = 0,
	eSNDPAUSE_SIMSTATE_IDLE = 1,
	eSNDPAUSE_SIMSTATE_INIT = 2,
	eSNDPAUSE_SIMSTATE_ACTIVE = 3,
	eSNDPAUSE_MEMCARD = 4,
	eSNDPAUSE_ONLINE = 5,
	eSNDPAUSE_MOVIE = 6,
	eSNDPAUSE_STARTNEWGAME = 7,
	eSNDPAUSE_QUITTOFE = 8,
	eSNDPAUSE_NISON = 9,
	eSNDPAUSE_PHOTOFINISH = 10,
	eSNDPAUSE_SMS_MESSAGE = 11
};

class EAXSound
{
public:
	void InitializeFromAemsManager();
	void Update(float a2);
	void EnterPauseMenu(int a2, bool a3);
	void Destroy();
	void ExitPauseMenu(eSNDPAUSE_REASON pause_reason);
};

extern EAXSound*& g_pEAXSound;