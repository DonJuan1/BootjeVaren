#include "ShipFactory.h"
#include "RandomGenerator.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"
#include "NormalShip.h"

Ship* ShipFactory::getRandomShip(bool withCannons)
{
	RandomGenerator &random = RandomGenerator::getInstance();
	int randomIndex = random.generate(0, shipVector.size());


	// Replace with getting 1 out of the list.
	Ship *ship = new Ship(shipVector.at(randomIndex));

	/*if (withCannons) {
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
	}*/

	return ship;
}

CustomVector<Ship>& ShipFactory::getShipVector() {
	return shipVector;
}
