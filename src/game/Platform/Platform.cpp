#include "Platform.hpp"
#include "Unsorted/MemoryPool.hpp"
#include "Realcore/RealSystem.hpp"
#include "Unsorted/SlotPool.hpp"
#include "Platform/bFile.hpp"
#include "Unsorted/MemoryPool.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"
#include "variables.hpp"

//DONE : 0x005B7B20
bool PlatformIsProcessRunning(char* exe, int count)
{
    int v2;
    int v3;
    HANDLE v4;
    char* v5;
    char* v6;
    char* v7;
    char v8;
    int v9;
    char v10;
    PROCESSENTRY32 pe;
    char String2[260];

    pe.dwSize = 0;
    memset(&pe.cntUsage, 0, 0x124u);
    v2 = 0;
    v3 = 3;
    v4 = CreateToolhelp32Snapshot(2u, 0);
    if (v4 == (HANDLE)-1)
        return 0;
    while (1)
    {
        pe.dwSize = 296;
        if (Process32First(v4, &pe))
        {
            do
            {
                v5 = strrchr(pe.szExeFile, 92);
                if (v5)
                {
                    v6 = v5 + 1;
                    v7 = (char*)(String2 - v6);
                    do
                    {
                        v8 = *v6;
                        v6[(_DWORD)v7] = *v6;
                        ++v6;
                    } while (v8);
                }
                else
                {
                    v9 = 0;
                    do
                    {
                        v10 = pe.szExeFile[v9];
                        String2[v9++] = v10;
                    } while (v10);
                }
                if (!_stricmp(exe, String2))
                    ++v2;
            } while (Process32Next(v4, &pe));
        }
        CloseHandle(v4);
        --v3;
        if (v2 <= count || v3 < 0)
            break;
        Sleep(1000);
        v2 = 0;
        v4 = CreateToolhelp32Snapshot(2u, 0);
        if (v4 == (HANDLE)-1)
            return 0;
    }
    return v2 > count;
}

//DONE : 0x0057CAC0
int bFileExists(char* Str)
{
    bFile* FileHandle; // eax
    int v2; // esi

    FileHandle = bOpen(Str, 1);
    if (!FileHandle)
        return 0;
    v2 = *((_DWORD*)FileHandle + 1);
    if (*((int*)FileHandle + 6) <= 0)
        FileHandle->bClose(1);
    else
        *((_DWORD*)FileHandle + 5) = 1;
    return v2 + 1;
}

//THUNK : 0x00440540
void bFree(char* a1)
{
    call<int(char*)>(0x00440540)(a1);
}

//THUNK : 0x00440E60
void bPListInit(int num_expected_bpnodes)
{
    call<int(int)>(0x00440E60)(num_expected_bpnodes);
}

//DONE : 0x0043DBB0
int bStrLen(const char* a1)
{
    int result; // eax

    result = 0;
    if (a1 && *a1)
    {
        while (a1[++result]);
    }
    return result;
}

//DONE : 0x00440E50
SlotPool* bOMalloc(SlotPool* pool)
{
    return pool->Malloc();
}

//THUNK : 0x0057B640
int bInitDisculatorDriver(char* Str, char* a2)
{
    return call<int(char*, char*)>(0x0057B640)(Str, a2);
}

//DONE : 0x0043DB50
std::uint32_t bStringHash(const char* string)
{
    const char* v1; // edx
    uint8_t v2; // cl
    uint32_t hash; // eax

    v1 = string;
    v2 = *string;
    for (hash = -1; v2; ++v1)
    {
        hash = v2 + 33 * hash;
        v2 = v1[1];
    }
    return hash;
}

//DONE : 0x0043BDF0
std::uint64_t bGetTicker()
{
    LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

    QueryPerformanceCounter(&PerformanceCount);
    return PerformanceCount.QuadPart >> dword_8284E4;
}

//THUNK : 0x0057A1A0
double GetDebugRealTime()
{
    return call<double()>(0x0057A1A0)();
}

//THUNK : 0x005BF3D0
bool PlatformCDCheckBinDat(bool a1)
{
    return call<bool(bool)>(0x005BF3D0)(a1);
}

//DONE : 0x0043BD90
void sub_43BD90()
{
    int v0;
    double v1;
    double v2;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    v0 = 0;
    dword_8284E4 = 0;
    v1 = flt_784550 / Frequency.QuadPart;
    flt_828028 = v1;
    v2 = v1 * flt_786D84;
    if (v2 < flt_786D80)
    {
        do
        {
            ++v0;
            v2 = v2 + v2;
        } while (v2 < flt_786D80);
        dword_8284E4 = v0;
    }
}

//DONE : 0x0043E5B0
void bInitTicker()
{
    sub_43BD90();
}

//THUNK : 0x00440330
void bInitMemoryPool(int pool_num, void* mem, int mem_size, const char* debug_name)
{
    call<void(int, void*, int, const char*)>(0x00440330)(pool_num, mem, mem_size, debug_name);
}

//TODO : 0x00440360
void bMemoryInit()
{
    if (!MemoryInitialized)
    {
        bInitMemoryPool(0, 0, 0, "Main Pool");
        MemoryInitialized = 1;
    }
}

//DONE : 0x0043DC30
int bStrCmp(char* s1, char* s2)
{
    char c1; // al
    char c2; // cl

    do
    {
        c1 = *s1;
        c2 = *s2;
        ++s1;
        ++s2;
    } while (c1 && c2 && c1 == c2);
    return c1 - c2;
}

