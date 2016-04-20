#include "GameAssetManager.h"

/**
 * Creates a GameAssetManager to load the correct shaders based on the ApplicationMode.
 */
GameAssetManager::GameAssetManager(ApplicationMode mode)
{
	std::string vertex_shader("shaders/translate.vs");
	std::string fragment_shader("shaders/fragment.fs");

	switch(mode)
	{
		case ROTATE:
			vertex_shader = "shaders/rotate.vs";
			break;
		case SCALE:
			vertex_shader = "shaders/scale.vs";
			break;
		case TRANSFORM:
		default:
			break;
	};

	program_token = CreateGLProgram(vertex_shader, fragment_shader);
}

/**
 * Deletes a GameAssetManager, in particular it will clean up any modifications
 * to the OpenGL state.
 */
GameAssetManager::~GameAssetManager() 
{
	glDeleteProgram(program_token);
}

/**
 * Unimplemented copy constructor -- this means that the GameAssetManager
 * may not work as you'd expect when being copied.
 */
GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) 
{
	// TODO: implement this
}

/**
 * Unimplemented move constructor -- this unimplemented method violates the
 * C++11 move semantics for GameAssetManager.
 */
GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager)
{
	// TODO: implement this
}

/**
 * Unimplemented assisgnment operator -- violates the expected semantics for
 * assignment in C++11.
 */
void GameAssetManager::operator=(GameAssetManager const& the_manager)
{
	// TODO: implement this
}

/**
 * Adds a GameAsset to the scene graph.
 */
void GameAssetManager::AddAsset(std::shared_ptr<CubeAsset> cube_asset)
{
	// Rather than pass two CubeAssets, only parse one and *cast* to GameAsset
	std::shared_ptr<GameAsset> the_asset = cube_asset;

	// Loop setup
	bool flag = false;
	CubeAsset cc = *cube_asset;
	CubeAsset nc = CubeAsset(glm::vec3(0.0,0.0,0.0), glm::vec3(0,0,0));

	glm::vec3 cube_pos = cc.GetVec3();

	// Loop through the assetlist to check if there is already a cube in the position
	for(int i = 0; i < asset_list.size(); i++)
	{
		nc = *asset_list[i];
		if(glm::to_string(cc.GetVec3()) == glm::to_string(nc.GetVec3()))
		{
			flag = true;
			break;
		}
	}

	if(!flag)
	{
		asset_list.push_back(cube_asset);
		draw_list.push_back(the_asset);
	}
}
/**
 * Adds a GameAsset to the scene graph.
 * THIS ADDS A DIAMOND ASSET, BUT DOES NOT GIVE IT THE SAME FUNCTIONALITY AS CUBEASSET
 */
void GameAssetManager::AddAssetDiamond(std::shared_ptr<GameAsset> diamond_asset)
{
	draw_list.push_back(diamond_asset);
}

/**
 * Removes all of the assets from the world
 */
void GameAssetManager::RemoveAll()
{
	// Free the GL buffer data
	for(int i = 0; i < asset_list.size(); i++)
	{
		CubeAsset cc = *asset_list[i];
	}

	// Remove the assets from the list
	asset_list.clear();
	draw_list.clear();
}

/**
 * Removes an asset from the gameworld
 */
void GameAssetManager::RemoveAsset(glm::vec3 position, glm::vec3 offset_pos)
{		
	// Loops setup
	int r = 0;
	bool flag = false;
	CubeAsset cc = CubeAsset(glm::vec3(0.0,0.0,0.0), glm::vec3(0,0,0));

	// Loop through the assetlist to check if there is a cube in the position we want to remove from
	for(int i = 0; i < asset_list.size(); i++)
	{
		cc = *asset_list[i];
		if(glm::to_string(cc.GetVec3()) == glm::to_string(glm::vec3(0.0f + int(round(position.x)) + offset_pos.x, 0.0f + int(round(position.y)) + offset_pos.y, 0.0f + int(round(position.z)) + offset_pos.z)))
		{
			r = i;
			flag = true;
			break;
		}
	}

	if(flag)
	{
		// Remove the asset
		asset_list.erase(asset_list.begin() + r);
		draw_list.erase(draw_list.begin() + r);
	}
}

