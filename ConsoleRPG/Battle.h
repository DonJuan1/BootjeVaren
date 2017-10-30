#pragma once

#include "LocationState.h"
#include "RandomGenerator.h"

class City;
class Sea;
class Game;
class Pirate;

class Battle : public LocationState
{
public:
	Battle(const City* cityDestination, int turns);
	~Battle();

	void processState(Game* game) override;

private:
	const City* cityDestination;
	int turnsLeft;
	Pirate* pirate;


};
