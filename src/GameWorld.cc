#include "GameWorld.h"

/**
 * Initialises the GameWorld
 * Places some blocks within the GameWorld to demonstrate all of the available animation and key-frame features
 */
GameWorld::GameWorld ()
{
	asset_manager = std::make_shared<GameAssetManager>();
	colour_manager.AddColour("random", glm::vec3(-0.1, -0.1, -0.1));
	colour_manager.AddColour("grey", glm::vec3(112,128,144));
    colour_manager.AddColour("blue", glm::vec3(0,0,255));
    colour_manager.AddColour("brown", glm::vec3(139,69,19));

	/**
	*   Create the PlayerAsset Model
	*/

    asset_manager->AddAsset(std::make_shared<PlayerAsset>(glm::vec3(0.0, 0.0, 0.0),colour_manager.GetColour("random"), PLAYER, 0.25f, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));


	/**
	 * Assets that are sitting on the spot, but performing an action
	 * (Such as Translate, Rotate and Scale)
	 *
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(6.0, 10.0, 23.0),colour_manager.GetColour("random"), ROTATE, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(9.0, 0.0, 30.0), colour_manager.GetColour("random"), SCALE, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, -3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, -6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-6.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-9.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-9.0, -5.0, 20.0),colour_manager.GetColour("random"), NONE, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-20.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-26.0, 10.0, 23.0),colour_manager.GetColour("random"), ROTATE, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, 0.0, 30.0), colour_manager.GetColour("random"), SCALE, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, -3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, -6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-26.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, -5.0, 20.0),colour_manager.GetColour("random"), NONE, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(20.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(26.0, 10.0, 23.0),colour_manager.GetColour("random"), ROTATE, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, 0.0, 30.0), colour_manager.GetColour("random"), SCALE, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, -3.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, -6.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(26.0, 0.0, 20.0),colour_manager.GetColour("random"), SPECIAL, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, 0.0, 20.0),colour_manager.GetColour("random"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, -5.0, 20.0),colour_manager.GetColour("random"), NONE, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	/**
	 * Assets that are using "path"/"key-frames"
	 *
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 0.0),colour_manager.GetColour("random"), FOLLOWPATH, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(6.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(6.0,3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(6.0,3.0,3.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);

    asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 0.0, 0.0),colour_manager.GetColour("random"), FOLLOWPATH, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(-6.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(-6.0,-3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(-6.0,-3.0,-3.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);

    asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 0.0),colour_manager.GetColour("random"), FOLLOWPATH, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(0.0,3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,-3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), true);
    asset_manager->SetPath(glm::vec3(3.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), true);
    asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);
    */



//// 2d array storing a maze generated using my own java maze generator, numbers represent room types from 1 to 15 that can only connect to other certain room types.
//// tested and works - would be a simple matter to generated a map upto a 100x100 , anything beyond would be excessive for performance purposes
//// with abit of time it wouldnt be too far fetched to port over my java map generator code and have a a dynamically random maze generated on a keypress or on each build
	int maze [10][10] = {
{ 4,10,12, 7, 6, 2, 4, 7, 3, 3},
{ 3, 4, 8,11,14,12,12,15,13, 9},
{ 9, 6, 7, 5, 7, 5, 8, 9,11,13},
{ 5,15, 8, 3, 9, 4, 2, 9, 5,13},
{ 3,11,10, 8,11, 2, 4,15, 7, 9},
{11,13, 3, 6,13, 6,12,13, 9, 9},
{ 5,15,14,13, 5,14,14,15,15, 8},
{ 6,13, 6,15, 7, 3, 6,14,13, 3},
{ 9,11,14,14,13,11,15,12,15,13},
{ 5,14, 2, 4,14, 8, 1, 1, 5, 8},
		};



//// spawns cubes based on the positions in the array , numbers represent a 3x3 grid of cubes that represent a single room type.
/// currently the star asset spawns in dead end rooms ( could be a collectible? )
		for ( int x = 0; x < 10; x++)
			{
				for (int z = 0; z < 10; z++)
					{
						if (maze[x][z] == 1)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
									asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-3.0 * x, -0.0, -3.0 * z),colour_manager.GetColour("blue"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
					else if (maze[x][z] == 2)
						{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));;
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
									asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-3.0 * x, -0.0, -3.0 * z),colour_manager.GetColour("blue"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
						}
					else if (maze[x][z] == 3)
						{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
									asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-3.0 * x, -0.0, -3.0 * z),colour_manager.GetColour("blue"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
						}
						else if (maze[x][z] == 4)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
									asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-3.0 * x, -0.0, -3.0 * z),colour_manager.GetColour("blue"), ROTATE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 5)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));

							}
						else if (maze[x][z] == 6)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));

							}
						else if (maze[x][z] == 7)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));

							}
						else if (maze[x][z] == 8)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));

							}
						else if (maze[x][z] == 9)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));

							}
						else if (maze[x][z] == 10)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 11)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 12)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 13)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 14)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
						else if (maze[x][z] == 15)
							{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -0.0 , -3.0 * z-1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -0.0 , -3.0 * z+1),colour_manager.GetColour("grey"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
							}
					}
			}



