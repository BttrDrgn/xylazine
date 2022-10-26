#include "DragCamera.hpp"
#include "memory.hpp"

//THUNK : 0x00452EC0
void DragCamera::Init()
{
    call<void()>(0x00452EC0)();
}