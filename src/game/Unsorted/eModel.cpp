#include "eModel.hpp"
#include "memory.hpp"
 
eModel* StandardCubeModel = new eModel();
eModel* StandardDebugModel = new eModel();

//THUNK : 0x00493600
void eModel::Init(std::uint32_t name_hash)
{
	reinterpret_cast<void(__thiscall*)(eModel*, std::uint32_t)>(0x00493600)(this, name_hash);
}