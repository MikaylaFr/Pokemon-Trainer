#include "itemSpace.hpp"
#include "menu.hpp"

ItemSpace::ItemSpace()
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
}


void ItemSpace::spawn()
{
	Menu menu;
	if(menu.randomInt(1, 100) <= 2)
	{
		spawned = true;

		if(menu.randomInt(1, 2) == 1)
		{
			howMany = menu.randomInt(1, 5);
			type = -1;
		}
		else
		{
			howMany = 1;
			type = -2;
		}
	}
}
