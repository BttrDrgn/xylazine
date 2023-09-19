#pragma once

namespace EAGL
{
	class Device
	{
	public:
		static void SetNewOverride(void*(__cdecl* a1)(size_t));
		static void SetDeleteOverride(void(__cdecl* a1)(void*));
	};
}