#include "DemoDiscManager.hpp"
#include "memory.hpp"

extern DemoDiscManager* TheDemoDiscManager = new DemoDiscManager();

//DONE : 0x005B7EA0
void DemoDiscManager::Init(int argc, char* argv[])
{
    reinterpret_cast<void(__thiscall*)(DemoDiscManager*, int, char**)>(0x005B7EA0)(this, argc, argv);
}