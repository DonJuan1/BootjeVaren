#pragma once

#include "Game.h"
#include "LocationState.h"

class Sea : public LocationState
{
public:
	Sea();
	~Sea() {};

	void processState(Game* game) override;

private:
	int turns;

};