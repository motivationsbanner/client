// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include "mainPlayer.h"
#include "Fireball.h"

// c++ includes
#include <iostream>
#include <string>

mainPlayer::mainPlayer(int X, int Y,  std::string  pTexturefile)
{
	//Name, X, Y, Items[], Gold, XP, Character Model, Skilltree, Hp
	hp = 100;
	maxhp = 100;
	mana = 100;
	maxmana = 100;
	posX = X;
	posY = Y;
	

	fireballtexture = loadTexture("textures/fireball.bmp");
	// init movement variables
	move = false;
	frame = 0;

	//Sprite und player texture erstellen
	spriteposition = 0;
	texture = loadTexture("textures/" + pTexturefile + ".bmp");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x /4, texture.getSize().y / 3));

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

void mainPlayer::Update(sf::View &view, Map &map, std::vector<Fireball> &fireball) {
	//cd von spell verkleinern und icon offcd bearbeiten
	int fireballcdinprozent;
	if (fireballcd >= 0) {
		 fireballcdinprozent = 100-((double)fireballcd/ (double)fireballmaxcd*100);
	}
	else {
		fireballcdinprozent = 100;
	}
		fireballoffcdsprite.setTextureRect(sf::IntRect(0, 0, 20, 20 * fireballcdinprozent / 100));
	
	
	fireballcd -= 1;
	//colliding blocks
	sf::FloatRect boundingBox = sprite.getGlobalBounds();
	boundingBox.top = boundingBox.top+boundingBox.height-15;
	boundingBox.height = 15;

	// Movement
	move = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !map.Collision(boundingBox,"l",speed) == 0){
		spriteposition = texture.getSize().x / 4 * 3;
		posX = posX - map.Collision(boundingBox, "l", speed);
		direction = 4;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !map.Collision(boundingBox, "r", speed) == 0) {
		spriteposition = texture.getSize().x / 4 * 2;
		posX = posX + map.Collision(boundingBox, "r", speed);
		direction = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !map.Collision(boundingBox, "u", speed) == 0){
		spriteposition = texture.getSize().x / 4 ;
		posY = posY - map.Collision(boundingBox, "u", speed);
		direction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !map.Collision(boundingBox, "d", speed) == 0) {
		spriteposition = 0;
		posY = posY + map.Collision(boundingBox, "d", speed);
		direction = 3;
	}
	else {
		move = false;
	}
	// neue fireballs hinzufügen
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireballcd <= 0 && mana >= fireballmana) {
		Fireball fire(posX, posY, 4, 25, direction, fireballtexture);
		fireball.push_back(fire);
		fireballcd = fireballmaxcd;
		SpendMana(fireballmana);
	}

	//fireballs updaten und löschen wenn return true
	for (int i = 0; i < fireball.size(); i++) {
		if (fireball[i].Update(map)) {
			fireball.erase(fireball.begin() +i);
		}
	}


	//Hier werden alle Positionen geupdated
	sprite.setPosition(posX, posY);
	view.setCenter(posX, posY);
	healthsprite.setPosition(posX - (health.getSize().x / 2) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3) + 42);
	healthbarsprite.setPosition(posX - (healthbar.getSize().x / 2) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3 + 42));
	manasprite.setPosition(posX - (manatexture.getSize().x / 2) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3) + 56);
	manabarsprite.setPosition(posX - (manabar.getSize().x / 2) + (texture.getSize().x / 8), posY + (texture.getSize().y / 3 + 56));
	profilsprite.setPosition(healthbarsprite.getPosition().x - 30, healthbarsprite.getPosition().y);

	healthspritek.setPosition(posX - (health.getSize().x / 4) + (texture.getSize().x / 8), posY - 20);
	healthbarspritek.setPosition(posX - (healthbar.getSize().x / 4) + (texture.getSize().x / 8), posY - 20);
	manaspritek.setPosition(posX - (manatexture.getSize().x / 4) + (texture.getSize().x / 8), posY - 20 + (manatexture.getSize().y / 2));
	manabarspritek.setPosition(posX - (manatexture.getSize().x / 4) + (texture.getSize().x / 8), posY - 20 + (manatexture.getSize().y / 2));
	txtname.setPosition(posX - (txtname.getLocalBounds().width / 4) + (texture.getSize().x / 8), posY - 35);

	fireballoncdsprite.setPosition(profilsprite.getPosition().x - 22, profilsprite.getPosition().y + 8);
	fireballoffcdsprite.setPosition(profilsprite.getPosition().x - 22, profilsprite.getPosition().y + 8);
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
	manaregen();
	frame += 1;
	
}

