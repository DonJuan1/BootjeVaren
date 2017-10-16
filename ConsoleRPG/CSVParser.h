#pragma once

#include <iostream>
#include <fstream> 

#include "Ship.h"
#include "Goods.h"
#include "CustomVector.h"

using namespace std;

class CSVParser
{
public:
	CSVParser();
	virtual ~CSVParser();

	void parseCSVShips(CustomVector<Ship*>&);
	void parseCSVCities(CustomVector<Goods*>&);

private:


};
