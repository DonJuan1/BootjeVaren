#pragma once

#include "Cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon() : Cannon("Light", 50, 5, 2) {};
	~LightCannon() {};

	int testOutput() override { return 69; }
	Cannon* Clone() const override { return new LightCannon(*this); };
};
