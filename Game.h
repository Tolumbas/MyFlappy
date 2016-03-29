#pragma once
#include <SFML/Graphics.hpp>
#include "bird.h"
#include <iostream>
#include "wall.h"
#include <vector> 
#include <time.h>
#include <functional>
#include <stdlib.h>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void update();
	void draw();
	void eventHandler();
	int getTime();
	Bird* bird;
	vector<Wall*>  walls;
	short state;
	int timer;
	int spawntimer;
	sf::RenderWindow window;
};

