#pragma once

#include <iostream>
#include "Ship.h"
#include "CustomVector.h"

class ShipFactory
{
public:
	ShipFactory();
	~ShipFactory();

	Ship& getRandomShip();
	Ship& getShipWithType(char* shipType);
	CustomVector<Ship*>& getShipVector();


private:
	CustomVector<Ship*> shipVector;
};
