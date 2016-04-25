#include <glm/ext.hpp>
#include "common.h"

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_
class Camera{

public:
	Camera();
	glm::mat4 UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY);

private:


	glm::vec3 cameraPosition;

	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

 	float horizontalAngle;
 	float verticalAngle;
 
	float mouseDeltaX;
	float mouseDeltaY;

	float cameraMovementSpeed;


};


#endif

