#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 position, int type, float scale , glm::vec3 rotation)
{
	this->position = position;
	this->type = type;
	this->scale = scale;
	this->rotation = rotation;

	std::cout << "Initialised BoundingBox at point: [" << position.x << "," << position.y << "," << position.z << "]" << std::endl;
}

glm::mat4 BoundingBox::GetModelTransformation()
{

    if (this->type == 1){
        this->Translate(glm::vec3(0.01f, 0.0f, 0.0f));
	}
    else if (this->type == 2){
        this->Rotate(glm::vec3(0.01f, 0.1f, 0.1f));
	}
    else if(this->type == 3){
       // this->Scale();
        }


    glm::mat4 scale_matrix = glm::scale(glm::vec3(this->scale, this->scale, this->scale));

	glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->position));

	model_matrix = translate_matrix * scale_matrix;

    model_matrix = glm::rotate(model_matrix, this->rotation.x, glm::vec3(1, 0, 0));
	model_matrix = glm::rotate(model_matrix, this->rotation.y, glm::vec3(0, 1, 0));
    model_matrix = glm::rotate(model_matrix, this->rotation.z, glm::vec3(0, 0, 1));

	return model_matrix;
}

/**
 * Used to translate
 */
void BoundingBox::Translate(glm::vec3 position_to)
{
	std::cout << "[BoundingBox::Translate()]: vec3 position_to" << std::endl;

	glm::vec3 new_position;

	// This will make it move left on the X
	if(this->position.x > 2.0f)
	{
		new_position = glm::vec3(0,0,0);
	}
	else
	{
		new_position = this->position + position_to;
	}

	std::cout << glm::to_string(new_position) << std::endl;

	this->position = new_position;
}

/**
 * Used to scale
 */
void BoundingBox::Scale()
{
	std::cout << "To-do: Add Code in BoundingBox::Scale()" << std::endl;
}

/**
 * Used to rotate
 */
void BoundingBox::Rotate(glm::vec3 rotate_to)
{
		std::cout << "[BoundingBox::Translate()]: vec3 position_to" << std::endl;

	glm::vec3 new_rotation;

	// This will make it move left on the X
	if(this->rotation.x > 2.0f && this->rotation.y > 2.0f && this->rotation.z > 2.0f)
	{
		new_rotation = glm::vec3(0,0,0);
	}
	else
	{
		new_rotation = this->rotation + rotate_to;
	}

	std::cout << glm::to_string(new_rotation) << std::endl;

	this->rotation = new_rotation;
}

/**
 * Get vec3 for bbox
 */
glm::vec3 BoundingBox::GetVec3()
{
	return position;
}
