
#include <SDL\SDL.h>
#include "MainGame.h"

int main(int arg, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	MainGame game;
	game.run();
	system("PAUSE");
	return 0;
}