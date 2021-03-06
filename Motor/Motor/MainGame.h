#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include "Sprite.h"
#include "GLProgram.h"
#include "Window.h"

enum class GameState
{
	PLAY,EXIT
};

class MainGame
{
private:
	int witdh;
	int height;
	GLProgram glProgram;
	Window window;
	Sprite sprite;
	void processInput();
	void init();
	void initShaders();
	float time;
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

