// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "Map.h"

// c++ includes
#include <iostream>
#include <string>


Map::Map(std::string path)
{
	texture = loadTexture("textures/" + path);
	sprite.setTexture(texture);
}


Map::~Map()
{
}

void Map::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Map::Mapchange(std::string path)
{
	texture = loadTexture(path);
}
