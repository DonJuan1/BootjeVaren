#pragma once

#include "Cannon.h"

class MediumCannon : public Cannon
{
public:
	MediumCannon() {};
	MediumCannon(int pMaxAmount, int pPrice) : Cannon(pMaxAmount, pPrice) {};
	~MediumCannon() {};

	int getDamage();

private:

};
