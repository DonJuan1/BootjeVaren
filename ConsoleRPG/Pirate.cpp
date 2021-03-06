#include "Pirate.h"

Pirate::Pirate()
{
	ship = nullptr;
}

Pirate::Pirate(Ship* pShip)
{
	ship = pShip;
	ship->addPirateCannons();
}

Pirate::~Pirate()
{
	delete ship;
}

Ship* Pirate::getShip() const
{
	return ship;
}
