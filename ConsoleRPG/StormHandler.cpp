#include "StormHandler.h"
#include "RandomGenerator.h"
#include "NormalHandler.h"
#include "NoneHandler.h"

int StormHandler::getSailTurns(Ship* ship)
{
	int damage = RandomGenerator::getInstance().generate(1, ship->getDamagePoints());
	ship->getHit(damage);

	int windChance = RandomGenerator::getInstance().generate(0, 100);
	if (windChance < 20) {
		NormalHandler wind;
		return wind.getSailTurns(ship);
	}
	else if (windChance > 60) {
		NoneHandler wind;
		return wind.getSailTurns(ship);
	}
	else {
		return -1;
	}
}
