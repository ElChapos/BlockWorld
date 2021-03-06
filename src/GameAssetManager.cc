#include "GameAssetManager.h"

/**
 * Creates a GameAssetManager to load the correct shaders based on the
 * ApplicationMode.
 */
GameAssetManager::GameAssetManager()
{
    std::string vertex_shader("shaders/translate.vs");
    std::string fragment_shader("shaders/fragment.fs");

    program_token = CreateGLProgram(vertex_shader, fragment_shader);

    // link to the uniform variables in the translate shader
    projection_matrix_link = glGetUniformLocation(program_token, "projection_matrix");
    translate_matrix_link = glGetUniformLocation(program_token, "translate_matrix");
    view_matrix_link = glGetUniformLocation(program_token, "view_matrix");

    // create the matrix based on the window size. used to solve z buffering.
    projection_matrix = glm::perspective(glm::radians(45.0f), (float) 640/ (float) 480, 0.1f, 1000.0f);
}

/**
 * Communicates with Camera class
 */
void GameAssetManager::UpdateCameraPosition(Input input_direction,  int mouse_x, int mouse_y)
{
    view_matrix = camera->UpdateCameraPosition(input_direction, mouse_x, mouse_y);
}

/**
 * Fetches and returns the camera position
 */
glm::vec3 GameAssetManager::GetCameraPosition()
{
    return camera->GetCameraPosition();
}

/**
 * Fetches and returns the camera direction
 */
glm::vec3 GameAssetManager::GetCameraDirection()
{
    return camera->GetCameraDirection();
}

/**
*  Gives a gameAsset some path Coordinates
*/
void GameAssetManager::SetPath(glm::vec3 path, bool active)
{
    if(active == true)
    {
        path_list.push_back(path);
    }
    else if (active == false)
    {
        draw_list.back()->SetPath(path_list);
        path_list.clear();
    }
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
 * Adds a GameAsset to the scene graph.
 */
void GameAssetManager::AddAsset(std::shared_ptr<GameAsset> the_asset)
{
    // Assume we create the block
    bool create = true;

    // Check each asset`
    for(auto item: draw_list)
    {
        // if the asset exists
        if(glm::to_string(item->GetVec3()) == glm::to_string(the_asset->GetVec3()))
        {
            // Change create to false so we do not make one
            std::cout << "Block was not added to draw_list, one already exists on that position" << std::endl;
            create = false;
            break;
        }
    }

    // Check if we can create a block
    if(create)
    {
        draw_list.push_back(the_asset);
    }
}

/**
 * Deletes an asset from the draw_list
 */
void GameAssetManager::DeleteAsset(glm::vec3 position)
{
    bool del = false;
    int i = 0;

    glm::vec3 position_bounds_max, position_bounds_min, asset_bounds_max, asset_bounds_min;
    for(auto item: draw_list)
    {
        std::cout << "Compare ITEM: [" << glm::to_string(item->GetVec3()) << "] with POS: [" << glm::to_string(position) << "]" << std::endl;

        position_bounds_max = position += glm::vec3(0.75,0.75,0.75);
        position_bounds_min = position += glm::vec3(-0.75,-0.75,-0.75);
        asset_bounds_max = item->GetMaxAndMin(1);
        asset_bounds_min = item->GetMaxAndMin(2);

        if (asset_bounds_max.x > position_bounds_min.x && asset_bounds_min.x < position_bounds_max.x &&
            asset_bounds_max.y > position_bounds_min.y && asset_bounds_min.y < position_bounds_max.y &&
            asset_bounds_max.z > position_bounds_min.z && asset_bounds_min.z < position_bounds_max.z)
        {
            std::cout << "Found block, flagging for delete" << std::endl;
            del = true;
            break;
        }
        i++;
    }

    if(del)
    {
        draw_list.erase(draw_list.begin()+i);
    }
    else
    {
        std::cout << "No cube was found." << std::endl;
    }
}

/**
 * Draws each GameAsset in the scene graph.
 */
void GameAssetManager::Draw()
{
    for(auto ga: draw_list)
    {

        // before drawing an asset , update the matrix values in the translate shader
        glUniformMatrix4fv(projection_matrix_link, 1, GL_FALSE, &projection_matrix[0][0]);
        glUniformMatrix4fv(view_matrix_link, 1, GL_FALSE, &view_matrix[0][0]);


        // Get the translate matrix from our game asset
        translate_matrix= ga->GetModelTransformation(camera->GetCameraPosition() ,camera->GetCameraDirection());

        glUniformMatrix4fv(translate_matrix_link, 1, GL_FALSE, &translate_matrix[0][0]);

        bounding_box1_max = ga->GetMaxAndMin(1);
        bounding_box1_min = ga->GetMaxAndMin(2);
        bounding_box1_position = ga->GetVec3();

        camera->CheckCollision(bounding_box1_max, bounding_box1_min);

        if ( ga->GetType() == FOLLOWPATH || ga->GetType() == TRANSLATE || ga->GetType() == SPECIAL)
        {
            for(auto ga2: draw_list)
            {
                bounding_box2_max = ga2->GetMaxAndMin(1);
                bounding_box2_min = ga2->GetMaxAndMin(2);
                bounding_box2_position = ga2->GetVec3();

                //If the two bounding boxes are not in the same position (not the same bounding box), then check for a collision.
                if( bounding_box1_position != bounding_box2_position)
                {
                    ga -> CheckCollision(bounding_box1_max, bounding_box1_min, bounding_box2_max, bounding_box2_min);
                }
            }
        }

        ga->Draw(program_token);
    }
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
GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader)
{
    GLuint shader_token;
    GLint shader_ok;
    auto source = ReadShader(shader);

    if (!source.first)
    {
        return 0;
    }

    shader_token = glCreateShader(type);
    glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
    glCompileShader(shader_token);
    delete(source.first);
    glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);

    if (!shader_ok)
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

    input_file.seekg(0, std::ios::end); // go to the end of the file
    length = input_file.tellg(); // get length of the file
    input_file.seekg(0, std::ios::beg); // go to beginning of the file

    GLchar * buffer = new GLchar[length+1];
    input_file.read(buffer, length);
    buffer[length+1]='\0';  // Ensure null terminated

    input_file.close();
    return std::make_pair(buffer, length);
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
