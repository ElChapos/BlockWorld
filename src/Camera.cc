#include "Camera.h"
#include <glm/ext.hpp>
//// based on the tutorial found here http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/

// this class stores the position of the camera/player and creates the view matrix based on current position of the camera.

// initialises the camera position and variables
Camera::Camera(){


 	  cameraPosition = glm::vec3(0.0, 0.0, 0.0);
	  direction = glm::vec3(0,0,0);
	  right = glm::vec3(0,0,0);
	  up = glm::vec3(0,0,0);

	  horizontalAngle = 0;
	  verticalAngle = 0;

      mouseDeltaX = 1;
	  mouseDeltaY = 1;

	  cameraMovementSpeed = 0.25;
}

glm::vec3 Camera::getCameraPosition(){
std::cout <<  "returning camera" << std::endl;
return cameraPosition;
}

// Updates the cameras position based on user input, if a change is detected the view matrix is updated and returned to be used by the translate shader
glm::mat4 Camera::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){

 // mouse delta position inverted
	mouseDeltaX = -mouseX;
	mouseDeltaY = -mouseY;

	horizontalAngle += 0.01 * mouseDeltaX;
// restrict the mouse view from going too far up or down
if((verticalAngle + (0.01 * mouseDeltaY)) < 1 && (verticalAngle + (0.01 * mouseDeltaY)) > -1 ){
	verticalAngle += 0.01 * mouseDeltaY;
}


// calculate the direction to look at, the angle to the right of horiontal angle and the angle up and between the forward and right angles
	direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),sin(verticalAngle),cos(verticalAngle) * cos(horizontalAngle));

	right = glm::vec3(sin(horizontalAngle - 3.14/2.0f),0,cos(horizontalAngle - 3.14/2.0f));

	up = glm::cross(right, direction);




// update the position of the camera/player  based on user input
 	if(input_Direction == UP){

		cameraPosition += glm::vec3(cos(verticalAngle) * sin(horizontalAngle), 0,cos(verticalAngle) * cos(horizontalAngle))* cameraMovementSpeed;

	}else if(input_Direction == DOWN){

		cameraPosition -= glm::vec3(cos(verticalAngle) * sin(horizontalAngle),0,cos(verticalAngle) * cos(horizontalAngle))* cameraMovementSpeed;

	}else if(input_Direction == LEFT){

		cameraPosition -= right * cameraMovementSpeed;

	}else if(input_Direction == RIGHT){

		cameraPosition += right * cameraMovementSpeed;
	}

//	return the view matrix
	  return glm::lookAt(cameraPosition, cameraPosition + direction,up);
 }




