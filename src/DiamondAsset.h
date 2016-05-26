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
        DiamondAsset(glm::vec3,glm::vec3, BBoxType, float, glm::vec3, glm::vec3);
        ~DiamondAsset();

};

#endif // DIAMONDASSET_H
