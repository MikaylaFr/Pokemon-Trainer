#include "game.hpp"
#include "space.hpp"
#include "pokemonSpace.hpp"
#include "itemSpace.hpp"
#include "normalSpace.hpp"
#include "menu.hpp"

#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

bool Game::makeMap()
{
	for(int i=0; i<42; i++) //Set all spaces to nullptr
	{
		for(int j=0; j<107; j++)
			spaces[i][j] = nullptr;
	}
	
	std::ifstream inFile;
	inFile.open("map4.txt");

	if(!inFile)
	{
		cout << "Missing map file" << endl;
		return false;
	}
	
	string in;
	for(int i=0; i<42; i++)
	{
		getline(inFile, in);
		for(int j=0; j<107; j++)
		{
			printMap[i][j] = in[j];
		}
	}
	inFile.close();

	for(int i=1; i<9; i++) //Lab
	{
		for(int j=38; j<62; j++)
			spaces[i][j] = new NormalSpace;
	}

	for(int i=14; i<21; i++) //home
	{
		for(int j=80; j<97; j++)
			spaces[i][j] = new NormalSpace;
	}
	
	for(int i=26; i<33; i++) //Extra houses
	{
		for(int j=9; j<28; j++)
			spaces[i][j] = new NormalSpace;
		for(int k=80; k<100; k++)
			spaces[i][k] = new NormalSpace;
	}

	for(int i=0; i<42; i++) //Fill the rest of the spaces
	{
		for(int j=0; j<107; j++)
		{
			if(printMap[i][j] != ' ')
				spaces[i][j] = new NormalSpace;
			else if(spaces[i][j] == nullptr) //randomly assign space types
			{
				Menu menu;
				int sp = menu.randomInt(1, 7);

				if(sp <= 3)
					spaces[i][j] = new ItemSpace;
				else if(sp >= 4 && sp <= 6)
					spaces[i][j] = new PokemonSpace;
				else
					spaces[i][j] = new NormalSpace;
			}

			spaces[i][j]->setPrint(printMap[i][j]);
		}
	}

	for(int i=1; i<42; i++) //connect up pointers
	{
		for(int j=0; j<107; j++)
		{
			spaces[i][j]->setUp(spaces[i-1][j]);
		}
	}

	for(int i=0; i<41; i++) //connect down pointers
	{
		for(int j=0; j<107; j++)
			spaces[i][j]->setDown(spaces[i+1][j]);
	}

	for(int i=0; i<42; i++) //connect left pointers
	{
		for(int j=1; j<107; j++)
			spaces[i][j]->setLeft(spaces[i][j-1]);
	}
	
	for(int i=0; i<42; i++) //connect right pointers
	{
		for(int j=0; j<106; j++)
			spaces[i][j]->setRight(spaces[i][j+1]);
	}
	
	player = spaces[14][48]; //Starting position
	return true;
}


