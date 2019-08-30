#include "pokemonSpace.hpp"
#include "menu.hpp"

PokemonSpace::PokemonSpace()
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
}


void PokemonSpace::spawn()
{
	Menu menu;

	if(menu.randomInt(1, 100) <= 1)
	{
		int poke = menu.randomInt(1, 100);
		spawned = true;
		howMany = 1;

		if(poke <= 12)
			type = 1;
		else if(poke >= 13 && poke <=24)
			type = 2;
		else if(poke >= 25 && poke <= 36)
			type = 3;
		else if(poke >= 37 && poke <= 48)
			type = 4;
		else if(poke >= 49 && poke <= 60)
			type = 5;
		else if(poke >= 61 && poke <= 67)
			type = 6;
		else if(poke >= 68 && poke <= 73)
			type = 7;
		else if(poke >= 74 && poke <= 79)
			type = 8;
		else if(poke >= 80 && poke <= 86)
			type = 9;
		else if(poke >= 87 && poke <= 92)
			type = 10;
		else if(poke >= 93 && poke <= 100)
			type = 11;
	}
}
