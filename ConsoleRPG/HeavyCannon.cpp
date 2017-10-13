#include "HeavyCannon.h"


int HeavyCannon::getDamage()
{
	std::uniform_int_distribution<int> distribution1(0, 6);
	return distribution1(randomGenerator);
}
