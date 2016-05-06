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

    private:
        glm::vec3 position;
};

#endif // DIAMONDASSET_H
