#include "EAGLInternal.hpp"
#include "memory.hpp"

void*(__cdecl* EAGLInternal::EAGLMalloc)(size_t) = 0;
void(__cdecl* EAGLInternal::EAGLFree)(void*) = 0;
