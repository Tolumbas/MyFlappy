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

	sf::Texture texture_top;
	sf::Texture texture_bot;

	sf::Sprite pipe_top;
	sf::Sprite pipe_bot;
public:
	Wall();
	void reset();
	bool out();
	bool Colision(Bird&);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~Wall();
};

