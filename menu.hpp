//Menu class header file

#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu
{
	
	public:
		bool begin();
		bool end();
		int validateInt(std::string input);
		double validateDoub(std::string input);
		std::string validateName(std::string input);
		int validateAllInt(std::string input);
		int randomInt(int min, int max);
};
#endif
