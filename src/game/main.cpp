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
#include "World/World.hpp"
#include "RaceCoordinator/RaceCoordinator.hpp"
#include "TrackStreamer/TrackStreamer.hpp"
#include "FEPackageManager/FEPackageManager.hpp"
#include "ReplayMenu/ReplayMenu.hpp"

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
SlotPool*& AcidActiveGroupSlotPool = GET((SlotPool*)0, 0x0082DA3C);
SlotPool*& AcidEmitterSlotPool = GET((SlotPool*)0, 0x0082DA40);
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
bool& ExitTheGameFlag = GET(BOOL, 0x00864F4C);
int& MainLoopTimingStartTime = GET(INT, 0x00864F44);
int& FrameCounter = GET(INT, 0x00865138);
int& TweakerStepWorld = GET(INT, 0x00890088);
int& NeedToPrepareWorldTimestep = GET(INT, 0x007FB728);
int& last_frame_count_8872 = GET(INT, 0x00866640);
float& WorldTimeElapsed = GET(FLOAT, 0x00865154);
float& RealTimeElapsed = GET(FLOAT, 0x00865198);
int& NumTextureCreatedThisFrame = GET(INT, 0x00864F50);
int& MainLoopTimingLimitFrameRate = GET(INT, 0x00864F48);
int& RealTimer = GET(INT, 0x008651AC);
bool& SkipMovies = GET(BOOL, 0x008650A8);
int& dword_00869084 = GET(INT, 0x00869084);
int& dword_008669F4 = GET(INT, 0x008669F4);
int& dword_00866A14 = GET(INT, 0x00866A14);
int& dword_00872ED8 = GET(INT, 0x00872ED8);
int& dword_00865488 = GET(INT, 0x00865488);
int& dword_00872F0C = GET(INT, 0x00872F0C);
int& dword_0086511C = GET(INT, 0x0086511C);
_DWORD& dword_00828770 = GET(UINT32, 0x00828770);
int& dword_00865120 = GET(INT, 0x00865120);
int& dword_00865118 = GET(INT, 0x00865118);
int& dword_008650CC = GET(INT, 0x008650CC);
int& dword_00872EE0 = GET(INT, 0x00872EE0);
int& dword_008650DC = GET(INT, 0x008650DC);
float& flt_0078435C = GET(FLOAT, 0x0078435C);
bool& byte_007FBE78 = GET(BOOL, 0x007FBE78);
auto& unused_MainLoop_func = *reinterpret_cast<int(**)()>(0x00865490);

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

//THUNK : 0x005809C0
void GenerateJoyEvents()
{
    call<void()>(0x005809C0)();
}

//DONE : 0x005BCFA0
void sub_005BCFA0()
{
    int v0; // edx

    v0 = dword_00872EE0;
    memset(&dword_00872ED8, 0, 0x3Cu);
    dword_00872F0C = v0;
}

//THUNK : 0x006F876C
void sub_006F876C(int a1, int a2, int a3, int a4, int a5)
{
    call<void(int, int, int, int, int)>(0x006F876C)(a1, a2, a3, a4, a5);
}

//DONE : 0x0057CB70
void sub_0057CB70(char* Str, int a2, int a3)
{
    bFile* v3; // eax
    bFile* v4; // esi
    int v5; // ecx
    int v6; // edx

    v3 = bOpen(Str, 2);
    v4 = v3;
    if (v3)
    {
        sub_006F876C(*((_DWORD*)v3 + 3), *((_DWORD*)v3 + 2), a2, a3, 100);
        v5 = *((_DWORD*)v4 + 1);
        v6 = a3 + *((_DWORD*)v4 + 2);
        *((_DWORD*)v4 + 2) = v6;
        if (v6 > v5)
            *((_DWORD*)v4 + 1) = v6;
        if (*((int*)v4 + 6) <= 0)
            bClose(v4, 1);
        else
            *((_DWORD*)v4 + 5) = 1;
    }
}

//DONE : 0x0057D860
void sub_0057D860(void* a1)
{
    _DWORD* v1; // edi
    int v2; // ecx
    _DWORD* v3; // esi

    if (dword_008650CC)
    {
        if (dword_008650DC)
        {
            v1 = (_DWORD*)(dword_008650DC + 12);
            v2 = *(_DWORD*)dword_008650DC - *(_DWORD*)(dword_008650DC + 12);
            v3 = (_DWORD*)dword_008650DC;
            if (v2 > 0)
            {
                sub_0057CB70((char*)(dword_008650DC + 36), dword_008650DC + 296, v2);
                *v1 = *v3;
                v3[1] = 0;
            }
        }
        dword_008650CC = 0;
        nullsub(a1);
    }
}

//DONE : 0x004C1210
void UpdateReplayUserInterface()
{
    if (gReplayMenu)
    {
        ReplayMenu::ServiceLoading(gReplayMenu);
    }
}

