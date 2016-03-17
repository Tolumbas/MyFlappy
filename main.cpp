#include <SFML/Graphics.hpp>
#include "bird.h"
#include <iostream>
#include "main.h"

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy!");
	Bird bird;
	Walls walls;
	short state = 0;



	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
			if (state == 0) {
				if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Space)) {
					bird.jump();
					std::cout << "jump\n";
				}
				if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape)) {
					state = 1;
					window.close();
				}
			}
		}
		if (state == 0) {
			window.draw(bird);
			bird.update();
		}
		if (state == 1) {

		}
		window.display();
	}
}