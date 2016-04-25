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
#include "ColourManager.h"

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
		void DoAction(int);
		void UpdateFacingDirection();
		void CreateShape(std::string, int);
		void ChangeBlockDist(int);
		void LoadMap(std::string);
		void SetBlockType(int);

		bool CheckCollision(glm::vec3);

		glm::vec3 GetOffset();

		ColourManager colour_manager;

		void UpdateCameraPosition(Input, int mouseX, int mouseY);


	private:
		std::shared_ptr<GameAssetManager> asset_manager;

		int block_dist = 3;
		double point = 0.39375;
		std::string f_pos = "N";
		int block_type = 1;
};

#endif // GAMEWORLD_H
