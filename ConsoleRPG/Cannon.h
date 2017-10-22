#pragma once

class Cannon
{
public:
	Cannon() {};
	Cannon(int pMaxAmount, int pPrice) : maxAmount(pMaxAmount), price{pPrice} {};
	virtual ~Cannon() = 0;

	virtual int getDamage() = 0;

protected:
	int maxDamage;
	int maxAmount;
	int price;
};
