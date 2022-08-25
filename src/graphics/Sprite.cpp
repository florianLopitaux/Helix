#include "Sprite.h"


// CONSTRUCTORS
Helix::Graphics::Sprite::Sprite(const std::string & imagePath) {
    this->texture = Helix::Graphics::loadTexture(imagePath);
    this->position = Helix::Utils::Vector2D();
}

Helix::Graphics::Sprite::Sprite(const std::string & imagePath, const Helix::Utils::Vector2D & position) {
    this->texture = Helix::Graphics::loadTexture(imagePath);
    this->position = position;
}


// DESTRUCTOR
Helix::Graphics::Sprite::~Sprite() {
    Helix::hlx_freeTexture(this->texture);
}


// GETTERS
SDL_Texture* Helix::Graphics::Sprite::getTexture() const {
    return this->texture;
}

Helix::Utils::Vector2D Helix::Graphics::Sprite::getPosition() const {
    return this->position;
}


// SETTER
void Helix::Graphics::Sprite::setPosition(const Helix::Utils::Vector2D & vector) {
    this->position = vector;
}
