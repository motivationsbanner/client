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
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	hp = 100;
	maxhp = 100;
	mana = 100;
	maxmana = 100;
	posX = 0;
	posY = 0;


	// init movement variables
	move = false;
	frame = 0;

	//Sprite und player texture erstellen
	spriteposition = 0;
	/*texture = loadTexture("textures/keggly.bmp");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));*/
}

Player::~Player()
{
	// destructor
}

void Player::Update(sf::View &view) {


	//hier würde die Position vom server gesetzt

	move = false;
	
	
	 if (sprite.getPosition().x < posX && sprite.getPosition().y == posY) {
		spriteposition = texture.getSize().x / 4 * 2;
		move = true;
	}
	else if (sprite.getPosition().x > posX && sprite.getPosition().y == posY) {
		spriteposition = texture.getSize().x / 4 * 3;
		move = true;
	}
	else if (sprite.getPosition().x == posX && sprite.getPosition().y < posY) {
		spriteposition = 0;
		move = true;
	}
	else if (sprite.getPosition().x == posX && sprite.getPosition().y > posY) {
		spriteposition = texture.getSize().x / 4;
		move = true;
	}
	else if (sprite.getPosition().x == posX && sprite.getPosition().y == posY) {
		move = false;
	}

	//Hier werden alle Positionen geupdated
	sprite.setPosition(posX, posY);

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
	//window.draw(txtname);
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

void Player::SetTexture(sf::Texture &newtexture) {
	texture = newtexture;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));
}
