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
	window.clear(sf::Color::Black);
	window.display();
	window.setFramerateLimit(20);
	sf::Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
		std::cerr << "Failed to load C:\\Windows\\Fonts\\Arial.ttf";
	}
	sf::Text loadingtxt;
	loadingtxt.setString("LOADING...");
	loadingtxt.setFont(font);
	loadingtxt.setCharacterSize(24);
	loadingtxt.setPosition(window.getSize().x / 2 - loadingtxt.getLocalBounds().width / 2, 280);
	window.draw(loadingtxt);
	window.display();

	ServerConnection con("cravay.me", 4499);

	Base base = Base();
	sf::Texture keggly = base.loadTexture("textures/keggly.bmp");
	sf::Texture manabar = base.loadTexture("textures/manabar.bmp");
	sf::Texture mana = base.loadTexture("textures/mana.bmp");
	sf::Texture healthbar = base.loadTexture("textures/healthbar.bmp");
	sf::Texture health = base.loadTexture("textures/health.bmp");
	sf::Texture login = base.loadTexture("textures/loginscreen.bmp");
	sf::Sprite spritelogin;
	spritelogin.setTexture(login);
	//mainplayer position und daten aus der Datenbank lesen
	int x = 300;
	int y = 200;
	mainPlayer mainplayer(x, y, "keggly");
	//map vom server laden

	//json file mit map vom Server laden
	std::string mapstr = "19,19,19,19,19,19,19,19,19,19,19,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4|19,19,19,19,19,19,19,19,19,19,19,26,26,26,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4|19,19,19,19,19,19,19,19,19,19,19,26,26,24,26,0,0,0,0,0,26,0,23,23,0,0,0,0,0,0,0,4|19,19,19,19,19,19,19,19,19,19,19,24,24,24,26,0,0,0,0,0,26,26,23,26,25,25,23,28,29,29,29,4|19,19,19,19,19,19,19,19,19,19,19,23,26,24,26,0,0,0,0,24,24,24,24,25,25,23,0,31,36,0,36,4|19,19,19,19,19,19,19,19,19,19,19,26,23,23,26,0,0,0,0,25,25,0,24,24,23,26,25,31,0,36,0,4|19,19,19,19,19,19,19,19,19,19,19,26,26,23,26,0,0,0,0,25,26,23,23,24,24,26,25,31,0,36,36,4|19,19,19,19,19,19,19,19,19,19,19,25,26,23,25,0,0,0,0,25,26,23,26,24,24,0,25,33,34,34,34,4|4,26,25,25,25,26,24,24,23,26,26,25,26,26,25,0,0,0,0,25,0,23,26,24,23,23,0,0,0,0,37,4|4,26,25,26,26,25,25,26,23,23,23,25,26,26,25,0,0,0,0,25,25,23,26,24,24,24,23,0,0,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,0,0,0,0,23,23,23,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,39,0,0,0,0,0,0,0,0,0,0,0,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40,41,5,5,0,5,0,0,0,0,0,0,0,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,5,0,5,0,0,0,0,0,0,0,0,4|4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,4|4,22,22,22,22,22,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,4|4,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,4|4,22,0,22,22,22,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,1,27,27,27,27,27,27|4,22,0,22,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,1,1,1,1,1,1,27|4,22,0,22,22,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,1,1,1,1,1,1,27|4,22,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,1,1,1,1,1,1,27|4,22,22,22,22,22,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,42,43,1,1,1,1,27|4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,27,27,27,27,27,27,27,27";
	//json string in Map übergeben
	Map map = Map::Map();
	map.Loadmap(mapstr);
	//views erstellen
	sf::View view(sf::Vector2f(x, y), sf::Vector2f(300, 200));
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	
	//ToDO Map grösse herausfinden und diese beim view einsetzen
	sf::View minimapView(sf::Vector2f(0, 0), sf::Vector2f(1880, 1200));
	minimapView.setViewport(sf::FloatRect(0.5, 0.5, 0.5, 0.5));

	std::string namestr;
	sf::Text nametext;
	nametext.setFont(font);
	nametext.setCharacterSize(24);
	nametext.setPosition(window.getSize().x /2 - nametext.getLocalBounds().width / 2, 200);
	bool nameselected = true;

	std::string passwordstr;
	sf::Text passwordtext;
	passwordtext.setFont(font);
	passwordtext.setCharacterSize(24);
	passwordtext.setPosition(window.getSize().x / 2 - passwordtext.getLocalBounds().width / 2, 230);
	bool passwordselected = true;

	// players map
	std::map<sf::Uint16, Player> players;
	std::string looptype = "login";
	//Update
	while (window.isOpen())
	{

		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(looptype == "login"){
				if (event.type == sf::Event::TextEntered &&  nameselected)
				{
					// Handle ASCII characters only that arent enter or tab or del etc.
					if (event.text.unicode == '\b' && namestr.length() >0)
					{
						namestr.erase(namestr.size() - 1, 1);
						nametext.setString(namestr);
						nametext.setPosition(window.getSize().x / 2 - nametext.getLocalBounds().width / 2, 285);
					}
					else if (event.text.unicode < 128 && event.text.unicode > 31)
					{
						nametext.setPosition(window.getSize().x / 2 - nametext.getLocalBounds().width / 2, 285);
						namestr += static_cast<char>(event.text.unicode);
						nametext.setString(namestr);
					}
					else if (event.text.unicode == 13) {
						nameselected = false;
						passwordselected = true;
						//go to password
					}else if (event.text.unicode == 9) {
						nameselected = false;
						passwordselected = true;
						//go to password
					}
				}
				else if (event.type == sf::Event::TextEntered &&  passwordselected) 
				{
					if (event.text.unicode == '\b' && passwordstr.length() > 0)
					{
						passwordstr.erase(passwordstr.size() - 1, 1);
						passwordtext.setString(passwordstr);
						passwordtext.setPosition(window.getSize().x / 2 - passwordtext.getLocalBounds().width / 2, 330);
					}
					else if (event.text.unicode < 128 && event.text.unicode > 32)
					{
						passwordtext.setPosition(window.getSize().x / 2 - passwordtext.getLocalBounds().width / 2, 330);
						passwordstr += static_cast<char>(event.text.unicode);
						passwordtext.setString(passwordstr);
					}
					else if (event.text.unicode == 13) {

						//send data to server to check if positive change looptype
						looptype = "game";
						//change data to data sent by server
						mainplayer.SetName(font, namestr);
						mainplayer.SetTexture(keggly);
						mainplayer.SetManaBar(mana, manabar);
						mainplayer.SetHealthBar(health, healthbar);
					}
					else if (event.text.unicode == 9) {
						nameselected = true;
						passwordselected = false;
						//go to name
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (event.mouseButton.x > 70 && event.mouseButton.x < 850 && event.mouseButton.y < 320 && event.mouseButton.y > 290)
					{
						nameselected = true;
						passwordselected = false;
						//go to name
					}
					else if(event.mouseButton.x > 70 && event.mouseButton.x < 850 && event.mouseButton.y < 365 && event.mouseButton.y > 330)
					{
						nameselected = false;
						passwordselected = true;
						//go to password
					}
					else if (event.mouseButton.x > 250 && event.mouseButton.x < 650 && event.mouseButton.y < 485 && event.mouseButton.y > 440)
					{
						//send data to server to check if positive change looptype
						looptype = "game";
						//change data to data sent by server
						mainplayer.SetName(font, namestr);
						mainplayer.SetTexture(keggly);
						mainplayer.SetManaBar(mana, manabar);
						mainplayer.SetHealthBar(health, healthbar);
					}
				}
			}
		}	
		if (event.key.code == sf::Keyboard::Escape) {
			window.close();
		}

		if (looptype == "login") {
			window.draw(spritelogin);
			window.draw(nametext);
			window.draw(passwordtext);
			window.display();

		}
		else if (looptype == "game") {

			con.setPosition(mainplayer.getPosX(), mainplayer.getPosY());

			while (sf::Uint16 player_id = con.popNewPlayer()) {
				auto coords = con.getPlayerPosition(player_id);
				Player player;
				players[player_id] = player;
			}

			while (sf::Uint16 player_id = con.popDisconnectedPlayer()) {
				players.erase(player_id);
			}

			mainplayer.Update(view);

			// Draw View
			window.clear(sf::Color::Black);
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
	}
	
	return 0;
}