#pragma once
#include "Base.h"
#include "Map.h"
#include "Fireball.h"
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
	sf::Texture fireballtexture;
	sf::Texture fireballoncdtexture;
	sf::Texture fireballoffcdtexture;
	sf::Sprite fireballoncdsprite;
	sf::Sprite fireballoffcdsprite;
	bool move;
	bool mainplayer;
	int frame;
	int spriteposition;
	int hp;
	int maxhp;
	int mana;
	int maxmana;
	int speed = 2;
	int direction = 3;
	int manaregeneration = 1;
	int fireballmana = 25;
	int fireballmaxcd = 15;
public:
	int fireballcd = 0;
	mainPlayer(int X, int Y,  std::string pTexturefile);
	~mainPlayer();

	void manaregen();
	void Update(sf::View &, Map &, std::vector<Fireball> &);
	void DrawMinimap(sf::RenderWindow &, std::vector<Fireball> &);
	void DrawUI(sf::RenderWindow &, std::vector<Fireball> &);
	void TakeDamage(int damage);
	void SpendMana(int manaspent);
	void SetTexture(sf::Texture &);
	void SetName(sf::Font &, std::string);
	void SetManaBar(sf::Texture &, sf::Texture &);
	void SetHealthBar(sf::Texture &, sf::Texture &);
	void SetFireballTextures(sf::Texture &, sf::Texture &);
};

