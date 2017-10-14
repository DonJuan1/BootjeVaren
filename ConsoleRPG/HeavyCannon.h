#pragma once

#include "Cannon.h"

class HeavyCannon : public Cannon
{
public:
	HeavyCannon() : Cannon() {};
	~HeavyCannon() {};

	int getDamage();

private:

};