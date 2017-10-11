#include "CSVParser.h"

CSVParser::CSVParser()
{

}

CSVParser::~CSVParser()
{

}

void CSVParser::parseCSV()
{
	ifstream fileIn("./schepen.csv");
	
	char type[256];
	char price[256];
	char loadSpace[256];
	char cannonry[256];
	char damagePoint[256];
	char specialty[256];

	while (fileIn.good())
	{
		fileIn.getline(type, 256, ';');
		fileIn.getline(price, 256, ';');
		fileIn.getline(loadSpace, 256, ';');
		fileIn.getline(cannonry, 256, ';');
		fileIn.getline(damagePoint, 256, ';');
		fileIn.getline(specialty, 256);
		
		char *output = nullptr;
		output = std::strstr(type, "Pinnace");

		if (output)
		{
			cout << "Found substring" << endl;
		}
		else
		{
			cout << "Not found substring" << endl;
		}

		
	}

	cout << "Done reading CSV " << endl;

	fileIn.close();
}
