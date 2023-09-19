#pragma once

#include "types.hpp"

///Unsorted function thunks

//While this can be macroed or just a normal call, I have opted to call the game's malloc
//incase for whatever reason CRT mismatch causes issues
//THUNK : 0x0075C6C8
void* j__malloc(size_t size)
{
    return call<void* (size_t)>(0x00575620)(size);
}

//THUNK : 0x0057CEF0
ResourceFile* CreateResourceFile(const char* a1, int a2, int a3, int a4, int a5)
{
    return call<ResourceFile* (const char*, int, int, int, int)>(0x0057CEF0)(a1, a2, a3, a4, a5);
}

//THUNK : 0x004944D0
int eLoadStreamingTexturePack(char* a1, void(__cdecl* a2)(unsigned int), int a3, __int16 a4)
{
    return call<int(char*, void*, int, __int16)>(0x004944D0)(a1, a2, a3, a4);
}

//THUNK : 0x00490170
int eWaitForStreamingTexturePackLoading(const char* a1)
{
    return call<int(const char*)>(0x00490170)(a1);
}

//THUNK : 0x00512360
void SetCurrentLanguage(eLanguages new_language)
{
    call<void(eLanguages)>(0x00512360)(new_language);
}

//THUNK : 0x0051CD10
void FEngSetUseIdleList(char* a4, char a2)
{
    call<void(char*, char)>(0x0051CD10)(a4, a2);
}

//THUNK : 0x0051CD40
void FEngSetPermanent(char* a4, __int16 a2)
{
    call<void(char*, __int16)>(0x0051CD40)(a4, a2);
}

//THUNK : 0x0048D9D0
void eWaitForStreamingSolidPackLoading(const char* filename)
{
    call<void(const char*)>(0x0048D9D0)(filename);
}

//THUNK : 0x004901D0
int GetTextureInfo(std::uint32_t a1, int a2, int a3)
{
    return call<int(std::uint32_t, int, int)>(0x004901D0)(a1, a2, a3);
}

//THUNK : 0x00494D30
int* eLoadStreamingTexture(unsigned int a1, void(__cdecl* a2)(int), int a3, char a4)
{
    return call<int*(unsigned int, void*, int, char)>(0x00494D30)(a1, a2, a3, a4);
}

//THUNK : 0x00579830
int AddMemoryFile(void* pmemory_file)
{
    return call<int(void*)>(0x00579830)(pmemory_file);
}

//THUNK : 0x0057F000
void BlockUntilMemoryFileLoaded(void* memory_file)
{
    call<void(void*)>(0x0057F000)(memory_file);
}

//THUNK : 0x005809C0
void GenerateJoyEvents()
{
    call<void()>(0x005809C0)();
}

//THUNK : 0x006F876C
void FILESYS_writesync(int a1, int a2, int a3, int a4, int a5)
{
    call<void(int, int, int, int, int)>(0x006F876C)(a1, a2, a3, a4, a5);
}

//THUNK : 0x0057EE00
void VerifyJoylogChecksum()
{
    call<void()>(0x0057EE00)();
}

//THUNK : 0x005EB390
void DetermineAllPlayersInputModes()
{
    call<void()>(0x005EB390)();
}

//THUNK : 0x0057EAD0
void sub_57EAD0(float a1)
{
    call<void(float)>(0x0057EAD0)(a1);
}

//THUNK : 0x005BA610
void sub_5BA610()
{
    call<void()>(0x005BA610)();
}

//THUNK : 0x005CF960
void ShutdownTheGame()
{
    call<void()>(0x005CF960)();
}

//THUNK : 0x005F1390
bool sub_5F1390(World* a1)
{
    return call<bool(World*)>(0x005F1390)(a1);
}

//THUNK : 0x005EA360
float sub_5EA360(World* _this)
{
    return call<float(World*)>(0x005EA360)(_this);
}

//THUNK : 0x00585B20
void sub_585B20()
{
    call<void()>(0x00585B20)();
}

//THUNK : 0x005877D0
void sub_5877D0()
{
    call<void()>(0x005877D0)();
}

//THUNK : 0x0058EBC0
void sub_58EBC0()
{
    call<void()>(0x0058EBC0)();
}

//THUNK : 0x0060AEE0
void sub_60AEE0(_DWORD* a1, bool a2)
{
    reinterpret_cast<void(__thiscall*)(_DWORD*, bool)>(0x0060AEE0)(a1, a2);
}

//THUNK : 0x00600900
void UpdatePlayersNonGameState()
{
    call<void()>(0x00600900)();
}

