#include "Npc.h"

#include <iostream>

Npc::Npc()
{
	Base();
	this->friendly = false;
}

Npc::Npc(int hp)
{
	Base b(hp);
	this->friendly = false;
}

Npc::Npc(int hp, int posX, int posY)
{
	Base(hp, posX, posY);
	this->friendly = false;
}

Npc::Npc(int hp, int posX, int posY, int map)
{
	Base(hp, posX, posY, map);
	this->friendly = false;
}

Npc::~Npc()
{

}
