#include "Platform.hpp"
#include "MemoryPool/MemoryPool.hpp"
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

//THUNK : 0x005B7B20
bool PlatformIsProcessRunning(char* exe, int count)
{
    return call<bool(char*, int)>(0x005B7B20)(exe, count);
}

//THUNK : 0x0057CAC0
int bFileExists(char* Str)
{
    return call<int(char*)>(0x0057CAC0)(Str);
}

//THUNK : 0x00440540
void bFree(char* a1)
{
    call<int(char*)>(0x00440540)(a1);
}

//THUNK : 0x00440E60
void bPListInit(int expected_nodes)
{
    call<int()>(0x00440E60)();
}

//THUNK : 0x0057CA10
std::uint32_t* bOpen(char* Str, int a2)
{
    return call<std::uint32_t*(char*, int)>(0x0057CA10)(Str, a2);
}

//THUNK : 0x0057B640
int bInitDisculatorDriver(char* Str, char* a2)
{
    return call<int(char*, char*)>(0x0057B640)(Str, a2);
}

//THUNK : 0x0043DB50
std::uint32_t bStringHash(const char* str)
{
    return call<std::uint32_t(const char*)>(0x0043DB50)(str);
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
}

//THUNK : 0x006FBE2C
void sub_006FBE2C()
{
    call<void()>(0x006FBE2C)();
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