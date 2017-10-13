#pragma once

#include "Game.h"

class Game;
class LocationState
{
public:
	LocationState() {};
	virtual ~LocationState() {};

	virtual void processState(Game* game) = 0;

private:


protected:
	const char* lastCommandMessage = "";
	char buf[64] = { 0 };


};