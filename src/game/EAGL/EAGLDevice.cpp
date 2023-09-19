#include "EAGLDevice.hpp"
#include "EAGLInternal.hpp"
#include "memory.hpp"

//DONE : 0x006D81D0
void EAGL::Device::SetNewOverride(void*(__cdecl* a1)(size_t))
{
	EAGLInternal::EAGLMalloc = a1;
}

//DONE : 0x006D81E0
void EAGL::Device::SetDeleteOverride(void(__cdecl* a1)(void*))
{
	EAGLInternal::EAGLFree = a1;
}