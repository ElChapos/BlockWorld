#include "GameAsset.h"

/**
*  Initalise a bounding box with the gameasset
*/
GameAsset::GameAsset(glm::vec3 position, int type, float scale , glm::vec3 rotation, glm::vec3 speed)
{
	bounding_box = std::make_shared<BoundingBox>(position, type, scale, rotation, speed);
}

/**
*  Update a gameAssets position to the position of the bounding box
*/
glm::mat4 GameAsset::GetModelTransformation()
{
	return bounding_box->GetModelTransformation();
}

/**
*  Get the Max and Minimum bounds of a bounding box
*/
glm::vec3 GameAsset::GetMaxAndMin(int type){

    if (type == 1)
    {
        return bounding_box->GetMaxAndMin(1);
    }
    else if (type == 2)
    {
        return bounding_box->GetMaxAndMin(2);
    }
}

/**
*  Check the bounds of two bounding boxes for a collision
*/
void GameAsset::CheckCollision(glm::vec3 bounding_box1_max, glm::vec3 bounding_box1_min, glm::vec3 bounding_box2_max, glm::vec3 bounding_box2_min)
{
    bounding_box->CheckCollision(bounding_box1_max, bounding_box1_min, bounding_box2_max, bounding_box2_min);
}

/**
*  Return the position of a boundingbox
*/
glm::vec3 GameAsset::GetVec3(){
    return bounding_box->GetVec3();
}
