#include "Bird.h"
#include <math.h>


Bird::Bird()
{
	vx = 0;
	vy = 0;
	setPosition(10,10);
}

void Bird::jump()
{
	vy = 5;
}

void Bird::update()
{
	move(vx, vy);
	setRotation(atan2(vy, vx));
}


Bird::~Bird()
{
}
