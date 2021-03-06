#include "DiamondAsset.h"

/**
 * Heavily modified from the original. Initialisation for the asset
 * @param glm::vec3 p: The asset initial position
 * @param glm::vec3 c: The asset colour
 * @param int type: What action to perform, check BoundingBox.cc for the types
 * @param float scale: Initialisation scale/size of the asset. (1 will create it at normal size, lower = smaller, higher = larger)
 * @param glm::vec3 rotation: Initialises the asset rotated if the vec3 is more than (0.0f,0.0f,0.0f)
 * @param glm::vev3 speed: Initialises the asset translating towards a point.
 */
DiamondAsset::DiamondAsset(glm::vec3 p, glm::vec3 c,BBoxType type, float scale, glm::vec3 rotation, glm::vec3 speed) : GameAsset(p , type, scale, rotation, speed)
{
	if(glm::to_string(c) == glm::to_string(glm::vec3(-0.1, -0.1, -0.1)))
	{
		c = glm::vec3(rf(),rf(),rf());
	}
	else
	{
		c = glm::vec3(c.x/255, c.y/255, c.z/255);
	}

	// model coordinates, origin at centre.
	GLfloat vertex_buffer [] {
		-0.5f,  0.0f,  0.5f, //0
		 0.0f, -0.5f,  0.0f, //1
		 0.5f,  0.0f,  0.5f, //2
		 0.0f,  0.5f,  0.0f, //3
		 0.0f,  0.5f,  0.0f, //4
		 0.5f,  0.0f, -0.5f, //5
		 0.0f,  0.5f,  0.0f, //6
		-0.5f,  0.0f, -0.5f, //7
		 0.5f,  0.0f, -0.5f, //8
		 0.0f,  0.5f,  0.0f //9
	};
	vertex_buffer_length = sizeof(vertex_buffer);

	// Solid block colours
	GLfloat colour_buffer[] = {
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z,
		c.x, c.y, c.z
	};

	colour_buffer_length = sizeof(colour_buffer);

	GLuint element_buffer [] {
		0,2,1,
		3,2,0,
		2,4,5,
		2,5,1,
		0,1,7,
		6,0,7,
		7,1,8,
		7,8,9
	};
	element_buffer_length = sizeof(element_buffer);

	/**
	* Transfer buffers to the GPU
	* create buffer
	* immediately bind the buffer and transfer the data
	*/

	// Send over GLfloats for the triangles
	glGenBuffers(1, &vertex_buffer_token);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

	// Send over GLfloats for the colours
	glGenBuffers(1, &colour_buffer_token);
	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
	glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer, GL_STATIC_DRAW);

	// Send over GLfloats for the elements (joining the triangles)
	glGenBuffers(1, &element_buffer_token);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);


}

/**
 * Class destructor method
 */
DiamondAsset::~DiamondAsset() {}
