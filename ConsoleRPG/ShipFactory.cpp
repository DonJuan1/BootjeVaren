#include "ShipFactory.h"
#include "RandomGenerator.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"
#include "NormalShip.h"

ShipFactory::ShipFactory()
{

}

ShipFactory::~ShipFactory()
{
	for (int i = 0; i < shipVector.size(); i++)
	{
		delete shipVector.at(i);
	}
}

Ship& ShipFactory::getRandomShip(bool withCannons)
{
	RandomGenerator &random = RandomGenerator::getInstance();
	int randomIndex = random.generate(0, shipVector.size());

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

	return *shipVector.at(randomIndex);
}

Ship& ShipFactory::getShipWithType(char* shipType)
{
	for (int i = 0; i < shipVector.size(); i++)
	{
		if (strcmp(shipVector.at(i)->getType(), shipType) == 0)
		{
			return *shipVector.at(i);
		}
	}

	throw std::runtime_error("Exception caught: Ship not found");
}

CustomVector<Ship*>& ShipFactory::getShipVector() {
	return shipVector;
}
