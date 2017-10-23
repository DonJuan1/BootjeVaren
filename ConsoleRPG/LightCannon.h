#pragma once

#include "Cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon() : Cannon("Light", 50, 5) {};
	~LightCannon() {};

	int testOutput() override { return 69; }
};
