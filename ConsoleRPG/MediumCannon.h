#pragma once

#include "Cannon.h"

class MediumCannon : public Cannon
{
public:
	MediumCannon() : Cannon("Meduim", 200, 3) {};
	~MediumCannon() {};
};
