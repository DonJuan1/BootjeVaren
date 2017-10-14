#include "ShipFactory.h"
#include "RandomGenerator.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"
#include "NormalShip.h"

Ship* ShipFactory::getRandomShip(bool withCannons)
{
	RandomGenerator &random = RandomGenerator::getInstance();

	// Replace with getting 1 out of the list.
	Ship *ship = new NormalShip("pirateship",10,10,40,100,false);

	if (withCannons) {
		int amountCannons = random.generate(0, ship->getCannonry());

		for (int i = 0; i < amountCannons; i++) {

			switch (random.generate(1, (ship->canHoldHeavyCannons()? 3 : 2))) {
				case 1:			
					ship->addCannon(new LightCannon());
					break;
				case 2:
					ship->addCannon(new MediumCannon());
					break;
				case 3:
					ship->addCannon(new HeavyCannon());
					break;
			}

		}
	}

	return ship;
}
