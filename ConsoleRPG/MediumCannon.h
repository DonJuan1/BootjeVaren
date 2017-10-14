#pragma once

#include "Cannon.h"

class MediumCannon : public Cannon
{
public:
	MediumCannon() : Cannon() {};
	~MediumCannon() {};

	int getDamage();

private:

};