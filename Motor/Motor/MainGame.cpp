#include "MainGame.h"
#include <iostream>
#include "Error.h"

using namespace std;


MainGame::MainGame() 
	//: window(nullptr),witdh(800),height(600), gameState(GameState::PLAY)
{
	witdh = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
}

MainGame::~MainGame()
{
}

void MainGame::initShaders() {
	glProgram.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	glProgram.AddAtribute("vertexPosition");
	glProgram.AddAtribute("vertexColor");
	glProgram.AddAtribute("vertexUV");
	glProgram.linkShader();
}

void MainGame::run()
{
	init();
	sprite.init(-1, -1, 1, 1,"Images/mario.png");
	update();
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//cout << event.motion.x <<  " , " << event.motion.y << endl;
			break;
		}
	}
}

void MainGame::init()
{
	window.create("GAAA", witdh, height);
	initShaders();
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glProgram.use();
	
	GLuint timeLocation = glProgram.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	GLuint imageLocation = glProgram.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	time += 0.0002;
	sprite.draw();
	glProgram.unuse();
	window.swapBuffer();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}
