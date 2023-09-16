#include "main.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"
#include "Platform/Platform.hpp"
#include "Platform/bFile.hpp"
#include "RaceStarter/RaceStarter.hpp"
#include "GameFlowManager/GameFlowManager.hpp"
#include "ReplayManager/ReplayManager.hpp"
#include "SlotPool/SlotPool.hpp"
#include "RealFile/RealFile.hpp"
#include "RealSystem/RealSystem.hpp"
#include "DragCamera/DragCamera.hpp"
#include "cFrontendDatabase/cFrontendDatabase.hpp"
#include "eModel/eModel.hpp"
#include "EAXSound/EAXSound.hpp"
#include "World/World.hpp"
#include "RaceCoordinator/RaceCoordinator.hpp"
#include "TrackStreamer/TrackStreamer.hpp"
#include "FEPackageManager/FEPackageManager.hpp"
#include "ReplayMenu/ReplayMenu.hpp"
#include "DemoDiscManager/DemoDiscManager.hpp"
#include "OnlineManager/OnlineManager.hpp"
#include "eModel/eModel.hpp"
#include "Stomper/Stomper.hpp"
#include "Player/Player.hpp"
#include "ResourceFile/ResourceFile.hpp"
#include "DragCameraManager/DragCameraManager.hpp"
#include "thunks.hpp"
#include "variables.hpp"

//DONE : 0x004022C0
void nullsub(void* unused) {}

//nullsub
//DONE : 0x004022C0
void _return() {}

//DONE : 0x005BCFA0
void sub_5BCFA0()
{
    int v0;

    v0 = dword_00872EE0;
    memset(&dword_00872ED8, 0, 0x3Cu);
    dword_00872F0C = v0;
}

//DONE : 0x0057CB70
bFile* sub_57CB70(char* path, int a2, int a3)
{
    bFile* result;
    bFile* v4;
    int v5;
    int v6;

    result = bFile::bOpen(path, 2);
    v4 = result;
    if (result)
    {
        FILESYS_writesync(result[1].unk_4, result[1].unk_0, a2, a3, 100);
        v5 = v4->unk_4;
        v6 = a3 + v4[1].unk_0;
        v4[1].unk_0 = v6;
        if (v6 > v5)
            v4->unk_4 = v6;
        result = (bFile*)v4[3].unk_0;
        if ((int)result <= 0)
            result->bClose(1);
        else
            v4[2].unk_4 = 1;
    }
    return result;
}