/// spawns the ground underneath the maze
		for ( int  x = 0; x < 10; x++)
			{
				for ( int z = 0; z < 10; z++)
					{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -1.0 , -3.0 * z),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -1.0 , -3.0 * z),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -1.0 , -3.0 * z),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -1.0 , -3.0 * z+1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x,   -1.0 , -3.0 * z-1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -1.0 , -3.0 * z+1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -1.0 , -3.0 * z-1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x+1, -1.0 , -3.0 * z-1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0 * x-1, -1.0 , -3.0 * z+1),colour_manager.GetColour("brown"), NONE, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
					}
			}

}

/**
 * Calls GameAssetManager Drawing method
 */
void GameWorld::Draw()
{
	asset_manager->Draw();
}

/**
 * Calls the UpdateCameraPosition method in GameAssetManager passing the user input and mouse coordnates.
 */
void GameWorld::UpdateCameraPosition(Input input_direction, int mouse_x, int mouse_y)
{
	asset_manager->UpdateCameraPosition(input_direction, mouse_x, mouse_y);
}

/**
 * Add and remove cubes from the game world
 */
void GameWorld::BlockAction(bool mode)
{
	glm::vec3 camera_position = asset_manager->GetCameraPosition() += asset_manager->GetCameraDirection();
	glm::vec3 block_position = glm::vec3(round(camera_position.x), round(camera_position.y), round(camera_position.z));

	if(mode)
	{
		if(placement_type == BW_CUBE)
		{
			asset_manager->AddAsset(std::make_shared<CubeAsset>(block_position, colour_manager.GetColour("random"), NONE, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
		}
		else if(placement_type == BW_STAR)
		{
			asset_manager->AddAsset(std::make_shared<StarAsset>(block_position, colour_manager.GetColour("random"), NONE, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
		}
		else if(placement_type == BW_DIAMOND)
		{
			asset_manager->AddAsset(std::make_shared<DiamondAsset>(block_position, colour_manager.GetColour("random"), NONE, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
		}
		else
		{
			std::cout << "Unknown asset type" << std::endl;
		}
	}
	else
	{
		asset_manager->DeleteAsset(block_position);
	}
}

/**
 * Changes the type of asset to make based on user input
 */
void GameWorld::BlockType(AssetType type)
{
	std::cout << "Switched type to:";

	switch(type)
	{
		case BW_CUBE:
			std::cout << "BW_CUBE" << std::endl;
			break;
		case BW_STAR:
			std::cout << "BW_STAR" << std::endl;
			break;
		case BW_DIAMOND:
			std::cout << "BW_DIAMOND" << std::endl;
			break;
		default:
			type = BW_UNKNOWN;
			std::cout << "BW_UNKNOWN" << std::endl;
			break;
	}

	placement_type = type;
}
