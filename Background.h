#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Background : public Drawable
{
private:
	float speed = -0.6f;
	Texture backgroundTexture;
	Texture groundTexture;
	Sprite background;
	Sprite ground1;
	Sprite ground2;
public:
	void draw(RenderTarget &target, RenderStates states) const;
	void move(float);
	Background();
};

