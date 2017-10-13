#pragma once

#include "Cannon.h"

class Ship
{
public:
	Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall);
	~Ship();

	void getHit(int damage);
	void addCannon(Cannon* cannon);
	int shootCannons();

	inline const char* getType() const { return this->type; }
	inline const int& getPrice() const { return this->price; }
	inline const int& getLoadSpace() const { return this->loadSpace; }
	inline const int& getCannonry() const { return this->cannonry; }
	inline const int& getDamagePoints() const { return this->damagePoints; }
	inline const bool& getIsSmall() const { return this->isSmall; }

private:
	int cannonCount = 0;
	Cannon** cannons;

	char* type;
	int price;
	int loadSpace; 
	int cannonry;
	int damagePoints;
	bool isSmall;

};

