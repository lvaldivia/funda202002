#include "MainGame.h"
#include <iostream>
#include "Error.h"

using namespace std;


MainGame::MainGame() 
	//: window(nullptr),witdh(800),height(600), gameState(GameState::PLAY)
{
	window = nullptr;
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
	glProgram.linkShader();
}

void MainGame::run()
{
	init();
	sprite.init(-1, -1, 1, 1);
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
	window = SDL_CreateWindow("GAAAA :v", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, witdh, height, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		fatalError("Error in loading SDL_Windows");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Error in loading Glew");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	initShaders();
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glProgram.use();
	GLuint timeLocation = glProgram.getUniformLocation("times");

	glUniform1f(timeLocation, time);
	time += 0.0002;
	sprite.draw();
	glProgram.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}
