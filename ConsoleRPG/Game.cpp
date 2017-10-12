
#include <stdlib.h>

#include "Game.h"



Game::Game()
{

	parser.parseCSV();


	// Csv objects to factories

	setState(new City());


	int choice;
	while (state != nullptr) {
		
		system("cls");
		

		cout << "Aantal goud: " << gold << endl;

		state->processState(this);
	}
}

Game::~Game()
{

}

void Game::setState(LocationState * s)
{
	state = s;
}

void Game::setNextCity(City * c)
{
	nextCity = c;
}

//void Game::mainMenu()
//{
//	//cout << "MAIN MENU" << endl << endl;
//	//cout << "0: Quit" << endl;
//	//cout << "1: Travel" << endl;
//	//cout << "2: Shop" << endl;
//	//cout << "3: Level up" << endl;
//	//cout << "0: Rest" << endl;
//
//	//cout << endl << "Choice: " ;
//
//	//cin >> choice;
//	//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input
//
//	//switch (choice)
//	//{
//	//	case 0:
//	//		playing = false;
//	//		break;
//	//	default:
//	//		break;
//	//}
//}
//
//bool Game::getPlaying() const
//{
//	//return this->playing;
//}
