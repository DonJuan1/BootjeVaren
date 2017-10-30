#pragma once

#include <iostream>
#include <random>
#include <ctime>

#include "RandomGenerator.h"
#include "LocationState.h"
#include "CityDestination.h"
#include "Battle.h"
#include "WindHandler.h"
#include "NoneHandler.h"
#include "BreezeHandler.h"
#include "WeakHandler.h"
#include "NormalHandler.h"
#include "StrongHandler.h"
#include "StormHandler.h"

class Game;

using namespace std;

class Sea : public LocationState
{
public:
	Sea() {};
	Sea(const CityDestination* cityDestination);
	Sea(const City* city, int turns);
	~Sea();

	void processState(Game* game) override;

private:
	int turns;
	const City* city;
	Battle* battle;
	bool isInBattle = false;

	NoneHandler none;
	BreezeHandler breeze;
	WeakHandler weak;
	NormalHandler normal;
	StrongHandler strong;
	StormHandler storm;

	WindHandler* wind[20] {
		&none,&none,
		&breeze,&breeze,
		&weak,&weak,&weak,
		&normal,&normal,&normal,&normal,&normal,&normal,&normal,&normal,&normal,&normal,
		&strong,&strong,
		&storm
	};

};
