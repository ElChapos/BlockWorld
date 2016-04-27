#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position)
{
	this->position = position;
}

glm::vec3 BoundingBox::GetVec3()
{
	return position;
}
