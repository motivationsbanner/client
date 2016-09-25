#pragma once
#include "Base.h"
class Player : public Base
{
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text txtname;
	bool move;
	bool mainplayer;
	int frame;
	int spriteposition;

public:
	Player(int X, int Y, bool mainplayer, std::string  name);
	~Player();

	void Update(sf::View &);
	void Draw(sf::RenderWindow &);

};

