#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode)
{
	asset_manager = std::make_shared<GameAssetManager>(mode);
	asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(1000.0, 0.0, 0.0), colour_manager.COLOUR_NONE));
	asset_manager->AddAssetDiamond(std::make_shared<DiamondAsset>(glm::vec3(0.0, 3.0, 0.0), colour_manager.COLOUR_RED));

	CreateShape("ground", 20);
}

/**
 * Handles drawing of the camera and game world assets
 */
void GameWorld::Draw()
{
	// Update the facing direction
	UpdateFacingDirection();

	// Resetting camera position X
	if(camera_x >= 6.280)
		camera_x = 0.1;
	if(camera_x <= 0)
		camera_x = 6.280;

	// Resetting camera position Y
	if(camera_y >= 1.5f)
		camera_y = 1.5;
	if(camera_y <= -1.5f)
		camera_y = -1.5;

	glm::vec3 direction(
		cos(camera_y) * sin(camera_x),
		sin(camera_y),
		cos(camera_y) * cos(camera_x)
	);

	glm::vec3 move_direction(
		cos(camera_y) * sin(camera_x),
		0,
		cos(camera_y) * cos(camera_x)
	);
	z_direction = move_direction;

	x_direction = glm::vec3(
		sin(camera_x - 3.14f/2.0f),
		0,
		cos(camera_x - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(x_direction, direction);
	
	cam_proj = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	cam_view = glm::lookAt(
		position,
		position + direction,
		vup
	);

	// Calls draw from the asset manager
	asset_manager->Draw(cam_proj, cam_view);
}

/**
 * Sets the block type to place
 */
void GameWorld::SetBlockType(int b)
{
	block_type = b;
}

/**
 * Handles action codes passed from main
 */
void GameWorld::DoAction(int a)
{
	if(a == 1)
	{
		offset_pos = GetOffset();

		if(block_type == 1)
		{
			asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0f + int(round(position.x)) + offset_pos.x, 0.0f + int(round(position.y)) + offset_pos.y, 0.0f + int(round(position.z)) + offset_pos.z), colour_manager.COLOUR_RANDOM));
		}
		else if(block_type == 2)
		{
			asset_manager->AddAssetDiamond(std::make_shared<DiamondAsset>(glm::vec3(0.0f + int(round(position.x)) + offset_pos.x, 0.0f + int(round(position.y)) + offset_pos.y, 0.0f + int(round(position.z)) + offset_pos.z), colour_manager.COLOUR_RANDOM));
		}

	}
	if(a == 2)
	{
		offset_pos = GetOffset();
		asset_manager->RemoveAsset(position, offset_pos);
	}
	if(a == 3)
	{
		asset_manager->RemoveAll();
		CreateShape("sphere", rand() % 19 + 1);
	}
	if(a == 4)
	{
		asset_manager->RemoveAll();
		CreateShape("cube", rand() % 19 + 1);
	}
}

/**
* Handles the keyboard inputs passed from main.
*/
void GameWorld::CameraController(int k)
{
	std::vector<std::shared_ptr<CubeAsset>> asset_list = asset_manager->GetAssets();
	for(int i = 0; i < asset_list.size(); i++)
	{
		CubeAsset c = *asset_list[i];
		if(CheckCollision(c.GetVec3()))
		{
			std::cout << "[P]Detected collision with cube at: (X: " << position.x << ", Y: " << position.y << ", Z: " << position.z << ")" << std::endl;
			std::cout << "[C]Detected collision with cube at: (X: " << c.GetVec3().x << ", Y: " << c.GetVec3().y << ", Z: " << c.GetVec3().z << ")" << std::endl;
		}
	}

	// For W A S D
	if(k == 1) // W
		position += z_direction * camera_speed;
	if(k == 2) // A
		position -= x_direction * camera_speed;
	if(k == 3) // S
		position -= z_direction * camera_speed;
	if(k == 4) // D
		position += x_direction * camera_speed;

	// For Space/Control
	if(k == 9) // Space
		position.y += 0.5f * camera_speed;
	if(k == 10) // Control
		position.y -= 0.5f * camera_speed;

}

/**
 * Handles the mouse input for the camera
 */
void GameWorld::MoveCamera(glm::vec2 motion, glm::vec2 display)
{
	camera_x += ((display.x/2) - motion.x) * camera_speed / 100.0f;
	camera_y += ((display.y/2) - motion.y) * camera_speed / 100.0f;
}

/**
 * Calculates the camera facing direction
 */
