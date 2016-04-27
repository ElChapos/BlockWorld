#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <GL/gl.h>
#include <iostream>
#include <memory>

#include "BoundingBox.h"

class GameAsset{
	public:
		GameAsset(glm::vec3);

		virtual void Draw(GLuint) = 0;
		glm::mat4 GetModelTransformation();

	private:
		std::shared_ptr<BoundingBox> bounding_box;
};

#endif
