#include "GLProgram.h"
#include "Error.h"
#include <fstream>
#include <vector>

GLProgram::GLProgram() : programID(0), 
	vertexShaderID(0), 
	fragmentShaderID(0), 
	numAttribute(0)
{
}


void GLProgram::compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath)
{
	programID = glCreateProgram();
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShaderID == 0) {
		fatalError("Can't create VERTEX_SHADER");
	}
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShaderID == 0) {
		fatalError("Can't create FRAGMENT_SHADER");
	}
	compileShader(vertexShaderFilePath, vertexShaderID);
	compileShader(fragmentShaderFilePath, fragmentShaderID);
}



void GLProgram::compileShader(const string& shaderPath, GLuint id)
{
	string fileContent = "";
	string line = "";

	ifstream shaderFile(shaderPath);
	if (shaderFile.fail()) {
		fatalError("Could not open " + shaderPath);
	}
	while (getline(shaderFile, line)) {
		fileContent += line + "\n";
	}
	shaderFile.close();
	const char* contents = fileContent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);

	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLenght = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLenght);
		std::vector<GLchar> errorLog(maxLenght);
		
		glGetShaderInfoLog(id, maxLenght, &maxLenght, &errorLog[0]);
		fatalError("Shaders do not compile " + printf("%s", &(errorLog[0])));
		glDeleteShader(id);
		return;
	}
}

void GLProgram::AddAtribute(const string& atributeName)
{
	glBindAttribLocation(programID, numAttribute++, atributeName.c_str());
}

void GLProgram::use()
{
	glUseProgram(programID);
	for (int i = 0; i < numAttribute; i++)
	{
		glEnableVertexAttribArray(i);
	}

}

void GLProgram::unuse()
{
	glUseProgram(programID);
	for (int i = 0; i < numAttribute; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

GLuint GLProgram::getUniformLocation(const string& name)
{
	GLuint location = glGetUniformLocation(programID, name.c_str());
	if (location == GL_INVALID_ENUM) {
		fatalError("Uniform " + name + " not found in shader");
	}
	return location;
}

void GLProgram::linkShader()
{
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	GLint isLinked = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLenght = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLenght);
		std::vector<GLchar> infoLog(maxLenght);
		glGetProgramInfoLog(programID, maxLenght, &maxLenght, &infoLog[0]);
		glDeleteProgram(programID);
		fatalError("Shaders do not linked " + printf("%s",&(infoLog[0])));
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return;
	}
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}


GLProgram::~GLProgram()
{
}

