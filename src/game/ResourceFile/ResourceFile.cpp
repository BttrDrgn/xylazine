#include "ResourceFile.hpp"
#include "memory.hpp"

//THUNK : 0x0057BD70
void ResourceFile::BeginLoading(void* callback, int callback_param)
{
	reinterpret_cast<void(__thiscall*)(ResourceFile*, void*, int)>(0x0057BD70)(this, callback, callback_param);
}