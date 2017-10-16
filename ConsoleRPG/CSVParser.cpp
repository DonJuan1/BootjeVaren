#define _CRT_SECURE_NO_WARNINGS

#include "CSVParser.h"

CSVParser::CSVParser()
{

}

CSVParser::~CSVParser()
{

}

void CSVParser::parseCSVShips(CustomVector<Ship*>& shipVector)
{
	ifstream fileIn("./schepen.csv");

	char price[32];
	char loadSpace[32];
	char cannonry[32];
	char damagePoints[32];
	char isSmall[32];

	//Ignore first line
	fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (fileIn.good())
	{
		char* type = new char[32];

		fileIn.getline(type, 32, ';');
		fileIn.getline(price, 32, ';');
		fileIn.getline(loadSpace, 32, ';');
		fileIn.getline(cannonry, 32, ';');
		fileIn.getline(damagePoints, 32, ';');
		fileIn.getline(isSmall, 32);

		if (strlen(type) == 0)
		{
			delete[] type;
			break;
		}

		int intPrice = atoi(price);
		int intLoadSpace = atoi(loadSpace);
		int intCannonry = atoi(cannonry);
		int intDamagePoints = atoi(damagePoints);
		
		Ship* ship = new Ship(type, intPrice, intLoadSpace, intCannonry, intDamagePoints, false);
		
		shipVector.push_back(ship);	
	}

	fileIn.close();
}

void CSVParser::parseCSVCities(CustomVector<City*>& cityVector)
{
	ifstream fileIn1;
	ifstream fileIn2;
	ifstream fileIn3;

	try
	{
		fileIn1.open("./afstanden tussen steden.csv");
		fileIn2.open("./goederen prijzen.csv");
		fileIn3.open("./goederen hoeveelheid.csv");

		if (!fileIn1.good() || !fileIn2.good() || !fileIn3.good())
		{
			throw std::runtime_error("Could not open file");
		}
	}
	catch(...)
	{
		throw std::runtime_error("Could not open file");
	}

	CustomVector<char*> goodsNameVector;

	for (size_t i = 0; i < 3; i++)
	{
		fileIn1.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char input[256];
	fileIn1.getline(input, 256);
	char *p = strtok(input, ";");;

	while (p != NULL)
	{
		City* city = new City(p);
		cityVector.push_back(city);
		p = strtok(NULL, ";");
	}
	
	fileIn1.close();
	fileIn2.close();
	fileIn3.close();
}
