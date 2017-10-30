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

Ship& ShipFactory::getRandomShip() const
{
	RandomGenerator &random = RandomGenerator::getInstance();
	int randomIndex = random.generate(0, shipVector.size() - 1);

	return *shipVector.at(randomIndex);
}

Ship& ShipFactory::getShipWithType(const char* shipType) const
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

CustomVector<Ship*>& ShipFactory::getShipVector(){
	return shipVector;
}
