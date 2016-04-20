#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include <math.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "common.h"
#include "GameAssetManager.h"
#include "GameAsset.h"

#include "CubeAsset.h"
#include "DiamondAsset.h"

#include "BlockColours.h"

/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
	public:
		/**
		* We thread the ApplicationMode through the GameWorld ss we want to read it
		* in from the user.  Threading the state through the various function calls
		* is preferable (in this case) to having some kind of global state.
		*/
		GameWorld(ApplicationMode);

		void Draw();
		void CameraController(int);
		void MoveCamera(glm::vec2, glm::vec2);
		void DoAction(int);
		void UpdateFacingDirection();
		void CreateShape(std::string, int);
		void ChangeBlockDist(int);
		void LoadMap(std::string);
		void SetBlockType(int);

		bool CheckCollision(glm::vec3);

		glm::vec3 GetOffset();
		
		BlockColours colour_manager;
		
	private:
		std::shared_ptr<GameAssetManager> asset_manager;

		int block_dist = 3;

		GLfloat camera_speed = 0.1;
		GLfloat camera_x = 0.0;
		GLfloat camera_y = 0.0;

		double point = 0.39375;

		std::string f_pos = "N";

		glm::vec3 offset_pos;
		glm::vec3 position = glm::vec3(0, 0, -3);
		glm::vec3 z_direction;
		glm::vec3 x_direction;
		
		glm::mat4 cam_proj;
		glm::mat4 cam_view;

		int block_type = 1;
};

#endif // GAMEWORLD_H
