#include "Pirate.h"

Pirate::Pirate()
{
	ship = new Ship();

	//ship->addCannon(new HeavyCannon());
}

Pirate::~Pirate()
{
	delete ship;
}
