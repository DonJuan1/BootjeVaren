#include "City.h"
#include "Game.h"

City::City()
{

}

City::City(const char* pName)
{
	strcpy(name, pName);

	cannonVector.push_back(new LightCannon());
	cannonVector.push_back(new MediumCannon());
	cannonVector.push_back(new HeavyCannon());
}

City::City(const City& otherCity)
{	
	if (this != &otherCity)
	{
		strcpy(name, otherCity.getName());

		goodsVector = otherCity.getGoodsVector();
		cityDestinationVector = otherCity.getCityDestinationVector();
		
		for (int i = 0; i < otherCity.getCannonVector().size(); i++)
		{
			cannonVector.push_back(otherCity.getCannonVector().at(i)->Clone());
			cannonVector.at(i)->randomAmount();
		}

		for (int i = 0; i < goodsVector.size(); i++)
		{
			goodsVector.at(i).randomGoods();
		}
	}
}

City::~City()
{
	for (int i = 0; i < cannonVector.size(); i++)
	{
		delete cannonVector.at(i);
	}
}

City& City::operator=(const City& otherCity)
{
	if (this != &otherCity)
	{
		strcpy(name, otherCity.getName());

		goodsVector = otherCity.getGoodsVector();
		cityDestinationVector = otherCity.getCityDestinationVector();

		for (int i = 0; i < otherCity.getCannonVector().size(); i++)
		{
			cannonVector.push_back(otherCity.getCannonVector().at(i)->Clone());
			cannonVector.at(i)->randomAmount();
		}

		for (int i = 0; i < goodsVector.size(); i++)
		{
			goodsVector.at(i).randomGoods();
		}
	}

	return *this;
}

void City::processState(Game& game)
{
	system("cls");

	game.getShip()->printStats();

	cout << endl;
	cout << "You are in the city " << name << endl;
	cout << "" << endl;
	cout << "1: Buy goods" << endl;
	cout << "2: Sell goods" << endl;
	cout << "3: Buy cannons" << endl;
	cout << "4: Sell cannons" << endl;
	cout << "5: Sail to next city" << endl;
	cout << "6: Repare ship" << endl;
	cout << "7: Replace ship" << endl;
	cout << "8: Quit" << endl;
	cout << "" << endl;
	cout << "Option: ";
		
	int choice = 0;
	cin >> choice;

	while (!cin && cin.fail())
	{
		cout << "No valid input! Option: ";
		std::cin.clear();
		std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}

	switch (choice)
	{
		case 1:
			buyGoods(game);
			break;
		case 2:
			sellGoods(game);
			break;
		case 3:
			buyCannons(game);
			break;
		case 4:
			sellCannons(game);
			break;
		case 5:
			sailAway(game);
			break;
		case 6:
			repairShip(game);
			break;
		case 7:
			replaceShip(game);
			break;
		case 8:
			game.setState(nullptr);
			delete this;
			return;
		
	}
}

