#ifndef PLAYERASSET_H
#define PLAYERASSET_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class PlayerAsset : public GameAsset {
    public:
        PlayerAsset(glm::vec3, glm::vec3, BBoxType, float, glm::vec3, glm::vec3);
        ~PlayerAsset();

};

#endif // PLAYERASSET_H
