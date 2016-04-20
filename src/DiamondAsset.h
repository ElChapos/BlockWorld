#ifndef DIAMONDASSET_H
#define DIAMONDASSET_H

#include <vector>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class DiamondAsset : public GameAsset
{
	public:
		DiamondAsset(glm::vec3, glm::vec3);
		~DiamondAsset();

		virtual void Draw(GLuint);

		float rf();
		glm::vec3 GetVec3();

	private:
		glm::vec3 position;
		GLuint element_buffer_length, vertex_buffer_length, color_buffer_length;
		GLuint vertex_buffer_token, element_buffer_token, color_buffer_token;
};
#endif // DIAMONDASSET_H
