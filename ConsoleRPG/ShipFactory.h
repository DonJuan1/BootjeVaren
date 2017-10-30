#pragma once

#include <iostream>
#include "Ship.h"
#include "CustomVector.h"

class ShipFactory
{
public:
	ShipFactory();
	~ShipFactory();

	Ship& getRandomShip() const;
	Ship& getShipWithType (const char* shipType) const;
	const CustomVector<Ship*>& getShipVector() const;
	void addShip(Ship* ship) { shipVector.push_back(ship); }

private:
	CustomVector<Ship*> shipVector;
};