void City::buyGoods(const Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the shop of " << name << endl;
		cout << endl;
		cout << "Here are the goods you can buy:" << endl;
		cout << endl;

		printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Ton)");

		for (int i = 1; i < goodsVector.size() + 1; i++)
		{
			Goods& goods = goodsVector.at(i - 1);
			printf("%-2i %-12s %-12i %-12i\n", i, goods.getName(), goods.getPrice(), goods.getAmount());
		}

		cout << "" << endl;
		cout << "Select a number to select a product or 0 to quit the shop: ";

		int choice;
		cin >> choice;

		while (cin.fail())
		{
			cout << "No number selected! Select a number to select a product or 0 to quit the shop: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0)
		{
			return;
		}
		else if (choice > 0 && choice < goodsVector.size() + 1)
		{
			Goods& goods = goodsVector.at(choice - 1);
			
			while (true)
			{
				cout << "You selected: " << goods.getName() << ", selected the amount you want to buy: ";
				cin >> choice;

				while (cin.fail())
				{
					cout << "No number selected! Selected the amount you want to buy: ";
					std::cin.clear();
					std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> choice;
				}

				if (choice == 0)
				{
					break;
				}

				if (goods.getAmount() >= choice)
				{
					if (game.getShip()->getUnusedLoadSpace() >= choice)
					{
						int totalPrice = choice * goods.getPrice();
						if (game.getShip()->getGold() >= totalPrice)
						{
							goods.setAmount(goods.getAmount() - choice);
							game.getShip()->changeGold(-totalPrice);
							game.getShip()->addGoods(goods, choice);
							break;
						}
						else
						{
							cout << "You dont have that much cash, you poor bastard!" << endl;
						}
					}
					else
					{
						cout << "Your ship cannot carry that many goods!" << endl;
					}
				}
				else
				{
					cout << "Whooo, we dont have that many! " << goods.getName() <<  endl;
				}
				
			}
		}
	}
}

void City::sellGoods(const Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the shop of " << name << endl;
		cout << endl;
		
		if (game.getShip()->getGoodsOnShip().size() <= 0)
		{
			cout << "You have nothing to sell!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return;
		}
		else
		{
			cout << "Here are the goods you can sell:" << endl;
			cout << endl;
			printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Ton)");

			for (int i = 1; i < game.getShip()->getGoodsOnShip().size() + 1; i++)
			{
				Goods& goods = game.getShip()->getGoodsOnShip().at(i - 1);

				for (int i = 0; i < goodsVector.size(); i++)
				{
					if (strcmp(goods.getName(), goodsVector.at(i).getName()) == 0)
					{
						goods.setPrice(goodsVector.at(i).getPrice());
					}
				}

				printf("%-2i %-12s %-12i %-12i\n", i, goods.getName(), goods.getPrice(), goods.getAmount());
			}

			cout << "" << endl;
			cout << "Select a number to select a product or 0 to quit the shop: ";

			int choice;
			cin >> choice;

			while (cin.fail())
			{
				cout << "No number selected! Select a number to select a product or 0 to quit the shop: ";
				std::cin.clear();
				std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> choice;
			}

			if (choice == 0)
			{
				return;
			}
			else if (choice > 0 && choice < game.getShip()->getGoodsOnShip().size() + 1)
			{
				Goods& goods = game.getShip()->getGoodsOnShip().at(choice - 1);

				while (true)
				{
					cout << "You selected: " << goods.getName() << ", selected the amount you want to buy: ";
					cin >> choice;

					while (cin.fail())
					{
						cout << "No number selected! Selected the amount you want to buy: ";
						std::cin.clear();
						std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
						std::cin >> choice;
					}

					if (choice == 0)
					{
						break;
					}

					if (goods.getAmount() >= choice)
					{
						int totalPrice = choice * goods.getPrice();

						for (int i = 0; i < goodsVector.size(); i++)
						{
							if (strcmp(goods.getName(), goodsVector.at(i).getName()) == 0)
							{
								goodsVector.at(i).setAmount(goodsVector.at(i).getAmount() + choice);
							}
						}

						game.getShip()->changeGold(totalPrice);
						game.getShip()->deleteGoods(goods, choice);

						break;
					}
					else
					{
						cout << "Whooo, you dont have that many! " << goods.getName() << endl;
					}
				}
			}
		}
	}
}

