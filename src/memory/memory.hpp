#pragma once

#include <Windows.h>
#include <functional>
#include <cstdint>

template <typename T> inline std::function<T> call(std::uintptr_t callback)
{
    return std::function<T>(reinterpret_cast<T*>(callback));
}

template <typename T> inline void set(std::uint32_t address, T value)
{
	DWORD protecc;
	VirtualProtect(reinterpret_cast<void*>(address), sizeof(T), PAGE_EXECUTE_READWRITE, &protecc);
	*reinterpret_cast<T*>(address) = value;
	VirtualProtect(reinterpret_cast<void*>(address), sizeof(T), protecc, &protecc);
}

#ifndef INT
#define INT 0
#endif

#ifndef INT_PTR
#define INT_PTR (int*)0
#endif

#ifndef UINT32
#define UINT32 (std::uint32_t)0
#endif

#ifndef UINT32_PTR
#define UINT32_PTR (std::uint32_t*)0
#endif

#ifndef UINT8
#define UINT8 (std::uint8_t)0
#endif

#ifndef UINT8_PTR
#define UINT8_PTR (std::uint8_t*)0
#endif

#ifndef FLOAT
#define FLOAT 0.0f
#endif

#ifndef DOUBLE
#define DOUBLE 0.0
#endif

#ifndef BOOL
#define BOOL false
#endif

#ifndef CHAR
#define CHAR '\0'
#endif

#ifndef CHAR_PTR
#define CHAR_PTR (char*)0
#endif

#ifndef typeof
#define typeof(x) decltype(x)
#endif

#ifndef GET
#define GET(T, addr) *reinterpret_cast<typeof(T)*>(addr)
#endif

inline void replace(std::uint32_t address, std::uint32_t function)
{
    DWORD protecc;
    VirtualProtect(reinterpret_cast<void*>(address), 5, PAGE_EXECUTE_READWRITE, &protecc);

    *reinterpret_cast<std::uint8_t*>(address) = 0xE9;
    *reinterpret_cast<std::uint32_t*>(address + 1) = (function - address - 5);

    VirtualProtect(reinterpret_cast<void*>(address), 5, protecc, &protecc);
}