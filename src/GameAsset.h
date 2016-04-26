#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>
#include <GL/gl.h>
#include <memory>
#include "BoundingBox.h"

class GameAsset
{
	public:
		GameAsset(glm::vec3);
		virtual void Draw(GLuint) = 0;
		std::shared_ptr<BoundingBox> bounding_box;
};

#endif