void City::buyCannons(const Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the cannon shop of " << name << endl;
		cout << endl;
		cout << "Here are the cannons you can buy:" << endl;
		cout << endl;

		printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Unit)");

		for (int i = 1; i < cannonVector.size() + 1; i++)
		{
			Cannon* cannon = cannonVector.at(i - 1);
			printf("%-2i %-12s %-12i %-12i\n", i, cannon->getName(), cannon->getPrice(), cannon->getAmount());
		}

		cout << "" << endl;
		cout << "Select a number to select a cannon or 0 to quit the shop: ";

		int choice;
		cin >> choice;

		while (cin.fail())
		{
			cout << "No number selected! Select a number to select a cannon or 0 to quit the shop: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0)
		{
			return;
		}
		else if (choice > 0 && choice < cannonVector.size() + 1)
		{
			Cannon* cannon = cannonVector.at(choice - 1);

			while (true)
			{
				cout << "You selected: " << cannon->getName() << ", selected the amount you want to buy: ";
				cin >> choice;

				while (cin.fail())
				{
					cout << "No number selected! Selected the amount you want to buy: ";
					std::cin.clear();
					std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> choice;
				}

				if (choice == 0)
				{
					break;
				}

				if (!(game.getShip()->getIsSmall() && cannon->isHeavy()))
				{
					if (cannon->getAmount() >= choice)
					{
						if (game.getShip()->getUnusedCannonSpace() >= choice)
						{
							int totalPrice = choice * cannon->getPrice();

							if (totalPrice <= game.getShip()->getGold())
							{
								game.getShip()->addCannon(cannon, choice);
								game.getShip()->changeGold(-totalPrice);
								cannon->setAmount(cannon->getAmount() - choice);
								break;
							}
							else
							{
								cout << "You dont have that much cash, you poor bastard!" << endl;
							}
						}
						else
						{
							cout << "You dont have enough cannon space!" << endl;
						}
					}
					else
					{
						cout << "Whooo, we dont have that many " << cannon->getName() << " !" << endl;
					}
				}
				else
				{
					cout << "Your ship is to small for that heavy cannon!" << endl;
				}
			}
		}
	}
}

void City::sellCannons(const Game& game)
{
	while (true) 
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the cannon shop of " << name << endl;
		cout << endl;
		cout << "Here are the cannons you can sell:" << endl;
		cout << endl;

		printf("%-2s %-12s %-12s %-12s\n", "#", "Name", "Price (G)", "Amount (Unit)");

		for (int i = 1; i < game.getShip()->getCannonsOnShip().size() + 1; i++)
		{
			Cannon* cannon = game.getShip()->getCannonsOnShip().at(i - 1);
			printf("%-2i %-12s %-12i %-12i\n", i, cannon->getName(), cannon->getPrice(), cannon->getAmount());
		}

		cout << "" << endl;
		cout << "Select a number to select a cannon or 0 to quit the shop: ";

		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cout << "No number selected! Select a number to select a cannon or 0 to quit the shop: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0) 
		{
			return;
		}
		else if (choice > 0 && choice < game.getShip()->getCannonsOnShip().size() + 1) 
		{
			Cannon* cannon = game.getShip()->getCannonsOnShip().at(choice - 1);

			while (true)
			{
				cout << "You selected: " << cannon->getName() << ", selected the amount you want to buy: ";
				cin >> choice;

				while (cin.fail())
				{
					cout << "No number selected! Selected the amount you want to buy: ";
					std::cin.clear();
					std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> choice;
				}

				if (choice == 0)
				{
					break;
				}

				if (cannon->getAmount() >= choice)
				{					
					int totalPrice = choice * cannon->getPrice();

					for (int i = 0; i < cannonVector.size(); i++)
					{
						if (strcmp(cannon->getName(), cannonVector.at(i)->getName()) == 0)
						{
							cannonVector.at(i)->setAmount(cannonVector.at(i)->getAmount() + choice);
						}
					}

					game.getShip()->deleteCannon(cannon, choice);
					game.getShip()->changeGold(totalPrice);
					break;
			
				}
				else
				{
					cout << "Whooo, you dont have that many " << cannon->getName() << " !" << endl;
				}
			}
		}
	}
	
}

