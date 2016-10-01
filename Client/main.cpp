// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

//class include
#include "Player.h"
#include "Npc.h"
#include "Map.h"
#include "ServerConnection.h"

// c++ includes
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(920, 580), "Overkeggly!");
	window.setFramerateLimit(20);
	int x = 100;
	int y = 100;
	
	ServerConnection con("cravay.me", 4499);

	//Startposition des Spielers vom server laden
	Player player(x, y, true, "Player1","keggly.bmp");

	//map vom server laden
	Map map = Map::Map();

	//views erstellen
	sf::View view(sf::Vector2f(x, y), sf::Vector2f(300, 200));
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	
	//ToDO Map grösse herausfinden und diese beim view einsetzen
	sf::View minimapView(sf::Vector2f(0, 0), sf::Vector2f(1880, 1200));
	minimapView.setViewport(sf::FloatRect(0.5, 0.5, 0.5, 0.5));

	// players map
	std::map<sf::Uint16, Player> players;

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
		
		con.setPosition(player.getPosX(), player.getPosY());

		while (sf::Uint16 player_id = con.popNewPlayer()) {
			Player player(false);
			auto coords = con.getPlayerPosition(player_id);

			player.setPosition(coords.x, coords.y);

			players[player_id] = player;
		}

		while (sf::Uint16 player_id = con.popDisconnectedPlayer()) {
			players.erase(player_id);
		}

		
		// Draw View
		window.setView(view);
		map.Draw(window);
		player.Draw(window);

		for (auto &player : players) {
			auto position = con.getPlayerPosition(player.first);

			player.second.setPosition(position.x, position.y);
			player.second.Draw(window);
		}

		//Draw Minimap
		window.setView(minimapView);
		map.Draw(window);
		player.Draw(window);

		window.display();
		
	}
	
	return 0;
}