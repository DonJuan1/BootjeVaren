#pragma once

#include "LocationState.h"
#include "RandomGenerator.h"
#include "Pirate.h"

class City;
class Game;

class Battle : public LocationState
{
public:
	Battle(const City* cityDestination, int turns);
	~Battle();

	void processState(Game& game) override;

private:
	const City* cityDestination;
	int turnsLeft;
	Pirate* pirate;


};
