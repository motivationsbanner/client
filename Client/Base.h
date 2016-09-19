#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

class Base
{
	int hp;
	int posX;
	int posY;
	int map;

public:
	Base();
	Base(int hp);
	Base(int hp, int posX, int posY);
	Base(int hp, int posX, int posY, int map);

	~Base();

	sf::Texture loadTexture(std::string uri);
	
	// Getters
	int getPosX() { return posX; }
	int getPosY() { return posY; }
	int getMap() { return map; }
	int getHp() { return hp; }

	// Setters
	void setPosX(int x) { this->posX = x; }
	void setPosY(int y) { this->posY = y; }
	void setMap(int map) { this->map = map; }
	void setHp(int hp) { this->hp= hp; }


};

