#include "Particle.h"

#include "../../Helix.h"


// CONSTRUCTORS
Helix::Utils::Particle::Particle(const Shape & shape,
                                 const Helix::Utils::Vector2D & position, const Helix::Utils::Vector2D & velocity,
                                 const int life, const unsigned size) {

    this->shape = shape;
    this->size = size;

    this->position = position;
    this->velocity = velocity;

    this->life, this->currentLife = life;
    
    SDL_Color randomColor = {};
    randomColor.r = rand() % 256;
    randomColor.g = rand() % 256;
    randomColor.b = rand() % 256;
    randomColor.a = 255;

    this->color = randomColor;
}

Helix::Utils::Particle::Particle(const Shape & shape,
                                 const Helix::Utils::Vector2D & position, const Helix::Utils::Vector2D & velocity,
                                 const int life, const unsigned size, const SDL_Color & color)
    : Helix::Utils::Particle(shape, position, velocity, life, size){

    this->color = color;
}


// GETTERS
Helix::Utils::Shape Helix::Utils::Particle::getShape() const {
    return this->shape;
}

unsigned Helix::Utils::Particle::getSize() const {
    return this->size;
}

int Helix::Utils::Particle::getX() const {
    return this->position.getX();
}

int Helix::Utils::Particle::getY() const {
    return this->position.getY();
}

Helix::Utils::Vector2D Helix::Utils::Particle::getPosition() const {
    return this->position;
}

int Helix::Utils::Particle::getVelocityX() const {
    return this->velocity.getX();
}

int Helix::Utils::Particle::getVelocityY() const {
    return this->velocity.getY();
}

Helix::Utils::Vector2D Helix::Utils::Particle::getVelocity() const {
    return this->velocity;
}

SDL_Color Helix::Utils::Particle::getColor() const {
    return this->color;
}

int Helix::Utils::Particle::getLifeDuree() const {
    return this->life;
}

int Helix::Utils::Particle::getCurrentLife() const {
    return this->currentLife;
}


// SETTERS
void Helix::Utils::Particle::setSize(const unsigned size) {
    this->size = size;
}

void Helix::Utils::Particle::setColor(const SDL_Color & color) {
    this->color = color;
}


// METHODS
int Helix::Utils::Particle::update(const Uint32 & deltaTime) {
    this->position += this->velocity;
    this->currentLife -= deltaTime;

    if (this->currentLife <= 0) {
        return -1;
    }

    this->color.a = 255 * (this->currentLife / this->life);
}

void Helix::Utils::Particle::draw() const {
    switch (this->shape) {
        case Shape::EmptySquare:
            Helix::Graphics::drawEmptyRectangle(this->position, this->size, this->size);
            break;

        case Shape::EmptyCircle:
            Helix::Graphics::drawEmptyCircle(this->position, this->size, 0.8);
            break;

        case Shape::FillSquare:
            Helix::Graphics::drawFillRectangle(this->position, this->size, this->size);
            break;
        
        case Shape::FillCircle:
            Helix::Graphics::drawFillCircle(this->position, this->size);
            break;

        default:
            break;
    }
}
