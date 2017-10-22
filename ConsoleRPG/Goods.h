#pragma once

#include <cstring>
#include "RandomGenerator.h"

class Goods
{
public:
	Goods() ;
	Goods(const char* pName);
	~Goods();

	inline const void setMinAmount(int const amount) { minAmount = amount; };
	inline const void setMaxAmount(int const amount) { maxAmount = amount; };
	inline const void setMinPrice(int const price) { minPrice = price; };
	inline const void setMaxPrice(int const price) { maxPrice = price; };
	inline const void setAmount(int const amount) { currentAmount = amount; };
	inline const void setPrice(int const price) { currentPrice = price; };

	inline const char* getName() const { return name; };
	inline const int getAmount() const { return currentAmount; };
	inline const int getPrice() const { return currentPrice; };
	
	const void randomGoods();

private:
	char name[32];

	int minAmount;
	int maxAmount;
	int minPrice;
	int maxPrice;

	int currentAmount;
	int currentPrice;
};
 
