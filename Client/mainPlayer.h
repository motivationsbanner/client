#pragma once
#include "Base.h"
#include "Map.h"
#include "Fireball.h"
class mainPlayer : public Base
{
	std::string name;
	sf::Text txtname;

	sf::Texture charactertexture;
	sf::Sprite charactersprite;

	sf::Texture profil;
	sf::Sprite profilsprite;

	sf::Texture healthtexture;
	sf::Texture healthbartexture;
	sf::Sprite healthsprite;
	sf::Sprite healthbarsprite;
	sf::Sprite healthspritek;
	sf::Sprite healthbarspritek;

	sf::Texture xptexture;
	sf::Texture xpbartexture;
	sf::Sprite xpsprite;
	sf::Sprite xpbarsprite;


	sf::Texture manatexture;
	sf::Texture manabartexture;
	sf::Sprite manasprite;
	sf::Sprite manabarsprite;
	sf::Sprite manaspritek;
	sf::Sprite manabarspritek;
	
	
	sf::Texture fireballtexture;
	sf::Texture fireballoncdtexture;
	sf::Texture fireballoffcdtexture;
	sf::Sprite fireballoncdsprite;
	sf::Sprite fireballoffcdsprite;

	int hp;
	int maxhp;

	int mana;
	int maxmana;

	bool move;
	int frame;
	int spriteposition;
	int speed = 2;
	int direction = 3;

	int manaregeneration = 1;

	int fireballmana = 25;
	int fireballmaxcd = 15;

	int xp = 0;
	int maxxp = 20;

	int level = 1;
	sf::Text txtlvl;

	int fireballcd = 0;
	sf::Font font;

public:
	
	std::vector<Fireball> fireball;

	mainPlayer(int X, int Y,  std::string pTexturefile, sf::Font &pfont);
	~mainPlayer();

	
	void Update(sf::View &, Map &, std::vector<Mob> &mobs);
	void DrawMinimap(sf::RenderWindow &);
	void DrawUI(sf::RenderWindow &);
	void TakeDamage(int damage);
	void SpendMana(int manaspent);
	void SetTexture(sf::Texture &);
	void SetName(std::string);

	void SetManaBar(sf::Texture &, sf::Texture &);
	void SetHealthBar(sf::Texture &, sf::Texture &);
	void SetFireballTextures(sf::Texture &, sf::Texture &);
	void SetXPBar(sf::Texture &pxp, sf::Texture &pxpbar);

	void SetXp(int pxp);
	int GetXp();
	void SetLevel();
	int GetLevel();
	void manaregen();
};

