#pragma once

class EAGLInternal
{
public:
	static void*(__cdecl* EAGLMalloc)(size_t);
	static void(__cdecl* EAGLFree)(void*);
};
