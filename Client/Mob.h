#pragma once
#include "Base.h"
class Mob :
	public Base
{
	
	int maxhp = 100;
	int hp = maxhp;
	int speed = 2;
	int direction = 1;
	int spriteposition = 0;
	int xp = 11;
	sf::Texture mobtexture;
	sf::Sprite mobsprite;
	sf::Sprite healthsprite;
	sf::Sprite healthbarsprite;
	sf::Texture health;
	sf::Texture healthbar;
	
public:
	Mob(int X, int Y);
	~Mob();
	void Mob::Update();
	void Mob::Draw(sf::RenderWindow &window);
	void Mob::DrawMap(sf::RenderWindow &window);
	void Mob::SetTexture(sf::Texture &);
	bool Mob::TakeDamage(int damage);
	void Mob::SetHealthBar(sf::Texture &, sf::Texture &);
	sf::FloatRect Mob::getFloatRect();
	int Mob::getXp();
};

