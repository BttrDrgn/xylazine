#pragma once

class Player
{
public:
	static Player**& pPlayersByIndex;
	static int NumPlayers;
	char DetermineInputMode();
};
