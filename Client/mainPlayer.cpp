// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "mainPlayer.h"

// c++ includes
#include <iostream>
#include <string>

mainPlayer::mainPlayer(int X, int Y,  std::string pName, std::string  pTexturefile, sf::Font font)
{
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	hp = 100;
	maxhp = 100;
	mana = 100;
	maxmana = 100;
	posX = X;
	posY = Y;
	

	// init movement variables
	move = false;
	frame = 0;

	//Sprite und player texture erstellen
	spriteposition = 0;
	texture = loadTexture("textures/" + pTexturefile + ".bmp");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x /4, texture.getSize().y / 3));

	// set name
	name = pName;


	// init name font
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(name);
	txtname.setPosition(posX - (txtname.getLocalBounds().width / 4) +(texture.getSize().x / 8), posY-20);

	
		//Healthbar erstellen
		health = loadTexture("textures/health.bmp");
		healthbar = loadTexture("textures/healthbar.bmp");
		healthbarsprite.setTexture(healthbar);
		healthsprite.setTexture(health);
		healthbarsprite.setScale(0.5f, 0.5f);
		healthsprite.setScale(0.5f, 0.5f);
		healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
		healthsprite.setPosition(posX- (health.getSize().x/4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3)+42);
		healthbarsprite.setPosition(posX- (healthbar.getSize().x/4) + (texture.getSize().x / 8), posY +(texture.getSize().y / 3+42));

		//Manabar erstellen
		manatexture = loadTexture("textures/mana.bmp");
		manabar = loadTexture("textures/manabar.bmp");
		manabarsprite.setTexture(manabar);
		manasprite.setTexture(manatexture);
		manabarsprite.setScale(0.5f, 0.5f);
		manasprite.setScale(0.5f, 0.5f);
		manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
		manasprite.setPosition(posX - (manatexture.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3) + 56);
		manabarsprite.setPosition(posX - (manabar.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3 + 56));

		//profil erstellen
		profil = loadTexture("textures/" + pTexturefile + "profil.bmp");
		profilsprite.setTexture(profil);
		profilsprite.setScale(1.45f,1.45f);
		profilsprite.setPosition(healthbarsprite.getPosition().x-30, healthbarsprite.getPosition().y);
	
}

mainPlayer::~mainPlayer()
{
	// destructor
}

void mainPlayer::Update(sf::View &view) {

	
		// Movement
		move = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
			spriteposition = texture.getSize().x / 4 * 3;
			posX = posX - 2;
		}//920 muss durch map grösse ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 920 - 14) {
			spriteposition = texture.getSize().x / 4 * 2;
			posX = posX + 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {
			spriteposition = texture.getSize().x / 4 ;
			posY = posY - 2;
		}//580 muss durch map heigth ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 580 - 26) {
			spriteposition = 0;
			posY = posY + 2;
		}
		else {
			move = false;
		}
	



	//Hier werden alle Positionen geupdated
	sprite.setPosition(posX, posY);
	view.setCenter(posX, posY);
	txtname.setPosition(posX, posY);
	healthsprite.setPosition(posX - (health.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3) + 42);
	healthbarsprite.setPosition(posX - (healthbar.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3 + 42));
	manasprite.setPosition(posX - (manatexture.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3) + 56);
	manabarsprite.setPosition(posX - (manabar.getSize().x / 4) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3 + 56));
	profilsprite.setPosition(healthbarsprite.getPosition().x - 30, healthbarsprite.getPosition().y);

	//hier wird die Position an den Server gesendet

	// sprite texture show correct part.
	if (move == true) {
		if (frame % 6 == 0 || frame % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));
		}
		else if (frame % 6 == 2 || frame % 6 == 3) {
			sprite.setTextureRect(sf::IntRect(spriteposition, texture.getSize().y / 3, texture.getSize().x / 4, texture.getSize().y / 3));
		}
		else if (frame % 6 == 4 || frame % 6 == 5) {
			sprite.setTextureRect(sf::IntRect(spriteposition, texture.getSize().y / 3 * 2, texture.getSize().x / 4, texture.getSize().y / 3));
		}
	}
	else {
		if (frame % 6 == 0 || frame % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));
		}
	}

	frame += 1;

	std::cout << frame << std::endl;
	
}

void mainPlayer::DrawUI(sf::RenderWindow &window) {
	window.draw(sprite);
	//window.draw(txtname);
	
	window.draw(healthsprite);
	window.draw(healthbarsprite);
	window.draw(manasprite);
	window.draw(manabarsprite);
	window.draw(profilsprite);
	
}

void mainPlayer::DrawMinimap(sf::RenderWindow &window) {
	window.draw(sprite);
}

void mainPlayer::TakeDamage(int damage) {
	if (hp - damage < 0) {
		//er hat verloren
	}
	else {
		hp = hp-damage;
		healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	}
}

void mainPlayer::SpendMana(int manaspent) {
	if (mana - manaspent < 0) {
		//er hat verloren
	}
	else {
		mana = mana - manaspent;
		manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
	}
}

void mainPlayer::SetTexture(sf::Texture &newtexture) {
	texture = newtexture;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));
}
