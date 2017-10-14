#include "Pirate.h"

Pirate::Pirate()
{
	ship = new Ship("ship", 20, 20, 20, 100, false);

	//ship->addCannon(new HeavyCannon());
}

Pirate::~Pirate()
{
	delete ship;
}
