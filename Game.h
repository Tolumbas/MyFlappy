#pragma once
#include <SFML/Graphics.hpp>
#include <vector> 
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "bird.h"
#include "wall.h"
#include "Score.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	vector<Wall*>  walls;
	short state;
	int timer;
	int spawntimer;
	sf::RenderWindow window;
	Score score;
	Bird* bird;
	bool scored;
	bool gameover;

	void update();
	void draw();
	void eventHandler();
	int getTime();




};

