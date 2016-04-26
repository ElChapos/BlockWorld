#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position)
{
	this->position = position;

		std::cout << "Setup BoundingBox at [" << glm::to_string(position) << "]" << std::endl;
}



/**
* Sets up the bounding box for an asset by storing it in bounding_box
**/

/*
void BoundingBox::SetBounds(glm::vec3 pos)
{

	bounding_box = pos;
	std::cout << "Setup BoundingBox at [" << glm::to_string(bounding_box) << "]" << std::endl;
}
*/

/**
* Checks BoundingBox collisions
**/

/*
bool BoundingBox::CollidesWith(glm::vec3 pos)
{
	glm::vec3 player_pos = glm::vec3(round(pos.x), round(pos.y),round(pos.z));
	glm::vec3 box_pos = glm::vec3(round(GetVec3().x), round(GetVec3().y), round(GetVec3().z));

	std::cout << "PP: " << glm::to_string(player_pos) << " - BP: " << glm::to_string(box_pos) << std::endl;

	if(glm::to_string(player_pos) == glm::to_string(box_pos))
	{
		return true;
	}

	return false;
}

glm::vec3 BoundingBox::GetVec3()
{
	return bounding_box;
}*/
