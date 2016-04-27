#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode)
{
	colour_manager.AddColour("random", glm::vec3(-0.1, -0.1, -0.1));
	
	test_asset = std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 0.0), colour_manager.GetColour("random"));
	
	asset_manager = std::make_shared<GameAssetManager>(mode);
	asset_manager->AddAsset(test_asset);
}

/**
 * Handles drawing of the camera and game world assets
 */
void GameWorld::Draw()
{
	// Calls draw from the asset manager
	asset_manager->Draw(camera_controller.GetProjection(), camera_controller.GetView());
	
	// Draw camera
	camera_controller.Draw();
	
	/* THIS WAS A TEST ONLY
		auto offset_pos = camera_controller.GetOffset();
		auto translate_pos = glm::vec3(0.0f + int(round(camera_controller.GetPosition().x)) + offset_pos.x, 0.0f + int(round(camera_controller.GetPosition().y)) + offset_pos.y, 0.0f + int(round(camera_controller.GetPosition().z)) + offset_pos.z);
		test_asset->Translate(translate_pos);
	*/
}

/**
 * Forwards input from main to camera
 */
void GameWorld::MoveCamera(glm::vec2 motion, glm::vec2 display)
{
	camera_controller.MoveCamera(motion, display);
}

/**
 * Handles all input from main
 */
void GameWorld::HandleInput(std::string action, int code)
{
	if(action == "asset_management")
	{
		if(code == 1)
		{
			offset_pos = camera_controller.GetOffset();
			asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0f + int(round(camera_controller.GetPosition().x)) + offset_pos.x, 0.0f + int(round(camera_controller.GetPosition().y)) + offset_pos.y, 0.0f + int(round(camera_controller.GetPosition().z)) + offset_pos.z), colour_manager.GetColour("random")));
		}
		if(code == 2)
		{
			offset_pos = camera_controller.GetOffset();
			asset_manager->RemoveAsset(camera_controller.GetPosition(), offset_pos);
		}
		if(code == 3)
		{
			asset_manager->RemoveAll();
			CreateShape("sphere", rand() % 19 + 1);
		}
		if(code == 4)
		{
			asset_manager->RemoveAll();
			CreateShape("cube", rand() % 19 + 1);
		}
	}
	else if(action == "block_type")
	{
		block_type = code;
	}
	else if(action == "block_distance")
	{
		camera_controller.SetBlockDistance(code);
	}
	else if(action == "camera_code")
	{
		// Simply forward the camera controls, can also use multiple camera instances (if done correctly)
		camera_controller.CameraController(code);
	}
	else if(action == "test_translation")
	{	
		float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		
		auto translate_position = glm::vec3(x, y, z);
		
		test_asset->Translate(translate_position);
	}
	else if(action == "test_scale")
	{	
		// Scale parameter is how many units to scale by. -1 (smaller) 1 (bigger)
		test_asset->Scale(1);
	}
}

/**
 * Generates a shape
 */
void GameWorld::CreateShape(std::string shape, int size)
{
	if(shape == "sphere")
	{
		for (int z = 0; z < size; z++)
		{
			for (int y = 0; y < size; y++)
			{
				for (int x = 0; x < size; x++)
				{
					if (sqrt((float) (x-size/2)*(x-size/2) + (y-size/2)*(y-size/2) + (z-size/2)*(z-size/2)) <= size/2)
					{
						asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.GetColour("random")));
					}
				}
			}
		}
		return;
	}
	if(shape == "cube")
	{
		for (int z = 0; z < size; z++)
		{
			for (int y = 0; y < size; y++)
			{
				for (int x = 0; x < size; x++)
				{
					asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.GetColour("random")));
				}
			}
		}
		return;
	}
	if(shape == "ground")
	{
		for(int z = 0; z < size; z++)
		{
			for(int x = 0; x < size; x++)
			{
				asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-10.0+x, -1.0f, -10.0+z), colour_manager.GetColour("random")));
			}
		}
		return;
	}
	std::cout << "Shape not found!" << std::endl;
}

/**
 * A very bad example of rendering heightmaps
 * Takes in a PPM file, reads the headers and then the map data
 */
void GameWorld::LoadMap(std::string filename)
{
	std::cout << "Reading file: " << filename << "..." << std::endl;
	std::ifstream infile(filename);
	
	if(infile.is_open())
	{
		// Stores the cube Y cordinates from the PPM file
		std::vector<int> cube_y;

		// For the loop, increment and Y co-ordinate
		int push_i = 0, push_s = 0, i = 0;

		// For the headers
		std::string MAP_TYPE; 
		int MAP_WIDTH, MAP_HEIGHT, MAP_COLOURS, TOTAL_BLOCKS;

		// Read in headers
		infile >> MAP_TYPE >> MAP_WIDTH >> MAP_HEIGHT >> MAP_COLOURS;
		TOTAL_BLOCKS = MAP_WIDTH * MAP_HEIGHT;

		std::cout 	<< "File Data:" << std::endl
					<< "    File Type: " << MAP_TYPE << std::endl
					<< "    Map Width: " << MAP_WIDTH << std::endl
					<< "    Map Height: " << MAP_HEIGHT << std::endl
					<< "    Map Colours: " << MAP_COLOURS << std::endl;

		// Read in map data
		while (infile >> push_s)
		{
			if(push_i == 1)
				cube_y.push_back(push_s);

			if(push_i == 2)
				push_i = 0;
			else
				push_i++;
		}
	
		for(int z = 0; z < MAP_HEIGHT; z++)
		{
			for(int x = 0; x < MAP_WIDTH; x++)
			{
				asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(x, cube_y[i], z), colour_manager.GetColour("random")));
				i++;

				std::cout << "[" << i << " / " << TOTAL_BLOCKS << "]\r";
				std::cout.flush();
			}
		} 	
	}
	return;
}