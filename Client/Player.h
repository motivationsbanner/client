#pragma once
#include "Base.h"
class Player : public Base
{
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;
	bool move;
	int frame;
	int spriteposition;

public:
	Player(int X, int Y);
	~Player();

	void Update(sf::View &);
	void Draw(sf::RenderWindow &);

};

