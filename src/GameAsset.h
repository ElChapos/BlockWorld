#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <GL/gl.h>
#include <iostream>
#include <memory>

#include "BoundingBox.h"

class GameAsset{
	public:
		GameAsset(glm::vec3, int);

		virtual void Draw(GLuint) = 0;
		glm::mat4 GetModelTransformation();

		void Translate(glm::vec3);

	private:
		std::shared_ptr<BoundingBox> bounding_box;
};

#endif
