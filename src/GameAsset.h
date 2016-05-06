#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <GL/gl.h>
#include <iostream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "BoundingBox.h"

class GameAsset{
	public:
		GameAsset(glm::vec3, int, float, glm::vec3, glm::vec3);

		void Draw(GLuint);
		glm::mat4 GetModelTransformation();
		glm::vec3 GetMaxAndMin(int);
		void CheckCollision(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
		glm::vec3 GetVec3();
		float rf();

        GLuint element_buffer_length, vertex_buffer_length, colour_buffer_length;
        GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;

	private:
		std::shared_ptr<BoundingBox> bounding_box;
};

#endif
