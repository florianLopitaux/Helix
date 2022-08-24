#include "Helix.h"
#include "SDL_image.h"


int main(int argc, char *argv[]) {
    Helix::hlx_init("template project", 640, 480);

    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }

        Helix::setColor(0, 0, 0);
        Helix::hlx_beginDraw();

        Helix::setColor(180, 37, 98);
        Helix::drawLine(10, 10, 630, 470);

        Helix::drawEmptyRectangle(40, 17, 30, 15);
        Helix::drawFillRectangle(100, 17, 18, 35);

        Helix::hlx_endDraw();
    }

    Helix::hlx_quit();
    return 0;
}
