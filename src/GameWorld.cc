#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {

colour_manager.AddColour("random", glm::vec3(-0.1, -0.1, -0.1));
asset_manager = std::make_shared<GameAssetManager>(mode);


asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 3.0), colour_manager.GetColour("random")));

}


//// calls the draw method in GameAssetManager.cc
	void GameWorld::Draw() {
  		asset_manager->Draw();
}

//// calls the updatecamera method in GameAssetManager passing the user input and mouse coordnates.

	void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
		asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);
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
