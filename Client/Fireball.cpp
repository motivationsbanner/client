#include "Fireball.h"
#include "Map.h"
#include "Mob.h"


Fireball::Fireball(int x, int y, int pspeed, int pdamage, int pdirection, sf::Texture &fireballtexture)
{
	posX = x;
	posY = y+12;
	speed = pspeed;
	damage = pdamage;
	direction = pdirection; // sets the direction the ball will travel 1 = up 2= right 3 = down 4 = left
	sprite.setTexture(fireballtexture);
	sprite.setPosition(posX, posY);
	texture = fireballtexture;
}

Fireball::~Fireball()
{

}

bool Fireball::Update(Map &map, std::vector<Mob> &mobs) {
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
	for (Mob &mob : mobs) {
		
		sf::FloatRect mobrect = mob.getFloatRect();
		sf::FloatRect fireballrect(posX, posY, texture.getSize().x, texture.getSize().y);
		if (mobrect.intersects(fireballrect)) {
			mob.TakeDamage(damage);
			return true;
		}
	}
	//überprüffen ob der ball in eine hitbox geworfen wurde
	if ((!map.Collision(boundingBoxBottom)&& direction == 3)|| (!map.Collision(boundingBoxTop)&& direction == 1)|| (!map.Collision(boundingBoxRight)&& direction == 2)|| (!map.Collision(boundingBoxLeft)&& direction == 4))return true;
	//das leben des balles verkleinern
	life = life - 1;
	if (life == 0) return true;
	return false;
}

void Fireball::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
