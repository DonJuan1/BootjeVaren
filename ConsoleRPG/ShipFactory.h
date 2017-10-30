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
	CustomVector<Ship*>& getShipVector();


private:
	CustomVector<Ship*> shipVector;
};
