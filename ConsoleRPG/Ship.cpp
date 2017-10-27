#include <iostream>
#include "Ship.h"
#include "LightShip.h"

Ship::Ship()
{
	
}

Ship::Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall)
	: price{ pPrice }, 
	loadSpace{ pLoadSpace }, 
	cannonry{ pCannory }, 
	damagePoints{ pDamagePoint  },
	hitPoints{ pDamagePoint },
	gold { 0 },
	loadSpaceUsed{ 0 },
	cannonsUsed{ 0 },
	isSmall{ pIsSmall }
{
	strcpy(type, pType);
}

Ship::~Ship()
{
	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		delete cannonsOnShip.at(i);
	}
}

Ship::Ship(const Ship& otherShip)
{
	strcpy(type, otherShip.getType());

	price = otherShip.price;
	loadSpace = otherShip.loadSpace;
	cannonry = otherShip.cannonry;
	damagePoints = otherShip.damagePoints;
	hitPoints = otherShip.hitPoints;
	gold = otherShip.gold;
	isSmall = otherShip.isSmall;
	loadSpaceUsed = otherShip.loadSpaceUsed;
	cannonsUsed = otherShip.cannonsUsed;

	goodsOnShip = otherShip.goodsOnShip;
}

void Ship::getHit(int damage)
{
	if (damage >= hitPoints) 
	{
		hitPoints = 0;
	}
	else 
	{
		hitPoints = hitPoints - damage;
	}
}

void Ship::addCannon(Cannon* cannon, int amount) 
{
	cannonsUsed++;

	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		Cannon* cannonPointer = cannonsOnShip.at(i);
		if (strcmp(cannonPointer->getName(), cannon->getName()) == 0)
		{
			cannonPointer->setAmount(cannonPointer->getAmount() + amount);
			return;
		}
	}

	Cannon* cann = cannon->Clone();
	cann->setAmount(amount);
	cannonsOnShip.push_back(cann);
}

void Ship::deleteCannon(Cannon* cannon, int amount)
{
	cannonsUsed--;
	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		Cannon* cannonPointer = cannonsOnShip.at(i);
		if (strcmp(cannonPointer->getName(), cannon->getName()) == 0)
		{
			cannonPointer->setAmount(cannonPointer->getAmount() - amount);

			if (cannonPointer->getAmount() == 0)
			{
				delete cannonsOnShip.at(i);
				cannonsOnShip.pop_index(i);
			}
		}
	}
}

bool Ship::isHoldingHeavyCannons() const
{
	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		if (cannonsOnShip.at(i)->isHeavy())
		{
			return true;
		}
	}
	return false;
}

int Ship::shootCannons() const
{
	int damage = 0;

	for (int i = 0; i < cannonsOnShip.size(); i++) 
	{
		damage += cannonsOnShip.at(i)->getDamage();
	}

	return damage;
}

void Ship::addGoods(Goods& goods, int amount)
{
	loadSpaceUsed += amount;

	for (int i = 0; i < goodsOnShip.size(); i++)
	{
		if (strcmp(goods.getName(), goodsOnShip.at(i).getName()) == 0)
		{
			goodsOnShip.at(i).setAmount(goodsOnShip.at(i).getAmount() + amount);
			return;
		}
	}

	Goods newGoods(goods);
	newGoods.setAmount(amount);
	goodsOnShip.push_back(newGoods);
}

void Ship::deleteGoods(Goods& goods, int amount)
{
	loadSpaceUsed -= amount;

	for (int i = 0; i < goodsOnShip.size(); i++)
	{
		if (strcmp(goods.getName(), goodsOnShip.at(i).getName()) == 0)
		{
			if (goodsOnShip.at(i).getAmount() - amount <= 0)
			{
				goodsOnShip.pop_index(i);
			}
			else
			{
				goodsOnShip.at(i).setAmount(goodsOnShip.at(i).getAmount() - amount);
			}
			
			return;
		}
	}
}

void Ship::removeAllGoods() 
{
	for (int i = 0; i < goodsOnShip.size(); i++)
	{
		goodsOnShip.pop_index(i);
	}
}

void Ship::repairShip(int pGoldToRepair)
{
	int deltaPoints = damagePoints - hitPoints;
	if (deltaPoints < pGoldToRepair * 10)
	{
		int result = (10 - deltaPoints % 10) + deltaPoints;
		hitPoints = damagePoints;
		gold -= result / 10;
	}
	else
	{
		hitPoints += pGoldToRepair * 10;
		gold -= pGoldToRepair;
	}
}

void Ship::replaceShip(Ship* newShip)
{
	newShip->gold = gold;
	newShip->loadSpaceUsed = loadSpaceUsed;
	newShip->cannonsUsed = cannonsUsed;
	newShip->goodsOnShip = goodsOnShip;

	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		Cannon* cannon = cannonsOnShip.at(i)->Clone();
		newShip->cannonsOnShip.push_back(cannon);
	}
}

void Ship::printStats() const
{
	cout << "Amount of Gold: " << gold << endl;
	cout << "Current ship: " << type << endl;
	cout << "Hitpoints of ship: " << hitPoints << "/" << damagePoints << endl;
	cout << "LoadSpace of ship: " << loadSpaceUsed << "/" << loadSpace << endl;
	cout << "----------------------------" << endl;
}
