#pragma once

#include "FEngine.hpp"

class cFEng
{
public:
	static cFEng*& pInstance;
	/* 0x0 */ FEngine* mFEng;
	/* 0x4 */ bool bWasPaused;

	cFEng();
};