#include "StarAsset.h"

/**
* Heavily modified from the original. Initialisation for the asset
* @param glm::vec3 p: The asset initial position
* @param glm::vec3 c: The asset colour
* @param int type: What action to perform, check BoundingBox.cc for the types
* @param float scale: Initialisation scale/size of the asset. (1 will create it at normal size, lower = smaller, higher = larger)
* @param glm::vec3 rotation: Initialises the asset rotated if the vec3 is more than (0.0f,0.0f,0.0f)
* @param glm::vev3 speed: Initialises the asset translating towards a point.
*/
StarAsset::StarAsset(glm::vec3 p, glm::vec3 c,BBoxType type, float scale, glm::vec3 rotation, glm::vec3 speed) : GameAsset(p , type, scale, rotation, speed)
{
    if(glm::to_string(c) == glm::to_string(glm::vec3(-0.1, -0.1, -0.1)))
    {
        c = glm::vec3(rf(),rf(),rf());
    }
    else
    {
        c = glm::vec3(c.x/255, c.y/255, c.z/255);
    }

    // model coordinates, origin at centre.
    GLfloat vertex_buffer_data [] {
        0.00f,  1.00f, 0.5f,
        -0.25f,  0.25f, 0.5f,
        0.25f,  0.25f, 0.5f,
        -1.00f,  0.00f, 0.5f,
        0.00f,  0.00f, 0.5f,
        1.00f,  0.00f, 0.5f,
        -0.25f, -0.25f, 0.5f,
        0.25f, -0.25f, 0.5f,
        0.00f, -1.00f, 0.5f
    };
    GLfloat vertex_buffer_length = sizeof(vertex_buffer_data);

    GLfloat g_colour_buffer_data[] = {
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z,
        c.x, c.y, c.z
    };
    colour_buffer_length = sizeof(g_colour_buffer_data);

    GLuint element_buffer []  {
        0,1,2,
        1,4,2,
        2,4,7,
        5,2,7,
        1,4,6,
        1,6,3,
        4,6,7 ,
        7,6,8
    };
    element_buffer_length = sizeof(element_buffer);

    // Transfer buffers to the GPU
    // create buffer
    glGenBuffers(1, &vertex_buffer_token);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &colour_buffer_token);
    glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
    glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, g_colour_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &element_buffer_token);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

/**
 * Class destructor method
 */
StarAsset::~StarAsset() {}
