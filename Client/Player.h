#pragma once
#include "Base.h"
class Player : public Base
{
	std::string name;
	sf::Texture texture;
	sf::Texture health;
	sf::Texture healthbar;
	sf::Sprite healthsprite;
	sf::Sprite healthbarsprite;
	sf::Texture manatexture;
	sf::Texture manabar;
	sf::Sprite manasprite;
	sf::Sprite manabarsprite;
	sf::Sprite sprite;
	sf::Text txtname;
	bool move;
	bool mainplayer;
	int frame;
	int spriteposition;
	sf::Font font;
	int hp;
	int maxhp;
	int mana;
	int maxmana;

public:
	Player(int X, int Y, bool mainplayer, std::string  name, std::string  texturefile);
	~Player();

	void Update(sf::View &);
	void DrawMinimap(sf::RenderWindow &);
	void DrawUI(sf::RenderWindow &);
	void TakeDamage(int damage);
	void SpendMana(int manaspent);

};

