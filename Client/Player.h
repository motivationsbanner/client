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
	Player();
	~Player();

	void Update();
	void Draw(sf::RenderWindow &);

};

