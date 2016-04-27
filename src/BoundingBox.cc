#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position)
{
	this->position = position;
	
	std::cout << "Initialised BoundingBox at point: [" << position.x << "," << position.y << "," << position.z << "]" << std::endl;
}

glm::mat4 BoundingBox::GetModelTransformation()
{
	glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(position));
	return translate_matrix;
}

/**
 * Used to translate
 */
void BoundingBox::Translate(glm::vec3 position_to)
{
	std::cout << "[BoundingBox::Translate()]: vec3 position_to" << std::endl;
	
	glm::vec3 new_position;
	
	// This will make it move left on the X
	if(this->position.x > 2.0f)
	{
		new_position = glm::vec3(0,0,0);
	}
	else
	{
		new_position = this->position + position_to;
	}
	
	std::cout << glm::to_string(new_position) << std::endl;
	
	this->position = new_position;
}

/**
 * Used to scale
 */
void BoundingBox::Scale(int code)
{
	std::cout << "To-do: Add Code in BoundingBox::Scale()" << std::endl;
}

/**
 * Used to rotate
 */
void BoundingBox::Rotate()
{
	std::cout << "To-do: Add Code in BoundingBox::Rotate()" << std::endl;
}

/**
 * Get vec3 for bbox
 */
glm::vec3 BoundingBox::GetVec3()
{
	return position;
}
