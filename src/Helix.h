#ifndef HELIX_H
#define HELIX_H

#include <string>

#include "graphics/AnimatedSprite.h"


namespace Helix {
    #define FPS 60

    // SYSTEM FUNCTIONS
    int hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight);
    void hlx_quit();

    int hlx_update();
    Uint32 hlx_getDeltaTime();

    void hlx_beginDraw();
    void hlx_endDraw();
    void hlx_freeTexture(SDL_Texture *texture);

    bool hlx_isKeyDown(const SDL_Keycode & key);
    bool hlx_isKeyUp(const SDL_Keycode & key);
    bool hlx_isMouseButtonDown(const int buttonFlag);
    bool hlx_isMouseButtonUp(const int buttonFlag);

    Utils::Vector2D hlx_getMousePosition();


    // GRAPHIC FUNCTIONS
    namespace Graphics {
        void setColor(const int red, const int green, const int blue, const int alpha = 255);
        void drawLine(const Utils::Vector2D & pos1, const Utils::Vector2D & pos2);

        void drawEmptyRectangle(const Utils::Vector2D & pos, const unsigned width, const unsigned height);
        void drawEmptyCircle(const Utils::Vector2D & pos, const unsigned radius, const float borderWidth);

        void drawFillRectangle(const Utils::Vector2D & pos, const unsigned width, const unsigned height);
        void drawFillCircle(const Utils::Vector2D & pos, const unsigned radius);

        SDL_Texture* loadTexture(const std::string & imagePath);
        void draw(const Sprite & sprite);
        void drawSquad(const AnimatedSprite & animatedSprite);
    }
}

#endif