void mainPlayer::DrawUI(sf::RenderWindow &window, std::vector<Fireball> &fireball) {
	window.draw(sprite);
	for (int i = 0; i < fireball.size(); i++) {
		fireball[i].Draw(window);
	}
	window.draw(manaspritek);
	window.draw(manabarspritek);
	window.draw(healthspritek);
	window.draw(healthbarspritek);
	window.draw(txtname);
	window.draw(healthsprite);
	window.draw(healthbarsprite);
	window.draw(manasprite);
	window.draw(manabarsprite);
	window.draw(profilsprite);
	window.draw(fireballoncdsprite);
	window.draw(fireballoffcdsprite);
	
}

void mainPlayer::DrawMinimap(sf::RenderWindow &window, std::vector<Fireball> &fireball) {
	window.draw(sprite);
	for (int i = 0; i < fireball.size(); i++) {
		fireball[i].Draw(window);
	}
}

void mainPlayer::TakeDamage(int damage) {
	if (hp - damage < 0) {
		//er hat verloren
	}
	else {
		hp = hp-damage;
		healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
		healthspritek.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	}
}

void mainPlayer::SpendMana(int manaspent) {
	if (mana - manaspent < 0) {
		//er hat verloren
	}
	else {
		mana = mana - manaspent;
		manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
		manaspritek.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
	}
}

void mainPlayer::SetTexture(sf::Texture &newtexture) {
	texture = newtexture;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(spriteposition, 0, texture.getSize().x / 4, texture.getSize().y / 3));
}

void mainPlayer::SetName(sf::Font &font, std::string Pname) {
	txtname.setFont(font);
	txtname.setCharacterSize(24);
	txtname.setScale(0.5f, 0.5f);
	txtname.setString(Pname);
	txtname.setPosition(posX - (txtname.getLocalBounds().width / 4) + (texture.getSize().x / 8), posY - 15);
}

void mainPlayer::SetManaBar(sf::Texture &pmana, sf::Texture &pmanabar) {
	manatexture = pmana;
	manabar = pmanabar;
	manaspritek.setTexture(manatexture);
	manaspritek.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
	manaspritek.setScale(0.5f, 0.5f);
	manabarspritek.setTexture(manabar);
	manabarspritek.setScale(0.5f, 0.5f);

	manabarsprite.setTexture(manabar);
	manasprite.setTexture(manatexture);
	manasprite.setTextureRect(sf::IntRect(0, 0, (manatexture.getSize().x *  mana / maxmana), manatexture.getSize().y));
}

void mainPlayer::manaregen() {
	if (mana + manaregeneration <= maxmana)SpendMana(-manaregeneration);
}

void mainPlayer::SetHealthBar(sf::Texture &phealth, sf::Texture &phealthbar) {
	health = phealth;
	healthbar = phealthbar;
	healthspritek.setTexture(health);
	healthspritek.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
	healthspritek.setScale(0.5f, 0.5f);
	healthbarspritek.setTexture(healthbar);
	healthbarspritek.setScale(0.5f, 0.5f);

	healthbarsprite.setTexture(healthbar);
	healthsprite.setTexture(health);
	healthsprite.setTextureRect(sf::IntRect(0, 0, (health.getSize().x *  hp / maxhp), health.getSize().y));
}

void mainPlayer::SetFireballTextures(sf::Texture &oncd, sf::Texture &offcd) {
	fireballoncdtexture = oncd;
	fireballoffcdtexture = offcd;
	fireballoncdsprite.setTexture(fireballoncdtexture);
	fireballoffcdsprite.setTexture(fireballoffcdtexture);
}