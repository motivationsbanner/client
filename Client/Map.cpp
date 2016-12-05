// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Block.h"
#include "Map.h"

// c++ includes
#include <iostream>
#include <string>

Map::Map()
{	

}


Map::~Map()
{
}

void Map::Draw(sf::RenderWindow &window)
{
	
	for(int i = 0; i < vect.size(); i++) {
		for (int z = 0; z < vect.at(i).size(); z++) {
			//block zeichnen
			vect[i][z].Draw(i, z, window);
		}
	}
	
}

void Map::Loadmap(std::string s)
{
	blocks = loadTexture("textures/blocks.bmp");
	//split into array
	std::string delimiter = "|";
	size_t pos = 0;
	std::string token;

	while ((pos = s.find(delimiter)) != std::string::npos) {
		std::string token2;
		std::string delimiter2 = ",";
		size_t pos2 = 0;	
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
		std::vector <Block> vec;
		while ((pos2 = token.find(delimiter2)) != std::string::npos) {
			token2 = token.substr(0, pos2);
			token.erase(0, pos2 + delimiter2.length());
			Block block(std::stoi(token2), blocks);
			vec.push_back(block);
		}
		Block block(std::stoi(token), blocks);
		vec.push_back(block);
		vect.push_back(vec);
	}
	std::string token2;
	std::string delimiter2 = ",";
	size_t pos2 = 0;
	std::vector <Block> vec;
	while ((pos2 = s.find(delimiter2)) != std::string::npos) {
		token2 = s.substr(0, pos2);
		s.erase(0, pos2 + delimiter2.length());
		Block block(std::stoi(token2), blocks);
		vec.push_back(block);
	}
	Block block(std::stoi(token), blocks);
	vec.push_back(block);
	vect.push_back(vec);	
}

int Map::GetHeight() {
	return vect.size()*20;
}

int Map::GetWidth() {
	return vect.at(0).size()*20;
}

