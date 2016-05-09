#include "GameWorld.h"

/**
 * Initialises the GameWorld
 * Places some blocks within the GameWorld to demonstrate all of the available animation and key-frame features
 */
GameWorld::GameWorld ()
{
	asset_manager = std::make_shared<GameAssetManager>();
	colour_manager.AddColour("random", glm::vec3(-0.1, -0.1, -0.1));

	/**
	 * Assets that are sitting on the spot, but performing an action
	 * (Such as Translate, Rotate and Scale)
	 */
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(6.0, 10.0, 23.0),colour_manager.GetColour("random"), 2, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(9.0, 0.0, 30.0), colour_manager.GetColour("random"),3, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, -3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, -6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-6.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-9.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-9.0, -5.0, 20.0),colour_manager.GetColour("random"), 0, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-20.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-26.0, 10.0, 23.0),colour_manager.GetColour("random"), 2, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, 0.0, 30.0), colour_manager.GetColour("random"),3, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, 6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, -3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-23.0, -6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-26.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<DiamondAsset>(glm::vec3(-29.0, -5.0, 20.0),colour_manager.GetColour("random"), 0, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(20.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.01,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(26.0, 10.0, 23.0),colour_manager.GetColour("random"), 2, 10, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, 0.0, 30.0), colour_manager.GetColour("random"),3, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.03,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, 6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, -3.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,-0.02,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(23.0, -6.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(26.0, 0.0, 20.0),colour_manager.GetColour("random"), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(-0.04,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, 0.0, 20.0),colour_manager.GetColour("random"), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->AddAsset(std::make_shared<StarAsset>(glm::vec3(29.0, -5.0, 20.0),colour_manager.GetColour("random"), 0, 1, glm::vec3(2.0,2.0,2.0), glm::vec3(0.0,0.0,0.0)));

	/**
	 * Assets that are using "path"/"key-frames"
	 */
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 0.0),colour_manager.GetColour("random"), 5, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(6.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(6.0,3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(6.0,3.0,3.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);

    asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-3.0, 0.0, 0.0),colour_manager.GetColour("random"), 5, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(-6.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(-6.0,-3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(-6.0,-3.0,-3.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);

    asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 0.0),colour_manager.GetColour("random"), 5, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
	asset_manager->SetPath(glm::vec3(0.0,3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,-3.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), true);
    asset_manager->SetPath(glm::vec3(3.0,0.0,0.0), true);
	asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), true);
    asset_manager->SetPath(glm::vec3(0.0,0.0,0.0), false);
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
			asset_manager->AddAsset(std::make_shared<CubeAsset>(block_position, colour_manager.GetColour("random"), 0, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
		}
		else if(placement_type == BW_STAR)
		{
			asset_manager->AddAsset(std::make_shared<StarAsset>(block_position, colour_manager.GetColour("random"), 0, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
		}
		else if(placement_type == BW_DIAMOND)
		{
			asset_manager->AddAsset(std::make_shared<DiamondAsset>(block_position, colour_manager.GetColour("random"), 0, 1, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
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
