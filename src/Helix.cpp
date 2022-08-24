#include "Helix.h"

#include <iostream>

#include "SDL_image.h"


// FIELDS
SDL_Window *window;
SDL_Renderer *renderer;


// SYSTEM FUNCTIONS
int Helix::hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight) {
    // SDL initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Error ! Impossible to initialize the SDL." << std::endl;
        return -1;
    }

    // Window initialization
    window = SDL_CreateWindow(windowName.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              windowWidth, windowHeight,
                              SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Error ! The window cannot be created !" << std::endl
                  << "SDL error : " << SDL_GetError() << std::endl;
        return -1;
    }

    // Renderer initialization
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);

        std::cout << "Error ! The renderer cannot be created !" << std::endl
                  << "SDL error : " << SDL_GetError() << std::endl;
        return -1;

    } else {
        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);

            std::cout << "Error ! SDL_Image couldn't initialize !" << std::endl
                      << "SDL_Image error : " << IMG_GetError() << std::endl;
            return -1;
        }
    }

    return 0;
}

void Helix::hlx_beginDraw() {
    SDL_RenderClear(renderer);
}

void Helix::hlx_endDraw() {
    SDL_RenderPresent(renderer);
}

void Helix::hlx_quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}


// GRAPHIC FUNCTIONS
SDL_Texture* Helix::loadTexture(const std::string & imagePath) {
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(renderer, imagePath.c_str());

    if (texture == NULL) {
        std::cout << "Error ! Unable to create texture from " << imagePath << std::endl
                  << "SDL_image error : " << IMG_GetError() << std::endl;
    }

    return texture;
}

void Helix::setColor(const int red, const int green, const int blue, const int alpha) {
    // Assertions
    if ((red < 0 || red > 255) ||
        (green < 0 || green > 255) ||
        (blue < 0 || blue > 255) ||
        (alpha < 0 || alpha > 255)) {

        std::cout << "Error ! The arguments value is out of range ! It can only take values between 0 and 255."
                  << std::endl;
        return;
    }

    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
}

void Helix::drawLine(const int x1, const int y1, const int x2, const int y2) {
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
