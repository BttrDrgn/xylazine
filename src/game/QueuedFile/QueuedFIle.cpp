#include "QueuedFile.hpp"
#include "memory.hpp"

//THUNK : 0x0057B410
QueuedFile::QueuedFile(void* buf, const char* filename, int file_pos, int num_bytes, void* callback_function, int callback_param)
{
	reinterpret_cast<void(__thiscall*)(QueuedFile*, void*, const char*, int, int, void*, int )>(0x0057B410)(this, buf, filename, file_pos, num_bytes, callback_function, callback_param);
}

//THUNK : 0x0057B4A0
void AddQueuedFile(void* buf, const char* filename, int file_pos, int num_bytes, void(__cdecl* callback)(int, int), int callback_param)
{
	call<void(void*, const char*, int, int, void*, int)>(0x0057B4A0)(buf, filename, file_pos, num_bytes, callback, callback_param);
}