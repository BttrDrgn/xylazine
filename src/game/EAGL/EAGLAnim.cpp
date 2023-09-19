#include "EAGLAnim.hpp"
#include "memory.hpp"

//THUNK : 0x006E1B30
void EAGLAnim::Initializer::InitInternal(unsigned int memorySize, bool enableStats)
{
	call<void(unsigned int, bool)>(0x006E1B30)(memorySize, enableStats);
}
