#pragma once

#include "SlotPool/SlotPool.hpp"

extern int& PlatformSkipDRM;
extern int& dword_00800B98;
extern int& dword_008284E4;
extern float& flt_00828028;
extern char& a_char;

struct bList
{
	void* next;
	void* prev;
};


int bFileExists(char* Str);
void bFree(char* a1);
void bPListInit(int expected_nodes);
void bMemoryInit();
int bStrCmp(char* str1, char* str2);
int bInitDisculatorDriver(char* Str, char* a2);
std::uint32_t bStringHash(const char* string);
LONGLONG bGetTicker();
double GetDebugRealTime();
void bDeleteSlotPool(SlotPool* a1);
void SYNCTASK_run();
std::uint32_t bSleep(std::uint32_t dwMilliseconds);

void InitPlatform();
bool PlatformCDCheckBinDat(bool a1);
bool PlatformCDCheck();
bool PlatformDRM();
bool PlatformIsProcessRunning(char* exe, int count);
