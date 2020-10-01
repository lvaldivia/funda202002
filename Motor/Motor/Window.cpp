#include "Window.h"
#include "Error.h"


Window::Window() {

}
Window::~Window() {

}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(window);
}

int Window::create(string windowName, int _screenWidth, int _screenHeight) {
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
	window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
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
	return 0;
}
