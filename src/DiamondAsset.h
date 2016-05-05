#ifndef DIAMONDASSET_H
#define DIAMONDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class DiamondAsset : public GameAsset {
    public:
        DiamondAsset(glm::vec3,glm::vec3, int, float, glm::vec3, glm::vec3);
        ~DiamondAsset();

        virtual void Draw(GLuint);

        float rf();

    private:
        glm::vec3 position;
        GLuint element_buffer_length, vertex_buffer_length, colour_buffer_length;
        GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;

};

#endif // DIAMONDASSET_H
