#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 position)
{
	bounding_box = std::make_shared<BoundingBox>(position);
}

