#include "ResourceFile.hpp"
#include "memory.hpp"

//THUNK : 0x0057BD70
void ResourceFile::BeginLoading()
{
	call<void()>(0x0057BD70)();
}