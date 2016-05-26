#define GLEW_STATIC // Easier debugging
#define RUN_GRAPHICS_DISPLAY 0x00;

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <boost/program_options.hpp>

#include "common.h"
#include "App.h"
#include "GameWorld.h"

/**
 * SDL timers run in separate threads.  In the timer thread
 * push an event onto the event queue.  This event signifies
 * to call display() from the thread in which the OpenGL
 * context was created.
 */
Uint32 tick(Uint32 interval, void *param)
{
    SDL_Event event;
    event.type = SDL_USEREVENT;
    event.user.code = RUN_GRAPHICS_DISPLAY;
    event.user.data1 = 0;
    event.user.data2 = 0;
    SDL_PushEvent(&event);
    return interval;
}

/**
 * Destroys the game SDL_Window
 */
struct SDLWindowDeleter
{
    inline void operator()(SDL_Window* window)
    {
        SDL_DestroyWindow(window);
    }
};

/**
 * Handles global input from mouse and keyboard
 */
void App::HandleInput(const std::shared_ptr<GameWorld> &game_world)
{
    int mouse_x;
    int mouse_y;
    const Uint8 * keyboard_state;
    Input input_direction = NILL;

    // For camera pitch/yaw
    SDL_GetRelativeMouseState(&mouse_x, &mouse_y);

    // Slow down the mouse_x and mouse_y
    mouse_x = mouse_x*0.2;
    mouse_y = mouse_y*0.2;

    game_world->UpdateCameraPosition(input_direction, mouse_x, mouse_y);

    // For keyboard presses
    keyboard_state = SDL_GetKeyboardState(NULL);
    if(keyboard_state[SDL_SCANCODE_W])
    {
        game_world->UpdateCameraPosition(W, mouse_x, mouse_y);
    }
    if(keyboard_state[SDL_SCANCODE_A])
    {
        game_world->UpdateCameraPosition(A, mouse_x, mouse_y);
    }
    if(keyboard_state[SDL_SCANCODE_S])
    {
        game_world->UpdateCameraPosition(S, mouse_x, mouse_y);
    }
    if(keyboard_state[SDL_SCANCODE_D])
    {
        game_world->UpdateCameraPosition(D, mouse_x, mouse_y);
    }
	if(keyboard_state[SDL_SCANCODE_SPACE])
    {
        game_world->UpdateCameraPosition(SPACE, mouse_x, mouse_y);
    }
	if(keyboard_state[SDL_SCANCODE_LCTRL])
    {
        game_world->UpdateCameraPosition(CTRL, mouse_x, mouse_y);
    }

	if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        game_world->BlockAction(true);
    }
	if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
    {
        game_world->BlockAction(false);
    }

    if(keyboard_state[SDL_SCANCODE_ESCAPE])
    {
        SDL_Quit();
    }

    if(keyboard_state[SDL_SCANCODE_1])
    {
        game_world->BlockType(BW_CUBE);
    }
    if(keyboard_state[SDL_SCANCODE_2])
    {
        game_world->BlockType(BW_STAR);
    }
    if(keyboard_state[SDL_SCANCODE_3])
    {
        game_world->BlockType(BW_DIAMOND);
    }
}

/**
 * Draws the colour and calls to GameWorld for Drawing
 */
void App::Draw(const std::shared_ptr<SDL_Window> &window, const std::shared_ptr<GameWorld> &game_world)
{
    // Background
	glClearColor(0.0f, 0.2f, 0.2f, 0.3f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    game_world->Draw();

    // Don't forget to swap the buffers
    SDL_GL_SwapWindow(window.get());
}

/**
 * Initialises the SDL_Window and OpenGL 3.0
 */
std::shared_ptr<SDL_Window> App::InitWorld()
{
    Uint32 width = 1027;
    Uint32 height = 768;
    SDL_Window * _window;
    std::shared_ptr<SDL_Window> window;

    // Glew will later ensure that OpenGL 3 *is* supported
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Do double buffering in GL
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Initialise SDL - when using C/C++ it's common to have to
    // initialise libraries by calling a function within them.
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)<0)
    {
        std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // When we close a window quit the SDL application
    atexit(SDL_Quit);
    SDL_ShowCursor(0);

    // Create a new window with an OpenGL surface
    _window = SDL_CreateWindow("BlockWorld",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!_window)
    {
        std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (!glContext)
    {
        std::cout << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Initialise GLEW - an easy way to ensure OpenGl 3.0+
    // The *must* be done after we have set the video mode - otherwise we have no
    // OpenGL context to test.
    glewInit();
    if (!glewIsSupported("GL_VERSION_3_0"))
    {
        std::cerr << "OpenGL 3.0 not available" << std::endl;
        return nullptr;
    }

    // OpenGL settings
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    window.reset(_window, SDL_DestroyWindow);
    return window;
}

/**
 * Starts our game loop, called via Python or Main
 */
void App::Run()
{
    Uint32 delay = 1000/60; // in milliseconds

    auto window = InitWorld();
    auto game_world = std::make_shared<GameWorld>();

    if(!window)
    {
        SDL_Quit();
    }

    // Call the function "tick" every delay milliseconds
    SDL_AddTimer(delay, tick, NULL);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    // Add the main event loop
    SDL_Event event;
    while (SDL_WaitEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                 SDL_Quit();
                break;
            }
            case SDL_USEREVENT:
            {
                HandleInput(game_world);
                Draw(window, game_world);
                break;
            }
            default:
            break;
        }
    }
}
