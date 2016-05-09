#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
    public:
        CubeAsset(glm::vec3,glm::vec3, int, float, glm::vec3, glm::vec3);
        ~CubeAsset();
    
};

#endif // CUBEASSET_H
