#pragma once

#include <iostream>
#include <fstream> 

#include "Ship.h"
#include "City.h"
#include "Goods.h"
#include "CustomVector.h"

using namespace std;

class City;
class Ship;

class CSVParser
{
public:
	CSVParser();
	virtual ~CSVParser();

	void parseCSVShips(CustomVector<Ship*>&);
	void parseCSVCities(CustomVector<City*>&);

private:


};
