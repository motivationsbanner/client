#pragma once
#include "Base.h"
#include "Block.h"
class Map : public Base
{
	std::vector< std::vector<Block> > vect;
	sf::Texture blocks;
public:
	Map();
	~Map();
	void Draw(sf::RenderWindow &);
	void Loadmap(std::string path);
	int Map::GetHeight();
	int Map::GetWidth();
};

