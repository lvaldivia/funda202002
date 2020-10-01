#pragma once
#include <SDL/SDL.h>
#include <gl/glew.h>
#include <string>
using namespace std;
enum WindowFlags {
	INVISIBLE,
	FULLSCREEN,
	BORDERLESS
};
class Window
{
private:
	SDL_Window* window;
	int screenWidth, screenHeight;
public:
	Window();
	~Window();
	void swapBuffer();
	int getScreenWidth() {
		return screenWidth;
	}
	int getScreenHeight() {
		return screenHeight;
	}

	int create(string windowName,int _screenWidth, int _screenHeight);

};

