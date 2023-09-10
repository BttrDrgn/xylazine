#pragma once

///Unsorted function thunks

//While this can be macroed or just a normal call, I have opted to call the game's malloc
//incase for whatever reason CRT mismatch causes issues
//THUNK : 0x0075C6C8
void* j__malloc(size_t size)
{
    return call<void* (size_t)>(0x00575620)(size);
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
void sub_0057EAD0(float a1)
{
    call<void(float)>(0x0057EAD0)(a1);
}

//THUNK : 0x005F1390
bool sub_005F1390(World* a1)
{
    return call<bool(World*)>(0x005F1390)(a1);
}

//THUNK : 0x005EA360
float sub_005EA360(World* _this)
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
void sub_0060AEE0(_DWORD* a1, bool a2)
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

//THUNK : 0x005F0140
void sub_005F0140()
{
    call<void()>(0x005F0140)();
}

//THUNK : 0x0057A050
void sub_0057A050()
{
    call<void()>(0x0057A050)();
}

//THUNK : 0x005CE850
void sub_005CE850()
{
    call<void()>(0x005CE850)();
}

//THUNK : 0x005D2850
void sub_005D2850()
{
    call<void()>(0x005D2850)();
}

//THUNK : 0x005CE8A0
void sub_005CE8A0()
{
    call<void()>(0x005CE8A0)();
}

//THUNK : 0x0057EF60
void ServiceResourceLoading()
{
    call<void()>(0x0057EF60)();
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

//THUNK : 0x00456940
void sub_00456940(std::uint32_t* a1)
{
    reinterpret_cast<void(__thiscall*)(std::uint32_t*)>(0x00456940)(a1);
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

//THUNK : 0x00431840
void InitNFSAnimEngine()
{
    call<void()>(0x00431840)();
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

//THUNK : 0x005CCD60
LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    return reinterpret_cast<LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM)>(0x005CCD60)(hWnd, Msg, wParam, lParam);
}

//THUNK : 0x005BF5A0
bool sub_5BF5A0()
{
    return call<bool()>(0x005BF5A0)();
}

//THUNK : 0x005B9750
void eInitD3D()
{
    call<void()>(0x005B9750)();
}

//THUNK : 0x005D21F0
void sub_5D21F0()
{
    call<void()>(0x005D21F0)();
}

//THUNK : 0x005CED60
void sub_5CED60()
{
    call<void()>(0x005CED60)();
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

//THUNK : 0x0057FB00
void sub_0057FB00()
{
    call<void()>(0x0057FB00)();
}

//THUNK : 0x004FF680
void InitLocalization()
{
    call<void()>(0x004FF680)();
}

//THUNK : 0x0057FB40
void LoadGlobalChunks()
{
    call<void()>(0x0057FB40)();
}

//THUNK : 0x0060C820
void InitStandardModels()
{
    call<void()>(0x0060C820);
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

//THUNK : 0x005CF960
void ShutdownTheGame()
{
    call<void()>(0x005CF960)();
}