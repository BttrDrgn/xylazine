#include "main.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"
#include "Platform/Platform.hpp"
#include "RaceStarter/RaceStarter.hpp"
#include "GameFlowManager/GameFlowManager.hpp"
#include "ReplayManager/ReplayManager.hpp"
#include "SlotPool/SlotPool.hpp"
#include "RealFile/RealFile.hpp"
#include "DragCamera/DragCamera.hpp"
#include "cFrontendDatabase/cFrontendDatabase.hpp"
#include "eModel/eModel.hpp"
#include "EAXSound/EAXSound.hpp"

int& GlobalMemoryFile = *reinterpret_cast<int*>(0x00864F98);
int& QueuedFileNumReadsInProgress = *reinterpret_cast<int*>(0x008650F4);
int& WaitingQueuedFileList = *reinterpret_cast<int*>(0x00865220);
int& unused_init_0 = *reinterpret_cast<int*>(0x0086534C);
int& unused_init_1 = *reinterpret_cast<int*>(0x00865354);
_DWORD& dword_008709F8 = *reinterpret_cast<_DWORD*>(0x008709F8);
_DWORD& dword_0089CF48 = *reinterpret_cast<_DWORD*>(0x0089CF48);
char*& dword_00865128 = *reinterpret_cast<char**>(0x00865128);
bool& WindowedMode = *reinterpret_cast<bool*>(0x0087098C);
int& CarPartModelPool = *reinterpret_cast<int*>(0x008A1BE4);
int& AcidActiveGroupSlotPool = *reinterpret_cast<int*>(0x0082DA3C);
int& AcidEmitterSlotPool = *reinterpret_cast<int*>(0x0082DA40);
SlotPool*& SpaceNodeSlotPool = GET((SlotPool*)0, 0x008A1BCC);
SlotPool*& AnimCtrlSlotPool = GET((SlotPool*)0, 0x00827B54);
bool& AnimBankSlotPoolInitialized = GET(BOOL, 0x00827B50);
SlotPool*& AnimBankSlotPool = GET((SlotPool*)0, 0x00827B4C);
bool& AnimPartSlotPoolInitialized = GET(BOOL, 0x00827B68);
SlotPool*& AnimPartSlotPool = GET((SlotPool*)0, 0x00827B64);
bool& AnimSkelSlotPoolInitialized = GET(BOOL, 0x00827B60);
SlotPool*& AnimSkelSlotPool = GET((SlotPool*)0, 0x00827B5C);
SlotPool*& ResourceFileSlotPool = GET((SlotPool*)0, 0x00864F78);
SlotPool*& EventSlotPool = GET((SlotPool*)0, 0x00883E38);
SlotPool*& EventHandlerSlotPool = GET((SlotPool*)0, 0x00883E3C);
SlotPool*& QueuedFileSlotPool = GET((SlotPool*)0, 0x008650F0);

//DONE : 0x004022C0
void nullsub(void* unused)
{

}

//While this can be macroed or just a normal call, I have opted to call the game's malloc
//incase for whatever reason CRT mismatch causes issues
//THUNK : 0x0075C6C8
void* j__malloc(size_t size)
{
    return call<void*(size_t)>(0x00575620)(size);
}

//THUNK : 0x005811C0
void MainLoop()
{
    call<void()>(0x005811C0)();
}

//THUNK : 0x0057E800
void ServiceQueuedFiles()
{
    call<void()>(0x0057E800)();
}

