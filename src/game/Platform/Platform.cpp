#include "Platform.hpp"
#include "memory.hpp"

int& PlatformSkipDRM = *reinterpret_cast<int*>(0x0079DC60);
int& dword_00800B98 = *reinterpret_cast<int*>(0x00800B98);
int& dword_008709CC = *reinterpret_cast<int*>(0x008709CC);
char A_Char = 'A';

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

//THUNK : 0x005BF3D0
bool PlatformCDCheckBinDat(bool a1)
{
    return call<bool(bool)>(0x005BF3D0)(a1);
}

//THUNK : 0x0043E5B0
void sub_0043E5B0()
{
    call<void()>(0x0043E5B0)();
}

//THUNK : 0x00440360
void bMemoryInit()
{
    call<void()>(0x00440360)();
}

//THUNK : 0x006FBE2C
void sub_006FBE2C()
{
    call<void()>(0x006FBE2C)();
}

//THUNK : 0x006F57EA
void THREAD_init()
{
    call<void()>(0x006F57EA)();
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

//THUNK : 0x0043DC30
int sub_0043DC30(char* a1, char* a2)
{
    return call<int(char*, char*)>(0x0043DC30)(a1, a2);
}

//DONE : 0x005B7690
void InitPlatform()
{
#ifdef MATCHING
    int v0 = 0; // [esp+4h] [ebp+4h]
    int v1 = 0; // [esp+8h] [ebp+8h]

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

    if (v0 > 1 && !sub_0043DC30(*(char**)(v1 + 4), "/s"))
    {
        dword_008709CC = 1;
    }
#else
    call<void()>(0x005B7690)();
#endif
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
    char v0; // al

    while (1)
    {
        if (!dword_00800B98)
        {
            v0 = PlatformCDCheckBinDat(A_Char);
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
            return 1;
        if (MessageBoxA(0, "Please insert Disc 2", "NFS Underground 2", 1u) != 1)
            return 0;
    }
#else
    return true;
#endif
}

//THUNK : 0x005B7B20
bool PlatformIsProcessRunning(char* exe, int count)
{
    return call<bool(char*, int)>(0x005B7B20)(exe, count);
}