#include "src/Helix.h"
#include "SDL_image.h"


int main(int argc, char *argv[]) {
    Helix::hlx_init("template project", 640, 480);

    Helix::Graphics::Sprite background = Helix::Graphics::Sprite("assets/background.jpg");
    Helix::Graphics::Sprite secondBackground = background; // second background to infinite scrolling

    while (true) {
        if (Helix::hlx_update() != 0) {
            break;
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

        Helix::hlx_endDraw();
    }

    Helix::hlx_quit();
    return 0;
}
