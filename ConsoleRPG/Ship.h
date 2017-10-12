#pragma once

#include "Cannon.h"

class Ship
{
public:
	Ship();
	~Ship();

	void getHit(int damage);
	void addCannon(Cannon* cannon);
	int shootCannons();

private:
	int cannonCount = 0;
	Cannon** cannons;

	char type;
	int price;
	int loadSpace;
	int cannonry = 40;
	int damagePoints = 100;
	bool isSmall;

};

