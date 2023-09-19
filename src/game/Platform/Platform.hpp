#pragma once
#pragma once

#include "SlotPool/SlotPool.hpp"

typedef HANDLE EAFileHandle;

extern int& PlatformSkipDRM;
extern int& dword_00800B98;
extern int& dword_008284E4;
extern float& flt_00828028;
extern char& a_char;

struct bNode
{
	bNode* Next;
	bNode* Prev;
};

struct bList
{
	bNode HeadNode;
};

template<class T> struct bTNode
{
	T* Next;
	T* Prev;
};

struct bPNode : bTNode<bPNode>
{
	void* Object;
};

template<class T> struct bTList
{
	bTNode<T> HeadNode;
};

struct bChunk
{
	unsigned int ID;
	int Size;
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
void* bMalloc(int a1, int a2);
char* bStrNCpy(char* to, const char* from, int m);
int bFileSize(char* filename);
int bInitMemoryPool(int a1, void* a2, int a3, const char* a4);

void InitPlatform();
bool PlatformCDCheckBinDat(bool a1);
bool PlatformCDCheck();
bool PlatformDRM();
bool PlatformIsProcessRunning(char* exe, int count);
