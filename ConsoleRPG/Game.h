#pragma once

#include <iostream>
#include "CSVParser.h"
#include "CityBuilder.h"

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	void mainMenu();

	bool getPlaying() const;

private:
	int choice;
	bool playing;
	CSVParser parser;
	CityBuilder cityBuilder;

	

};
