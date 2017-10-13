#pragma once

#include <random>

class Cannon
{
public:
	Cannon(std::default_random_engine& generator);
	virtual ~Cannon() {};

	virtual int getDamage() = 0;

protected:
	std::default_random_engine* randomGenerator;

};