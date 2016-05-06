#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "BoundingBox.h"

class GameAsset{
	public:
		GameAsset(glm::vec3, int, float, glm::vec3, glm::vec3);

		void Draw(GLuint);
		glm::mat4 GetModelTransformation();
		glm::vec3 GetMaxAndMin(int);
        void SetPath(std::vector<glm::vec3>);
		void CheckCollision(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
		glm::vec3 GetVec3();
		float rf();

        GLuint element_buffer_length, vertex_buffer_length, colour_buffer_length;
        GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
        std::shared_ptr<BoundingBox> bounding_box;

	private:

};

#endif
