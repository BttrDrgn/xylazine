#pragma once
#pragma once

#include "Unsorted/SlotPool.hpp"

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
int bStrCmp(char* s1, char* s2);
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
void bInitMemoryPool(int pool_num, void* mem, int mem_size, const char* debug_name);
std::uint16_t* bStrCpy(std::uint16_t* a1, char* a2);

void InitPlatform();
bool PlatformCDCheckBinDat(bool a1);
bool PlatformCDCheck();
bool PlatformDRM();
bool PlatformIsProcessRunning(char* exe, int count);
