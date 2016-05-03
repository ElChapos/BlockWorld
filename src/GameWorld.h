#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include <GL/gl.h>

#include "common.h"
#include "CubeAsset.h"
#include "ColourManager.h"
#include "GameAssetManager.h"

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

        /**
        * Calling Draw() will draw the entire world.
        */
        void Draw();
        void UpdateCameraPosition(Input, int mouse_x, int mouse_y);

    private:
        ColourManager colour_manager;
        std::shared_ptr<GameAssetManager> asset_manager;

};
#endif // GAMEWORLD_H
