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

void CSVParser::parseCSVCities(CustomVector<Goods*>& cityVector)
{

}
