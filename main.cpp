#include <SFML/Graphics.hpp>
#include "bird.h"
#include <iostream>

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy!");
	Bird bird;
	/*
	sf::Texture t;
	t.loadFromFile("img/flappy.png");

	sf::Sprite test;
	test.setTexture(t);*/

	sf::Texture png = sf::Texture();
	png.loadFromFile("img/flappy.png");

	sf::Sprite test(png);

	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				bird.jump();
				std::cout << "jump\n";
			}
		}
		
		window.draw(bird);
		//window.draw(test);
		//bird.update();
		window.display();
	}
}