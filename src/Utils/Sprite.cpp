#include "Sprite.h"


// CONSTRUCTORS
Helix::Sprite::Sprite(const std::string & imagePath) {
    this->texture = Helix::loadTexture(imagePath);
    this->position = Helix::Vector2D();
}

Helix::Sprite::Sprite(const std::string & imagePath, const Vector2D & position) {
    this->texture = Helix::loadTexture(imagePath);
    this->position = position;
}


// DESTRUCTOR
Helix::Sprite::~Sprite() {
    Helix::hlx_freeTexture(this->texture);
}


// GETTERS
SDL_Texture* Helix::Sprite::getTexture() const {
    return this->texture;
}

Helix::Vector2D Helix::Sprite::getPosition() const {
    return this->position;
}


// SETTER
void Helix::Sprite::setPosition(const Vector2D & vector) {
    this->position = vector;
}
