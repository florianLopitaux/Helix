#include "../src/Helix.h"


int main(int argc, char *argv[]) {
    if (Helix::hlx_init("animatedSprite template", 640, 480) != 0) {
        return -1;
    }

    // Player initialization
    Helix::Graphics::AnimatedSprite player ("assets/player_idle.png", Helix::Utils::Vector2D(308, 227), 21, 38);
    
    player.addNewAnimation("IDLE_RIGHT", (Helix::Graphics::Animation){0, 0, 1, 4, 150, true});
    player.addNewAnimation("IDLE_LEFT", (Helix::Graphics::Animation){0, 5, 1, 9, 150, true});

    player.launchAnimation("IDLE_RIGHT");

    while (true) {
        // UPDATE
        if (Helix::hlx_update() != 0) {
            break;
        }

        if (Helix::hlx_isKeyDown(SDLK_d)) {
            player.launchAnimation("IDLE_RIGHT");

        } else if (Helix::hlx_isKeyDown(SDLK_q)) {
            player.launchAnimation("IDLE_LEFT");
        }

        player.updateAnimation(Helix::hlx_getDeltaTime());


        // DRAW
        Helix::Graphics::setColor(0, 0, 0);
        Helix::hlx_beginDraw();

        Helix::Graphics::drawSquad(player);

        Helix::hlx_endDraw();
    }
    
    Helix::hlx_quit();
    return 0;
}
