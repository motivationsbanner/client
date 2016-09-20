// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

//class include
#include "Player.h"
#include "Npc.h"
#include "Map.h"

// c++ includes
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(920, 580), "Hallo!");
	window.setFramerateLimit(20);
	Player player;
	Player player2;
	
	std::string mappath = "map.bmp";
	Map map(mappath);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(300, 200));
	sf::View minimapView(sf::Vector2f(0, 0), sf::Vector2f(940, 592));
	minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	window.setView(view);
	player2.Update(view);
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	//Update
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	
		if (event.key.code == sf::Keyboard::Escape) {
			window.close();
		}
		player.Update(view);
		window.clear();
		window.setView(view);
		
		// Draw view
		map.Draw(window);
		player.Draw(window);
		player2.Draw(window);
		//Draw minimap
		window.setView(minimapView);
		map.Draw(window);
		player.Draw(window);
		player2.Draw(window);
		window.display();
		
	}
	
	return 0;
}