//THUNK : 0x006FBD9E
void sub_6FBD9E(int a1, char a2)
{
    call<void(int, char)>(0x006FBD9E)(a1, a2);
}

//THUNK : 0x006FBD0C
void sub_6FBD0C(int a1, char a2)
{
    call<void(int, char)>(0x006FBD0C)(a1, a2);
}

//DONE : 0x006FBE2C
void sub_6FBE2C()
{
    char* v0;
    char* v1;
    _DWORD* v2;
    char* v3;

    if (!byte_8AD918)
    {
        byte_8AD918 = 1;
        v0 = &byte_814580;
        do
        {
            *v0 = 0;
            v0 += 12;
        } while ((int)v0 < (int)&dword_8145E0);
        v1 = &byte_81437C;
        do
        {
            *v1 = 0;
            v1 += 8;
        } while ((int)v1 < (int)&funcs_6FBE26);
        v2 = &unk_8145C4;
        do
        {
            *(v2 - 1) = 0;
            *v2 = 0;
            v2 += 3;
        } while ((int)v2 < (int)&unk_8145DC);
        v3 = &unk_81447D;
        do
        {
            *(_DWORD*)(v3 - 5) = 0;
            *v3 = 0;
            v3 += 8;
        } while ((int)v3 < 8471933);
        sub_6FBD9E(2, 1);
        sub_6FBD0C(0, 1);
    }
}

//DONE : 0x006F57EA
void THREAD_init()
{
    HANDLE v0;
    HANDLE v1;
    HANDLE v2;

    if (!ThreadInitalized)
    {
        g_thMain = GetCurrentThreadId();
        v2 = GetCurrentProcess();
        v1 = GetCurrentThread();
        v0 = GetCurrentProcess();
        DuplicateHandle(v0, v1, v2, &TargetHandle, 0, 0, 2u);
        ThreadInitalized = 1;
    }
}

//THUNK : 0x006F5C91
void TIMER_init(int a1)
{
    call<void(int)>(0x006F5C91)(a1);
}

//THUNK : 0x005B7A70
void sub_5B7A70()
{
    call<void()>(0x005B7A70)();
}

//DONE : 0x005B7690
void InitPlatform(int argc, char* argv[])
{
    bInitTicker();
    bMemoryInit();
    sub_6FBE2C();
    THREAD_init();
    TIMER_init(100);
    sub_5B7A70();
    if (!PlatformDRM())
        _exit(0);
    if (argc > 1 && !bStrCmp(argv[1], "/s"))
        dword_8709CC = 1;
}

//THUNK : 0x005BF450
bool PlatformCDCheck()
{
    return call<bool()>(0x005BF450)();
}

//DONE : 0x005C0D30
bool PlatformDRM()
{
    char v0;

    while (1)
    {
        if (!dword_800B98)
        {
            v0 = PlatformCDCheckBinDat(a_char);

            if (!v0)
            {
                dword_800B98 = 1;
                goto LABEL_6;
            }

            goto LABEL_5;
        }

        v0 = PlatformCDCheck();

        if (v0)
        {
            v0 = 1;
        LABEL_5:
            dword_800B98 = 0;
            goto LABEL_6;
        }

        dword_800B98 = 1;

    LABEL_6:
        if (PlatformSkipDRM || v0 || bFileExists("foobar"))
        {
            return 1;
        }

        if (MessageBoxA(0, "Please insert Disc 2", "NFS Underground 2", 1u) != 1)
        {
            return 0;
        }
    }
}

//THUNK : 0x00440E40
void bDeleteSlotPool(SlotPool* a1)
{
    call<void(SlotPool*)>(0x00440E40)(a1);
}

//THUNK : 0x006F56BD
void SYNCTASK_run()
{
    call<void()>(0x006F56BD);
}

//DONE : 0x006F5889
std::uint32_t bSleep(std::uint32_t dwMilliseconds)
{
    return SleepEx(dwMilliseconds, 1);
}

//THUNK : 0x00440820
void* bMalloc(int size, int allocation_parameters)
{
    return call<void* (int, int)>(0x00440820)(size, allocation_parameters);
}

//DONE : 0x0043DC00
char* bStrNCpy(char* to, const char* from, int m)
{
    char* result; // eax
    int v4; // esi
    char* v5; // edx
    char v6; // cl

    result = to;
    v4 = m;
    if (m)
    {
        v5 = to;
        do
        {
            v6 = v5[from - to];
            --v4;
            *v5 = v6;
            if (!v6)
                break;
            ++v5;
        } while (v4);
    }
    return result;
}

//DONE : 0x0057D900
int __cdecl bFileSize(char* filename)
{
    bFile* v1; // eax
    int v2; // edx
    int v3; // esi
    int result; // eax

    v1 = bOpen(filename, 1);
    if (!v1)
        return -1;
    v2 = v1->unk_4 < 0 ? 0 : v1->unk_4;
    v3 = v2;
    if (v1->unk_24 <= 0)
    {
        v1->bClose(1);
        result = v3;
    }
    else
    {
        v1->unk_20 = 1;
        result = v2;
    }
    return result;
}

//DONE : 0x0043E000
std::uint16_t* bStrCpy(std::uint16_t* a1, char* a2)
{
    char* v2; // edx
    uint16_t v3; // cx
    uint16_t* result; // eax
    uint16_t* v5; // esi
    uint16_t v6; // cx

    v2 = a2;
    v3 = *a2;
    result = a1;
    *a1 = v3;
    if (v3)
    {
        v5 = a1;
        do
        {
            v6 = *++v2;
            *++v5 = v6;
        } while (v6);
    }
    return result;
}
