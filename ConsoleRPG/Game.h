#pragma once

#include <iostream>
#include "CSVParser.h"
#include "CityBuilder.h"
#include "Ship.h"
#include "LocationState.h"
#include "City.h"


class Game
{
public:
	Game();
	~Game();

	void setState(LocationState *s);
	
	void setNextCity(City *c);
	

	City* nextCity;

private:

	int gold = 100;

	CSVParser parser;
	CityBuilder cityBuilder;

	LocationState* state;

	Ship* ship;

};
