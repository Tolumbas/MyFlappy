#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
class Wall :
	public sf::Drawable,
	public sf::Transformable
{
private:
	sf::Image image_top;
	sf::Image image_bot;

	float gap = 200;
	float speed = -0.6f;
	float offset;

	sf::Texture texture_top;
	sf::Texture texture_bot;

	sf::Sprite pipe_top;
	sf::Sprite pipe_bot;
public:
	Wall(float);
	void reset();
	bool out();
	float getX();
	bool scored;
	float getGap();
	float getY();
	float getOffset();
	void update(float);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~Wall();
};

