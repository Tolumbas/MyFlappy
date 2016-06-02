#include "Game.h"
void Game::update() {
	int timeNow = getTime();
	int diff = timeNow-timer;
	if (diff <= 0)diff = 1;

	//std::cout << diff << '\n';
	timer = timeNow;

	if (state == 0 && !gameover) {
		if (timeNow-spawntimer>2000) {
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
			float wx = walls[a]->getX()+5;
			float ww = 140.0f;
			float wh = 376.0f;
			float gap = walls[a]->getGap();
			float offset = walls[a]->getOffset();
			float bx = bird->getX()-25;
			float by = bird->getY()-25;
			float bw = 50.0f;
			bool scored = walls[a]->scored;

			if (bx + bw >= wx && bx <= wx + ww && (by <= offset + wh || by + bw >= offset + wh + gap)) {
				std::cout << " wall colision\n";
				gameover = true;
				Sbuf.play();
			}
			if (bird->Coltopbot()) {
				std::cout << "bondry colision\n";
				gameover = true;
				bird->stop();
				Sbuf.play();
			}
			if (bx-75 + bw >= wx && bx-75 <= wx + ww) {
				if (scored == false) {
					score.itterate();
					Scling.play();
					walls[a]->scored = true;
				}
			}
			/*else if (scored == true) {
				scored = false;
			}*/
		}

		bird->update(diff);
		background.move(diff);
		//bird->coutPos();
	}
	if (state == 0 && gameover) {
		bird->update(diff);
		if (bird->Colbot()) {
			state = 1;
		}
	}
	if (state == 1) {
		
	}
	
}

Game::Game()
{
	srand(time(NULL));
	bird = new Bird();
	cling.loadFromFile("sounds/get_point.ogg");
	buf.loadFromFile("sounds/die.ogg");
	Scling.setBuffer(cling);
	Sbuf.setBuffer(buf);
	state = 0;
	score.reset();

	gameover = false;
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
			if (!gameover) {
				if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Space)) {
					bird->jump();
					std::cout << "jump\n";
				}
			}
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape)) {
				state = 1;
				window.close();
			}
		}
		if (state == 1) {
			if (event.type == sf::Event::KeyPressed && !(event.key.code == sf::Keyboard::Escape)) {
				bird->reset();
				std::cout << "new Game\n";
				for (unsigned int a = 0;a < walls.size();a++) {
					delete walls[a];
				}
				walls.clear();
				score.reset();
				gameover = false;
				state = 0;
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
	window.draw(background);
	for (unsigned int a = 0;a < walls.size();a++) {
		window.draw(*walls[a]);
	}
	window.draw(score);
	window.draw(*bird);
	window.display();
	
}
