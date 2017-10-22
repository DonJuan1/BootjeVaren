#pragma once

#include "Cannon.h"
#include "RandomGenerator.h"

class HeavyCannon : public Cannon
{
public:
	HeavyCannon() {};
	HeavyCannon(int pMaxAmount, int pPrice) : Cannon(pMaxAmount, pPrice) {};
	~HeavyCannon() {};

	int getDamage() override { return RandomGenerator::getInstance().generate(0, maxDamage); };
};
