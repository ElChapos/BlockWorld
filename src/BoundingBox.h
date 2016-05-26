#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <memory>
#include <utility>
#include <ostream>
#include "common.h"

#include <vector>

class BoundingBox {
    public:
        BoundingBox(glm::vec3, BBoxType, float, glm::vec3, glm::vec3);
        ~BoundingBox();

        glm::vec3 GetVec3();
        glm::mat4 GetModelTransformation();
        glm::vec3 GetMaxAndMin(int);

        void Translate(glm::vec3);
        void Scale(float);
        void Rotate(glm::vec3);
        void CheckCollision(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
        void SetPath(std::vector<glm::vec3>);
        void FollowPath();
        std::vector<glm::vec3> path_list;
        BBoxType type = NONE;

    private:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 speed;
        glm::vec3 direction;

        float scale;
        glm::mat4 translate_matrix;
        glm::mat4 scale_matrix;
        glm::mat4 model_matrix;
        int path_counter = 0 ;
        bool destination_reached = true;

};
