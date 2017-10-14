#pragma once

#include <iostream>

#include "Ship.h"


class ShipFactory
{
public:
	ShipFactory() {};
	~ShipFactory() {};

	Ship* getRandomShip(bool withCannons);

private:



};
