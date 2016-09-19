// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

//class include
#include "Player.h"
#include "Npc.h"

// c++ includes
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(920, 580), "Hallo!");
	window.setFramerateLimit(20);
	Player player;

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
		player.Update();
		window.clear();

		// Draw
		player.Draw(window);
		window.display();
		
	}
	
	return 0;
}