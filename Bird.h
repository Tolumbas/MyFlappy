#pragma once
#include <SFML/Graphics.hpp>

class Bird : public sf::Drawable
{
private:
	sf::Sprite bird;
	float vx, vy;
	float gravity;
	sf::Image image;
	sf::Texture texture;
public:
	Bird();
	bool Coltopbot();
	void jump();
	void coutPos();
	void update(float);
	float getX();
	float getY();
	void reset();
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::VertexArray m_vertices;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
