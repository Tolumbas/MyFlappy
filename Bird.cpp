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
	return (coords.y < 25.0f || coords.y + 25>600);
}

void Bird::jump()
{
	vy = -0.5f;
}

void Bird::coutPos()
{
	std::cout << vy << '\n';
}

void Bird::update(float diff)
{
	//diff = diff/3;
	//std::cout << diff << '\n';
	vy += gravity*diff;
	//std::cout << vx << vy;
	bird.move(vx*diff, vy*diff);
	bird.setRotation(asin(vy)*180/M_PI);
}

float Bird::getY()
{
	return bird.getPosition().y;
}
float Bird::getX()
{
	return bird.getPosition().x;
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

