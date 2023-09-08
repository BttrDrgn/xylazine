#include "Platform.hpp"
#include "MemoryPool/MemoryPool.hpp"
#include "RealSystem/RealSystem.hpp"
#include "SlotPool/SlotPool.hpp"
#include "memory.hpp"
#include "ida_defs.hpp"

int& PlatformSkipDRM = GET(INT, 0x0079DC60);
int& dword_00800B98 = GET(INT, 0x00800B98);
int& dword_008709CC = GET(INT, 0x008709CC);
char& a_char = GET(CHAR, 0x0080057F);
int& dword_008284E4 = GET(INT, 0x008284E4);
float& flt_00784550 = GET(FLOAT, 0x00784550);
float& flt_00828028 = GET(FLOAT, 0x00828028);
float& flt_00786D84 = GET(FLOAT, 0x00786D84);
float& flt_00786D80 = GET(FLOAT, 0x00786D80);
_DWORD*& dword_00828154 = GET(UINT32_PTR, 0x00828154);
_DWORD*& dword_00828218 = GET(UINT32_PTR, 0x00828218);
bool& MemoryInitialized = GET(BOOL, 0x00828510);
HANDLE& TargetHandle = GET((HANDLE)0, 0x008AD410);
_DWORD& g_thMain = GET(UINT32, 0x008AD40C);
bool& ThreadInitalized = GET(BOOL, 0x008AD408);
char& byte_008AD918 = GET(CHAR, 0x008AD918);
char& byte_00814580 = GET(CHAR, 0x00814580);
char& byte_0081437C = GET(CHAR, 0x0081437C);
_DWORD& dword_008145E0 = GET(UINT32, 0x008145E0);
auto& funcs_6FBE26 = *reinterpret_cast<int(__cdecl**)(int, int)>(0x0081457C);
_DWORD& unk_008145C4 = GET(UINT32, 0x008145C4);
_DWORD& unk_008145DC = GET(UINT32, 0x008145DC);
std::uint8_t& unk_0081447D = GET(UINT8, 0x0081447D);

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
        Sleep(0x3E8u);
        v2 = 0;
        v4 = CreateToolhelp32Snapshot(2u, 0);
        if (v4 == (HANDLE)-1)
            return 0;
    }
    return v2 > count;
}

