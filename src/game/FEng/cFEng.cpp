#include "cFEng.hpp"
#include "memory.hpp"

cFEng*& cFEng::pInstance = *reinterpret_cast<cFEng**>(0x008384C4);

//THUNK : 0x005372E0
cFEng::cFEng()
{
	reinterpret_cast<void(__thiscall*)(cFEng*)>(0x005372E0)(this);
}