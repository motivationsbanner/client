#include "Base.h"
#include <iostream>

Base::Base()
{

}

Base::Base(int hp)
{
	this->hp = hp;
	std::cout << "I HAVE " << hp << " HP" << std::endl;

}

Base::Base(int hp, int posX, int posY)
{
	this->hp = hp;
	this->posX = posX;
	this->posY = posY;
}

Base::Base(int hp, int posX, int posY, int map)
{
	this->hp = hp;
	this->posX = posX;
	this->posY = posY;
	this->map = map;

}

Base::~Base(void)
{

}

