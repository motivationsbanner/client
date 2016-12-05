#include "Block.h"



Block::Block(int zahl, sf::Texture &Ptexture)
{

	
	spriteblock.setTexture(Ptexture);
	//viele IF statements für die richtige position
	switch (zahl)
	{
	case 0:
		posX = 0;
		posY = 0;
		name = "grass";
		hitbox = false;
		break;
	case 1:
		posX = 80;
		posY = 0;
		name = "stone";
		hitbox = true;
		break;
	case 2:
		posX = 40;
		posY = 0;
		name = "sand";
		hitbox = false;
		break;
	case 3:
		posX = 60;
		posY = 0;
		name = "stone2";
		hitbox = true;
		break;
	case 4:
		posX = 20;
		posY = 0;
		name = "stone3";
		hitbox = false;
		break;
	case 5:
		posX = 100;
		posY = 0;
		name = "dirt";
		hitbox = false;
		break;
	case 6:
		posX = 120;
		posY = 0;
		name = "prison_door";
		hitbox = true;
		break;
	case 7:
		posX = 140;
		posY = 0;
		name = "damaged_stone3";
		hitbox = true;
		break;
	case 8:
		posX = 0;
		posY = 20;
		name = "table_ul";
		hitbox = true;
		break;
	case 9:
		posX = 20;
		posY = 20;
		name = "table_uc";
		hitbox = true;
		break;
	case 10:
		posX = 40;
		posY = 20;
		name = "table_ur";
		hitbox = true;
		break;
	case 11:
		posX = 0;
		posY = 40;
		name = "table_mr";
		hitbox = true;
		break;
	case 12:
		posX = 20;
		posY = 40;
		name = "table_mc";
		hitbox = true;
		break;
	case 13:
		posX = 40;
		posY = 40;
		name = "table_ml";
		hitbox = true;
		break;
	case 14:
		posX = 0;
		posY = 60;
		name = "table_bl";
		hitbox = true;
		break;
	case 15:
		posX = 20;
		posY = 60;
		name = "table_bc";
		hitbox = true;
		break;
	case 16:
		posX = 40;
		posY = 60;
		name = "table_br";
		hitbox = true;
		break;
	case 17:
		posX = 60;
		posY = 20;
		name = "sandstone";
		hitbox = true;
		break;
	case 18:
		posX = 80;
		posY = 20;
		name = "cactus";
		hitbox = true;
		break;
	case 19:
		posX = 100;
		posY = 20;
		name = "water";
		hitbox = true;
		break;
	case 20:
		posX = 120;
		posY = 20;
		name = "sand_grass";
		hitbox = true;
		break;
	case 21:
		posX = 140;
		posY = 20;
		name = "sand_bush";
		hitbox = true;
		break;
	case 22:
		posX = 60;
		posY = 40;
		name = "bush";
		hitbox = false;
		break;
	case 23:
		posX = 80;
		posY = 40;
		name = "flowers_red";
		hitbox = false;
		break;
	case 24:
		posX = 100;
		posY = 40;
		name = "flowers_orange";
		hitbox = false;
		break;
	case 25:
		posX = 120;
		posY = 40;
		name = "flowers_purble";
		hitbox = false;
		break;
	case 26:
		posX = 140;
		posY = 40;
		name = "flowers_blue";
		hitbox = false;
		break;
	case 27:
		posX = 60;
		posY = 60;
		name = "bridge";
		hitbox = false;
		break;
	case 28:
		posX = 80;
		posY = 60;
		name = "fence_ul";
		hitbox = true;
		break;
	case 29:
		posX = 80;
		posY = 80;
		name = "fence_um";
		hitbox = true;
		break;
	case 30:
		posX = 80;
		posY = 100;
		name = "fence_ur";
		hitbox = true;
		break;
	case 31:
		posX = 100;
		posY = 60;
		name = "fence_ml";
		hitbox = true;
		break;
	case 32:
		posX = 100;
		posY = 100;
		name = "fence_mr";
		hitbox = true;
		break;
	case 33:
		posX = 120;
		posY = 60;
		name = "fence_bl";
		hitbox = true;
		break;
	case 34:
		posX = 120;
		posY = 80;
		name = "fence_bm";
		hitbox = true;
		break;
	case 35:
		posX = 120;
		posY = 100;
		name = "fence_br";
		hitbox = true;
		break;
	case 36:
		posX = 100;
		posY = 80;
		name = "sheep";
		hitbox = true;
		break;
	case 37:
		posX = 140;
		posY = 60;
		name = "hay_ball";
		hitbox = true;
		break;
	case 38:
		posX = 40;
		posY = 80;
		name = "fountain_ul";
		hitbox = true;
		break;
	case 39:
		posX = 40;
		posY = 100;
		name = "fountain_ur";
		hitbox = true;
		break;
	case 40:
		posX = 60;
		posY = 80;
		name = "fountain_bl";
		hitbox = true;
		break;
	case 41:
		posX = 60;
		posY = 100;
		name = "fountain_br";
		hitbox = true;
		break;
	case 42:
		posX = 0;
		posY = 80;
		name = "bed_l";
		hitbox = true;
		break;
	case 43:
		posX = 20;
		posY = 80;
		name = "bed_r";
		hitbox = true;
		break;
	default:
		posX = 0;
		posY = 0;
		name = "grass";
		hitbox = false;
		break;
	}
	spriteblock.setTextureRect(sf::IntRect(posX, posY, 20, 20));
}


Block::~Block()
{
}

void Block::Draw(int i, int z, sf::RenderWindow &window) 
{
	
	spriteblock.setPosition(i * 20, z * 20);
	window.draw(spriteblock);
}

