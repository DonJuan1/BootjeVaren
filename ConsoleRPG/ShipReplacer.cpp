#include "ShipReplacer.h"

ShipReplacer::ShipReplacer(Ship* pNewShip, Ship* pOldShip)
{
	newShip = pNewShip;

	newShip->setGold(pOldShip->getGold());
	newShip->setLoadSpaceUsed(pOldShip->getLoadSpaceUsed());
	newShip->setGoodsVector(pOldShip->getGoodsOnShip());

	for (int i = 0; i < pOldShip->getCannonsOnShip().size(); i++)
	{
		Cannon* cannon = pOldShip->getCannonsOnShip().at(i);
		newShip->addCannon(cannon, cannon->getAmount());
	}
}

ShipReplacer::~ShipReplacer()
{
	delete newShip;
}
