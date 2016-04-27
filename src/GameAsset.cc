#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 position, int type, float scale , glm::vec3 rotation)
{
	bounding_box = std::make_shared<BoundingBox>(position, type, scale, rotation);
}

glm::mat4 GameAsset::GetModelTransformation()
{
	return bounding_box->GetModelTransformation();
}

/**
 * Used to translate
 */
void GameAsset::Translate(glm::vec3 position)
{
	bounding_box->Translate(position);
}
