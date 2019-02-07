#include "Wall.h"
#include <iostream>
using namespace sf;


Wall::Wall(float offset)
{
	this->offset = offset;
	scored = false;
	image_top = Image();
	image_top.loadFromFile("img/pipe_up.png");
	texture_top = Texture();
	texture_top.loadFromImage(image_top);
	pipe_top = Sprite();
	pipe_top.setTexture(texture_top);

	image_bot = Image();
	image_bot.loadFromFile("img/pipe_down.png");
	texture_bot = Texture();
	texture_bot.loadFromImage(image_bot);
	pipe_bot = Sprite();
	pipe_bot.setTexture(texture_bot);

	reset();
}

void Wall::reset()
{
	setPosition(800, 0);
}


bool Wall::out()
{
	return getPosition().x + 150 < 0;
}

float Wall::getX()
{
	return getPosition().x;
}
float Wall::getGap()
{
	return gap;
}
float Wall::getY()
{
	return getPosition().y;
}
float Wall::getOffset()
{
	return offset;
}

void Wall::update(float diff)
{
	diff = diff / 3;
	move(speed*diff, 0);
	//std::cout << getPosition().x << " " << getPosition().y << '\n';
	pipe_top.setPosition(getPosition().x, offset);
	pipe_bot.setPosition(getPosition().x, offset+376+gap);
}

void Wall::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(pipe_bot);
	target.draw(pipe_top);
}

Wall::~Wall()
{
}
