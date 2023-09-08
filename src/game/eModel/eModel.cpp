#include "eModel.hpp"
#include "memory.hpp"
 
eModel*& StandardCubeModel = *reinterpret_cast<eModel**>(0x008A1DE4);
eModel*& StandardDebugModel = *reinterpret_cast<eModel**>(0x008A3168);

//THUNK : 0x00493600
void eModel::Init(std::uint32_t a2)
{
	call<void(eModel*, std::uint32_t)>(0x00493600)(this, a2);
}