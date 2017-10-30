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

	void setState(LocationState* s);

	Ship *getShip() const;
	void setShip(Ship* newShip) { delete ship; ship = newShip; }

	const ShipFactory& getShipFactory() const { return shipFactory; }
	const CityFactory& getCityFactory() const { return cityFactory; }
	
private:
	LocationState* state = nullptr;
	Ship* ship = nullptr;

	ShipFactory shipFactory;
	CityFactory cityFactory;

	void ReadCSVFiles();
};
