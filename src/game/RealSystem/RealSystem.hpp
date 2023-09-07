#pragma once

namespace RealSystem
{
	class Mutex
	{
	public:
		char unk_0;
		LPCRITICAL_SECTION Section;
		void Create();
	};
};

extern RealSystem::Mutex*& pRealSystemMutex;