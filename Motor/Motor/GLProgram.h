#pragma once
#include <GL/glew.h>
#include <string>

using namespace std;

class GLProgram
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;

	void compileShader(const string& shaderPath, GLuint id);
	
	
	int numAttribute;
public:
	GLProgram();
	~GLProgram();
	void compileShaders(const string& vertexShaderFilePath,
		const string& fragmentShaderFilePath);
	void linkShader();
	void AddAtribute(const string& atributeName);
	void use();
	GLuint getUniformLocation(const string& name);
	void unuse();
};

