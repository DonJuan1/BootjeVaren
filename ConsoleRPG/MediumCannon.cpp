#include "MediumCannon.h"
#include <random>
#include <ctime>

int MediumCannon::getDamage()
{
	std::uniform_int_distribution<int> distribution1(0, 4);
	return distribution1(randomGenerator);
}