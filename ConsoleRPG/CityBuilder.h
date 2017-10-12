#pragma once

#include <iostream>

#include "ShipFactory.h"
#include "CityFactory.h"
#include "GoodsFactory.h"

using namespace std;

class CityBuilder
{
public:
	CityBuilder() {};
	~CityBuilder() {};

private:
	ShipFactory shipFactory;
	CityFactory cityFactory;
	GoodsFactory goodsfactory;



};
