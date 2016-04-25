#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 pos)
{
	bounding_box = pos;
	std::cout << "Initialised BoundingBox at [" << glm::to_string(bounding_box) << "]" << std::endl;
}

/**
* Sets up the bounding box for an asset by storing it in bounding_box
**/
void BoundingBox::SetBounds(glm::vec3 pos)
{

	bounding_box = pos;
	std::cout << "Updated BoundingBox at [" << glm::to_string(bounding_box) << "]" << std::endl;
}