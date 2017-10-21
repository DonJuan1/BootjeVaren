#pragma once

#include "LocationState.h"
#include "RandomGenerator.h"

class Sea;
class Game;
class Pirate;

class Battle : public LocationState
{
public:
	Battle(Sea* sea);
	~Battle();

	void processState(Game* game) override;

private:
	Sea* seaState;
	Pirate* pirate;


};
