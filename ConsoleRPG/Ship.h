#pragma once

#include "Cannon.h"

class Ship
{
public:
	Ship();
	Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall);
	virtual ~Ship();

	void getHit(int damage);
	void addCannon(Cannon* cannon);
	int shootCannons();
	virtual int getBaseFlightChance() { return 0; };
	virtual int getModifierFlightChance() { return 0; };

	inline const char* getType() const { return this->type; }
	inline const int& getPrice() const { return this->price; }
	inline const int& getLoadSpace() const { return this->loadSpace; }
	inline const int& getCannonry() const { return this->cannonry; }
	inline const int& getDamagePoints() const { return this->damagePoints; }
	inline const bool& getIsSmall() const { return this->isSmall; }

	inline const int& getHitPoints() const { return this->hitPoints; }

	bool canHoldHeavyCannons() { return !isSmall; }
	bool isDead() { return (hitPoints <= 0); }

	int cannonCount = 0;
private:
	Cannon** cannons;

	char* type;
	int price;
	int loadSpace; 
	int cannonry;
	int damagePoints;
	bool isSmall;

	int hitPoints;
};