//THUNK : 0x00579B90
bFile* bClose(bFile* file, char a2)
{
    return call<bFile*(bFile*, char)>(0x00579B90)(file, a2);
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
        bClose(FileHandle, 1);
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
void bPListInit(int expected_nodes)
{
    call<int(int)>(0x00440E60)(expected_nodes);
}

//DONE : 0x0043DBB0
int __cdecl bStrLen(const char* a1)
{
    int result; // eax

    result = 0;
    if (a1 && *a1)
    {
        while (a1[++result]);
    }
    return result;
}

SlotPool* bOMalloc(SlotPool* pool)
{
    return pool->Malloc();
}

//THUNK : 0x0057CA10
bFile* bOpen(char* path, int a2)
{
    return call<bFile*(char*, int)>(0x0057CA10)(path, a2);
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
LONGLONG bGetTicker()
{
    LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

    QueryPerformanceCounter(&PerformanceCount);
    return PerformanceCount.QuadPart >> dword_008284E4;
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
void sub_0043BD90()
{
    int v0;
    double v1;
    double v2;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    v0 = 0;
    dword_008284E4 = 0;
    v1 = flt_00784550 / Frequency.QuadPart;
    flt_00828028 = v1;
    v2 = v1 * flt_00786D84;
    if (v2 < flt_00786D80)
    {
        do
        {
            ++v0;
            v2 = v2 + v2;
        } while (v2 < flt_00786D80);
        dword_008284E4 = v0;
    }
}

//DONE : 0x0043E5B0
void sub_0043E5B0()
{
    sub_0043BD90();
}

//THUNK : 0x00440330
int bInitMemoryPool(int a1, void* a2, int a3, const char* a4)
{
    return call<int(int, void*, int, const char*)>(0x00440330)(a1, a2, a3, a4);
}

//The proper method is working, whatever the PC version is doing is wrong and needs to be fixed
//it looks like the wrapper for InitMemoryPool was inlined or the code was not updated when it was made
//TODO : 0x00440360
void bMemoryInit()
{
    if (!MemoryInitialized)
    {
#if 0
        * (_DWORD*)MemoryPools = &MemoryPoolMem;    // bInitMemoryPool inlined
        MemoryPool::Init((MemoryPool*)&MemoryPoolMem, 0, 0, "Main Pool");
        MemoryInitialized = 1;
#else
        bInitMemoryPool(0, 0, 0, "Main Pool");
#endif
        MemoryInitialized = 1;
    }
}

//DONE : 0x0043DC30
int bStrCmp(char* str1, char* str2)
{
#if 0
    char v4;
    char v5;

    do
    {
        v4 = *str1;
        v5 = *str2;
        ++str1;
        ++str2;
    } while (v4 && v5 && v4 == v5);
    return v4 - v5;
#else
    while (*str1 == *str2++)
        if (*str1++ == 0)
            return (0);
    return (*(unsigned char*)str1 - *(unsigned char*)--str2);
#endif
}

//THUNK : 0x006FBD9E
void sub_006FBD9E(int a1, char a2)
{
    call<void(int, char)>(0x006FBD9E)(a1, a2);
}

//THUNK : 0x006FBD0C
void sub_006FBD0C(int a1, char a2)
{
    call<void(int, char)>(0x006FBD0C)(a1, a2);
}

//DONE : 0x006FBE2C
void sub_006FBE2C()
{
    char* v0;
    char* v1;
    _DWORD* v2;
    _BYTE* v3;

    if (!byte_008AD918)
    {
        byte_008AD918 = 1;
        v0 = &byte_00814580;
        do
        {
            *v0 = 0;
            v0 += 12;
        } while ((int)v0 < (int)&dword_008145E0);
        v1 = &byte_0081437C;
        do
        {
            *v1 = 0;
            v1 += 8;
        } while ((int)v1 < (int)&funcs_6FBE26);
        v2 = &unk_008145C4;
        do
        {
            *(v2 - 1) = 0;
            *v2 = 0;
            v2 += 3;
        } while ((int)v2 < (int)&unk_008145DC);
        v3 = &unk_0081447D;
        do
        {
            *(_DWORD*)(v3 - 5) = 0;
            *v3 = 0;
            v3 += 8;
        } while ((int)v3 < 8471933);
        sub_006FBD9E(2, 1);
        sub_006FBD0C(0, 1);
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
void sub_005B7A70()
{
    call<void()>(0x005B7A70)();
}

//DONE : 0x005B7690
void InitPlatform()
{
    int v0 = 0;
    int v1 = 0;

    sub_0043E5B0();
    bMemoryInit();
    sub_006FBE2C();
    THREAD_init();
    TIMER_init(100);
    sub_005B7A70();

    if (!PlatformDRM())
    {
        _exit(0);
    }

    if (v0 > 1 && !bStrCmp(*(char**)(v1 + 4), "/s"))
    {
        dword_008709CC = 1;
    }
}

//THUNK : 0x005BF450
bool PlatformCDCheck()
{
    return call<bool()>(0x005BF450)();
}

//DONE : 0x005C0D30
bool PlatformDRM()
{
#ifdef MATCHING
    char v0;

    while (1)
    {
        if (!dword_00800B98)
        {
            v0 = PlatformCDCheckBinDat(a_char);

            if (!v0)
            {
                dword_00800B98 = 1;
                goto LABEL_6;
            }

            goto LABEL_5;
        }

        v0 = PlatformCDCheck();

        if (v0)
        {
            v0 = 1;
        LABEL_5:
            dword_00800B98 = 0;
            goto LABEL_6;
        }

        dword_00800B98 = 1;

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
#else
    return true;
#endif
}