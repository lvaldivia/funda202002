#pragma once
#include <GL/glew.h>
using namespace std;

class Sprite
{
private:
	float x;
	float y;
	int width;
	int height;
	GLuint vboID;
public:
	Sprite();
	~Sprite();
	void init(float _x, float _y, int _width, int _height);
	void draw();
};

