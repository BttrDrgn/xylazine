#include "Player.hpp"
#include "memory.hpp"

Player**& pPlayersByIndex = *reinterpret_cast<Player***>(0x008900B4);
int NumPlayers = *reinterpret_cast<int*>(0x008900BC);

//THUNK : 0x005EA650
char Player::DetermineInputMode()
{
    return reinterpret_cast<char(__thiscall*)(Player*)>(0x005EA650)(this);
}