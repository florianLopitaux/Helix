#include "../src/Helix.h"


int main(int argc, char *argv[]) {
    if (Helix::hlx_init("animatedSprite template", 640, 480) != 0) {
        return -1;
    }

    while (true) {
        if (Helix::hlx_update() != 0) {
            break;
        }

        Helix::Graphics::setColor(0, 0, 0);
        Helix::hlx_beginDraw();

        Helix::hlx_endDraw();
    }
    
    Helix::hlx_quit();
    return 0;
}
