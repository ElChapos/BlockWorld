#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position)
{
	this->position = position;
}

glm::mat4 BoundingBox::GetModelTransformation(){

this->position += 1;
glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(position));

return translate_matrix;
}

glm::vec3 BoundingBox::GetVec3()
{
	return position;
}
