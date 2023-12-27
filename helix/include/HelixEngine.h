/**
 * @file HelixEngine.h
 * @author Florian LOPITAUX
 * @brief This file contains the HelixEngine class declaration.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#ifndef _HELIX_ENGINE_H
#define _HELIX_ENGINE_H

#include "graphics/RenderManager.h"

#include "SDL2/SDL.h"


/**
 * @namespace nsHelix
 * @brief Base namespace that contains all contents of the Helix library.
*/
namespace nsHelix {

    /**
     * @class HelixEngine "HelixEngine.h"
     * @brief Class that represent our game engine and contains most important functions (initialization, game loop, fps, ...).
    */
    class HelixEngine {

        private:
            // FIELDS
            /** @brief the window of the game. */
            SDL_Window *window;

            /** @brief the render manager of our game. */
            nsGraphics::RenderManager *renderer;

            /** @brief boolean variable to know if the engine run or has to stop. */
            bool running;

            /** @brief variable that storage the targeted fps (60 by default). */
            unsigned fps;

            /** @brief variable that storage the time passing during each frame to compute the framerate. */
            Uint32 elapsedTime;


        public:
            // CONSTRUCTOR & DESTRUCTOR
            /**
             * Create the Helix game engine and initialize all components to create the window.
             * 
             * @param windowName the name of the window game
             * @param width the width of the window game
             * @param height the height of the window game 
            */
            HelixEngine(const std::string & windowName, const unsigned width, const unsigned height);

            /**
             * Destroy everything initialize at the start and liberate all memory used (textures, renderer, window, ...).
            */
            ~HelixEngine();



            // GETTERS & SETTERS
            /**
             * Getter method of the 'running' attribute.
             * 
             * @return True if the engine run or false if it is stopped
            */
            bool isRunning() const;

            /**
             * Setter method of the 'fps' attribute.
             * 
             * @param fps the number of frame per seconds that we want for the game
            */
            void setTargetFPS(const unsigned fps);



            // METHODS
            /**
             * Manage and get all events triggered.
             * This method has to be called at the beginning of the game loop (update time).
             * 
             * @return a list that contains all events triggered since the last frame
            */
            std::vector<SDL_Event> handleEvents();

            /**
             * Configure everything to begin to draw in the current frame.
             * This method has to be called before any draw at each frame, see game loop mechanics.
             * 
             * @throws HelixException
            */
            void beginDraw();

            /**
             * Configure everything after all drawing elements on the window.
             * This method has to be called after all draw call at each frame, see game loop mechanics.
            */
            void endDraw();
    };
}

#endif
