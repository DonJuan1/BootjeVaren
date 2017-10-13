#pragma once

#include "Cannon.h"

class MediumCannon : public Cannon
{
public:
	MediumCannon(std::default_random_engine& generator) : Cannon(generator) {};
	~MediumCannon() {};

	int getDamage();

private:

};