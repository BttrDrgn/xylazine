#pragma once

#include "Platform/Platform.hpp"

enum ResourceFileType
{
	RESOURCE_FILE_NONE = 0x0,
	RESOURCE_FILE_GLOBAL = 0x1,
	RESOURCE_FILE_FRONTEND = 0x2,
	RESOURCE_FILE_INGAME = 0x3,
	RESOURCE_FILE_TRACK = 0x4,
	RESOURCE_FILE_NIS = 0x5,
	RESOURCE_FILE_CAR = 0x6,
	RESOURCE_FILE_LANGUAGE = 0x7,
	RESOURCE_FILE_REPLAY = 0x8,
};

struct LoadedHotFileEntry
{
	bChunk* pChunk;
	int OriginalSize;
	int MaxSize;
	uint32_t Checksum;
};

class ResourceFile : public bTList<ResourceFile>
{
public:
	bool mEnableFreeMemory;
	ResourceFileType Type;
	int Flags;
	int FileOffset;
	int FileSize;
	char* Filename;
	char* HotFilename;
	char* AllocationName;
	int AllocationParams;
	int FileTransfersInProgress;
	int LoadingFinishedFlag;
	void* Callback;
	int CallbackParam;
	bChunk* pFirstChunk;
	int SizeofChunks;
	LoadedHotFileEntry* pLoadedHotFileEntries;
	int NumLoadedHotFileEntries;
	int HotFileNumber;
	char padding[2000];

	void BeginLoading(void* callback, int callback_param);
};

