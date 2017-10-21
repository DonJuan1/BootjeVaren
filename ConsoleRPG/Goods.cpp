#include "Goods.h"

Goods::Goods()
{

}

Goods::Goods(const char* pName)
{
	{ strcpy(name, pName); };
}

Goods::~Goods()
{
	
}
