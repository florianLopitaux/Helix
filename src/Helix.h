#ifndef HELIX_H
#define HELIX_H

#include <string>

#include "SDL.h"

namespace Helix {
    // SYSTEM FUNCTIONS
    int hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight);
    void hlx_beginDraw();
    void hlx_endDraw();
    void hlx_quit();

    // GRAPHIC FUNCTIONS
    void setColor(const int red, const int green, const int blue, const int alpha = 255);
    void drawLine(const int x1, const int y1, const int x2, const int y2);
    void drawEmptyRectangle(const int x, const int y, const unsigned width, const unsigned height);
    void drawFillRectangle(const int x, const int y, const unsigned width, const unsigned height);

    SDL_Texture* loadTexture(const std::string & imagePath);
}

#endif
