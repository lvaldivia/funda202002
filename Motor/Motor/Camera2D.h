#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera2D
{
private:
	glm::vec2 position;
	float scale;
	int screenWidth;
	int screenHeight;
	bool needUpdateMatrix;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
public:
	Camera2D();
	~Camera2D();
	void update();
	void init(int _screenWidth, int _screenHeight);
	void setPosition(const glm::vec2& newPosition) {
		position = newPosition;
		needUpdateMatrix = true;
	}
	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}


};

