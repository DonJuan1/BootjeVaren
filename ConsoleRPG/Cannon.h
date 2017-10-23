#pragma once

#include "RandomGenerator.h"

class Cannon
{
public:
	Cannon() {};
	Cannon(char* pName, int pPrice, int pAmount) : price(pPrice), amount(pAmount) { strcpy(name, pName); };
	virtual ~Cannon() {};

	virtual int testOutput() { return 5; }

	void setAmount(int pAmount){ amount = pAmount; }

	int getPrice() const { return price; }
	int getAmount() const { return amount; }
	int getDamage() const { return RandomGenerator::getInstance().generate(0, maxDamage); };
	
	void randomAmount() { amount = RandomGenerator::getInstance().generate(0, maxAmount); };

protected:
	char name[32];

	int maxDamage;
	int maxAmount;
	int amount;
	int price;
};
