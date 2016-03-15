#include "Bird.h"
#include <math.h>
#include <iostream>

Bird::Bird()
{
	sf::Texture png = sf::Texture();
	png.loadFromFile("img/flappy.png");
	bird.setTexture(png);
	/*
	vx = 0;
	vy = 0;

	setPosition(100,100);

	sf::Texture y;
	y.loadFromFile("img/flappy2.png");

	setTexture(y);

	gravity = 0.001f;
	*/
}

void Bird::jump()
{
	//vy = -0.5;
}

void Bird::update()
{
	//vy += gravity;
	//std::cout << vx << vy;
	//move(vx, vy);
	//setRotation(atan2(vy, vx));
}

void Bird::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bird);
}

