#include "GameFlowManager.hpp"
#include "memory.hpp"

bool& SetSingleFunction_Inlined = *reinterpret_cast<bool*>(0x00865498);
std::uint32_t*& SingleFunction_Inlined = *reinterpret_cast<std::uint32_t**>(0x00865484);
char*& SingleFunctionState_Inlined = *reinterpret_cast<char**>(0x0086548C);
int& GameFlowManagerState = *reinterpret_cast<int*>(0x008654A4);
char*& GameFlowCallback = *reinterpret_cast<char**>(0x0086549C);

//THUNK : 0x0057FF10
bool BeginGameFlowLoadingFrontEnd()
{
	return call<bool()>(0x0057FF10)();
}