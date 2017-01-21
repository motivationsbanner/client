#include "Mob.h"



Mob::Mob(int X, int Y)
{
	posX = X;
	posY = Y;
}

Mob::~Mob()
{

}

void Mob::Update()
{	
	healthsprite.setPosition(posX - (health.getSize().x / 4) + (mobtexture.getSize().x / 8), posY - health.getSize().y);
	healthbarsprite.setPosition(posX - (health.getSize().x / 4) + (mobtexture.getSize().x / 8), posY - health.getSize().y);
	mobsprite.setTextureRect(sf::IntRect(direction*mobtexture.getSize().x / 4, spriteposition * mobtexture.getSize().y / 3, mobtexture.getSize().x / 4, mobtexture.getSize().y / 3));
}

void Mob::Draw(sf::RenderWindow &window)
{
	window.draw(mobsprite);
	window.draw(healthsprite);
	window.draw(healthbarsprite);
}

void Mob::DrawMap(sf::RenderWindow &window) {
	window.draw(mobsprite);
}

void Mob::SetTexture(sf::Texture &ptexture) 
{
	mobtexture = ptexture;
	mobsprite.setTexture(mobtexture);
	mobsprite.setPosition(posX, posY);
	mobsprite.setTextureRect(sf::IntRect(direction*mobtexture.getSize().x/4, spriteposition * mobtexture.getSize().y / 3, mobtexture.getSize().x / 4, mobtexture.getSize().y / 3));
}

void Mob::TakeDamage(int damage)
{
	if (hp - damage <= 0) {
		//er hat verloren
	}
	else {
		hp = hp - damage;
		healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	}
}

sf::FloatRect Mob::getFloatRect() {
	sf::FloatRect mobrect(posX, posY, mobtexture.getSize().x/4, mobtexture.getSize().y / 3);
	return mobrect;
}

void Mob::SetHealthBar(sf::Texture &phealth, sf::Texture &phealthbar)
{
	health = phealth;
	healthbar = phealthbar;
	healthsprite.setTexture(health);
	healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	healthsprite.setScale(0.5f, 0.5f);
	healthbarsprite.setTexture(healthbar);
	healthbarsprite.setScale(0.5f, 0.5f);
}