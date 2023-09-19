#include "DeviceDriver.hpp"

//THUNK : 0x006F6C23
RealFile::DeviceDriver::DeviceDriver(const char* label)
{
	reinterpret_cast<RealFile::DeviceDriver(__thiscall*)(RealFile::DeviceDriver*, const char*)>(0x006F6C23)(this, label);
}