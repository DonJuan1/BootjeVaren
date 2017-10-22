#include "LightCannon.h"
#include "RandomGenerator.h"

int LightCannon::getDamage()
{
	return RandomGenerator::getInstance().generate(0, 2);
}
