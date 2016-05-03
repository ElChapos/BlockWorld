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
#include "Camera.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager {
 public:
  explicit GameAssetManager(ApplicationMode); // constructor
  virtual ~GameAssetManager();
  GameAssetManager(GameAssetManager const&); // copy constructor
  GameAssetManager(GameAssetManager const&&); // move constructor
  void operator=(GameAssetManager const&); // assignment
  void AddAsset(std::shared_ptr<GameAsset>);
  void Draw();
  void UpdateCameraPosition(Input, int mouseX, int mouseY);

 private:
  GLuint CreateGLProgram(std::string &, std::string &);
  GLuint CreateGLESShader(GLenum, std::string &);
  // As this is private and we're writing to the GPU, we will use raw pointers.
  std::pair<GLchar *, GLint>  ReadShader(std::string &);

  // The internal scene graph is a simple list.
  std::vector<std::shared_ptr<GameAsset>> draw_list;
  GLuint program_token;
  Camera camera;

// variables to gather the bounds of two bounding boxes to check collisions
  	    glm::vec3 bounding_box1_max;
		glm::vec3 bounding_box1_min;
		glm::vec3 bounding_box2_max;
		glm::vec3 bounding_box2_min;

		glm::vec3 bounding_box1_position;
		glm::vec3 bounding_box2_position;

// variables to communicate with the shader(Camera)
  GLuint translate_matrix_link;
  GLuint view_matrix_link;
  GLuint projection_matrix_link;

  glm::mat4 translate_matrix;
  glm::mat4 view_matrix;
  glm::mat4 projection_matrix;
};

#endif // GAMEASSETMANAGER_H
