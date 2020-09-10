#include "Sprite.h"

Sprite::Sprite()
{
	vboID = 0;
}

Sprite::~Sprite()
{
}

void Sprite::init(float _x, float _y, int _width, int _height)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	if (vboID == 0) {
		glGenBuffers(1, &vboID);
	}
	float vertexData[12];

	vertexData[0] = x + width;
	vertexData[1] = y + height;

	vertexData[2] = x;
	vertexData[3] = y + height;

	vertexData[4] = x;
	vertexData[5] = y;

	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x;
	vertexData[9] = y;

	vertexData[4] = x;
	vertexData[5] = y;
}

void Sprite::draw()
{
}
