#pragma once

#include "Game.h"
#include "LocationState.h"
#include "Battle.h"
#include "City.h"

class City;
class Sea : public LocationState
{
public:
	Sea(City* nextCity);
	~Sea();

	void processState(Game* game) override;

private:
	int turns;
	City* nextCity;
	bool isInBattle = false;

};