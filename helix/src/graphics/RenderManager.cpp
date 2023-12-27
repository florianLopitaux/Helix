/**
 * @file RenderManager.cpp
 * @author Florian LOPITAUX
 * @brief This file contains the RenderManager class implementation.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#include "../../include/graphics/RenderManager.h"

#include <iostream>
#include "../../include/exceptions/HelixExceptions.h"

#include "SDL2/SDL_image.h"


/*
* ---------------------------------------------
* CONSTRUCTOR & DESTRUCTOR
* ---------------------------------------------
*/

nsHelix::nsGraphics::RenderManager::RenderManager(SDL_Window *window) {
    // Renderer initialization
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (this->renderer == NULL) {
        SDL_DestroyWindow(window);

        const std::string sdlError = SDL_GetError();
        throw nsExceptions::HelixInitializationException("The renderer cannot be created.\nSDL error : " + sdlError);
    }
}

nsHelix::nsGraphics::RenderManager::~RenderManager() {
    // liberate all textures and the SDL renderer
    this->clearAllTextures();
    SDL_DestroyRenderer(this->renderer);
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/

SDL_Texture * nsHelix::nsGraphics::RenderManager::loadTexture(const std::string & imagePath, const std::string & tag = "") {
    SDL_Texture *texture = IMG_LoadTexture(this->renderer, imagePath.c_str());

    if (texture == NULL) {
        throw nsExceptions::FileNotFoundException(imagePath);
    }

    this->texturesLoaded.push_back(std::make_pair(texture, tag));
    return texture;
}

void nsHelix::nsGraphics::RenderManager::freeTexture(SDL_Texture * texture) {
    SDL_DestroyTexture(texture);
}

void nsHelix::nsGraphics::RenderManager::clearAllTextures(const std::string & tag = "") {
    for (size_t i = this->texturesLoaded.size() - 1; i >= 0; --i) {
        const std::pair<SDL_Texture*, std::string> currentTexture = this->texturesLoaded[i];

        if (tag.size() == 0 || currentTexture.second == tag) {
            SDL_DestroyTexture(currentTexture.first);
            this->texturesLoaded.pop_back();
        }
    }
}

void nsHelix::nsGraphics::RenderManager::beginDraw() {
    if (SDL_RenderClear(this->renderer) != 0) {
        const std::string sdlError = SDL_GetError();
        throw nsExceptions::HelixException("Can't clear the renderer and start to drawing.\nSDL error : " + sdlError);
    }
}

void nsHelix::nsGraphics::RenderManager::endDraw() {
    SDL_RenderPresent(this->renderer);
}
