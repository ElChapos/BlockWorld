#include <SDL2/SDL.h>
#include <memory>
#include "GameWorld.h"

#ifndef SRC_APP_H_
#define SRC_APP_H_

class App{

public:
	std::shared_ptr<SDL_Window> InitWorld();
	void Draw(const std::shared_ptr<SDL_Window> &window, const std::shared_ptr<GameWorld> &game_world);
	void Run();
	void HandleInput(const std::shared_ptr<GameWorld> &game_world);
};



#endif /* SRC_APP_H_ */
