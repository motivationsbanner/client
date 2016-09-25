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
	sf::RenderWindow window(sf::VideoMode(920, 580), "Overkeggly!");
	window.setFramerateLimit(20);

	//Startposition des Spielers vom server laden
	int playerx;
	int playery;
	playerx = 100;
	playery = 100;
	Player player(playerx, playery, true, "Player1","keggly.bmp");
	Player player2(200, 110, false, "Player2", "rat.bmp");
	//map vom server laden
	std::string mappath = "map2.bmp";
	Map map(mappath);

	//views erstellen
	sf::View view(sf::Vector2f(playerx, playery), sf::Vector2f(300, 200));
	//ToDO Map grösse herausfinden und diese beim view einsetzen
	sf::View minimapView(sf::Vector2f(0, 0), sf::Vector2f(1880, 1200));
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	minimapView.setViewport(sf::FloatRect(0.5, 0.5, 0.5, 0.5));
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
		player2.Update(view);
		window.clear();
		
		
		// Draw view
		window.setView(view);
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