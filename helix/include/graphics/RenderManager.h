/**
 * @file RenderManager.h
 * @author Florian LOPITAUX
 * @brief This file contains the RenderManager class declaration.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#ifndef _RENDER_MANAGER_H
#define _RENDER_MANAGER_H

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"


/**
 * @namespace nsHelix
 * @brief Base namespace that contains all contents of the Helix library.
*/
namespace nsHelix {

    /**
     * @namespace nsGraphics
     * @brief Sub-namespace that contains all stuff about graphics in the game (display, sprite, images...)
    */
    namespace nsGraphics {

        /**
         * @class RenderManager "graphics/RenderManager.h"
         * @brief Class to manage displaying on the window and loading images.
        */
        class RenderManager {

            private:
                // FIELDS
                /** @brief renderer of the SDL2 library to draw on the window. */
                SDL_Renderer *renderer;

                /** @brief list of all textures loaded to clear them when we want. */
                std::vector<std::pair<SDL_Texture*, std::string>> texturesLoaded;


            public:
                // CONSTRUCTOR & DESTRUCTOR
                /**
                 * Create a renderer for the given window to display elements on it.
                 * 
                 * @param window a pointer of the window where the renderer has to draw
                 * 
                 * @throws HelixInitializationException
                */
                RenderManager(SDL_Window *window);

                /**
                 * Liberate the memory of all textures loaded and the SDL renderer.
                */
                ~RenderManager();



                // PUBLIC METHODS
                /**
                 * Load an image from a given path and convert to a texture of the image.
                 * 
                 * @param imagePath the path of the image to load
                 * @param tag a special tag associated with the loaded texture to clear later more easer
                 * 
                 * @throws FileNotFoundException
                 * 
                 * @return the texture of the image loaded
                */
                SDL_Texture *loadTexture(const std::string & imagePath, const std::string & tag = "");

                /**
                 * Liberate in the memory a texture loaded.
                 * 
                 * @param texture the texture to erase
                */
                void freeTexture(SDL_Texture * texture);

                /**
                 * Liberate all textures loaded or a specefic group with the correct tag associated.
                 * 
                 * @param tag the tag of the textures given in the loading, by default liberate all textures
                */
                void clearAllTextures(const std::string & tag = "");

                /**
                 * Clear the last loop step to begin to draw the new loop step.
                 * 
                 * @throws HelixException
                */
                void beginDraw();

                /**
                 * Display all elements in the renderer on the window.
                */
                void endDraw();
        };
    }
}

#endif
