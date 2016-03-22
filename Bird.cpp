#include "Bird.h"
#include <math.h>
#include <iostream>
#define M_PI 3.14159265359f
Bird::Bird()
{
	//image = sf::Image();
	image.loadFromFile("img/flappy.png");
	texture.loadFromImage(image);
	bird.setTexture(texture);
	
	reset();
	
}

bool Bird::Coltopbot()
{
	sf::Vector2f coords = bird.getPosition();
	return (coords.y < 0 || coords.y + 50>600);
}

void Bird::jump()
{
	vy = -0.5;
}

void Bird::update()
{
	vy += gravity;
	//std::cout << vx << vy;
	bird.move(vx, vy);
	bird.setRotation(asin(vy)*180/M_PI);
}

void Bird::reset()
{
	vx = 0;
	vy = 0;
	bird.setOrigin(25.0f, 25.0f);
	bird.setPosition(100, 100);
	gravity = 0.001f;
}

void Bird::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bird);
}

