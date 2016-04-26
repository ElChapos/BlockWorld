#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position)
{
	this->position = position;
	std::cout << "Setup BoundingBox at [" << glm::to_string(position) << "]" << std::endl;
}
