#include "Fireball.h"
#include "Map.h"


Fireball::Fireball(int x, int y, int pspeed, int pdamage, int pdirection, sf::Texture fireballtxt)
{
	posX = x;
	posY = y;
	speed = pspeed;
	damage = pdamage;
	direction = pdirection; // sets the direction the ball will travel 1 = up 2= right 3 = down 4 = left
	texture = fireballtxt;
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
}


Fireball::~Fireball()
{

}

bool Fireball::Update(Map &map) {
	//den ball bewegen
	sf::FloatRect boundingBox = sprite.getGlobalBounds();

	sf::FloatRect boundingBoxTop = boundingBox;
	boundingBoxTop.top = boundingBoxTop.top - speed;
	sf::FloatRect boundingBoxBottom = boundingBox;
	boundingBoxBottom.top = boundingBoxBottom.top + speed;
	sf::FloatRect boundingBoxLeft = boundingBox;
	boundingBoxLeft.left = boundingBoxLeft.left - speed;
	sf::FloatRect boundingBoxRight = boundingBox;
	boundingBoxRight.left = boundingBoxRight.left + speed;
	// Movement
	if (direction == 4 && map.Collision(boundingBoxLeft)) {
		posX = posX - speed;
	}
	else if (direction == 2 && map.Collision(boundingBoxRight)) {
		posX = posX + speed;
	}
	else if (direction == 1 && map.Collision(boundingBoxTop)) {
		posY = posY - speed;
	}
	else if (direction == 3 && map.Collision(boundingBoxBottom)) {
		posY = posY + speed;
	}
	sprite.setPosition(posX, posY);
	//überprüfen ob ein gegner getroffen wurde

	//überprüffen ob der ball in eine hitbox geworfen wurde
	if (!map.Collision(boundingBoxBottom) || !map.Collision(boundingBoxTop) || !map.Collision(boundingBoxRight) || !map.Collision(boundingBoxLeft))return true;
	//das leben des balles verkleinern
	life = life - 1;
	if (life == 0) return true;
	return false;
}

void Fireball::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
