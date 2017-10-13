#pragma once

#include "Cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon(std::default_random_engine& generator): Cannon(generator) {};
	~LightCannon() {};

	int getDamage();

private:

};