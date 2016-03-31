#include "Score.h"
#include <string>


void Score::update()
{
	text.setString(std::to_string(score));
}

Score::Score() : Score(0)
{
}

Score::Score(int in)
{
	font.loadFromFile("FlappyFont.TTF");
	text.setCharacterSize(50);
	text.setFont(font);
	text.setPosition(10,10);
	set(in);
	update();
}


Score::~Score()
{
}

int Score::get()
{
	return score;
}

void Score::itterate()
{
	score++;
	update();
}

void Score::reset()
{
	score = 0;
	update();

}

void Score::set(int in)
{
	if (score >= 0) {
		score = in;
		update();
	}
}

void Score::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text,states);
}
