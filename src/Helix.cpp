#include "Helix.h"

#include <iostream>
#include <vector>
#include <algorithm>

#include "SDL_image.h"
#include "utils/MathHelper.h"


// FIELDS
SDL_Window *window;
SDL_Renderer *renderer;

Uint32 oldSDL_GetTicks;
Uint32 deltaTime;

std::vector<SDL_Event> events;
std::vector<SDL_Texture*> resources;


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

    oldSDL_GetTicks = 0;
    return 0;
}

void Helix::hlx_quit() {
    for (SDL_Texture *currentTexture : resources) {
        SDL_DestroyTexture(currentTexture);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

int Helix::hlx_update() {
    deltaTime = SDL_GetTicks() - oldSDL_GetTicks;
    oldSDL_GetTicks = SDL_GetTicks();

    events.clear();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return -1;

        } else {
            events.push_back(event);
        }
    }

    return 0;
}

Uint32 Helix::hlx_getDeltaTime() {
    return deltaTime;
}

void Helix::hlx_beginDraw() {
    SDL_RenderClear(renderer);
}

void Helix::hlx_endDraw() {
    SDL_RenderPresent(renderer);

    // Limit framerate
    if (1000 / FPS > deltaTime) {
        SDL_Delay(1000 / FPS - deltaTime);
    }
}

void Helix::hlx_freeTexture(SDL_Texture *texture) {
    if (texture != NULL) {
        resources.erase(std::remove(resources.begin(), resources.end(), texture), resources.end());
        SDL_DestroyTexture(texture);
    }
}

bool Helix::hlx_isKeyDown(const SDL_Keycode & key) {
    for (const SDL_Event & event : events) {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == key) {
            return true;
        }
    }

    return false;
}

bool Helix::hlx_isKeyUp(const SDL_Keycode & key) {
    for (const SDL_Event & event : events) {
        if (event.type == SDL_KEYUP && event.key.keysym.sym == key) {
            return true;
        }
    }

    return false;
}

Helix::Utils::Vector2D Helix::hlx_getMousePosition() {
    int x, y;
    SDL_GetMouseState(&x, &y);

    return Helix::Utils::Vector2D(x, y);
}

bool Helix::hlx_isMouseButtonDown(const int buttonFlag) {
    for (const SDL_Event & event : events) {
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == buttonFlag) {
            return true;
        }
    }

    return false;
}

bool Helix::hlx_isMouseButtonUp(const int buttonFlag) {
    for (const SDL_Event & event : events) {
        if (event.type == SDL_MOUSEBUTTONUP && event.button.button == buttonFlag) {
            return true;
        }
    }

    return false;
}


// GRAPHIC FUNCTIONS
void Helix::Graphics::setColor(const int red, const int green, const int blue, const int alpha) {
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

void Helix::Graphics::drawLine(const Utils::Vector2D & pos1, const Utils::Vector2D & pos2) {
    SDL_RenderDrawLine(renderer, pos1.getX(), pos1.getY(), pos2.getX(), pos2.getY());
}

void Helix::Graphics::drawEmptyRectangle(const Utils::Vector2D & pos, const unsigned width, const unsigned height) {
    SDL_Rect rect = {pos.getX(), pos.getY(), (int)width, (int)height};

    SDL_RenderDrawRect(renderer, &rect);
}

void Helix::Graphics::drawEmptyCircle(const Utils::Vector2D & pos, const unsigned radius, const float borderWidth) {
    for (int column = pos.getX() - radius; column <= pos.getX() + radius; ++column) {
        for (int row = pos.getY() - radius; row <= pos.getY() + radius; ++row) {
            
            if (abs(Utils::euclideanDistance(pos, Utils::Vector2D(column, row)) - radius) <= borderWidth) {
                SDL_RenderDrawPoint(renderer, column, row);
            }
        }
    }
}

void Helix::Graphics::drawFillRectangle(const Utils::Vector2D & pos, const unsigned width, const unsigned height) {
    SDL_Rect rect = {pos.getX(), pos.getY(), (int)width, (int)height};

    SDL_RenderFillRect(renderer, &rect);
}

void Helix::Graphics::drawFillCircle(const Utils::Vector2D & pos, const unsigned radius) {
    for (int column = pos.getX() - radius; column <= pos.getX() + radius; ++column) {
        for (int row = pos.getY() - radius; row <= pos.getY() + radius; ++row) {
            
            if (Utils::euclideanDistance(pos, Utils::Vector2D(column, row)) <= radius) {
                SDL_RenderDrawPoint(renderer, column, row);
            }
        }
    }
}

SDL_Texture* Helix::Graphics::loadTexture(const std::string & imagePath) {
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(renderer, imagePath.c_str());

    if (texture == NULL) {
        std::cout << "Error ! Unable to create texture from " << imagePath << std::endl
                  << "SDL_image error : " << IMG_GetError() << std::endl;

    } else {
        resources.push_back(texture);
    }

    return texture;
}

void Helix::Graphics::draw(const Sprite & sprite) {
    SDL_Rect rectDest = {sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight()};

    if (SDL_RenderCopy(renderer, sprite.getTexture(), NULL, &rectDest) != 0) {
        std::cout << "Error ! Impossible to draw a texture" << std::endl
                  << "SDL error : " << SDL_GetError() << std::endl;
    }
}

void Helix::Graphics::drawSquad(const AnimatedSprite & sprite) {
    SDL_Rect rectDest = {sprite.getX(), sprite.getY(), (int)sprite.getFrameWidth(), (int)sprite.getFrameHeight()};

    if (SDL_RenderCopy(renderer, sprite.getTexture(), &sprite.getCurrentSprite(), &rectDest) != 0) {
        std::cout << "Error ! Impossible to draw a texture" << std::endl
                  << "SDL error : " << SDL_GetError() << std::endl;
    }
}
