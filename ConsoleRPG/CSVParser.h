#pragma once

#include <iostream>
#include <fstream> 
#include "Ship.h"
#include "Pirate.h"
#include "CustomVector.h"

using namespace std;

class CSVParser
{
public:
	CSVParser();
	virtual ~CSVParser();

	void parseCSV();

private:


};
