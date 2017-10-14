#include "HeavyCannon.h"
#include "RandomGenerator.h"


int HeavyCannon::getDamage()
{
	return RandomGenerator::getInstance().generate(0,6);
}
