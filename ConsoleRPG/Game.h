#pragma once

#include <iostream>

#include "CSVParser.h"
#include "ShipFactory.h"
#include "CityFactory.h"
#include "Ship.h"
#include "City.h"

class Game
{
public:
	Game();
	~Game();

	void setState(LocationState *s);

	Ship *getShip() const;

	void getHit(int damage) { ship->getHit(damage); };

	ShipFactory shipFactory;
	CityFactory cityFactory;

private:

	int gold = 5000;

	LocationState* state;
	Ship* ship;

	void ReadCSVFiles();

};
