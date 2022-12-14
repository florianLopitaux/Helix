#include <iostream>

#include "../src/Helix.h"
#include "SDL_image.h"


int main(int argc, char *argv[]) {
    if (Helix::hlx_init("template project", 640, 480) != 0) {
        return -1;
    }

    Helix::Graphics::Sprite background = Helix::Graphics::Sprite("assets/background.jpg");
    Helix::Graphics::Sprite secondBackground = background; // second background to infinite scrolling

    while (true) {
        if (Helix::hlx_update() != 0) {
            break;
        }

        // Test if keyboard functions works correctly
        if (Helix::hlx_isKeyDown(SDLK_b)) {
            std::cout << "The 'b' key is down !" << std::endl;

        } else if (Helix::hlx_isKeyUp(SDLK_b)) {
            std::cout << "The 'b' key is up !" << std::endl;
        }

        if (Helix::hlx_isMouseButtonDown(SDL_BUTTON_LEFT)) {
            std::cout << "left button is down !" << std::endl;
        }
        if (Helix::hlx_isMouseButtonDown(SDL_BUTTON_RIGHT)) {
            std::cout << "right button is down !" << std::endl;
        }
        if (Helix::hlx_isMouseButtonUp(SDL_BUTTON_LEFT)) {
            std::cout << "left button is up !" << std::endl;
        }
        if (Helix::hlx_isMouseButtonUp(SDL_BUTTON_RIGHT)) {
            std::cout << "right button is up !" << std::endl;
        }

        // Update background
        background.setX(background.getX() - 3);

        if (background.getX() <= -background.getWidth()) {
            background.setX(0);
        }

        secondBackground.setX(background.getX() + background.getWidth());


        Helix::Graphics::setColor(0, 0, 0);
        Helix::hlx_beginDraw();

        Helix::Graphics::draw(background);
        Helix::Graphics::draw(secondBackground);

        Helix::Graphics::setColor(180, 37, 98);

        Helix::Graphics::drawLine(Helix::Utils::Vector2D(10, 10), Helix::Utils::Vector2D(630, 470));

        Helix::Graphics::drawEmptyRectangle(Helix::Utils::Vector2D(40, 17), 30, 15);
        Helix::Graphics::drawFillRectangle(Helix::Utils::Vector2D(100, 17), 18, 35);

        Helix::Graphics::setColor(20, 10, 230);
        Helix::Graphics::drawEmptyCircle(Helix::Utils::Vector2D(250, 300), 20, 0.7);
        Helix::Graphics::drawFillCircle(Helix::Utils::Vector2D(150, 300), 20);

        Helix::hlx_endDraw();
    }

    Helix::hlx_quit();
    return 0;
}
