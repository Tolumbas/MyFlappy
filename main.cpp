#include <SFML/Graphics.hpp>
#include "bird.h"
#include <iostream>
#include "wall.h"
#include <vector> 
#include <time.h>
#include <functional>
#include <stdlib.h>



void update(int state, std::vector<Wall*> walls, Bird bird, sf::RenderWindow window) {
	time_t timer = time(0);
	if (state == 0) {
		if (difftime(time(NULL), timer) >= 1) {
			walls.push_back(new Wall(-rand() % 300));
			timer = time(NULL);
		}

		for (unsigned int a = 0;a < walls.size();a++) {
			if (walls[a]->out()) {
				delete walls[a];
				walls.erase(walls.begin() + a);
			}
			else {
				walls[a]->update();
				window.draw(*walls[a]);
			}
		}
		window.draw(bird);
		bird.update();
	}
	if (state == 1) {

	}
}


void main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy!");
	Bird bird;
	std::vector<Wall*> walls;
	short state = 0;
	

	unsigned int frames = 0;

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
		sf::Thread thread(std::bind(&update, state, walls, bird, window));
		thread.launch();

		window.display();
		frames++;
	}
}