void City::sailAway(Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are planning your next trip" << endl;
		cout << endl;
		cout << "Here is a list of places to go" << endl;
		cout << endl;

		printf("%-2s %-20s %-16s\n", "#", "City", "Distance (turns)");

		for (int i = 1; i < cityDestinationVector.size() + 1; i++)
		{
			printf("%-2i %-20s %-2i \n", i, cityDestinationVector.at(i - 1).destination->getName(), cityDestinationVector.at(i - 1).turns);
		}

		cout << endl;
		cout << "Select a place where you want to go to: ";

		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cout << "No number selected! Select a place where you want to go to: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0)
		{
			return;
		}
		else if (choice > 0 && choice < cityDestinationVector.size() + 1)
		{
			if (strcmp(cityDestinationVector.at(choice - 1).destination->getName(), name) != 0)
			{
				CityDestination& cityDestination = cityDestinationVector.at(choice - 1);
				game.setState(new Sea(cityDestination));
				delete this;
				return;
			}
		}
	}
}

void City::replaceShip(Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the ship shop of " << name << endl;
		cout << endl;
		cout << "Here is a list of ships to buy: " << endl;
		cout << endl;

		printf("%-2s %-20s %-16s\n", "#", "Name", "Price (G)");

		for (int i = 1; i < game.getShipFactory().getShipVector().size() + 1; i++)
		{
			printf("%-2i %-20s %-16i\n", i, game.getShipFactory().getShipVector().at(i - 1)->getType(), game.getShipFactory().getShipVector().at(i - 1)->getPrice());
		}

		cout << endl;
		cout << "Select a ship you want to buy: ";

		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cout << "No number selected! Select a ship you want to buy: ";
			std::cin.clear();
			std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> choice;
		}

		if (choice == 0)
		{
			break;
		}
		else if (choice > 0 && choice < game.getShipFactory().getShipVector().size() + 1)
		{
			Ship* shipToBuy = game.getShipFactory().getShipVector().at(choice - 1);

			while (true)
			{
				if (!(game.getShip()->isHoldingHeavyCannons() && !shipToBuy->canHoldHeavyCannons()))
				{
					if (shipToBuy->getPrice() < game.getShip()->getGold())
					{
						if (shipToBuy->getLoadSpace() > game.getShip()->getLoadSpace() - game.getShip()->getUnusedLoadSpace())
						{
							game.getShip()->changeGold(game.getShip()->getPrice() / 2);

							ShipReplacer shipReplacer(shipToBuy->clone(), game.getShip());
							game.setShip(shipReplacer.getNewShip());
							shipReplacer.clearReplacer();
							game.getShip()->changeGold(-game.getShip()->getPrice());

							break;
						}	
						else
						{
							cout << "The new ship does not have enough loadspace!" << endl;
						}
					}
					else
					{
						cout << "You dont have enough money to buy that ship!" << endl;
					}
				}
				else
				{
					cout << "You are carrying heavy cannons and that new ship cant carry that!" << endl;
				}

				cin >> choice;
				while (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> choice;
				}

				break;
			}
		}
	}
}

void City::repairShip(const Game& game)
{
	while (true)
	{
		system("cls");

		game.getShip()->printStats();

		cout << "You are in the docks of " << name << endl;
		cout << endl;
		cout << "Here you can repair your ship for only 1G" << endl;
		cout << endl;

		if (game.getShip()->getDamagePoints() == game.getShip()->getHitPoints())
		{
			cout << "Your ship doens't have any damage!";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return;
		}
		else
		{
			cout << "How much gold do you want to spent to repair your ship: ";

			int choice;
			cin >> choice;
			while (cin.fail())
			{
				cout << "No number selected! How much gold do you want to spent to repair your ship: ";
				std::cin.clear();
				std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> choice;
			}

			if (choice == 0)
			{
				return;
			}

			if (game.getShip()->getGold() < choice)
			{
				cout << "Oh no, you dont have that much money";
			}
			else
			{
				game.getShip()->repairShip(choice);
			}
		}
	}
}

