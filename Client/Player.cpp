// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "Player.h"

// c++ includes
#include <iostream>
#include <string>

Player::Player()
{
	// get and set texture
	texture = loadTexture("textures/keggly.bmp");
	sprite.setTexture(texture);

	// init movement variables
	move = false;
	frame = 0;

	spriteposition = 0;
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));

	// player or networkplayer
	mainplayer = false;
	// set name
	name = "fag";

	//Name als Text anzeigen lassen
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
		return;
	}

	// init name font
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(name);
}

Player::Player(bool pMainplayer)
{
	// get and set texture
	texture = loadTexture("textures/keggly.bmp");
	sprite.setTexture(texture);

	// init movement variables
	move = false;
	frame = 0;

	spriteposition = 0;
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));

	// player or networkplayer
	mainplayer = pMainplayer;
	// set name
	name = "fag";

	//Name als Text anzeigen lassen
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
		return;
	}

	// init name font
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(name);
}

Player::Player(int X, int Y, bool pMainplayer, std::string pName, std::string  pTexturefile)
{
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	hp = 100;
	maxhp = 100;
	mana = 100;
	maxmana = 100;
	texture = loadTexture("textures/" + pTexturefile + ".bmp");
	sprite.setTexture(texture);

	// init movement variables
	move = false;
	frame = 0;

	//Sprite und player texture erstellen
	spriteposition = 0;
	sprite.setPosition(X, Y);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x /4, texture.getSize().y / 3));

	// player or networkplayer
	mainplayer = pMainplayer;
	// set name
	name = pName;

	//Name als Text anzeigen lassen
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
		return;
	}

	// init name font
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(name);
	txtname.setPosition(X - (txtname.getLocalBounds().width / 4) +(texture.getSize().x / 8), Y-20);

	//Healthbar erstellen
	health = loadTexture("textures/health.bmp");
	healthbar = loadTexture("textures/healthbar.bmp");
	healthbarsprite.setTexture(healthbar);
	healthsprite.setTexture(health);
	healthbarsprite.setScale(0.5f, 0.5f);
	healthsprite.setScale(0.5f, 0.5f);
	healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	healthsprite.setPosition(X- (health.getSize().x/4) + (texture.getSize().x / 8),Y + (texture.getSize().y / 3)+42);
	healthbarsprite.setPosition(X- (healthbar.getSize().x/4) + (texture.getSize().x / 8),Y+(texture.getSize().y / 3+42));

	//Manabar erstellen
	manatexture = loadTexture("textures/mana.bmp");
	manabar = loadTexture("textures/manabar.bmp");
	manabarsprite.setTexture(manabar);
	manasprite.setTexture(manatexture);
	manabarsprite.setScale(0.5f, 0.5f);
	manasprite.setScale(0.5f, 0.5f);
	manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
	manasprite.setPosition(X - (manatexture.getSize().x / 4) + (texture.getSize().x / 8), Y + (texture.getSize().y / 3) + 56);
	manabarsprite.setPosition(X - (manabar.getSize().x / 4) + (texture.getSize().x / 8), Y + (texture.getSize().y / 3 + 56));

	//profil erstellen
	profil = loadTexture("textures/" + pTexturefile + "profil.bmp");
	profilsprite.setTexture(profil);
	profilsprite.setScale(1.45f,1.45f);
	profilsprite.setPosition(healthbarsprite.getPosition().x-30, healthbarsprite.getPosition().y);
}

Player::~Player()
{
	// destructor
}

void Player::Update(sf::View &view) {

	if (mainplayer) {
		// Movement
		move = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
			spriteposition = texture.getSize().x / 4 * 3;
			sprite.move(-2, 0);
			view.move(-2, 0);
			txtname.move(-2,0);
			healthbarsprite.move(-2, 0);
			healthsprite.move(-2, 0);
			manabarsprite.move(-2, 0);
			manasprite.move(-2, 0);
			profilsprite.move(-2,0);
		}//920 muss durch map grösse ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 920 - 14) {
			spriteposition = texture.getSize().x / 4 * 2;
			sprite.move(2, 0);
			view.move(2, 0);
			txtname.move(2, 0);
			healthbarsprite.move(2, 0);
			healthsprite.move(2, 0);
			manabarsprite.move(2, 0);
			manasprite.move(2, 0);
			profilsprite.move(2, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {
			spriteposition = texture.getSize().x / 4 ;
			sprite.move(0, -2);
			view.move(0, -2);
			txtname.move(0, -2);
			healthbarsprite.move(0, -2);
			healthsprite.move(0, -2);
			manabarsprite.move(0, -2);
			manasprite.move(0, -2);
			profilsprite.move(0, -2);
		}//580 muss durch map heigth ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 580 - 26) {
			spriteposition = 0;
			sprite.move(0, 2);
			view.move(0, 2);
			txtname.move(0, 2);
			healthbarsprite.move(0, 2);
			healthsprite.move(0, 2);
			manabarsprite.move(0, 2);
			manasprite.move(0, 2);
			profilsprite.move(0, 2);
		}
		else {
			move = false;
		}
	}

	else {
		//hier würde die Position vom server gesetzt
		
		if (sprite.getPosition().x < 920 - 14) {
			spriteposition = texture.getSize().x / 4 * 2;
			move = true;
			sprite.move(2, 0);
			txtname.move(2, 0);
		}
		else if (sprite.getPosition().x > 0) {
			spriteposition = texture.getSize().x / 4 * 3;
			move = true;
			sprite.move(-2, 0);
			txtname.move(-2, 0);
		}
	}
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

void Player::DrawUI(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(txtname);
	if (mainplayer) {
		window.draw(healthsprite);
		window.draw(healthbarsprite);
		window.draw(manasprite);
		window.draw(manabarsprite);
		window.draw(profilsprite);
	}
}

void Player::DrawMinimap(sf::RenderWindow &window) {
	window.draw(sprite);

}

void Player::TakeDamage(int damage) {
	if (hp - damage < 0) {
		//er hat verloren
	}
	else {
		hp = hp-damage;
		healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	}
}

void Player::SpendMana(int manaspent) {
	if (mana - manaspent < 0) {
		//er hat verloren
	}
	else {
		mana = mana - manaspent;
		manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
	}
}
