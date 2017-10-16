#pragma once

class Goods
{
public:
	Goods() {};
	Goods(int pMinAmount, int pMaxAmount, int pMinPrice, int pMaxPrice) 
		: minAmount(pMinAmount), maxAmount(pMaxAmount), minPrice(pMinPrice), maxPrice(pMaxPrice) {};
	~Goods() {};

private:
	char name[32];

	int minAmount;
	int maxAmount;
	int minPrice;
	int maxPrice;

};