//DONE : 0x0057D860
void sub_57D860(void* a1)
{
    _DWORD* v1;
    int v2;
    _DWORD* v3;

    if (dword_008650CC)
    {
        if (dword_008650DC)
        {
            v1 = (_DWORD*)(dword_008650DC + 12);
            v2 = *(_DWORD*)dword_008650DC - *(_DWORD*)(dword_008650DC + 12);
            v3 = (_DWORD*)dword_008650DC;
            if (v2 > 0)
            {
                sub_57CB70((char*)(dword_008650DC + 36), dword_008650DC + 296, v2);
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
        gReplayMenu->ServiceLoading();
    }
}

//DONE : 0x0043BE20
float sub_43BE20(int a1, int a2)
{
    int a2a;

    a2a = a2 - a1;
    if (a2a < 0)
        a2a = 0;
    return (double)(1 << dword_008284E4) * (double)a2a * flt_00828028;
}

//DONE : 0x005F00F0
bool sub_5F00F0(_DWORD* a1)
{
    return *((_BYTE*)a1 + 33) || dword_8669F4 > 0 || dword_866A14 > 0;
}

//DONE : 0x005838A0
bool sub_5838A0()
{
    return dword_8669F4 > 0 || dword_866A14 > 0;
}

//DONE : 0x005F0140
void FrameRateLoop()
{
    if (sub_5838A0())
    {
        sub_58C220();
    }
}

//DONE : 0x0058F690
void sub_58F690()
{
    if (byte_7FBE78)
    {
        if (dword_8669F4 > 0)
        {
            sub_585B20();
        }

        if (dword_866A14 > 0)
        {
            sub_5877D0();

            if (dword_866A14 > 0)
            {
                sub_58EBC0();
            }
        }
        dword_869084 = RealTimer;
    }
}

//DONE : 0x005F0130
void sub_5F0130()
{
    if (sub_5838A0())
    {
        sub_58F690();
    }
}

//DONE : 0x005CEC80
void sub_5CEC80()
{
    sub_5CE4C0();
    sub_5BF1C0();
}

//DONE : 0x0057A050
void AdvanceRealTime()
{
    double temp; // st7
    int result; // eax

    temp = RealTimeElapsed + RealTimeElapsedFrame;
    *&result = (ExpectedFrameRate * temp);
    RealTimeElapsedFrame = temp - result * ExpectedFrameTime;

    if (!result)
    {
        result = 1;
    }

    RealTimeFrames += result;
    RealTimeFramesElapsed = result;
    gCardiogram = RealTimeFrames;
    RealTimer += (RealTimeElapsed * flt_784264 + flt_784260);
    ++RealLoopCounter;
}

//DONE : 0x005811C0
void __cdecl MainLoop()
{
    void* v0;
    int ticker;
    uint32_t* v2;
    uint32_t* v3;
    uint32_t* v4;
    uint32_t* v5;
    int v6;
    int v8;
    int v9;
    float v10;
    float v11;
    void* v12;
    void* v13;
    void* v14;
    void* v15;
    void* v16;
    void* v17;
    void* v18;
    bool v19;
    float a2;

    ticker = bGetTicker();
    if (!ExitTheGameFlag)
    {
        v12 = v0;
        do
        {
            MainLoopTimingStartTime = bGetTicker();
            sub_5BCFA0();
            last_frame_count_8872 = FrameCounter;
            sub_57D860(v12);
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
                pRaceCoordinator->ExecuteQueuedMessages();
                pRaceCoordinator->RCSendMessage(3, 0);
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
            {
                unused_MainLoop_func();
            }

            nullsub(v13);

            if (GameFlowManagerState != 6)
            {
                VerifyJoylogChecksum();
            }

            DetermineAllPlayersInputModes();

            if (pReplayManager)
            {
                pReplayManager->DoFancyJoylogDebugging();
            }

            v6 = bGetTicker();
            v10 = sub_43BE20(ticker, v6) * flt_0078435C;
            sub_57EAD0(v10);
            ticker = bGetTicker();
            TheDragCameraManager->Update();
            v19 = 1;

#if DEBUG
            static char callback[32];
            static char prev_callback[32];
            std::strcpy(callback, GameFlowCallback);

            if (std::strcmp(callback, prev_callback))
            {
                println("%s", callback);
            }

            std::strcpy(prev_callback, callback);
#endif

            if (!sub_5F00F0(&dword_0089CF48) && pRaceCoordinator && pRaceCoordinator->State == 6)
            {
                WorldTimeElapsed = pCurrentWorld->GetTimestep(0.0);
            }
            else
            {
                if (GameFlowManagerState == 6)
                {
                    pCurrentWorld->UpdateWorldPaused();

                    if (pCurrentWorld->IsWorldPaused() || pRaceCoordinator->State == 1)
                    {
                        WorldTimeElapsed = pCurrentWorld->GetTimestep(0.0);
                        NeedToPrepareWorldTimestep = 0;
                        GenerateJoyEvents();
                        sub_5F1390(pCurrentWorld);
                    }
                    else
                    {
                        pReplayManager->BeginFrame();
                        if (pReplayManager->unk_28)
                        {
                            WorldTimeElapsed = pCurrentWorld->GetTimestep(0.0);
                            NeedToPrepareWorldTimestep = 0;
                            GenerateJoyEvents();
                        }
                        else
                        {
                            v11 = sub_5EA360(pCurrentWorld);
                            a2 = pCurrentWorld->GetTimestep(v11);
                            WorldTimeElapsed = a2;
                            NeedToPrepareWorldTimestep = 0;
                            GenerateJoyEvents();
                            sub_5F0130();
                            pCurrentWorld->DoTimestep(a2);
                            v19 = 0;
                        }
                        pReplayManager->EndFrame();
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
            sub_60AEE0(&dword_0089CF48, v19);
            FEngUpdate();
            UpdatePlayersNonGameState();
            UpdateCameraMovers();

            if (g_pEAXSound)
            {
                g_pEAXSound->EAXSound::Update(RealTimeElapsed);
            }

            UpdatePortRumblers();
            UpdateCameraShakers();
            TheTrackStreamer.ServiceNonGameState();
            NumTextureCreatedThisFrame = 0;
            ServiceResourceLoading();
            sub_5CE850();
            sub_5CE8A0();
            sub_5D2850();
            nullsub(v16);
            nullsub(v17);
            AdvanceRealTime();
            AdvanceWorldTime();

            if (!v19)
            {
                FrameRateLoop();
            }

            nullsub(v18);
            MainLoopTimingLimitFrameRate = bGetTicker();
            DisplayDebugScreenPrints();
            if (PrintOneShotProfile)                     // Possibly gutted memory watchers from console versions
            {
                PrintOneShotProfile = 0;
                nullsub(v12);
            }
            if (PrintAccumulatedProfile)                     // Unused
            {
                PrintAccumulatedProfile = 0;
                nullsub(v12);
            }
            if (ClearAccumulatedProfile)                     // Unused
            {
                ClearAccumulatedProfile = 0;
                nullsub(v12);
            }
            sub_5CEC80();
        } while (!ExitTheGameFlag);
    }
}

//DONE : 0x0057CD70
void InitBigFiles()
{
    bFile* v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = bFile::bOpen("NFSUNDER\\ZDIR.BIN", 1);
    if (v0)
    {
        v1 = v0->unk_4;

        if (v0->unk_24 <= 0)
            v0->bClose(1);
        else
            v0->unk_20 = 1;
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

//DONE : 0x005BA7F0
void eMathInit()
{
    memset(&eMathZeroMatrix, 0, 0x40u);
    eMathIdentityMatrix = 1.0;
    dword_872E94 = 0;
    dword_872E98 = 0;
    dword_872E9C = 0;
    dword_872EA0 = 0;
    dword_872EA4 = 1.0;
    dword_872EA8 = 0;
    dword_872EAC = 0;
    dword_872EB0 = 0;
    dword_872EB4 = 0;
    dword_872EB8 = 1.0;
    dword_872EBC = 0;
    dword_872EC0 = 0;
    dword_872EC4 = 0;
    dword_872EC8 = 0;
    dword_872ECC = 1.0;
}

//DONE : 0x00488EF0
void eInitModels()
{
    eModelSlotPool = bNewSlotPool(24, 5000, "eModelSlotPool", 0);
}

//DONE : 0x0048B1F0
void eInitTextures()
{
    TexturePackSlotPool = bNewSlotPool(124, 128, "TexturePackSlotPool", 0);
}

//DONE : 0x005BB700
void elInitPlat()
{
    eLightMaterialPlatInfoSlotPool = bNewSlotPool(128, 220, "eLightMaterialPlatInfoSlotPool", 0);
}

//DONE : 0x005BF610
void PCGetResolution(LONG* width, LONG* height)
{
    switch (*&g_RacingResolution)
    {
    case 0:
        *width = 640;
        *height = 480;
        break;
    case 1:
        *width = 800;
        *height = 600;
        break;
    case 2:
        *width = 1024;
        *height = 768;
        break;
    case 3:
        *width = 1280;
        *height = 960;
        break;
    case 4:
        *width = 1280;
        *height = 1024;
        break;
    case 5:
        *width = 1600;
        *height = 1200;
        break;
    default:
        return;
    }
}

//DONE : 0x005B9A60
void PCEnableD3DFeatures(int width, int height)
{
    ZeroMemory(&D3D_PP, sizeof(D3D_PP));

    if (PCWindowed)
    {
        GetWindowRect(PCHwnd, &PCWindowRect);
        GetClientRect(PCHwnd, &PCClientRect);
    }

    D3D_PP.Windowed = PCWindowed;
    D3D_PP.BackBufferWidth = width;
    D3D_PP.BackBufferHeight = height;

    if ((D3D_DEVICE_CAPS.Caps3 & 0x20) != 0 || (D3D_PP.SwapEffect = D3DSWAPEFFECT_COPY, dword_8709A0))
    {
        D3D_PP.SwapEffect = D3DSWAPEFFECT_DISCARD;
    }

    D3D_PP.BackBufferFormat = D3D_BACK_BUF_FMT;
    D3D_PP.AutoDepthStencilFormat = D3D_DEPTH_STENCIL != 0 ? D3DFMT_D16 : D3DFMT_D24S8;
    D3D_PP.PresentationInterval = *&g_VSyncOn != 0 ? 1 : 0x80000000;
    D3D_PP.hDeviceWindow = PCHwnd;
    D3D_PP.EnableAutoDepthStencil = 1;
    D3D_PP.Flags = 0;
    ScreenHeight = height;
    ScreenWidth = width;

    if (*&g_FSAALevel <= 0)
    {
        D3D_PP.MultiSampleType = D3DMULTISAMPLE_NONE;
        D3D_PP.MultiSampleQuality = 0;
    }
    else
    {
        D3D_PP.MultiSampleType = D3DMULTISAMPLE_NONMASKABLE;
        D3D_PP.MultiSampleQuality = *&g_FSAALevel;
    }
}   

//DONE : 0x005B9B70
void PCCreateD3DDevice()
{
    HRESULT results; // esi

    results = D3D->CreateDevice(D3D_ADAPTER_DEFAULT, D3DDEVTYPE_HAL, PCHwnd, D3DCREATE_MIXED_VERTEXPROCESSING, &D3D_PP, &D3D_DEVICE);

    if (results != D3D_OK)
    {
        results = D3D->CreateDevice(D3D_ADAPTER_DEFAULT, D3DDEVTYPE_HAL, PCHwnd, 32, &D3D_PP, &D3D_DEVICE);
    }

    if (results == D3D_OK)
    {
        D3D_DEVICE->BeginScene();
        D3D_DEVICE->Clear(0, 0, 7, 0, 0x3F800000, 0);
        D3D_DEVICE->EndScene();
        D3D_DEVICE->Present(0, 0, 0, 0);
    }
}

//TODO : 0x005BE690
void sub_5BE690()
{
    if (dword_8764D0 < *&g_CarEnvironmentMapEnable) *&g_CarEnvironmentMapEnable = dword_8764D0;
    if (dword_8764D4 < *&g_CarEnvironmentMapUpdateData) *&g_CarEnvironmentMapUpdateData = dword_8764D4;
    if (dword_8764D8 < *&g_CarShadowEnable) *&g_CarShadowEnable = dword_8764D8;
    if (dword_8764DC < *&g_CarHeadlightEnable) *&g_CarHeadlightEnable = dword_8764DC;
    if (dword_8764E0 < *&g_CarLightingEnable) *&g_CarLightingEnable = dword_8764E0;
    if (dword_8764E4 < *&g_CarDamageEnable) *&g_CarDamageEnable = dword_8764E4;
    if (dword_8764E8 < *&g_CrowdEnable) *&g_CrowdEnable = dword_8764E8;
    if (dword_8764EC < *&g_RoadReflectionEnable) *&g_RoadReflectionEnable = dword_8764EC;
    if (dword_8764F0 < *&g_FogEnable) *&g_FogEnable = dword_8764F0;
    if (dword_8764F4 < *&g_MotionBlurEnable) *&g_MotionBlurEnable = dword_8764F4;
    if (dword_8764F8 < *&g_LightStreaksEnable) *&g_LightStreaksEnable = dword_8764F8;
    if (dword_8764FC < *&g_LightGlowEnable) *&g_LightGlowEnable = dword_8764FC;
    if (dword_876500 < *&g_AnimatedTextureEnable) *&g_AnimatedTextureEnable = dword_876500;
    if (dword_876504 < *&g_ParticleSystemEnable) *&g_ParticleSystemEnable = dword_876504;
    if (dword_876508 < *&g_DepthOfFieldEnable) *&g_DepthOfFieldEnable = dword_876508;
    if (dword_87650C < *&g_WorldLodLevel) *&g_WorldLodLevel = dword_87650C;
    if (dword_876510 < *&g_CarLodLevel) *&g_CarLodLevel = dword_876510;
    if (PCAAQuality < *&g_FSAALevel) *&g_FSAALevel = PCAAQuality;
    if (dword_876518 < *&g_BleachByPassEnable) *&g_BleachByPassEnable = dword_876518;
    if (dword_876514 < *&g_OverBrightEnable) *&g_OverBrightEnable = dword_876514;
    if (dword_876524 < *&g_HorizonFogEnable) *&g_HorizonFogEnable = dword_876524;
    if (dword_876528 < *&g_RainEnable) *&g_RainEnable = dword_876528;
    if (dword_87652C < dword_870D14) dword_870D14 = dword_87652C;
    if (dword_876530 < *&g_TextureFiltering) *&g_TextureFiltering = dword_876530;

    /*int v0 = *&g_RacingResolution;
    if (!dword_86E880[*&g_RacingResolution] && *&g_RacingResolution >= 0)
    {
        while (!dword_86E880[v0])
        {
            if (--v0 < 0)
                return;
        }
        *&g_RacingResolution = v0;
    }*/
}

//DONE : 0x005BCFF0
void InitSlotPools()
{
    eAnimTextureSlotPool = bNewSlotPool(4, 256, "eAnimTextureSlotPool", 0);
    eAnimTextureSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;

    eTextureBucketSlotPool = bNewSlotPool(32, 1024, "eTextureBucketSlotPool", 0);
    eTextureBucketSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;

    eDataRenderSlotPool = bNewSlotPool(44, 4096, "eMeshRender", 0);
    eDataRenderSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;
}

//DONE : 0x005BDFB0
void InitStripSlotPool()
{
    eStripSlotPool = bNewSlotPool(1540, 32, "eStripSlotPool", 0);
    eStripSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;
}

//TODO : 0x005BB220
void sub_5BB220(IDirect3DVertexBuffer9* this_, int* a2, int* a3)
{
    //call<void(IDirect3DVertexBuffer9*, int*, int*)>(0x005BB220)(this_, a2, a3);
    reinterpret_cast<void(__thiscall*)(IDirect3DVertexBuffer9*, int*, int*)>(0x005BB220)(this_, a2, a3);
}

//DONE : 0x005BF6E0
void DinputInit(LPDIRECTINPUTDEVICE8A* device)
{
    bool data_format_set; // sf
    LPDIRECTINPUTDEVICE8A device_2; // eax

    if (PCDirectInput)
    {
        if (PCDirectInput->CreateDevice(GUID_SysMouse, device, 0) < 0)
        {
            *device = 0;
        }

        data_format_set = (*device)->SetDataFormat(&c_dfDIMouse2) < 0;

        device_2 = *device;

        if (data_format_set)
        {
            if (device_2)
            {
                device_2->Unacquire();
            }

            if (*device)
            {
                (*device)->Release();
                *device = 0;
            }
        }
        else
        {
            device_2->SetCooperativeLevel(PCHwnd, 6);
            (*device)->Acquire();
        }
    }
}

//DONE : 0x004A9330
bool IsLoadingScreenUp()
{
    return FEngIsPackagePushed("PC_Loading.fng");
}

//DONE : 0x005CCD60
LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    //return reinterpret_cast<LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM)>(0x005CCD60)(hWnd, Msg, wParam, lParam);
    int result; // eax

    if (Msg <= WM_CHAR)
    {
        if (Msg == WM_CHAR)
        {
            sub_55DBD0(wParam);
            sub_5C8320(wParam);
        }
        else
        {
            if (Msg <= WM_CLOSE)
            {
                if (Msg != WM_CLOSE)
                {
                    switch (Msg)
                    {
                    case WM_DESTROY:
                        CreateRegistrySettings();
                        PostQuitMessage(0);
                        result = 0;
                        break;
                    case WM_SIZE:
                        PostMessageA(hWnd, 0xFu, 0, 0);
                        WParam = !IsIconic(hWnd);
                        return 0;
                    case WM_ACTIVATE:
                        if (g_pEAXSound && (wParam == 0) != IsLostFocus)
                        {
                            if (wParam)
                            {
                                g_pEAXSound->ExitPauseMenu(ePAUSE_ERROR);
                                IsLostFocus = 0;
                            }
                            else
                            {
                                g_pEAXSound->EnterPauseMenu(-1, 1);
                                g_pEAXSound->Update(0.0);
                                IsLostFocus = 1;
                            }
                        }
                        return DefWindowProcA(hWnd, Msg, wParam, lParam);
                    case WM_PAINT:
                        BeginPaint(hWnd, &Paint);
                        EndPaint(hWnd, &Paint);
                        return DefWindowProcA(hWnd, Msg, wParam, lParam);
                    default:
                        return DefWindowProcA(hWnd, Msg, wParam, lParam);
                    }
                    return result;
                }
                if (!IsLoadingScreenUp() && !ExitTheGameFlag)
                {
                    ExitTheGameFlag = 1;
                    return 0;
                }
                return 0;
            }

            if (Msg == WM_ACTIVATEAPP)
            {
                WParam = wParam;
                sub_5B7EE0();
            }
            //Unused debug stuff
            /*else if (Msg == WM_KEYDOWN)
            {
                switch (wParam)
                {
                case '#':
                    _return();
                    sub_5BF3A0(dword_8709C0);
                    break;
                case '$':
                    _return();
                    sub_5BF3A0(-dword_8709C0);
                    break;
                case '%':
                    _return();
                    sub_5BF3A0(-1);
                    break;
                case '\'':
                    _return();
                    sub_5BF3A0(1);
                    break;
                case '{':
                    dword_870994 = 1;
                    break;
                default:
                    break;
                }

                if (wParam == 17)
                {
                    dword_8709D8 = 1;
                }
            }
            else if (Msg == 257 && wParam == 17)
            {
                dword_8709D8 = 0;
            }*/
        }
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }

    if (Msg > WM_RBUTTONUP)
    {
        if (Msg == WM_MOUSEWHEEL || Msg == WM_QUERYNEWPALETTE || Msg == WM_PALETTECHANGED)
        {
            return 0;
        }

        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }

    if (Msg == WM_RBUTTONUP)
    {
    LABEL_40:
        ReleaseCapture();
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }

    switch (Msg)
    {
    case WM_SYSCOMMAND:
        if (wParam == SC_SCREENSAVE) return 0;
        if (wParam != SC_MONITORPOWER) return DefWindowProcA(hWnd, Msg, wParam, lParam);
        result = 0;
        break;
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
        SetCapture(hWnd);
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    case WM_LBUTTONUP:
        goto LABEL_40;
    default:
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    return result;
}


//DONE : 0x005D24F0
void eInitEnginePlat()
{
    EnginePlatState = 1;
    D3D = Direct3DCreate9(D3D_SDK_VERSION);
    D3D->GetDeviceCaps(0, D3DDEVTYPE_HAL, &D3D_DEVICE_CAPS);

    sub_5BE5A0();
    LoadRegistrySettings();
    _controlfp(3u, 0x8001Fu);

    TextureHeaderSlotPool = bNewSlotPool(4, 1024, "g_textureHeaderPool", 0);
    TextureHeaderSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;
    VertexBufferHeaderPool = bNewSlotPool(4, 1024, "g_vertexBufferHeaderPool", 0);
    VertexBufferHeaderPool->NumAllocatedSlots &= 0xFFFFFFFD;

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandleA(0);
    wc.hIcon = LoadIconA(GetModuleHandleA(0), "IDI_ICON1");
    wc.hCursor = LoadCursorA(GetModuleHandleA(0), IDC_ARROW);
    wc.hbrBackground = 0;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GameFrame";
    wc.hIconSm = LoadIconA(GetModuleHandleA(0), IDI_APPLICATION);
    RegisterClassExA(&wc);

    LONG screen_width;
    LONG screen_height;
    PCGetResolution(&screen_width, &screen_height);

    struct tagRECT rect;
    rect.left = 100;
    rect.top = 100;
    ScreenWidth = screen_width;
    ScreenHeight = screen_height;
    rect.right = screen_width + 100;
    rect.bottom = screen_height + 100;
    AdjustWindowRect(&rect, 0x80000000, 0);

    PCHwnd = CreateWindowExA
    (
        0,
        "GameFrame",
        "NFS Underground 2",
        0x80000000,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        GetDesktopWindow(),
        0,
        wc.hInstance,
        0
    );

    UpdateWindow(PCHwnd);

    if (!PCWindowed)
    {
        SetCursor(0);
        ShowCursor(0);
    }

    SetFocus(PCHwnd);
    SetForegroundWindow(PCHwnd);
    GetWindowRect(PCHwnd, &PCWindowRect);
    GetClientRect(PCHwnd, &PCClientRect);

    D3DDISPLAYMODE d3d_display;
    D3D->GetAdapterDisplayMode(D3D_ADAPTER_DEFAULT, &d3d_display);
    D3D_BACK_BUF_FMT = D3DFMT_A8R8G8B8;

    D3D->CheckDeviceMultiSampleType(
        D3D_ADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        D3DFMT_A8R8G8B8,
        0,
        D3DMULTISAMPLE_NONMASKABLE,
        &PCAAQuality
    );

    --PCAAQuality;
    if (D3D_IDENTIFIER.VendorId == 4098 && sub_5BF5A0())
    {
        PCAAQuality = 0;
    }

    PCEnableD3DFeatures(screen_width, screen_height);
    PCCreateD3DDevice();

    if (*&g_FSAALevel > 0)
    {
        *&g_FSAALevel = 0;
        PCAAQuality = 0;
        *&g_RacingResolution = 0;
        PCEnableD3DFeatures(screen_width, screen_height);
        PCCreateD3DDevice();
    }

    D3D_DEVICE->GetAvailableTextureMem();

    ShowWindow(PCHwnd, 1);
    SetWindowLongA(PCHwnd, -16, 0x10000000);
    eInitD3D();
    sub_5D21F0();
    sub_5CED60();
    sub_5BE690();
    InitSlotPools();
    SetScreenBuffers();

    D3D_DEVICE->GetAvailableTextureMem();

    screen_height = 1000;
    screen_width = 0;
    sub_5BB220((IDirect3DVertexBuffer9*)&dword_86B7A4, (int*)&screen_width, (int*)&screen_height);

    if (PCDirectInput)
    {
        PCDirectInput->Release();
        PCDirectInput = 0;
    }

    if (DirectInput8Create(GetModuleHandleA(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&PCDirectInput, 0) < 0)
    {
        PCDirectInput = 0;
    }

    DinputInit(&TheDinputDevice);
    InitStripSlotPool();
}

//DONE : 0x0048CD60
void eInitEngine()
{
    FrameMemoryBuffer = (int*)j__malloc(0x64000u);
    dword_82CC28 = (int*)j__malloc(0x64000u);
    CurrentBufferPos = FrameMemoryBuffer;
    FrameMemoryBufferSize = 409600;
    CurrentBufferEnd = (int)(FrameMemoryBuffer + 409600);
    FrameMallocAllocNum = 0;
    ePolySlotPool = bNewSlotPool(128, 32, "ePolySlotPool", 0);
    ePolySlotPool->NumAllocatedSlots &= 0xFFFFFFFD;
    eInitModels();
    eInitTextures();
    eInitSolids();
    epInitViews();
    memset(DefaultLightMaterial, 0, 0xA0u);
    elInitPlat();
    eInitLightFlarePool();
    eInitEnvMap();
    _return();                                    // eEnvEffectsInit
    InitNFSAnimEngine();
    eInitEnginePlat();
}

//DONE : 0x004886E0
void afxInit()
{
    AcidActiveGroupSlotPool = bNewSlotPool(44, 400, "AcidActiveGroupSlotPool", 0);
    AcidEmitterSlotPool = bNewSlotPool(208, 250, "AcidEmitterSlotPool", 0);
    AcidActiveGroupSlotPool->NumAllocatedSlots &= 0xFFFFFFFE;
    AcidActiveGroupSlotPool->NumAllocatedSlots &= 0xFFFFFFFD;
}

//DONE : 0x00570F80
void InitResourceLoader()
{
    ResourceFileSlotPool = bNewSlotPool(240, 80, "ResourceFileSlotPool", 0);
}

//DONE : 0x00486910
void InitializeSoundLoad()
{
    g_pEAXSound->InitializeFromAemsManager();
}

//DONE : 0x0060C680
void InitCarRender()
{
    CarPartModelPool = (int)bNewSlotPool(24, 1024, "CarPartModelPool", 0);
}

//DONE : 0x00534840
void InitFrontendDatabase()
{
    FEDatabase.Default();
}

//DONE : 0x0057B870
void InitStomper()
{
    Stomper* v0;
    Stomper* v1;

    v0 = (Stomper*)malloc(0xCu);
    v1 = v0;
    if (v0)
    {
        LOBYTE(v0->unk_0) = 1;
        v0->unk_4 = (int*)malloc(0x400u);
        v1->unk_8 = 0;
        pStomper = v1;
    }
    else
    {
        pStomper = 0;
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
    WindowedMode = true;
#endif

    InitPlatform();
    InitBigFiles();
    TheDemoDiscManager->Init(argc, argv);
    bPListInit(0x1400);
    nullsub(v2);
    InitJoylog();
    SeedRandomNumber();
    InitQueuedFiles();
    emEventManagerInit();
    TheOnlineManager->InitOnline(argc, argv);
    eMathInit();
    eInitEngine();
    nullsub(v3);
    afxInit();
    InitResourceLoader();
    InitJoystick();
    InitializeSoundDriver();
    FEngInitSystem();
    LoadGlobalAChunks();
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
    InitDragCameraManager();
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

//DONE : 0x00580E00
void _main(int argc, char* argv[])
{
#ifdef DEBUG
    SkipMovies = true;
#endif

    if (PlatformIsProcessRunning("BB2.exe", 1))
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
    while (*++argv != 0)
    {
        if (!strcmp("--skipfe", *argv))
        {
            SkipFE = true;
            continue;
        }
        else if (!strcmp("--pause", *argv))
        {
            //Prevent game from running to attach debugger
            MessageBoxA(nullptr, "Pause requested", "BB2", 0);
            continue;
        }
    }

    replace(0x00580E00, (std::uint32_t)_main);
}
