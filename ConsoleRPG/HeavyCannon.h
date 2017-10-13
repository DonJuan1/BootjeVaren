#pragma once

#include "Cannon.h"

class HeavyCannon : public Cannon
{
public:
	HeavyCannon(std::default_random_engine& generator) : Cannon(generator) {};
	~HeavyCannon() {};

	int getDamage();

private:

};