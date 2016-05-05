/*#ifndef STARASSET_H
#define STARASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class StarAsset : public GameAsset {
    public:
        StarAsset(glm::vec3,glm::vec3, int, float, glm::vec3, glm::vec3);
        ~StarAsset();

        virtual void Draw(GLuint);

        float rf();
        glm::vec3 GetVec3();

    private:
        glm::vec3 position;
        GLuint element_buffer_length, vertex_buffer_length, colour_buffer_length;
        GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;

        // Must be private, only called within StarAsset ONLY
        void UpdateBuffer(GLfloat);

};

#endif // STARASSET_H
*/