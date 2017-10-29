#include "Pirate.h"

Pirate::Pirate()
{
	ship = nullptr;
}

Pirate::Pirate(Ship* pShip)
{
	ship = pShip;

	ship->addCannon(new LightCannon(), 0);
	ship->addCannon(new MediumCannon(), 0);
	ship->addCannon(new HeavyCannon(), 0);

	for (int i = 0; i < ship->getCannonsOnShip().size(); i++)
	{
		ship->getCannonsOnShip().at(i)->randomAmount();
	}
}

Pirate::~Pirate()
{
	delete ship;
}

Ship* Pirate::getShip() const
{
	return ship;
}
