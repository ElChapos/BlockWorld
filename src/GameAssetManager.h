#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <GL/gl.h>

#include "common.h"
#include "GameAsset.h"
#include "CubeAsset.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager {
	public:
		explicit GameAssetManager(ApplicationMode); 	// constructor
		virtual ~GameAssetManager();

		GameAssetManager(GameAssetManager const&); 		// copy constructor
		GameAssetManager(GameAssetManager const&&); 	// move constructor

		void operator=(GameAssetManager const&); 		// assignment
		void AddAsset(std::shared_ptr<CubeAsset>);
		void RemoveAsset(glm::vec3, glm::vec3);
		void RemoveAll();
		void Draw(glm::mat4, glm::mat4);

		std::vector<std::shared_ptr<CubeAsset>> GetAssets();

	private:
		GLuint CreateGLProgram(std::string &, std::string &);
		GLuint CreateGLESShader(GLenum, std::string &);

		// As this is private and we're writing to the GPU, we will use raw pointers.
		std::pair<GLchar *, GLint>  ReadShader(std::string &);

		// The internal scene graph is a simple list.
		std::vector<std::shared_ptr<GameAsset>> draw_list;
		std::vector<std::shared_ptr<CubeAsset>> asset_list;
		GLuint program_token;
};

#endif // GAMEASSETMANAGER_H
