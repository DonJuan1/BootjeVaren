#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "CSVParser.h"
#include "CityBuilder.h"
#include "ShipFactory.h"
#include "Ship.h"
#include "LocationState.h"
#include "City.h"


class CSVParser;
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

	
	CityBuilder cityBuilder;

	LocationState* state;
	CSVParser* parser;
	Ship* ship;

};
