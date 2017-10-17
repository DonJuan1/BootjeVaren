#pragma once

class Goods
{
public:
	Goods() {};
	Goods(const char* pName) { strcpy(name, pName); };
	~Goods() {};

	inline const void setMinAmount(int const amount) { minAmount = amount; };
	inline const void setMaxAmount(int const amount) { maxAmount = amount; };
	inline const void setMinPrice(int const amount) { minPrice = amount; };
	inline const void setMaxPrice(int const amount) { maxPrice = amount; };

	inline const char* getName() { return name; };
	inline const int getMinAmount() { return minAmount; };
	inline const int getMaxAmount() { return maxAmount; };
	inline const int getMinPrice() { return minPrice; };
	inline const int getMaxPrice() { return maxPrice; };

private:
	char name[32];

	int minAmount;
	int maxAmount;
	int minPrice;
	int maxPrice;

};
 
