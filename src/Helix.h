#ifndef HELIX_H
#define HELIX_H

#include <string>

#include "SDL.h"
#include "utils/Vector2D.h"


namespace Helix {
    // SYSTEM FUNCTIONS
    int hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight);
    void hlx_beginDraw();
    void hlx_endDraw();
    void hlx_freeTexture(SDL_Texture *texture);
    void hlx_quit();

    // GRAPHIC FUNCTIONS
    void setColor(const int red, const int green, const int blue, const int alpha = 255);
    void drawLine(const Vector2D & pos1, const Vector2D & pos2);
    void drawEmptyRectangle(const Vector2D & pos, const unsigned width, const unsigned height);
    void drawFillRectangle(const Vector2D & pos, const unsigned width, const unsigned height);

    SDL_Texture* loadTexture(const std::string & imagePath);
}

#endif
