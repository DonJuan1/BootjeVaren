#pragma once

#include <iostream>

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

};
