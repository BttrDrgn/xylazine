#pragma once

extern bool& SetSingleFunction_Inlined;
extern std::uint32_t*& SingleFunction_Inlined;
extern char*& SingleFunctionState_Inlined;
extern int& GameFlowManagerState;
extern char*& GameFlowCallback;

bool BeginGameFlowLoadingFrontEnd();

class GameFlowManager
{
public:
};