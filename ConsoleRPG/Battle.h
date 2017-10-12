#pragma once

#include "Game.h"
#include "LocationState.h"

class Battle : public LocationState
{
public:
	Battle() {};
	~Battle() {};

	void processState(Game* game) override;

private:

};