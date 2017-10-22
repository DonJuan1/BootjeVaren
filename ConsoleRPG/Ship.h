#pragma once

#include "Cannon.h"
#include "CustomVector.h"
#include "Goods.h"
#include <cstring>

class Ship
{
public:
	Ship();
	Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall);	
	Ship(Ship& otherShip);
	virtual ~Ship();

	void getHit(int damage);
	void addCannon(Cannon& cannon);
	int shootCannons();
	virtual int getBaseFlightChance() { return 0; };
	virtual int getModifierFlightChance() { return 0; };

	inline const char* getType() const { return this->type; }
	inline const int& getPrice() const { return this->price; }
	inline const int& getLoadSpace() const { return this->loadSpace; }
	inline const int& getCannonry() const { return this->cannonry; }
	inline const int& getDamagePoints() const { return this->damagePoints; }
	inline const bool& getIsSmall() const { return this->isSmall; }
	inline const int& getGold() const { return this->gold; }

	inline const int& getHitPoints() const { return this->hitPoints; }
	inline const int getUnusedLoadSpace() const {return loadSpace - loadSpaceUsed; }

	inline const void changeGold(const int pGold) { gold += pGold; }

	void printStats();
	void addGoods(Goods& goods, int amount);

	bool canHoldHeavyCannons() { return !isSmall; }
	bool isDead() { return (hitPoints <= 0); }


private:
	char type[32];
	
	int price;
	int loadSpace; 
	int cannonry;
	int damagePoints;
	int hitPoints;
	int gold;
	int loadSpaceUsed;

	bool isSmall;

	CustomVector<Goods> goodsOnShip;
	
};

