#include "CSVParser.h"

CSVParser::CSVParser()
{

}

CSVParser::~CSVParser()
{

}

void CSVParser::parseCSV()
{
	ifstream fileIn("C:/Users/Jonathan/Desktop/csv/schepen.csv");
	
	char type[256];
	char price[256];
	char loadSpace[256];
	char cannonry[256];
	char damagePoint[256];
	char specialty[256];

	while (fileIn.good())
	{
		fileIn.getline(type, 1024, ';');
		fileIn.getline(price, 1024, ';');
		fileIn.getline(loadSpace, 1024, ';');
		fileIn.getline(cannonry, 1024, ';');
		fileIn.getline(damagePoint, 1024, ';');
		fileIn.getline(specialty, 1024);
		
		cout << price << endl;
	}

	cout << "Done reading CSV " << endl;

	fileIn.close();
}
