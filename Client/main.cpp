#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Http.hpp>

#include <iostream>
#include <string>

// http://stackoverflow.com/a/20733740
sf::Texture loadTexture(std::string uri)
{
	sf::Http http("www.cravay.me");
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

	sf::Texture texture = loadTexture("textures/keggly.bmp");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	int i = 0;
	window.setFramerateLimit(20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	


		window.clear();

		// draw everything here...
		if (i % 6 == 0 || i % 6 == 1) {
			sprite.setTextureRect(sf::IntRect(0, 0, 16, 28));
		}
		else if (i % 6 == 2 || i % 6 == 3) {
			sprite.setTextureRect(sf::IntRect(0, 28, 16, 28));
		}
		else if (i % 6 == 4 || i % 6 == 5) {
			sprite.setTextureRect(sf::IntRect(0, 56, 16, 28));
		}

		// Draw
		window.draw(sprite);

		window.display();
		i = i + 1;
	}
	
	return 0;
}