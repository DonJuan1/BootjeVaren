#include "MediumCannon.h"
#include "RandomGenerator.h"

int MediumCannon::getDamage()
{
	return RandomGenerator::getInstance().generate(0, 6);
}