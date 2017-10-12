#pragma once

#include "Canon.h"

class Ship
{
public:
	Ship();
	~Ship();

private:

	char type;
	int price;
	int loadSpace;
	int cannonry;
	int damagePoints;
	bool isSmall;

};

