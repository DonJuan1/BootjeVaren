#pragma once

#include "Game.h"

class LocationState
{
public:
	LocationState() {};
	virtual ~LocationState() {};

	virtual void processState(Game* game) = 0;

private:

};