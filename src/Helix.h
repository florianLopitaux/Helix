#ifndef HELIX_H
#define HELIX_H

#include <string>

#include "SDL.h"
#include "SDL_image.h"

namespace Helix {
    // SYSTEM FUNCTIONS
    int hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight);
    void hlx_quit();

    // GRAPHIC FUNCTIONS
    SDL_Texture* loadTexture(const std::string & imagePath);
}

#endif
