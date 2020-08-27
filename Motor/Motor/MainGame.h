#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
enum class GameState
{
	PLAY,EXIT
};

class MainGame
{
private:
	int witdh;
	int height;
	SDL_Window* window;
	//TODO-Sprite
	void processInput();
	void init();
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

