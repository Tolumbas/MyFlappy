#include "Background.h"



void Background::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(background);
	target.draw(ground1);
	target.draw(ground2);
}

void Background::move(float amount)
{
	//background.move(amount / 4,0);
	//ground1.move(amount / 3,0);
	//ground2.move(amount / 3, 0);
	if (ground1.getPosition().x <= -800) {
		ground1.move(800, 0);
	}
	if (ground2.getPosition().x <= -800) {
		ground2.move(800, 0);
	}
}

Background::Background()
{
	backgroundTexture.loadFromFile("img/background.png");
	groundTexture.loadFromFile("img/floor.png");
	background.setTexture(backgroundTexture);
	ground1.setTexture(groundTexture);
	ground2.setTexture(groundTexture);

	ground1.setPosition(0, 600 - 100);
	ground2.setPosition(800, 600 - 100);
}

