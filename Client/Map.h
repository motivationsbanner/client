#pragma once
#include "Base.h"
class Map : public Base
{
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Map(std::string path);
	~Map();
	void Draw(sf::RenderWindow &);
	void Mapchange(std::string path);
};

