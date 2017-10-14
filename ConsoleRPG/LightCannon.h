#pragma once

#include "Cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon(): Cannon() {};
	~LightCannon() {};

	int getDamage();

private:

};