#pragma once
#include "Base.h"
class Block :
	public Base
{
	std::string name;
	bool hitbox;
	sf::Sprite spriteblock;
public:
	Block(int zahl, sf::Texture &);
	~Block();
	void Draw(int i, int z, sf::RenderWindow &);
	bool getHitbox();

};

