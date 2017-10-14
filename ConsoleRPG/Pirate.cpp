#include "Pirate.h"

Pirate::Pirate(Ship* pShip)
{
	ship = pShip;
}

Pirate::~Pirate()
{
	delete ship;
}

Ship* Pirate::getShip() const
{
	return ship;
}