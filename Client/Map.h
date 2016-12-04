#pragma once
#include "Base.h"
class Map : public Base
{
	std::vector< std::vector<int> > vect;
	sf::Texture blocks;
	sf::Sprite spriteblock;
public:
	Map();
	~Map();
	void Draw(sf::RenderWindow &);
	void Loadmap(std::string path, sf::Texture blocks);
};

