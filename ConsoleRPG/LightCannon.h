#pragma once

#include "Cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon() {};
	LightCannon(int pMaxAmount, int pPrice) : Cannon(pMaxAmount, pPrice) {};
	~LightCannon() {};

	int getDamage();

private:

};
