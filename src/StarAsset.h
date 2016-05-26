#ifndef STARASSET_H
#define STARASSET_H

#include <vector>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class StarAsset : public GameAsset {
    public:
        StarAsset(glm::vec3,glm::vec3, BBoxType, float, glm::vec3, glm::vec3);
        ~StarAsset();

};

#endif // STARASSET_H
