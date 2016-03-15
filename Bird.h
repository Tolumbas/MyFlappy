#pragma once
#include <SFML/Graphics.hpp>

class Bird : public sf::Drawable
{
private:
	sf::Sprite bird;
	float vx, vy;
	float gravity;
public:
	Bird();
	void jump();
	void update();
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::VertexArray m_vertices;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
