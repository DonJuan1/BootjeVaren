#include "Goods.h"

Goods::Goods() : currentAmount{0}, currentPrice{0}
{

}

Goods::Goods(const char* pName) : currentAmount{0}, currentPrice{0}
{
	{ strcpy(name, pName); };
}

Goods::~Goods()
{
	
}

const void Goods::randomGoods()
{
	currentAmount = RandomGenerator::getInstance().generate(minAmount, maxAmount);
	currentPrice = RandomGenerator::getInstance().generate(minPrice, maxPrice);
}