/**
 * Gets the asset list
 */
std::vector<std::shared_ptr<CubeAsset>> GameAssetManager::GetAssets()
{
	return asset_list;
}

/**
 * Draws each GameAsset in the scene graph.
 */
void GameAssetManager::Draw(glm::mat4 cam_proj, glm::mat4 cam_view)
{
	for(auto ga: draw_list)
	{
		ga->Draw(program_token);
	}

	glm::mat4 cam_mod(1.0f);

	GLuint cam_proj_loc = glGetUniformLocation(program_token, "cam_proj");
	GLuint cam_view_loc = glGetUniformLocation(program_token, "cam_view");
	GLuint cam_mod_loc = glGetUniformLocation(program_token, "cam_mod");

	glUniformMatrix4fv(cam_proj_loc, 1, GL_FALSE, &cam_proj[0][0]);
	glUniformMatrix4fv(cam_view_loc, 1, GL_FALSE, &cam_view[0][0]);
	glUniformMatrix4fv(cam_mod_loc, 1, GL_FALSE, &cam_mod[0][0]);
}

/**
 * When given the contents of a vertex shader and fragment shader
 * GameAssetManager::CreateGLProgram will compile and link them.  This
 * implementation will exit with -1 error if an error is detected.
 *
 * @return the GL "token" referring to the gl program.
 */
GLuint GameAssetManager::CreateGLProgram(std::string & vertex_shader, std::string & fragment_shader)
{
	auto v_shader_token = CreateGLESShader(GL_VERTEX_SHADER, vertex_shader);
	auto f_shader_token = CreateGLESShader(GL_FRAGMENT_SHADER, fragment_shader);

	GLint program_ok;
	GLuint program = glCreateProgram();

	glAttachShader(program, v_shader_token);
	glAttachShader(program, f_shader_token);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
	if (!program_ok)
	{
		std::cerr << "Failed to link shader program:" << std::endl;
		glDeleteProgram(program);
		exit(-1);
	}

	return program;
}

/**
 * When given a type of shader to construct and the contents of a shader,
 * GameAssetManager::CreateGLESShader will create the shader or exit with
 * error -1.
 *
 * @return the GL "token" for the requested shader.
 */
GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader) {
	GLuint shader_token;
	GLint shader_ok;

	auto source = ReadShader(shader);

	if(!source.first)
	{
		return 0;
	}

	shader_token = glCreateShader(type);
	glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
	glCompileShader(shader_token);
	delete(source.first);

	glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);
	if(!shader_ok)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader_token, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shader_token, maxLength, &maxLength, &errorLog[0]);

		//Provide the infolog in whatever manor you deem best.
		std::cerr << "Failed to compile " << shader << " with error code " << shader_ok << std::endl;
		for(auto c: errorLog)
		{
			std::cerr << c;
		}

		glDeleteShader(shader_token); //Don't leak the shader.
		exit(-1);
	}

	return shader_token;
}

/**
 * ReadShader reads the contents of a file and packs it into a null termintated
 * GLchar * which is suitable for sending to OpenGL.
 *
 * @return a pair consisting of the shader file contents and a holder for the
 *         OpenGL "token".
 */
std::pair<GLchar *, GLint> GameAssetManager::ReadShader(std::string & shader)
{
	std::ifstream input_file;
	GLint length;
	input_file.open(shader, std::ios::in);

	input_file.seekg(0, std::ios::end);  	// go to the end of the file
	length = input_file.tellg();    		// get length of the file
	input_file.seekg(0, std::ios::beg);  	// go to beginning of the file

	GLchar * buffer = new GLchar[length+1];
	input_file.read(buffer, length);
	buffer[length+1]='\0';  				// Ensure null terminated

	input_file.close();
	return std::make_pair(buffer, length);
}
