#ifndef GAME_HPP
#define GAME_HPP
#include "space.hpp"
#include <string>

class Game
{
	private:
		char printMap[42][107];
		Space *spaces[42][107];
		Space *player;
		int howManyPok {0};
		int money {0};
		int pokeballs {0};
		std::string pokemon[10];
	public:
		bool makeMap();
		void displayBoard();
		bool play();
		void refresh();
		void move(char direction);
		void buy();
		void pickup();
};
#endif

