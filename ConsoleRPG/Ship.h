#pragma once

#include "Cannon.h"
#include "CustomVector.h"
#include "Goods.h"
#include <cstring>
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"

class Ship
{
public:
	Ship();
	Ship(const char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall);	
	Ship(const Ship& otherShip);
	virtual ~Ship();

	void getHit(int damage);
	
	virtual Ship* clone() const { return new Ship(*this); };
	virtual int getBaseFlightChance() const { return 0; };
	virtual int getModifierFlightChance() const { return 0; };

	inline const char* getType() const { return this->type; }
	inline const int& getPrice() const { return this->price; }
	inline const int& getLoadSpace() const { return this->loadSpace; }
	inline const int& getCannonry() const { return this->cannonry; }
	inline const int& getDamagePoints() const { return this->damagePoints; }
	inline const bool& getIsSmall() const { return this->isSmall; }
	inline const int& getGold() const { return this->gold; }
	inline const int& getHitPoints() const { return this->hitPoints; }
	inline const int& getLoadSpaceUsed() const { return loadSpaceUsed; }
	inline const int getUnusedLoadSpace() const {return loadSpace - loadSpaceUsed; }
	inline const int getUnusedCannonSpace() const { return cannonry - cannonsUsed; }
	
	inline const void changeGold(const int pGold) { gold += pGold; }
	inline const CustomVector<Goods>& getGoodsOnShip() const { return goodsOnShip; }
	inline const CustomVector<Cannon*>& getCannonsOnShip() const { return cannonsOnShip; }

	inline void setGold(int pGold) { gold = pGold; }
	inline void setLoadSpaceUsed(int spaceUsed) { loadSpaceUsed = spaceUsed; }
	inline void setGoodsVector(const CustomVector<Goods>& goods) { goodsOnShip = goods; }

	void printStats() const;
	void printPirateStats() const;
	int shootCannons() const;

	void addGoods(const Goods& goods, int amount);
	void deleteGoods(const Goods& goods, int amount);
	void addCannon(Cannon* cannon, int amount) ;
	void deleteCannon(const Cannon* cannon, int amount);
	void removeAllGoods();
	void repairShip(int pGoldToRepair);
	void replaceShip(Ship* newShip);

	void addPirateCannons();

	bool isHoldingHeavyCannons() const;

	inline const bool canHoldHeavyCannons() const { return !isSmall; }
	inline const bool isDead() const { return (hitPoints <= 0); }


private:
	char type[32];
	
	int price;
	int loadSpace; 
	int cannonry;
	int damagePoints;
	int hitPoints;
	int gold;
	
	int cannonsUsed;
	int loadSpaceUsed;

	bool isSmall;

	CustomVector<Goods> goodsOnShip;
	CustomVector<Cannon*> cannonsOnShip;
	
};

