#pragma once
#include "Base.h"
#include "Map.h"
class Fireball :
	public Base
{
public:
	int direction;
	int speed;
	int life = 90;
	int damage;

	sf::Sprite sprite;
	Fireball(int x, int y, int speed, int damage, int direction, sf::Texture &);
	~Fireball();
	bool Update(Map &map);
	void Draw(sf::RenderWindow &);
};

