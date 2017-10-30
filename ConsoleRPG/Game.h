#pragma once

#include <iostream>
#include <stdlib.h>

#include "CSVParser.h"
#include "ShipFactory.h"
#include "CityFactory.h"
#include "Ship.h"

class Game
{
public:
	Game();
	~Game();

	void setState(LocationState *s);

	Ship *getShip() const;
	void setShip(Ship* newShip) { ship = newShip; }

	void getHit(int damage) { ship->getHit(damage); };

	ShipFactory shipFactory;
	CityFactory cityFactory;

private:
	LocationState* state = nullptr;
	Ship* ship = nullptr;

	void ReadCSVFiles();
};
