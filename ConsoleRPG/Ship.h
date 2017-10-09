#pragma once

class Ship
{
public:
	Ship();
	virtual ~Ship();

private:

	char type;
	int price;
	int loadSpace;
	int cannonry;
	int damagePoint;
	int specialty;
};

