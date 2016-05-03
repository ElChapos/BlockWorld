#include "Camera.h"
#include <glm/ext.hpp>

/**
 * Initialise camera class
 */
Camera::Camera()
{
    camera_position = glm::vec3(0.0, 0.0, -30.0);
    camera_direction = glm::vec3(0,0,0);
    camera_right = glm::vec3(0,0,0);
    camera_up = glm::vec3(0,0,0);

    camera_horizontal_angle = 0;
    camera_vertical_angle = 0;

    mouse_delta_x = 1;
    mouse_delta_y = 1;

    camera_movement_speed = 0.25;
}

/**
 * Updates the camera position based on user input, if a change is detected the view matrix is updated and returned to be used by the translate shader
 */
glm::mat4 Camera::UpdateCameraPosition(Input input_direction, int mouse_x, int mouse_y)
{
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
    camera_right = glm::vec3(sin(camera_horizontal_angle - 3.14/2.0f), 0, cos(camera_horizontal_angle - 3.14/2.0f));
    camera_up = glm::cross(camera_right, camera_direction);

    // update the position of the camera/player  based on user input
    if(input_direction == UP)
    {
        camera_position += glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle), 0, cos(camera_vertical_angle) * cos(camera_horizontal_angle)) * camera_movement_speed;
        last_direction = "UP";
    }
    if(input_direction == DOWN)
    {
        camera_position -= glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle), 0, cos(camera_vertical_angle) * cos(camera_horizontal_angle)) * camera_movement_speed;
        last_direction = "DOWN";
    }
    if(input_direction == LEFT)
    {
        camera_position -= camera_right * camera_movement_speed;
        last_direction = "LEFT";
    }
    if(input_direction == RIGHT)
    {
        camera_position += camera_right * camera_movement_speed;
        last_direction = "RIGHT";
    }
    if(input_direction == SPACE)
    {
        camera_position += glm::vec3(0.0f, 0.2f, 0.0f);
        last_direction = "SPACE";
    }
    if(input_direction == CTRL)
    {
        camera_position -= glm::vec3(0.0f, 0.2f, 0);
        last_direction = "CTRL";
    }

    // return the view matrix
    return glm::lookAt(camera_position, camera_position + camera_direction, camera_up);
 }

 /**
 * Detects a collision
 */
 void Camera::CheckCollision(glm::vec3 bounding_box_max, glm::vec3 bounding_box_min)
{
    glm::vec3 camera_bounding_box_max = camera_position += glm::vec3(1.0,1.0,1.0);
    glm::vec3 camera_bounding_box_min = camera_position += glm::vec3(-1.0,-1.0,-1.0);

    //Check if Box1's max is greater than Box2's min and Box1's min is less than Box2's max
    if (bounding_box_max.x > camera_bounding_box_min.x && bounding_box_min.x < camera_bounding_box_max.x &&
        bounding_box_max.y > camera_bounding_box_min.y && bounding_box_min.y < camera_bounding_box_max.y &&
        bounding_box_max.z > camera_bounding_box_min.z && bounding_box_min.z < camera_bounding_box_max.z)
    {
        std::cout << "Collision detected with camera" << std::endl;
        if(last_direction == "UP")
        {
            camera_position -= glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle),0,cos(camera_vertical_angle) * cos(camera_horizontal_angle))* camera_movement_speed;
        }
        else if(last_direction == "DOWN")
        {
            camera_position += glm::vec3(cos(camera_vertical_angle) * sin(camera_horizontal_angle), 0,cos(camera_vertical_angle) * cos(camera_horizontal_angle))* camera_movement_speed;
        }
        else if(last_direction == "LEFT")
        {
            camera_position += camera_right * camera_movement_speed;
        }
        else if(last_direction == "RIGHT")
        {
            camera_position -= camera_right * camera_movement_speed;
        }
    }
}
