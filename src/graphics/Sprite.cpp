#include "Sprite.h"

#include "../Helix.h"


// CONSTRUCTORS
Helix::Graphics::Sprite::Sprite(const std::string & imagePath) {
    this->texture = Helix::Graphics::loadTexture(imagePath);
    this->position = Helix::Utils::Vector2D();

    SDL_QueryTexture(this->texture, NULL, NULL, &this->width, &this->height);
}

Helix::Graphics::Sprite::Sprite(const std::string & imagePath, const Helix::Utils::Vector2D & position) {
    this->texture = Helix::Graphics::loadTexture(imagePath);
    this->position = position;

    SDL_QueryTexture(this->texture, NULL, NULL, &this->width, &this->height);
}


// DESTRUCTOR
Helix::Graphics::Sprite::~Sprite() {
    Helix::hlx_freeTexture(this->texture);
}


// GETTERS
SDL_Texture* Helix::Graphics::Sprite::getTexture() const {
    return this->texture;
}

int Helix::Graphics::Sprite::getX() const {
    return this->position.getX();
}

int Helix::Graphics::Sprite::getY() const {
    return this->position.getY();
}

Helix::Utils::Vector2D Helix::Graphics::Sprite::getPosition() const {
    return this->position;
}

int Helix::Graphics::Sprite::getWidth() const {
    return this->width;
}

int Helix::Graphics::Sprite::getHeight() const {
    return this->height;
}

std::pair<int, int> Helix::Graphics::Sprite::getSize() const {
    return std::make_pair(this->width, this->height);
}


// SETTER
void Helix::Graphics::Sprite::setX(const int x) {
    this->position.setX(x);
}

void Helix::Graphics::Sprite::setY(const int y) {
    this->position.setY(y);
}

void Helix::Graphics::Sprite::setPosition(const Helix::Utils::Vector2D & vector) {
    this->position = vector;
}
