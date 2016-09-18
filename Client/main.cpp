#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Hallo!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::cout << "Hallo michael";

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	
	return 0;
}
