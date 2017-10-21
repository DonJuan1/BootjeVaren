#pragma once

#include <iostream>
#include "Ship.h"
#include "CustomVector.h"

class ShipFactory
{
public:
	ShipFactory() {};
	~ShipFactory() {};

	Ship* getRandomShip(bool withCannons);
	void setShipVector(CustomVector<Ship>& shipVector);
	CustomVector<Ship>& getShipVector();


private:
	CustomVector<Ship> shipVector;
	
};
