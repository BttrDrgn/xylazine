#pragma once

#include "Platform/Platform.hpp"

enum QueuedFileStatus
{
	QWAITING = 0x0,
	QREADING = 0x1,
	QDONE = 0x2,
	QERROR = 0x3,
};

class QueuedFile : bTList<QueuedFile>
{
private:
	/* 0x08 */ void* pBuf;
	/* 0x0c */ char* Filename;
	/* 0x10 */ int FilePos;
	/* 0x14 */ int NumBytes;
	/* 0x18 */ int NumRead;
	/* 0x1c */ int BlockSize;
	/* 0x20 */ int Priority;
	/* 0x24 */ void* CallbackFunction;
	/* 0x28 */ int CallbackParam;
	/* 0x2c */ int CallbackParam2;
	/* 0x30 */ int CallbackModeUseParam2;
	/* 0x34 */ int Handle;
	/* 0x38 */ QueuedFileStatus Status;
	/* 0x3c */ float StartReadTime;
	static int CurrentHandle;

	QueuedFile(void* buf, const char* filename, int file_pos, int num_bytes, void* callback_function, int callback_param);
};

void AddQueuedFile(void* buf, const char* filename, int file_pos, int num_bytes, void(__cdecl* callback)(int, int), int callback_param);