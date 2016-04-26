#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 position)
{
	bounding_box = std::make_shared<BoundingBox>(position);
}

std::shared_ptr<BoundingBox> GetBoundingBox()
{
	return bounding_box;
}