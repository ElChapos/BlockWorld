#ifndef DIAMONDASSET_H
#define DIAMONDASSET_H

#include <vector>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class DiamondAsset : public GameAsset {
    public:
        DiamondAsset(glm::vec3,glm::vec3, int, float, glm::vec3, glm::vec3);
        ~DiamondAsset();

    private:
};

#endif // DIAMONDASSET_H
