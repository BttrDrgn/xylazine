#pragma once

namespace RealSystem
{
	class Mutex
	{
	public:
		char unk_0;
		LPCRITICAL_SECTION Section;
		void Create();
		void Destroy();
	};
};

extern RealSystem::Mutex*& pRealSystemMutex;