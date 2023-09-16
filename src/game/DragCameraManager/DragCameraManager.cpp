#include "DragCameraManager.hpp"
#include "memory.hpp"

extern DragCameraManager*& TheDragCameraManager = *reinterpret_cast<DragCameraManager**>(0x00828770);

//THUNK : 0x00456940
void DragCameraManager::Update()
{
    reinterpret_cast<void(__thiscall*)(DragCameraManager**)>(0x00456940)(&TheDragCameraManager);
}