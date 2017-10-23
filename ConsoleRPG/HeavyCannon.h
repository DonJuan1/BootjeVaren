#pragma once

#include "Cannon.h"
#include "RandomGenerator.h"

class HeavyCannon : public Cannon
{
public:
	HeavyCannon() : Cannon("Heavy", 1000, 2) {};
	~HeavyCannon() {};

	int testOutput() override { return 1; }
};
