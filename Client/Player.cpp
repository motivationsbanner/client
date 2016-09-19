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
	std::string name;
	sf::Texture texture = loadTexture("textures/keggly.bmp");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	bool move = true;
	int frame = 0;
	int spriteposition = 0;


}


Player::~Player()
{
}

void Player::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		spriteposition = 48;
		move = true;
		sprite.move(-2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		spriteposition = 32;
		move = true;
		sprite.move(2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		spriteposition = 16;
		move = true;
		sprite.move(0, -2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		spriteposition = 0;
		move = true;
		sprite.move(0, 2);
	}
	else {
		move = false;
	}

	

	if (move == true) {
		if (frame % 6 == 0 || frame % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 0, 16, 28));
		}
		else if (frame % 6 == 2 || frame % 6 == 3) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 28, 16, 28));
		}
		else if (frame % 6 == 4 || frame % 6 == 5) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 56, 16, 28));
		}
	}
	else {
		if (frame % 6 == 0 || frame % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 0, 16, 28));
		}
	}
	frame = frame + 1;
}

void Player::Draw(sf::RenderWindow window) {
	window.draw(sprite);
}
