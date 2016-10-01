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
	sf::Font font;

public:
	Player();
	Player(bool pMainplayer);
	Player(int X, int Y, bool pMainplayer, std::string pName, std::string pTexturefile);
	~Player();

	void Update(sf::View &);
	void Draw(sf::RenderWindow &);

};

