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
	damagePoints{ pDamagePoint },
	hitPoints{ pDamagePoint }, 
	gold { 5000 },
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

Ship::Ship(Ship& otherShip)
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

void Ship::addCannon(Cannon* cannon) 
{
	cannonsUsed++;
	cannonsOnShip.push_back(cannon);
}

void Ship::deleteCannon(Cannon* cannon)
{
	cannonsUsed--;
	for (int i = 0; i < cannonsOnShip.size(); i++)
	{
		if (cannon == cannonsOnShip.at(i))
		{
			delete  cannonsOnShip.at(i);
			cannonsOnShip.pop_index(i);
		}
	}
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

void Ship::repairShip(int pGoldToRepair)
{
	int deltaPoints = hitPoints - damagePoints;
	if (deltaPoints < pGoldToRepair * 10)
	{
		int result = ((deltaPoints + 10 / 2) / 10) * 10;
		damagePoints = hitPoints;
		gold -= result / 10;
	}
	else
	{
		damagePoints += pGoldToRepair * 10;
		gold -= pGoldToRepair;
	}
}

void Ship::printStats() const
{
	cout << "----------------------------------------------------" << endl;
	cout << "Amount of Gold: " << gold << endl;
	cout << "Current ship: " << type << endl;
	cout << "Hitpoints of ship: " << hitPoints << "/" << damagePoints << endl;
	cout << "LoadSpace of ship: " << loadSpaceUsed << "/" << loadSpace << endl;
	cout << "----------------------------------------------------" << endl;
}
