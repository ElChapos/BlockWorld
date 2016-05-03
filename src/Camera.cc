#include "Camera.h"
#include <glm/ext.hpp>
//// based on the tutorial found here http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/

// this class stores the position of the camera/player and creates the view matrix based on current position of the camera.

// initialises the camera position and variables
Camera::Camera(){


 	  camera_position = glm::vec3(0.0, 0.0, 0.0);
	  camera_direction = glm::vec3(0,0,0);
	  camera_right = glm::vec3(0,0,0);
	  camera_up = glm::vec3(0,0,0);

	  camera_horizontal_angle = 0;
	  camera_vertical_angle = 0;

      mouse_delta_x = 1;
	  mouse_delta_y = 1;

	  camera_movement_speed = 0.25;
}




// Updates the cameras position based on user input, if a change is detected the view matrix is updated and returned to be used by the translate shader
glm::mat4 Camera::UpdateCameraPosition(Input input_direction, int mouse_x, int mouse_y){

 // mouse delta position inverted
	mouse_delta_x = -mouse_x;
	mouse_delta_y = -mouse_y;

	camera_horizontal_angle += 0.01 * mouse_delta_x;
    // restrict the mouse view from going too far up or down
    if((camera_vertical_angle + (0.01 * mouse_delta_y)) < 1 && (camera_vertical_angle + (0.01 * mouse_delta_y)) > -1 )
    {
        camera_vertical_angle += 0.01 * mouse_delta_y;
    }


    // calculate the camera_direction to look at, the angle to the right of horiontal angle and the angle up and between the forward and right angles
	camera_direction = glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle),sin(camera_vertical_angle),cos(camera_vertical_angle) * cos(camera_horizontal_angle));
	camera_right = glm::vec3(sin(camera_horizontal_angle - 3.14/2.0f),0,cos(camera_horizontal_angle - 3.14/2.0f));
	camera_up = glm::cross(camera_right, camera_direction);


    // update the position of the camera/player  based on user input
 	if(input_direction == UP)
 	{
		camera_position += glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle), 0,cos(camera_vertical_angle) * cos(camera_horizontal_angle))* camera_movement_speed;
	}
	else if(input_direction == DOWN)
	{
		camera_position -= glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle),0,cos(camera_vertical_angle) * cos(camera_horizontal_angle))* camera_movement_speed;
	}
	else if(input_direction == LEFT)
	{
		camera_position -= camera_right * camera_movement_speed;
	}
	else if(input_direction == RIGHT)
	{
		camera_position += camera_right * camera_movement_speed;
	}

    // return the view matrix
	  return glm::lookAt(camera_position, camera_position + camera_direction,camera_up);
 }




