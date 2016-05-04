#include <glm/ext.hpp>
#include "common.h"
#include <iostream>
#include <string>

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_
class Camera {
    public:
        Camera();
        void CheckCollision(glm::vec3 bounding_box_max, glm::vec3 bounding_box_min);

        glm::mat4 UpdateCameraPosition(Input input_direction, int mouse_x, int mouse_y);
        glm::vec3 GetCameraPosition();
        glm::vec3 GetCameraDirection();

    private:
        glm::vec3 camera_position, camera_direction, camera_right, camera_up;

        float camera_horizontal_angle, camera_vertical_angle;
        float mouse_delta_x, mouse_delta_y, camera_movement_speed;

        std::string last_direction;
};

#endif