//DONE : 0x0057CD70
void InitBigFiles()
{
    bFile* v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = bOpen("NFSUNDER\\ZDIR.BIN", 1);
    if (v0)
    {
        v1 = *((_DWORD*)v0 + 1);
        if (*((int*)v0 + 6) <= 0)
            bClose(v0, 1);
        else
            *((_DWORD*)v0 + 5) = 1;
        if (v1 != -1)
        {
            v2 = bInitDisculatorDriver("NFSUNDER\\ZDIR.BIN", "NFSUNDER\\ZZDATA");
            if (v2)
            {
                RealFile::AddDevice(v2);
                RealFile::AddSearchLocation("discu:", 1);
            }
        }
    }
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

//DONE : 0x005736D0
void InitQueuedFiles()
{
    QueuedFileSlotPool = bNewSlotPool(124, 100, "QueuedFileSlotPool", 0);
}

//DONE : 0x005D7AF0
void emEventManagerInit()
{
    EventSlotPool = bNewSlotPool(36, 60, "EventSlotPool", 0);
    EventHandlerSlotPool = bNewSlotPool(24, 20, "EventHandlerSlotPool", 0);
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

//DONE : 0x004886E0
void afxInit()
{
    AcidActiveGroupSlotPool = (int)bNewSlotPool(44, 400, "AcidActiveGroupSlotPool", 0);
    AcidEmitterSlotPool = (int)bNewSlotPool(208, 250, "AcidEmitterSlotPool", 0);
    *(_DWORD*)(AcidActiveGroupSlotPool + 20) &= 0xFFFFFFFE;
    *(_DWORD*)(AcidActiveGroupSlotPool + 20) &= 0xFFFFFFFD;
}

//DONE : 0x00570F80
void InitResourceLoader()
{
    ResourceFileSlotPool = bNewSlotPool(240, 80, "ResourceFileSlotPool", 0);
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

//DONE : 0x00486910
void InitializeSoundLoad()
{
    EAXSound::InitializeFromAemsManager(g_pEAXSound);
}

//DONE : 0x0060C680
void InitCarRender()
{
    CarPartModelPool = (int)bNewSlotPool(24, 1024, "CarPartModelPool", 0);
}

//TODO : 0x0060C820
void InitStandardModels()
{
#if 0
    unsigned int v0;

    eModel::Init(&StandardCubeModel, 0xC7395A8);
    v0 = bStringHash("DEBUG_LOD_CUBE");
    eModel::Init(&StandardDebugModel, v0);
#else
    call<void()>(0x0060C820);
#endif
}

//DONE : 0x00534840
void InitFrontendDatabase()
{
    cFrontendDatabase::Default(&FEDatabase);
}

//THUNK : 0x0061C700
void InitCarLoader()
{
    call<void()>(0x0061C700)();
}

//DONE : 0x0057B870
void InitStomper()
{
    char* v0;
    char* v1;

    v0 = (char*)malloc(0xCu);
    v1 = v0;
    if (v0)
    {
        *v0 = 1;
        *(char**)((_DWORD*)v0 + 1) = (char*)malloc(0x400u);
        *((_DWORD*)v1 + 2) = 0;
        dword_00865128 = v1;
    }
    else
    {
        dword_00865128 = 0;
    }
}

//DONE : 0x0060BC70
void InitSpaceNodes()
{
    SpaceNodeSlotPool = bNewSlotPool(240, 224, "SpaceNodeSlotPool", 0);
}

//DONE : 0x004313B0
void InitAnimCtrls()
{
    AnimCtrlSlotPool = bNewSlotPool(128, 64, "AnimCtrlSlotPool", 0);
}

//DONE : 0x00431380
void InitAnimBankSlotPool()
{
    if (!AnimBankSlotPoolInitialized)
    {
        AnimBankSlotPool = bNewSlotPool(60, 81, "Anim_CNFSAnimBank_SlotPool", 0);
        AnimBankSlotPoolInitialized = 1;
    }
}

//DONE : 0x00431580
void InitAnimPartSlotPool()
{
    if (!AnimPartSlotPoolInitialized)
    {
        AnimPartSlotPool = bNewSlotPool(20, 8, "Anim_CAnimPart_SlotPool", 0);
        AnimPartSlotPoolInitialized = 1;
    }
}

//DONE : 0x004314E0
void InitAnimSkelSlotPool()
{
    if (!AnimSkelSlotPoolInitialized)
    {
        AnimSkelSlotPool = bNewSlotPool(40, 8, "Anim_CAnimSkeleton_SlotPool", 0);
        AnimSkelSlotPoolInitialized = 1;
    }
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

#if !defined(MATCHING) || DEBUG
    WindowedMode = true;
#endif

    InitPlatform();
    InitBigFiles();
    sub_005B7EA0(&dword_008709F8, argc, argv);
    bPListInit(0x1400);
    nullsub(v2);
    InitJoylog();
    SeedRandomNumber();
    InitQueuedFiles();
    emEventManagerInit();
    InitOnline(&dword_0089CF48, argc, argv);
    eMathInit();
    eInitEngine();
    nullsub(v3);
    afxInit();
    InitResourceLoader();
    InitJoystick();
    InitializeSoundDriver();
    FEngInitSystem();
    sub_0057FB00();
    InitLocalization();
    LoadGlobalChunks();
    InitializeSoundLoad();
    nullsub(v4);
    InitCarRender();
    InitStandardModels();
    InitFrontendDatabase();
    InitCarLoader();
    InitStomper();
    InitSpaceNodes();
    InitAnimCtrls();
    InitAnimBankSlotPool();
    InitAnimPartSlotPool();
    InitAnimSkelSlotPool();
    DragCamera::Init();
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
#ifdef MATCHING
    if (PlatformIsProcessRunning("speed2.exe", 1))
    {
#else
    if (PlatformIsProcessRunning("BB2.exe", 1))
    {
#endif
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
