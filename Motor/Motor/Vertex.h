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

struct UV {
	float u;
	float v;
};

struct Vertex {
	Position position;
	Color color;
	UV uv;

	void setColor(GLubyte r, GLubyte g, GLubyte b , GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void setUV(float _u, float _v) {
		uv.u = _u;
		uv.v = _v;
	}

	void setPosition(float _x,float _y) {
		position.x = _x;
		position.y = _y;
	}

};

