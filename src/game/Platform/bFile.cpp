#include "bFile.hpp"
#include "memory.hpp"


//THUNK : 0x0057C5B0
bFile::bFile(char* path, int a2)
{
	reinterpret_cast<void(__thiscall*)(bFile*, int)>(0x0057C5B0)(this, a2);
}

//THUNK : 0x0057CA10
bFile* bFile::bOpen(char* path, int a2)
{
	return call<bFile* (char*, int)>(0x0057CA10)(path, a2);
}

//THUNK : 0x00579B90
void bFile::bClose(int a2)
{
	reinterpret_cast<void(__thiscall*)(bFile*, int)>(0x00579B90)(this, a2);
}