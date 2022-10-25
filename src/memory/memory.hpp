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

inline void replace(std::uint32_t address, std::uint32_t function)
{
    DWORD protecc;
    VirtualProtect(reinterpret_cast<void*>(address), 5, PAGE_EXECUTE_READWRITE, &protecc);

    *reinterpret_cast<std::uint8_t*>(address) = 0xE9;
    *reinterpret_cast<std::uint32_t*>(address + 1) = (function - address - 5);

    VirtualProtect(reinterpret_cast<void*>(address), 5, protecc, &protecc);
}