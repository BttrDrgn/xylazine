#pragma once

#include <cstdint>

#include <Windows.h>
#include <tlhelp32.h>
#include <string.h>
#include <d3d9.h>
#include <dinput.h>

#ifdef DEBUG
#include <intrin.h>
#endif

#define print(__FMT__, ...) std::printf(__FMT__, __VA_ARGS__);
#define println(__FMT__, ...) print(__FMT__ "\n", __VA_ARGS__);

//#define MATCHING