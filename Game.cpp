#include "Game.h"
void Game::update() {
	int timer = getTime();
	while (window.isOpen()) {
		int timeNow = getTime();
		int diff = timer - timeNow;
		
		if (state == 0) {
			if (diff>= 500) {
				walls.push_back(new Wall(-rand() % 300));
				timer = timeNow;
			}

			for (unsigned int a = 0;a < walls.size();a++) {
				if (walls[a]->out()) {
					delete walls[a];
					walls.erase(walls.begin() + a);
				}
				else {
					walls[a]->update();
				}
			}

			bird->update();
		}
		if (state == 1) {

		}
	}
}

Game::Game() : updateT(&Game::update, this), drawT(&Game::draw, this)
{
	sf::Thread updateT(&Game::update);
	sf::Thread drawT(&Game::draw);
	srand(time(NULL));
	bird = new Bird();
	state = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy!");
}


Game::~Game()
{
	for (unsigned int a = 0;a < walls.size();a++) {
		delete walls[a];
	}
	delete bird;
}
void Game::run() {

	draw.launch();
	update.launch();
}
void Game::eventHandler() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			window.close();
		if (state == 0) {
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Space)) {
				bird->jump();
				std::cout << "jump\n";
			}
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape)) {
				state = 1;
				window.close();
			}
		}
	}
}
int Game::getTime()
{
	return clock()/ CLOCKS_PER_SEC*1000;
}
void Game::draw()
{
	while(window.isOpen()){
		window.clear();
	
		for (unsigned int a = 0;a < walls.size();a++) {
			window.draw(*walls[a]);
		}
		window.draw(*bird);

		window.display();
		
	}
	
}
