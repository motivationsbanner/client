// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "Player.h"

// c++ includes
#include <iostream>
#include <string>


Player::Player(int X, int Y, bool pmainplayer, std::string  pname, std::string  texturefile)
{
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	
	texture = loadTexture("textures/" + texturefile);
	sprite.setTexture(texture);
	move = false;
	frame = 0;
	//Sprite und player texture erstellen
	spriteposition = 0;
	sprite.setPosition(X, Y);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x /4, texture.getSize().y / 3));
	mainplayer = pmainplayer;
	name = pname;
	//Name als Text anzeigen lassen
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
		return;
	}
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(name);
	txtname.setPosition(X-15 , Y-20);
	
}


Player::~Player()
{

}

void Player::Update(sf::View &view) {
	if (mainplayer) {
		// Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
			spriteposition = texture.getSize().x / 4 * 3;
			move = true;
			sprite.move(-2, 0);
			view.move(-2, 0);
			txtname.move(-2,0);
		}//920 muss durch map grösse ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 920 - 14) {
			spriteposition = texture.getSize().x / 4 * 2;
			move = true;
			sprite.move(2, 0);
			view.move(2, 0);
			txtname.move(2, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 0) {
			spriteposition = texture.getSize().x / 4 ;
			move = true;
			sprite.move(0, -2);
			view.move(0, -2);
			txtname.move(0, -2);
		}//580 muss durch map heigth ersetzt werden
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 580 - 26) {
			spriteposition = 0;
			move = true;
			sprite.move(0, 2);
			view.move(0, 2);
			txtname.move(0, 2);
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

void Player::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(txtname);
}
