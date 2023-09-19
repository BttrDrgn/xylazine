#include "EAGL.hpp"
#include "Platform/Platform.hpp"
#include "memory.hpp"

//DONE : 0x0042FB40
void* MyEAGLNewOverride(size_t a1)
{
	return bMalloc(a1, 0);
}

//DONE : 0x0042FB40
void MyEAGLDeleteOverride(void* a1)
{
	bFree((char*)a1);
}