#pragma once
#include <SFML/Graphics.hpp>
class Bird : public sf::Sprite
{
private:
	float vx, vy;
	float gravity;
public:
	Bird();
	void jump();
	void update();
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::VertexArray m_vertices;
};
