#include "Helix.h"

#include <iostream>


// FIELDS
SDL_Window *window;
SDL_Renderer *renderer;


// FUNCTIONS
int Helix::hlx_init(const std::string & windowName, const unsigned windowWidth, const unsigned windowHeight) {
    // SDL initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Error ! Impossible to initialize the SDL." << std::endl;
        return -1;
    }

    // Window initialization
    window = SDL_CreateWindow(windowName,
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
}

void Helix::hlx_quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}
