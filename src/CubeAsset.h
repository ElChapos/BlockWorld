#ifndef CUBEASSET_H
#define CUBEASSET_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
    public:
        CubeAsset(glm::vec3,glm::vec3, BBoxType, float, glm::vec3, glm::vec3);
        ~CubeAsset();

};

#endif // CUBEASSET_H
