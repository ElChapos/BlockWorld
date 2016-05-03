#include <glm/ext.hpp>
#include "common.h"
#include <iostream>
#include <string>

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_
class Camera {
    public:
        Camera();
        glm::mat4 UpdateCameraPosition(Input input_direction, int mouse_x, int mouse_y);
        void CheckCollision(glm::vec3 bounding_box_max, glm::vec3 bounding_box_min);
    private:
        glm::vec3 camera_position;
        glm::vec3 camera_direction;
        glm::vec3 camera_right;
        glm::vec3 camera_up;

        float camera_horizontal_angle;
        float camera_vertical_angle;

        float mouse_delta_x;
        float mouse_delta_y;

        float camera_movement_speed;

        std::string last_direction;
};

#endif