bool Game::play()
{
	cout << "\nPokemon Lab Assistant!" << endl;
	cout << "Objective: Assist Professor Oak with his research by collecting 5 Pokemon in 2 days. \n" << endl;
	cout << "'#' represents you on the map. A '*' means there is something for you to pick up. If its a pokemon, \nyou must throw your pokeballs at it.";
	cout << "Use WASD enter to move around. You will start with 5 pokeballs and \nyou can only hold 20 pokeballs at a time, visit the lab to buy more Pokeballs.";
	cout << "\nTo refresh the map, you must go home and you will continue to the next day. Refreshing the map will spawn new items and pokemon." << endl;
	cout << "You can view what kind of pokemon you have in your inventory by pressing 'i'" << endl;
	cout << "Press ENTER to continue" << endl;
	string input;
	getline(cin, input);

	pokeballs = 5;
	money = 10;

	if(!makeMap())
		return false;
	
	bool endDay = false;
	int day = 1;
	bool valid = false;
	while(day < 3)
	{
		refresh();
		while(!endDay)
		{
			cout << string(10, '\n');
			
			cout << "DAY: " << day << "    POKEBALLS: " << pokeballs << "   Bank: $" << money << "    POKEMON: " << howManyPok << "/5" << endl;
			displayBoard();
			cout << "(W)Up ";
			cout << "(S)Down ";
			cout << "(A)Left ";
			cout << "(D)Right (I)Inventory of Pokemon" << endl;
			getline(cin, input);
			
			if(input.length() > 1)
			{
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
			else if(input[0] == 'W' || input[0] == 'w')
				move('w');
			else if(input[0] == 'S' || input[0] == 's')
				move('s');
			else if(input[0] == 'A' || input[0] == 'a')
				move('a');
			else if(input[0] == 'D' || input[0] == 'd')
				move('d');
			else if(input[0] == 'I' || input[0] == 'i')
			{
				cout << string(10, '\n');
				if(howManyPok == 0)
					cout << "You dont have any pokemon!" << endl;
				else
				{
					for(int i=0; i<howManyPok; i++)
					{
						cout << i+1 << ". " << pokemon[i] << endl;
					}
				}
				cout << "\nPress ENTER to continue" << endl;
				getline(cin, input);
			}
			else
			{
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
			
			if(player->getSpawned()) //If player is on a space that has something
			{
				pickup();
			}

			if(howManyPok == 5) //Game over win
				return true;
			
			if(player == spaces[8][47] || player == spaces[8][48] || player == spaces[8][49] || player == spaces[8][50] ||
			player == spaces[8][51] || player == spaces[8][52]) //If player is at gym
			{
				cout << "Would you like to buy Pokeballs?" << endl;
				cout << "(1) Yes" << endl;
				cout << "(2) No" << endl;

				while(!valid)
				{	
					getline(cin, input);
					if(input.length() > 1)
					{
						cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
						cout << "Invalid input" << endl;
						cout << string(49, '=') << endl;
					}
					else if(input[0] == '1')
					{
						buy();
						valid = true;
					}
					else if(input[0] == '2')
					{
						valid = true;
					}
					else
					{
						cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
						cout << "Invalid input" << endl;
						cout << string(49, '=') << endl;
					}
				}
				valid = false;

		

			}

			if(player == spaces[16][80] || player == spaces[17][80] || player == spaces[18][80]) //If player is at home
			{
				cout << "Would you like to start a new day?" << endl;
				cout << "(1) Yes" << endl;
				cout << "(2) No" << endl;

				while(!valid)
				{	
					getline(cin, input);
					if(input.length() > 1)
					{
						cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
						cout << "Invalid input" << endl;
						cout << string(49, '=') << endl;
					}
					else if(input[0] == '1')
					{
						refresh();
						endDay = true;
						valid = true;
					}
					else if(input[0] == '2')
					{
						valid = true;
					}
					else
					{
						cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
						cout << "Invalid input" << endl;
						cout << string(49, '=') << endl;
					}
				}
				valid = false;
			}
		
		}
		endDay = false;
		day++;
	}
	
	return false;

	
}


void Game::displayBoard()
{
	
	for(int i=0; i<42; i++)
	{
		for(int j=0; j<107; j++)
		{
			if(spaces[i][j] == player)
				cout << "#";
			else if(spaces[i][j]->getSpawned())
				cout << "*";
			else
				cout << printMap[i][j];
		}
		cout << endl;
	}
}

void Game::refresh()
{
	for(int i=0; i<42; i++)
	{
		for(int j=0; j<107; j++)
		{
			spaces[i][j]->pickUp();
			spaces[i][j]->spawn();
		}
	}
}


void Game::move(char direction)
{
	Space *move;
	switch (direction)
	{
		case 'w':
			move = player->getUp();
			break;
		case 's':
			move = player->getDown();
			break;
		case 'a':
			move = player->getLeft();
			break;
		case 'd':
			move = player->getRight();
	}
		
	if(move->getPrint() == ' ' || move->getPrint() == '*')
	{
		player = move;
	}
	else	
	{	
		cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
		cout << "Sorry, cant move there" << endl;
		cout << string(49, '=') << endl;
	}
		
			
}


void Game::buy()
{
	string input;
	Menu menu;
	
	cout << "How many would you like to buy? Pokeballs are $5 each" << endl;
	
	getline(cin, input);
	int many = menu.validateInt(input);
		
	if((pokeballs + many) > 20)
	{
		cout << "You dont have enough room" << endl;
		cout << "Press ENTER to continue" << endl;
		getline(cin, input);
	}
	else if((many * 5) > money)
	{
		cout << "You dont have enough money" << endl;
		cout << "Press ENTER to continue" << endl;
		getline(cin, input);
	}
	else
	{
		pokeballs = pokeballs + many;
		money = money - (many * 5);
	}
}


void Game::pickup()
{
	string input;
	Menu menu;
	bool loop = true;
	cout << string(60, '\n');
	if(player->getType() == -1) //Money
	{
		cout << "You found $" << player->getHowMany() << "!" << endl;
		money = money + player->getHowMany();

		cout << "Press ENTER to continue" << endl;
		getline(cin, input);
	}
	else if(player->getType() == -2) //Pokeball
	{
		cout << "You found " << player->getHowMany() << " pokeballs!" << endl;
		
		if((pokeballs + player->getHowMany()) > 20)
		{
			cout << "You are at capacity for pokeballs" << endl;
			pokeballs = 20;
		}
		else
		{
			pokeballs = pokeballs + player->getHowMany();
		}
		cout << "Press ENTER to continue" << endl;
		getline(cin, input);

	}
	else
	{
		cout << "A wild ";
		switch (player->getType())
		{
			case 1:
				cout << "Squirtle";
				pokemon[howManyPok] = "Squirtle";
				break;
			case 2:
				cout << "Charmander";
				pokemon[howManyPok] = "Charmander";
				break;
			case 3:
				cout << "Bulbasaur";
				pokemon[howManyPok] = "Bulbasaur";
				break;
			case 4:
				cout << "Rattata";
				pokemon[howManyPok] = "Rattata";
				break;
			case 5:
				cout << "Snorlax";
				pokemon[howManyPok] = "Snorlax";
				break;
			case 6:
				cout << "Jigglypuff";
				pokemon[howManyPok] = "Jigglypuff";
				break;
			case 7:
				cout << "Ekans";
				pokemon[howManyPok] = "Ekans";
				break;
			case 8:
				cout << "Sandshrew";
				pokemon[howManyPok] = "Sandshrew";
				break;
			case 9:
				cout << "Vulpix";
				pokemon[howManyPok] = "Vulpix";
				break;
			case 10:
				cout << "Meowth";
				pokemon[howManyPok] = "Meowth";
				break;
			case 11:
				cout << "Pikachu";
				pokemon[howManyPok] = "Pikachu";
				break;
		}
		cout << " has appeared" << endl;
		
		while(loop)
		{
			if(pokeballs < 1)
			{
				cout << "You dont have any pokeballs." << endl;
				loop = false;
				cout << "Press ENTER to continue" << endl;
				getline(cin, input);
			}
			else
			{
				cout << "(1) Throw a pokeball or (2) walk away" << endl;
				cout << "Pokeballs: " << pokeballs << endl;
				getline(cin, input);
				if(input.length() > 1)
				{
					cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
					cout << "Invalid input" << endl;
					cout << string(49, '=') << endl;
				}
				else if(input[0] == '1')
				{
					if(menu.randomInt(1, 100) <= 35)
					{
						loop = false;
						cout << "\nYou caught a " << pokemon[howManyPok] << "!" << endl;
						howManyPok++;
						pokeballs--;
						cout << "Press ENTER to continue" << endl;
						getline(cin, input);
					}
					else
					{
						cout << "\n" << pokemon[howManyPok] << " escaped the pokeball. Try again!" << endl;
						pokeballs--;
					}
				}
				else if(input[0] == '2')
				{
					loop = false;
				}
				else
				{
					cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
					cout << "Invalid input" << endl;
					cout << string(49, '=') << endl;
				}
			}
		}
	}

	player->setHowMany(0);
	player->setSpawned(false);
	player->setType(0);
}
