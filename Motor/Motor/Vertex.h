#pragma once
#include <GL/glew.h>

struct Position {
	float x;
	float y;
};


struct Color {
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

};

struct Vertex {
	Position position;
	Color color;

	void setColor(GLubyte r, GLubyte g, GLubyte b , GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void setPosition(float _x,float _y) {
		position.x = _x;
		position.y = _y;
	}

};

