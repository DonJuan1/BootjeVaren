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
	
	char buffer[256];

	fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (fileIn.good())
	{
		fileIn.getline(buffer, 256);
		
		cout << buffer << endl;
		
	}

	cout << "Done reading CSV " << endl;

	fileIn.close();

	cin.get();
}
