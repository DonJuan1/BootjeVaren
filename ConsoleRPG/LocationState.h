#pragma once

#include "Game.h"

class Game;
class LocationState
{
public:
	LocationState() {};
	virtual ~LocationState() {};

	virtual void processState(Game* game) = 0;
	
	const char* lastCommandMessage = "";

private:


protected:
	char buf[128] = { 0 };


};
