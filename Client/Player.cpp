// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "Player.h"

// c++ includes
#include <iostream>
#include <string>


Player::Player(int X, int Y)
{
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	std::string name;
	texture = loadTexture("textures/keggly.bmp");
	sprite.setTexture(texture);
	move = true;
	frame = 0;
	spriteposition = 0;
	sprite.setPosition(X, Y);
}


Player::~Player()
{

}

void Player::Update(sf::View &view) {

	// Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0 ) {
		spriteposition = 48;
		move = true;
		sprite.move(-2, 0);
		view.move(-2, 0);
	}//920 muss durch map grösse ersetzt werden
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 920-14) {
		spriteposition = 32;
		move = true;
		sprite.move(2, 0);
		view.move(2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {
		spriteposition = 16;
		move = true;
		sprite.move(0, -2);
		view.move(0, -2);
	}//580 muss durch map heigth ersetzt werden
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 580-26) {
		spriteposition = 0;
		move = true;
		sprite.move(0, 2);
		view.move(0, 2);
	}
	else {
		move = false;
	}
	
	// sprite texture show correct part.
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
	} else {
		if (frame % 6 == 0 || frame % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(spriteposition, 0, 16, 28));
		}
	}
	
	frame += 1;

	std::cout << frame << std::endl;
}

void Player::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