void GameWorld::UpdateFacingDirection()
{
	if(camera_x <= point && camera_x >= 0.0 && f_pos != "N")
	{
		f_pos = "N";
		return;
	}
	if(camera_x >= point && camera_x <= point*3 && f_pos != "NW")
	{
		f_pos = "NW";
		return;
	}
	if(camera_x >= point*3 && camera_x <= point*5 && f_pos != "W")
	{
		f_pos = "W";
		return;
	}
	if(camera_x >= point*5 && camera_x <= point*7 && f_pos != "SW")
	{
		f_pos = "SW";
		return;
	}
	if(camera_x >= point*7 && camera_x <= point*9 && f_pos != "S")
	{
		f_pos = "S";
		return;
	}
	if(camera_x >= point*9 && camera_x <= point*11 && f_pos != "SE")
	{
		f_pos = "SE";
		return;
	}
	if(camera_x >= point*11 && camera_x <= point*13 && f_pos != "E")
	{
		f_pos = "E";
		return;
	}
	if(camera_x >= point*13 && camera_x <= point*15 && f_pos != "NE")
	{
		f_pos = "NE";
		return;
	}
	if(camera_x >= point*15 && camera_x <= point*17 && f_pos != "N")
	{
		f_pos = "N";
		return;
	}
}

/**
 * Returns an offset for the space in front of the camera
 * and also calculates block placement based on the camera angle
 */
glm::vec3 GameWorld::GetOffset()
{
	int x = 0, y = 0, z = 0, s = 0;
	float p = 0.0f;

	if(f_pos == "N")
	{
		if(camera_x < 1)
			p = camera_x;
		else
			p = camera_x - point*16;

		s = int(floor(p * 10));
		z += block_dist;
		x += s;
	}
	if(f_pos == "E")
	{
		s = int(floor((point*12 - camera_x) * 10));
		x -= block_dist;
		z -= s;	
	}
	if(f_pos == "S")
	{
		s = int(floor((point*8 - camera_x) * 10));
		z -= block_dist;
		x += s;
	}
	if(f_pos == "W")
	{
		s = int(floor((point*4 - camera_x) * 10));
		x += block_dist;
		z += s;
	}

	if(f_pos == "NE")
	{
		z += block_dist;
		x -= block_dist;
	}
	if(f_pos == "SE")
	{
		z -= block_dist;
		x -= block_dist;
	}
	if(f_pos == "SW")
	{
		z -= block_dist;
		x += block_dist;
	}
	if(f_pos == "NW")
	{
		z += block_dist;
		x += block_dist;
	}

	s = int(camera_y * 10);
	if(s > block_dist)
	{
		s = block_dist;
	}
	if(s < (0 - block_dist))
	{
		s = (0 - block_dist);
	}
	y += s;

	if(x > block_dist)
		x = block_dist;
	if(y > block_dist)
		y = block_dist;
	if(z > block_dist)
		z = block_dist;

	if(x < 0 - block_dist)
		x = 0 - block_dist;
	if(y < 0 - block_dist)
		y = 0 - block_dist;
	if(z < 0 - block_dist)
		z = 0 - block_dist;

	return glm::vec3(x, y, z);
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
						if(block_type == 1)
						{
							asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.COLOUR_RANDOM));
						}
						else
						{
							asset_manager->AddAssetDiamond(std::make_shared<DiamondAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.COLOUR_RANDOM));
						}
					}
				}
			}
		}
		std::cout << "Created Shape 1!" << std::endl;
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
					if(block_type == 1)
					{
						asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.COLOUR_RANDOM));
					}
					else
					{
						asset_manager->AddAssetDiamond(std::make_shared<DiamondAsset>(glm::vec3(0.0+x, 0.0+y, 0.0+z), colour_manager.COLOUR_RANDOM));
					}
				}
			}
		}
		std::cout << "Created Shape 2!" << std::endl;
		return;
	}
	if(shape == "ground")
	{
		for(int z = 0; z < size; z++)
		{
			for(int x = 0; x < size; x++)
			{
				if(block_type == 1)
				{
					asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-10.0+x, -1.0f, -10.0+z), colour_manager.COLOUR_GREEN));
				}
				else
				{
					asset_manager->AddAssetDiamond(std::make_shared<DiamondAsset>(glm::vec3(-10.0+x, -1.0f, -10.0+z), colour_manager.COLOUR_GREEN));
				}
			}
		}
		std::cout << "Created Shape 3!" << std::endl;
		return;
	}
	std::cout << "Shape not found!" << std::endl;
}


/**
 * Returns true if the position passed is already filled with a block
 */
bool GameWorld::CheckCollision(glm::vec3 point)
{
	if(point == glm::vec3(int(position.x), int(position.y), int(position.z)))
	{
		return true;
	}
	
	return false;
}

/**
 * Changes block distance
 */
void GameWorld::ChangeBlockDist(int i)
{
	block_dist += i;

	// Check distance
	if(block_dist < 1)
	{
		block_dist = 1;
	}
	if(block_dist > 10)
	{
		block_dist = 10;
	}
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
				asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(x, cube_y[i], z), colour_manager.COLOUR_GREEN));
				i++;

				std::cout << "[" << i << " / " << TOTAL_BLOCKS << "]\r";
				std::cout.flush();
			}
		} 	
	}

	return;
}