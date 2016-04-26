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
		
		std::shared_ptr<BoundingBox> GetBoundingBox();
	
	private:
		std::shared_ptr<BoundingBox> bounding_box;
};

#endif
