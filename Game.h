#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector> 
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "bird.h"
#include "wall.h"
#include "Score.h"
#include "Background.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	vector<Wall*>  walls;
	Score score;
	Bird* bird;
	Background background;
	SoundBuffer cling;
	SoundBuffer buf;
	Sound Scling;
	Sound Sbuf;

	short state;
	int timer;
	int spawntimer;
	sf::RenderWindow window;

	bool gameover;

	void update();
	void draw();
	void eventHandler();
	int getTime();




};

