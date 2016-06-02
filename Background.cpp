#include "Background.h"



void Background::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(background);
	target.draw(ground1);
	target.draw(ground2);
}

void Background::move(float d)
{
	//background.move(amount / 4,0);
	d /= 3;
	ground1.move(speed*d,0);
	ground2.move(speed*d, 0);
	if (ground1.getPosition().x <= -800) {
		ground1.move(1600, 0);
	}
	if (ground2.getPosition().x <= -800) {
		ground2.move(1600, 0);
	}
}

Background::Background()
{
	backgroundTexture.loadFromFile("img/background.png");
	groundTexture.loadFromFile("img/floor.png");
	background.setTexture(backgroundTexture);
	ground1.setTexture(groundTexture);
	ground2.setTexture(groundTexture);

	ground1.setPosition(0, 600 - 30);
	ground2.setPosition(800, 600 - 30);
}

