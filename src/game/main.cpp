#include "main.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"
#include "Platform/Platform.hpp"
#include "RaceStarter/RaceStarter.hpp"
#include "GameFlowManager/GameFlowManager.hpp"
#include "ReplayManager/ReplayManager.hpp"

int& GlobalMemoryFile = *reinterpret_cast<int*>(0x00864F98);
int& QueuedFileNumReadsInProgress = *reinterpret_cast<int*>(0x008650F4);
int& WaitingQueuedFileList = *reinterpret_cast<int*>(0x00865220);
int& unused_init_0 = *reinterpret_cast<int*>(0x0086534C);
int& unused_init_1 = *reinterpret_cast<int*>(0x00865354);
_DWORD& dword_008709F8 = *reinterpret_cast<_DWORD*>(0x008709F8);
_DWORD& dword_0089CF48 = *reinterpret_cast<_DWORD*>(0x0089CF48);

//DONE : 0x004022C0
void TickLoadingScreen(void* unused)
{

}

//THUNK : 0x005811C0
void MainLoop()
{
    call<void()>(0x005811C0)();
}

//THUNK
void ServiceQueuedFiles()
{
    call<void()>(0x0057E800)();
}

//THUNK : 0x00452EC0
void sub_00452EC0()
{
    call<void()>(0x00452EC0)();
}

//THUNK : 0x0057CD70
void InitBigFiles()
{
    call<void()>(0x0057CD70)();
}

//THUNK : 0x005B7EA0
int sub_005B7EA0(_DWORD* a1, int a2, char** a3)
{
    return reinterpret_cast<int(__thiscall*)(_DWORD*, int, char**)>(0x005B7EA0)(a1, a2, a3);
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

//THUNK : 0x005736D0
void InitQueuedFiles()
{
    call<void()>(0x005736D0)();
}

//THUNK : 0x005D7AF0
void emEventManagerInit()
{
    call<void()>(0x005D7AF0)();
}

//THUNK : 0x005EFE30
int InitOnline(_DWORD* a1, int a2, char** a3)
{
    return reinterpret_cast<int(__thiscall*)(_DWORD*, int, char**)>(0x005EFE30)(a1, a2, a3);
}

//THUNK : 0x005BA7F0
void eMathInit()
{
    call<void()>(0x005BA7F0)();
}

//THUNK : 0x0048CD60
void eInitEngine()
{
    call<void()>(0x0048CD60)();
}

//THUNK : 0x004886E0
void afxInit()
{
    call<void()>(0x004886E0)();
}

//THUNK : 0x00570F80
void InitResourceLoader()
{
    call<void()>(0x00570F80)();
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

//THUNK : 0x0x00486910
void InitializeSoundLoad()
{
    call<void()>(0x00486910)();
}

//THUNK : 0x0060C680
void InitCarInfo()
{
    call<void()>(0x0060C680)();
}

//THUNK : 0x0060C820
void InitStandardModels()
{
    call<void()>(0x0060C820)();
}

//THUNK : 0x00534840
void InitFrontendDatabase()
{
    call<void()>(0x00534840)();
}

//THUNK : 0x0061C700
void InitCarLoader()
{
    call<void()>(0x0061C700)();
}

//THUNK : 0x0057B870
void InitStomper()
{
    call<void()>(0x0057B870)();
}

//THUNK : 0x0060BC70
void InitSpaceNodes()
{
    call<void()>(0x0060BC70)();
}

//THUNK : 0x004313B0
void InitAnimCtrls()
{
    call<void()>(0x004313B0)();
}

//THUNK : 0x00431380
void InitAnimBankSlotPool()
{
    call<void()>(0x00431380)();
}

//THUNK : 0x0x00431580
void InitAnimPartSlotPool()
{
    call<void()>(0x00431580)();
}

//THUNK : 0x0x004314E0
void InitAnimSkelSlotPool()
{
    call<void()>(0x004314E0)();
}

//DONE : 0x0057ED10
void InitializeEverything(int argc, char* argv[])
{
    void* v2 = 0; // ecx
    void* v3  = 0; // ecx
    void* v4 = 0; // ecx
    char* v5 = 0; // edx
    _DWORD* v6 = 0; // ecx
    _DWORD* v7 = 0; // eax

    InitPlatform();
    InitBigFiles();
    sub_005B7EA0(&dword_008709F8, argc, argv);
    bPListInit(0x1400);
    TickLoadingScreen(v2);
    InitJoylog();
    SeedRandomNumber();
    InitQueuedFiles();
    emEventManagerInit();
    InitOnline(&dword_0089CF48, argc, argv);
    eMathInit();
    eInitEngine();
    TickLoadingScreen(v3);
    afxInit();
    InitResourceLoader();
    InitJoystick();
    InitializeSoundDriver();
    FEngInitSystem();
    sub_0057FB00();
    InitLocalization();
    LoadGlobalChunks();
    InitializeSoundLoad();
    TickLoadingScreen(v4);
    InitCarInfo();
    InitStandardModels();
    InitFrontendDatabase();
    InitCarLoader();
    InitStomper();
    InitSpaceNodes();
    InitAnimCtrls();
    InitAnimBankSlotPool();
    InitAnimPartSlotPool();
    InitAnimSkelSlotPool();
    sub_00452EC0();
    unused_init_0 = 1;
    unused_init_1 = 0;

    while (QueuedFileNumReadsInProgress || (int*)WaitingQueuedFileList != &WaitingQueuedFileList)// IsQueuedFileBusy Inlined
    {
        ServiceQueuedFiles();
    }

    v5 = (char*)GlobalMemoryFile;
    if (GlobalMemoryFile)
    {
        v6 = *(_DWORD**)GlobalMemoryFile;
        v7 = *(_DWORD**)(GlobalMemoryFile + 4);
        *v7 = *(_DWORD*)GlobalMemoryFile;
        v6[1] = *(_DWORD*)v7;
        bFree(v5);
    }
    GlobalMemoryFile = 0;
}

//THUNK : 0x005CF960
void ShutdownTheGame()
{
    call<void()>(0x005CF960)();
}

//DONE : 0x00580E00
void _main(int argc, char* argv[])
{
    if (PlatformIsProcessRunning("speed2.exe", 1))
    {
        _exit(0);
    }

    InitializeEverything(argc, argv);

    if (ReplayManager::DetectJoylogReplaySnapshot())
    {
        RaceStarter::StartReplayRace();
    }
    else if (SkipFE)
    {
        RaceStarter::StartSkipFERace();
    }
    else
    {
        if (SetSingleFunction_Inlined)
        {
            SetSingleFunction_Inlined = 0;
        }

        SingleFunction_Inlined = (std::uint32_t*)BeginGameFlowLoadingFrontEnd;
        SingleFunctionState_Inlined = "LoadingFrontEnd";
    }

    MainLoop();
    ShutdownTheGame();
    _exit(0);
}

void __cdecl init(int argc, char* argv[])
{
    replace(0x00580E00, (std::uint32_t)_main);
}
