#pragma once
#include <SFML/Graphics.hpp>
class Score :
	public sf::Drawable
{
private:
	int score;
	sf::Text text;
	void update();
	sf::Font font;
public:
	Score();
	Score(int);
	~Score();
	int get();
	void itterate();
	void reset();
	void set(int);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