//THUNK : 0x0057EE00
void VerifyJoylogChecksum()
{
    call<void()>(0x0057EE00)();
}

//THUNK : 0x005EB390
void sub_005EB390()
{
    call<void()>(0x005EB390)();
}

//DONE : 0x0043BE20
float sub_0043BE20(int a1, int a2)
{
    int a2a; // [esp+8h] [ebp+8h]

    a2a = a2 - a1;
    if (a2a < 0)
        a2a = 0;
    return (double)(1 << dword_008284E4) * (double)a2a * flt_00828028;
}

//THUNK : 0x0057EAD0
void sub_0057EAD0(float a1)
{
    call<void(float)>(0x0057EAD0)(a1);
}

//THUNK : 0x00456940
void sub_00456940(std::uint32_t* a1)
{
    reinterpret_cast<void(__thiscall*)(std::uint32_t*)>(0x00456940)(a1);
}

//DONE : 0x005F00F0
bool sub_005F00F0(_DWORD* a1)
{
    return *((_BYTE*)a1 + 33) || dword_008669F4 > 0 || dword_00866A14 > 0;
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

//DONE : 0x005838A0
bool sub_005838A0()
{
    return dword_008669F4 > 0 || dword_00866A14 > 0;
}

//THUNK : 0x00585B20
void sub_00585B20()
{
    call<void()>(0x00585B20)();
}

//THUNK : 0x005877D0
void sub_005877D0()
{
    call<void()>(0x005877D0)();
}

//THUNK : 0x0058EBC0
void sub_0058EBC0()
{
    call<void()>(0x0058EBC0)();
}

//DONE : 0x0058F690
bool sub_0058F690()
{
    bool result; // al

    result = byte_007FBE78;
    if (byte_007FBE78)
    {
        if (dword_008669F4 > 0)
            sub_00585B20();
        if (dword_00866A14 > 0)
        {
            sub_005877D0();
            if (dword_00866A14 > 0)
                sub_0058EBC0();
        }
        result = RealTimer;
        dword_00869084 = RealTimer;
    }
    return result;
}

//THUNK : 0x0060AEE0
void sub_0060AEE0(_DWORD* a1, bool a2)
{
    reinterpret_cast<void(__thiscall*)(_DWORD*, bool)>(0x0060AEE0)(a1, a2);
}

//DONE : 0x005F0130
void __cdecl sub_005F0130()
{
    if (sub_005838A0())
    {
        sub_0058F690();
    }
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

//THUNK : 0x005811C0
void __cdecl MainLoop()
{
    void* v0; // esi
    int Ticker; // edi
    uint32_t* v2; // eax
    uint32_t* v3; // esi
    uint32_t* v4; // eax
    uint32_t* v5; // esi
    int v6; // eax
    int v8; // [esp+0h] [ebp-1Ch]
    int v9; // [esp+0h] [ebp-1Ch]
    float v10; // [esp+0h] [ebp-1Ch]
    float v11; // [esp+0h] [ebp-1Ch]
    void* v12; // [esp+4h] [ebp-18h]
    void* v13; // [esp+4h] [ebp-18h]
    void* v14; // [esp+4h] [ebp-18h]
    void* v15; // [esp+4h] [ebp-18h]
    void* v16; // [esp+4h] [ebp-18h]
    void* v17; // [esp+4h] [ebp-18h]
    void* v18; // [esp+4h] [ebp-18h]
    bool v19; // [esp+10h] [ebp-Ch]
    float a2; // [esp+18h] [ebp-4h]

    Ticker = bGetTicker();
    if (!ExitTheGameFlag)
    {
        v12 = v0;
        do
        {
            MainLoopTimingStartTime = bGetTicker();
            sub_005BCFA0();
            last_frame_count_8872 = FrameCounter;
            sub_0057D860(v12);
            v2 = SingleFunction_Inlined;
            if (SingleFunction_Inlined)
            {
                do
                {
                    v3 = v2;
                    v8 = dword_00865488;
                    SingleFunction_Inlined = 0;
                    dword_00865488 = 0;
                    SingleFunctionState_Inlined = 0;
                    ((void(__cdecl*)(int))v2)(v8);
                    v2 = SingleFunction_Inlined;
                } while (SingleFunction_Inlined != v3 && SingleFunction_Inlined);
            }
            if (unused_MainLoop_func)               // Never assgiend to?
                unused_MainLoop_func();
            UpdateReplayUserInterface();
            if (pRaceCoordinator)
            {
                RaceCoordinator::ExecuteQueuedMessages(pRaceCoordinator);
                RaceCoordinator::RCSendMessage(pRaceCoordinator, 3, 0);
            }
            v4 = SingleFunction_Inlined;
            if (SingleFunction_Inlined)
            {
                do
                {
                    v5 = v4;
                    v9 = dword_00865488;
                    SingleFunction_Inlined = 0;
                    dword_00865488 = 0;
                    SingleFunctionState_Inlined = 0;
                    ((void(__cdecl*)(int))v4)(v9);
                    v4 = SingleFunction_Inlined;
                } while (SingleFunction_Inlined != v5 && SingleFunction_Inlined);
            }
            if (unused_MainLoop_func)
                unused_MainLoop_func();
            nullsub(v13);
            if (GameFlowManagerState != 6)
                VerifyJoylogChecksum();
            sub_005EB390();
            if (pReplayManager)
                ReplayManager::DoFancyJoylogDebugging(pReplayManager);
            v6 = bGetTicker();
            v10 = sub_0043BE20(Ticker, v6) * flt_0078435C;
            sub_0057EAD0(v10);
            Ticker = bGetTicker();
            sub_00456940(&dword_00828770);
            v19 = 1;

#if DEBUG
            //non matching
            static char callback[32];
            static char prev_callback[32];
            std::strcpy(callback, GameFlowCallback);

            if (std::strcmp(callback, prev_callback))
            {
                println("%s", callback);
            }

            std::strcpy(prev_callback, callback);
#endif

            if (!sub_005F00F0(&dword_0089CF48) && pRaceCoordinator && *(_DWORD*)pRaceCoordinator == 6)
            {
                WorldTimeElapsed = World::GetTimestep(pCurrentWorld, 0.0);
            }
            else
            {
                if (GameFlowManagerState == 6)
                {
                    World::UpdateWorldPaused(pCurrentWorld);
                    if (World::IsWorldPaused(pCurrentWorld) || *(_DWORD*)pRaceCoordinator == 1)
                    {
                        WorldTimeElapsed = World::GetTimestep(pCurrentWorld, 0.0);
                        NeedToPrepareWorldTimestep = 0;
                        GenerateJoyEvents();
                        sub_005F1390(pCurrentWorld);
                    }
                    else
                    {
                        ReplayManager::BeginFrame(pReplayManager);
                        if (*((_DWORD*)pReplayManager + 7))
                        {
                            WorldTimeElapsed = World::GetTimestep(pCurrentWorld, 0.0);
                            NeedToPrepareWorldTimestep = 0;
                            GenerateJoyEvents();
                        }
                        else
                        {
                            v11 = sub_005EA360(pCurrentWorld);
                            a2 = World::GetTimestep(pCurrentWorld, v11);
                            WorldTimeElapsed = a2;
                            NeedToPrepareWorldTimestep = 0;
                            GenerateJoyEvents();
                            sub_005F0130();
                            World::DoTimestep(pCurrentWorld, a2);
                            v19 = 0;
                        }
                        ReplayManager::EndFrame(pReplayManager);
                    }

                    if (TweakerStepWorld)
                    {
                        TweakerStepWorld = 0;
                        nullsub(v14);                       // bRefreshTweaker
                    }

                    goto LABEL_38;
                }
                WorldTimeElapsed = RealTimeElapsed;
            }

            NeedToPrepareWorldTimestep = 0;
            GenerateJoyEvents();
        LABEL_38:
            nullsub(v14);                             // ServicePlatform
            nullsub(v15);                             // ServiceScenery
            sub_0060AEE0(&dword_0089CF48, v19);
            FEngUpdate();
            UpdatePlayersNonGameState();
            UpdateCameraMovers();
            if (g_pEAXSound)
                EAXSound::Update(g_pEAXSound, RealTimeElapsed);
            UpdatePortRumblers();
            UpdateCameraShakers();
            TrackStreamer::ServiceNonGameState((TrackStreamer*)&TheTrackStreamer);
            NumTextureCreatedThisFrame = 0;
            ServiceResourceLoading();
            sub_005CE850();
            sub_005CE8A0();
            sub_005D2850();
            nullsub(v16);
            nullsub(v17);
            sub_0057A050();
            AdvanceWorldTime();
            if (!v19)
                sub_005F0140();
            nullsub(v18);
            MainLoopTimingLimitFrameRate = bGetTicker();
            DisplayDebugScreenPrints();
            if (dword_0086511C)                     // Possibly gutted memory watchers from console versions
            {
                dword_0086511C = 0;
                nullsub(v12);
            }
            if (dword_00865120)                     // Unused
            {
                dword_00865120 = 0;
                nullsub(v12);
            }
            if (dword_00865118)                     // Unused
            {
                dword_00865118 = 0;
                nullsub(v12);
            }
            PlatformPresent();
        } while (!ExitTheGameFlag);
    }
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
    AcidActiveGroupSlotPool = bNewSlotPool(44, 400, "AcidActiveGroupSlotPool", 0);
    AcidEmitterSlotPool = bNewSlotPool(208, 250, "AcidEmitterSlotPool", 0);
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

#if DEBUG
    //non matching
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
    InitOnline((std::uint32_t*)&dword_0089CF48, argc, argv);
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
#ifdef DEBUG
    //non matching
    SkipMovies = true;
#endif

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
    replace(0x00601A60, (std::uint32_t)World::GetTimestep);
}
