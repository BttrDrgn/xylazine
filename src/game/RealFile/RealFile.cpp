#include "RealFile.hpp"
#include "memory.hpp"

//THUNK : 0x006F7266
void RealFile::AddDevice(int a1)
{
	call<void(int)>(0x006F7266)(a1);
}

//THUNK : 0x006F6E7A
int RealFile::AddSearchLocation(const char* a1, char a2)
{
	return call<int(const char*, char)>(0x006F6E7A)(a1, a2);
}