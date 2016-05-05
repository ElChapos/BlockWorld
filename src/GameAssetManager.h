#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#include <GL/gl.h>
#include <glm/ext.hpp>
#include "common.h"
#include "GameAsset.h"
#include "CubeAsset.h"
#include "Camera.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager
{
  public:
    GameAssetManager(); // constructor
    virtual ~GameAssetManager();
    GameAssetManager(GameAssetManager const&); // copy constructor
    GameAssetManager(GameAssetManager const&&); // move constructor
    void operator=(GameAssetManager const&); // assignment
    void AddAsset(std::shared_ptr<GameAsset>);
    void DeleteAsset(glm::vec3);
    void Draw();
    void UpdateCameraPosition(Input, int, int);

    glm::vec3 GetCameraPosition();
    glm::vec3 GetCameraDirection();

  private:
    GLuint CreateGLProgram(std::string &, std::string &);
    GLuint CreateGLESShader(GLenum, std::string &);

    GLuint program_token;

    std::pair<GLchar *, GLint>  ReadShader(std::string &);
    std::vector<std::shared_ptr<GameAsset>> draw_list;
    std::shared_ptr<Camera> camera = std::make_shared<Camera>();

    // variables to gather the bounds of two bounding boxes to check collisions
    glm::vec3 bounding_box1_max, bounding_box1_min, bounding_box2_max, bounding_box2_min;
    glm::vec3 bounding_box1_position, bounding_box2_position;

    // variables to communicate with the shader(Camera)
    GLuint translate_matrix_link, view_matrix_link, projection_matrix_link;
    glm::mat4 translate_matrix, view_matrix, projection_matrix;

};

#endif // GAMEASSETMANAGER_H
