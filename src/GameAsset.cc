#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 position)
{
	bounding_box = std::make_shared<BoundingBox>(position);
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
	std::cout << "[GameAsset::Translate()]: vec3 position" << std::endl;
	bounding_box->Translate(position);
}

/**
 * Used to scale
 */
void GameAsset::Scale(int code)
{
	bounding_box->Scale(code);
}

/**
 * Used to rotate
 */
void GameAsset::Rotate()
{
	bounding_box->Rotate();
}
