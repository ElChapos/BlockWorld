#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
    public:
        CubeAsset(glm::vec3,glm::vec3, int, float, glm::vec3, glm::vec3);
        ~CubeAsset();
    private:
};

#endif // CUBEASSET_H
