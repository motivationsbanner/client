// sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

//class include
#include "Player.h"
#include "Npc.h"
#include "Map.h"
#include "ServerConnection.h"
#include "mainPlayer.h"
#include "Base.h"

// c++ includes
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(920, 580), "Overkeggly!");
	window.setFramerateLimit(20);
	sf::Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
	}
	
	ServerConnection con("cravay.me", 4499);

	Base base = Base();
	sf::Texture keggly = base.loadTexture("textures/keggly.bmp");
	sf::Texture manabar = base.loadTexture("textures/manabar.bmp");
	sf::Texture mana = base.loadTexture("textures/mana.bmp");
	sf::Texture healthbar = base.loadTexture("textures/healthbar.bmp");
	sf::Texture health = base.loadTexture("textures/health.bmp");
	//mainplayer position und daten aus der Datenbank lesen
	int x = 100;
	int y = 100;
	mainPlayer mainplayer(x, y, "keggly");
	mainplayer.SetTexture(keggly);
	mainplayer.SetName(font, "Tim");
	mainplayer.SetManaBar(mana,manabar);
	mainplayer.SetHealthBar(health, healthbar);
	//map vom server laden
	Map map = Map::Map("map2.bmp");

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

		
		window.clear();
		
		con.setPosition(mainplayer.getPosX(), mainplayer.getPosY());

		while (sf::Uint16 player_id = con.popNewPlayer()) {
			auto coords = con.getPlayerPosition(player_id);
			Player player;
			players[player_id] =  player;
		}

		while (sf::Uint16 player_id = con.popDisconnectedPlayer()) {
			players.erase(player_id);
		}
		
		
		mainplayer.Update(view);
		

		
		// Draw View
		window.setView(view);
		map.Draw(window);
		for (auto &player : players) {
			auto position = con.getPlayerPosition(player.first);
			player.second.SetTexture(keggly);
			player.second.SetName(font, "Test");
			player.second.setPosition(position.x, position.y);
			player.second.SetManaBar(mana, manabar);
			player.second.SetHealthBar(health, healthbar);
			player.second.Update(view);
			player.second.DrawUI(window);		
		}
		mainplayer.DrawUI(window);

		//Draw Minimap
		window.setView(minimapView);
		map.Draw(window);
		for (auto &player : players) {
			auto position = con.getPlayerPosition(player.first);
			player.second.DrawMinimap(window);
		}
		mainplayer.DrawMinimap(window);

		//Alles anzeigen lassen
		window.display();
		
	}
	
	return 0;
}