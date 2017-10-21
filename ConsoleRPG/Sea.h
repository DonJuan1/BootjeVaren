#pragma once

#include "LocationState.h"
#include "Battle.h"
#include "WindHandler.h"
#include "NoneHandler.h"
#include "BreezeHandler.h"
#include "WeakHandler.h"
#include "NormalHandler.h"
#include "StrongHandler.h"
#include "StormHandler.h"


class City;
class Game;

class Sea : public LocationState
{
public:
	Sea() {};
	Sea(City* nextCity);
	~Sea();

	void processState(Game* game) override;

private:
	int turns;
	City* nextCity;
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
