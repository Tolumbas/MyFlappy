#include <SFML/Graphics.hpp>
#include "bird.h";

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Bird bird;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				bird.jump();
		}

		window.draw(bird);
		bird.update();
	}
}