//THUNK : 0x0044EFE0
void UpdateCameraMovers()
{
    call<void()>(0x0044EFE0)();
}

//THUNK : 0x00572610
void UpdatePortRumblers()
{
    call<void()>(0x00572610)();
}

//THUNK : 0x005728C0
void UpdateCameraShakers()
{
    call<void()>(0x005728C0)();
}

//THUNK : 0x00570C00
void DisplayDebugScreenPrints()
{
    call<void()>(0x00570C00)();
}

//THUNK : 0x0058C220
void sub_58C220()
{
    call<void()>(0x0058C220)();
}

//THUNK : 0x005CE850
void sub_5CE850()
{
    call<void()>(0x005CE850)();
}

//THUNK : 0x005D2850
void eDisplayFrame()
{
    call<void()>(0x005D2850)();
}

//THUNK : 0x005CE8A0
void sub_5CE8A0()
{
    call<void()>(0x005CE8A0)();
}

//THUNK : 0x0057EF60
int ServiceResourceLoading()
{
    return call<int()>(0x0057EF60)();
}

//THUNK : 0x005CE4C0
void sub_5CE4C0()
{
    call<void()>(0x005CE4C0)();
}

//THUNK : 0x005BF1C0
void sub_5BF1C0()
{
    call<void()>(0x005BF1C0)();
}

//THUNK : 0x0057E800
void ServiceQueuedFiles()
{
    call<void()>(0x0057E800)();
}

//THUNK : 0x00580D90
int InitJoylog()
{
    return call<int()>(0x00580D90)();
}

//THUNK : 0x0057ECB0
void SeedRandomNumber()
{
    call<void()>(0x0057ECB0)();
}

//THUNK : 0x0048DE90
void eInitSolids()
{
    call<void()>(0x0048DE90)();
}

//THUNK : 0x005C2F90
void epInitViews()
{
    call<void()>(0x005C2F90)();
}

//THUNK : 0x0048AB60
void eInitLightFlarePool()
{
    call<void()>(0x0048AB60)();
}

//THUNK : 0x005C33D0
void eInitEnvMap()
{
    call<void()>(0x005C33D0)();
}

//THUNK : 0x005BE5A0
void sub_5BE5A0()
{
    call<void()>(0x005BE5A0)();
}

//THUNK : 0x005BEA20
void LoadRegistrySettings()
{
    call<void()>(0x005BEA20)();
}

//THUNK : 0x005BEEA0
void CreateRegistrySettings()
{
    call<void()>(0x005BEEA0)();
}

//THUNK : 0x0055DBD0
void sub_55DBD0(WPARAM wParam)
{
    call<void(WPARAM)>(0x0055DBD0)(wParam);
}

//THUNK : 0x005C8320
void sub_5C8320(WPARAM wParam)
{
    call<void(WPARAM)>(0x005C8320)(wParam);
}

//THUNK : 0x0052CF60
bool FEngIsPackagePushed(const char* a4)
{
    return call<bool(const char*)>(0x0052CF60)(a4);
}

//THUNK : 0x005BF5A0
bool sub_5BF5A0()
{
    return call<bool()>(0x005BF5A0)();
}

//THUNK : 0x005D21F0
void sub_5D21F0()
{
    call<void()>(0x005D21F0)();
}

//THUNK : 0x005BA780
void SetScreenBuffers()
{
    call<void()>(0x005BA780)();
}

//THUNK : 0x00579550
void InitJoystick()
{
    call<void()>(0x00579550)();
}

//THUNK : 0x005BE200
void sub_5BE200()
{
    call<void()>(0x005BE200)();
}

//THUNK : 0x005CEC90
void sub_5CEC90()
{
    call<void()>(0x005CEC90)();
}

//THUNK : 0x004859B0
void InitializeSoundDriver()
{
    call<void()>(0x004859B0)();
}

//THUNK : 0x00537830
void FEngInitSystem()
{
    call<void()>(0x00537830)();
}

//THUNK : 0x004FF680
void InitLocalization()
{
    call<void()>(0x004FF680)();
}

//THUNK : 0x00452EC0
void InitDragCameraManager()
{
    call<void()>(0x00452EC0)();
}

//THUNK : 0x0061C700
void InitCarLoader()
{
    call<void()>(0x0061C700)();
}

//THUNK : 0x0057B5D0
void sub_57B5D0()
{
    call<void()>(0x0057B5D0)();
}

//THUNK : 0x0057C920
void sub_57C920()
{
    call<void()>(0x0057C920)();
}
