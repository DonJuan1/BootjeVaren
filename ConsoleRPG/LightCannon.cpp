#include "LightCannon.h"

#include <random>
#include <ctime>

int LightCannon::getDamage()
{
	std::uniform_int_distribution<int> distribution1(0, 2);
	return distribution1(randomGenerator);
}
