// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

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
	
	spriteblock.setTexture(blocks);
	for(int i = 0; i < vect.size(); i++) {
		for (int z = 0; z < vect.at(i).size(); z++) {
			//Position ändern
			spriteblock.setPosition(i*20,z*20);
			//sprite position ändern
			spriteblock.setTextureRect(sf::IntRect(0,0,20,20));
			//malen auf window
			window.draw(spriteblock);
		}
	}
	
}

void Map::Loadmap(std::string s, sf::Texture Pblocks)
{
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
		std::vector <int> vec;
		while ((pos2 = token.find(delimiter2)) != std::string::npos) {
			token2 = token.substr(0, pos2);
			token.erase(0, pos2 + delimiter2.length());
			vec.push_back(std::stoi(token2));	
		}
		vect.push_back(vec);
	}
	std::string token2;
	std::string delimiter2 = ",";
	size_t pos2 = 0;
	std::vector <int> vec;
	while ((pos2 = s.find(delimiter2)) != std::string::npos) {
		token2 = s.substr(0, pos2);
		s.erase(0, pos2 + delimiter2.length());
		vec.push_back(std::stoi(token2));
	}
	vect.push_back(vec);
	blocks = Pblocks;
}


