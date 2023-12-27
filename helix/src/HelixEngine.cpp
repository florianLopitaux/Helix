#include "../include/HelixEngine.h"

#include "../include/exceptions/HelixExceptions.h"

#include "SDL2/SDL_image.h"


/*
* ---------------------------------------------
* CONSTRUCTOR & DESTRUCTOR
* ---------------------------------------------
*/

nsHelix::HelixEngine::HelixEngine(const std::string & windowName,
                                  const unsigned width, const unsigned height) {

    // SDL initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw nsExceptions::HelixInitializationException("Impossible to initialize the SDL.");
    }

    // Window initialization
    this->window = SDL_CreateWindow(windowName.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (this->window == NULL) {
        const std::string sdlError = SDL_GetError();
        throw nsExceptions::HelixInitializationException("The window cannot be created.\nSDL error : " + sdlError);
    }

    // Renderer and SDL image initialization
    this->renderer = new nsGraphics::RenderManager(this->window);

    this->fps = 60;
    this->running = true;
    this->elapsedTime = SDL_GetTicks();
}

nsHelix::HelixEngine::~HelixEngine() {
    delete this->renderer;
    SDL_DestroyWindow(this->window);

    IMG_Quit();
    SDL_Quit();
}


/*
* ---------------------------------------------
* GETTERS & SETTERS
* ---------------------------------------------
*/

bool nsHelix::HelixEngine::isRunning() const {
    return this->running;
}

void nsHelix::HelixEngine::setTargetFPS(const unsigned fps) {
    this->fps = fps;
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/

std::vector<SDL_Event> nsHelix::HelixEngine::handleEvents() {
    std::vector<SDL_Event> events;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->running = false;
        } else {
            events.push_back(event);
        }
    }

    return events;
}

void nsHelix::HelixEngine::beginDraw() {
    this->renderer->beginDraw();
}

void nsHelix::HelixEngine::endDraw() {
    this->renderer->endDraw();

    // compute and limit framerate
    const Uint32 deltaTime = SDL_GetTicks() - this->elapsedTime;

    if (1000 / this->fps > deltaTime) {
        SDL_Delay(1000 / this->fps - deltaTime);
    }

    this->elapsedTime = SDL_GetTicks();
}
