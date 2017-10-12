#pragma once

#include "Game.h"
#include "LocationState.h"
#include "Sea.h"
#include "Pirate.h"

class Sea;
class Battle : public LocationState
{
public:
	Battle(Sea* sea);
	~Battle() {};

	void processState(Game* game) override;

private:
	Sea* seaState;
	Pirate pirate;


};