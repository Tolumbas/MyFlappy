#include "game.h"





void main()
{
	Game* game = new Game();
	game->run();
	delete game;
}