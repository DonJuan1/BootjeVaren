#pragma once

#include "RandomGenerator.h"

class Cannon
{
public:
	Cannon() {};
	Cannon(const char* pName, int pPrice, int pAmount, int pDamage) : price(pPrice), maxAmount(pAmount), maxDamage(pDamage) { strcpy(name, pName); };
	virtual ~Cannon() {};

	virtual bool isHeavy() const { return false; };
	virtual Cannon* Clone() const { return new Cannon(*this); };

	void setAmount(int pAmount){ amount = pAmount; }

	const char* getName() const { return this->name; }
	int getPrice() const { return price; }
	int getAmount() const { return amount; }
	int getDamage() const { return RandomGenerator::getInstance().generate(0, maxDamage); };
	
	void randomAmount() { amount = RandomGenerator::getInstance().generate(0, maxAmount); };
	

private:
	char name[32];

	int maxDamage;
	int maxAmount;
	int amount;
	int price;
};
