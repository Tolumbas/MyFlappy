#include "Game.h"
void Game::update() {
	int timeNow = getTime();
	int diff = timeNow-timer;
	if (diff <= 0)diff = 1;

	//std::cout << diff << '\n';
	timer = timeNow;

	if (state == 0) {
		if (timeNow-spawntimer>1800) {
			walls.push_back(new Wall(-rand() % 300));
			spawntimer = timeNow;
		}

		for (unsigned int a = 0;a < walls.size();a++) {
			if (walls[a]->out()) {
				delete walls[a];
				walls.erase(walls.begin() + a);
			}
			else {
				walls[a]->update(diff);
			}
			float x = walls[a]->getX();
			float y = walls[a]->getY();
			float offset = walls[a]->getOffset();
			//if()
		}

		bird->update(diff);
		bird->coutPos();
	}
	if (state == 1) {

	}
	
}

Game::Game()
{
	srand(time(NULL));
	bird = new Bird();
	state = 0;
	window.create(sf::VideoMode(800, 600), "Flappy!");
	window.setFramerateLimit(120);
}


Game::~Game()
{
	for (unsigned int a = 0;a < walls.size();a++) {
		delete walls[a];
	}
	delete bird;
}
void Game::run() {
	timer = getTime();
	spawntimer = timer;
	while (window.isOpen()) 
	{
		update();
		draw();
		eventHandler();
	}
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
	//std::cout << "clock: " << clock() / (float)CLOCKS_PER_SEC * 1000 << '\n';
	return clock()/(float)CLOCKS_PER_SEC * 1000;
}
void Game::draw()
{
	window.clear();
	for (unsigned int a = 0;a < walls.size();a++) {
		window.draw(*walls[a]);
	}
	window.draw(*bird);
	window.display();
	
}
