#include <iostream>

#include "Main.h"
#include "Game.h"
#include "CSVParser.h"

int main()
{
	Game game;
	CSVParser parser;

	parser.parseCSV();
	
	cin.get();

	return _CrtDumpMemoryLeaks();
}
