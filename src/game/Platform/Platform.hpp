#pragma once

extern int& PlatformSkipDRM;
extern int& dword_00800B98;
extern char A_Char;

int bFileExists(char* Str);
void bFree(char* a1);
void bPListInit(int expected_nodes);

void InitPlatform();
bool PlatformCDCheckBinDat(bool a1);
bool PlatformCDCheck();
bool PlatformDRM();
bool PlatformIsProcessRunning(char* exe, int count);