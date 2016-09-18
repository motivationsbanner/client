#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include <iostream>
#include <string>
#include <fstream>

sf::Texture loadTexture(std::string host, std::string uri)
{
	sf::Http http(host);
	sf::Http::Request request(uri);
	auto response = http.sendRequest(request);
	auto data = response.getBody();

	sf::Texture text;
	text.loadFromMemory(data.data(), data.length());

	return text;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(920, 580), "Hallo!");

	sf::Texture texture = loadTexture("www.cravay.me", "textures/keggly.bmp");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	


		window.clear();

		window.draw(sprite);

		window.display();
	}
	
	return 0;
}