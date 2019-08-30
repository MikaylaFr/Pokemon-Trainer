#include "game.hpp"
#include <iostream>
#include <string>
int main()
{
	Game game;
	if(game.play())
	{
		std::string(60, '\n');
		std::cout << "Hurray! You collected enough pokemon! Professor Oak appreciates your help!\n" << std::endl;
	}
	else
	{
		std::string(60, '\n');
		std::cout << "You didnt collect enough pokemon in time! Professor Oak will never forgive you...\n" << std::endl;
	}
	return 0;
}
