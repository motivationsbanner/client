#pragma once
#include "Base.h"
#include "Map.h"
#include "Mob.h"
class Fireball :
	public Base
{
public:
	int direction;
	int speed;
	int life = 90;
	int damage;
	sf::Texture texture;
	sf::Sprite sprite;
	Fireball(int x, int y, int speed, int damage, int direction, sf::Texture &);
	~Fireball();
	bool Update(Map &map, std::vector<Mob> &mobs);
	void Draw(sf::RenderWindow &);
};

