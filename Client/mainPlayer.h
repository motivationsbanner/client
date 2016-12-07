#pragma once
#include "Base.h"
#include "Map.h"
class mainPlayer : public Base
{
	std::string name;
	sf::Texture texture;
	sf::Texture profil;
	sf::Texture health;
	sf::Texture healthbar;
	sf::Sprite profilsprite;
	sf::Sprite healthsprite;
	sf::Sprite healthbarsprite;
	sf::Sprite healthspritek;
	sf::Sprite healthbarspritek;
	sf::Texture manatexture;
	sf::Texture manabar;
	sf::Sprite manasprite;
	sf::Sprite manabarsprite;
	sf::Sprite manaspritek;
	sf::Sprite manabarspritek;
	sf::Sprite sprite;
	sf::Text txtname;

	bool move;
	bool mainplayer;
	int frame;
	int spriteposition;
	int hp;
	int maxhp;
	int mana;
	int maxmana;
	int speed = 2;

public:
	mainPlayer(int X, int Y,  std::string pTexturefile);
	~mainPlayer();

	void Update(sf::View &, Map &);
	void DrawMinimap(sf::RenderWindow &);
	void DrawUI(sf::RenderWindow &);
	void TakeDamage(int damage);
	void SpendMana(int manaspent);
	void SetTexture(sf::Texture &);
	void SetName(sf::Font &, std::string);
	void SetManaBar(sf::Texture &pmana, sf::Texture &pmanabar);
	void SetHealthBar(sf::Texture &pmana, sf::Texture &pmanabar);
};

