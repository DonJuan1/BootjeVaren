#pragma once

#include <iostream>
#include "CSVParser.h"
#include "CityBuilder.h"
#include "ShipFactory.h"
#include "Ship.h"
#include "LocationState.h"
#include "City.h"

class LocationState;
class City;
class Game
{
public:
	Game();
	~Game();

	void setState(LocationState *s);

	Ship *getShip() const;

	void getHit(int damage) { ship->getHit(damage); };

	ShipFactory shipFactory;

private:

	int gold = 5000;

	CSVParser parser;
	CityBuilder cityBuilder;

	LocationState* state;

	Ship* ship;

};
