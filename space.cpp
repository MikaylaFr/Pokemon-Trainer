#include "space.hpp"

void Space::spawn()
{

}


void Space::setPrint(char &p)
{
	print = &p;
}


char Space::getPrint()
{
	return *print;
}


bool Space::getPlayer()
{
	return player;
}


void Space::setPlayer(bool sp)
{
	player = sp;
}


void Space::pickUp()
{
	spawned = false;
	type = 0;
	howMany = 0;
}	


Space* Space::getUp()
{
	return up;
}


void Space::setUp(Space *u)
{
	up = u;
}


Space* Space::getDown()
{
	return down;
}


void Space::setDown(Space *d)
{
	down = d;
}


Space* Space::getLeft()
{
	return left;
}


void Space::setLeft(Space *l)
{
	left = l;
}


Space* Space::getRight()
{
	return right;
}


void Space::setRight(Space *r)
{
	right = r;
}


int Space::getType()
{
	return type;
}


void Space::setType(int t)
{
	type = t;
}


int Space::getHowMany()
{
	return howMany;
}


void Space::setHowMany(int h)
{
	howMany = h;
}


bool Space::getSpawned()
{
	return spawned;
}


void Space::setSpawned(bool s)
{
	spawned = s;
}

