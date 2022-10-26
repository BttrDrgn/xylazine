#include "cFrontendDatabase.hpp"
#include "memory.hpp"

cFrontendDatabase& FEDatabase = *reinterpret_cast<cFrontendDatabase*>(0x0083A9D0);

//THUNK : 0x005346F0
void cFrontendDatabase::Default(cFrontendDatabase* _this)
{
	call<void(cFrontendDatabase*)>(0x005346F0)(_this);
}