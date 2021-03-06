#include "GameAsset.h"

/**
*  Initalise a BoundingBox with the GameAsset
*/
GameAsset::GameAsset(glm::vec3 position, BBoxType type, float scale , glm::vec3 rotation, glm::vec3 speed)
{
    bounding_box = std::make_shared<BoundingBox>(position, type, scale, rotation, speed);
}

/**
*  Update a GameAsset position to the position of the BoundingBox
*/
glm::mat4 GameAsset::GetModelTransformation(glm::vec3 player_position, glm::vec3 camera_direction)
{
    return bounding_box->GetModelTransformation(player_position, camera_direction);
}

/**
*  Gives a GameAsset path coordinates
*/
void GameAsset::SetPath(std::vector<glm::vec3> path_list)
{
    bounding_box->SetPath(path_list);
}


/**
*  Get the Max and Minimum bounds of a BoundingBox
*/
glm::vec3 GameAsset::GetMaxAndMin(int type)
{

    if(type == 1)
    {
        return bounding_box->GetMaxAndMin(1);
    }
    else if(type == 2)
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
*  Return the Bounding Box type
*/
BBoxType GameAsset::GetType()
{
    return bounding_box->GetType();
}

/**
*  Return the position of a BoundingBox
*/
glm::vec3 GameAsset::GetVec3()
{
    return bounding_box->GetVec3();
}

/**
 * Generate a random float value between 0 and 1
 */
float GameAsset::rf()
{
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

#ifdef DEBUG
    #define checkGLError() checkError(__FILE__, __LINE__)
#else
    #define checkGLError()
#endif

/**
 * Checks for GL errors
 */
void checkError(std::string file, int line)
{
    GLenum gl_error = glGetError();
    if(GL_NO_ERROR != gl_error)
    {
        std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
        exit(-1);
    }
}

/**
 * Main drawing method for the GameAsset
 */
void GameAsset::Draw(GLuint program_token)
{
	//Check that the program token points to a valid shader program.
	if(!glIsProgram(program_token)) {
		std::cerr << "Drawing asset with invalid program" << std::endl;
		return;
	}

	//Validate the shader program.
	GLint validation_ok;
	glValidateProgram(program_token);
	glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);

	//If validation fails then display an error and return -1.
	if(!validation_ok) {
		GLint maxLength = 0;
		glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

		std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
		for(auto c: errorLog) {
			std::cerr << c;
		}
		exit(-1);
	}

	//Link to the 'position' variable inside the shader program.
	GLuint position_attrib = glGetAttribLocation(program_token, "position");
	checkGLError();
    GLuint colour_attrib = glGetAttribLocation(program_token, "colour");
	checkGLError();

	//Tell openGL that we are using this shader program.
	glUseProgram(program_token);
	checkGLError();

	//Use the previously transferred buffer as the vertex array.  This way
	//we transfer the buffer once -- at construction -- not on every frame.
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
	glVertexAttribPointer(
			position_attrib,               /* attribute */
			3,                             /* size */
			GL_FLOAT,                      /* type */
			GL_FALSE,                      /* normalized? */
			0,                             /* stride */
			(void*)0                       /* array buffer offset */
	);
	glEnableVertexAttribArray(position_attrib);
	checkGLError();

	glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
	glVertexAttribPointer(
		colour_attrib,				/* attribute */
		3,				/* size */
		GL_FLOAT,		/* type */
		GL_FALSE,		/* normalized? */
		0,				/* stride */
		(void*)0		/* array buffer offset */
	);
    glEnableVertexAttribArray(colour_attrib);
	checkGLError();


	//Draw the triangles stored in the element buffer on screen.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
	glDrawElements(
			GL_TRIANGLES,
			element_buffer_length,
			GL_UNSIGNED_INT,
			(GLvoid*) 0
	);
	checkGLError();
	glDisableVertexAttribArray(position_attrib);
}
