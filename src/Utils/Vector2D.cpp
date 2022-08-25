#include "Vector2D.h"

#include <math.h>


// CONSTRUCTORS
Helix::Utils::Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

Helix::Utils::Vector2D::Vector2D(const int x, const int y) {
    this->x = x;
    this->y = y;
}


// GETTERS
int Helix::Utils::Vector2D::getX() const {
    return this->x;
}

int Helix::Utils::Vector2D::getY() const {
    return this->y;
}

std::pair<int, int> Helix::Utils::Vector2D::getCoordinate() const {
    return std::make_pair(this->x, this->y);
}


// SETTERS
void Helix::Utils::Vector2D::setX(const int x) {
    this->x = x;
}

void Helix::Utils::Vector2D::setY(const int y) {
    this->y = y;
}

void Helix::Utils::Vector2D::setCoordinate(const int x, const int y) {
    this->x = x;
    this->y = y;
}


// OPERATORS OVERLOADING
Helix::Utils::Vector2D Helix::Utils::Vector2D::operator+(const Helix::Utils::Vector2D & vector) const {
    return Helix::Utils::Vector2D(this->x + vector.getX(), this->y + vector.getY());
}

Helix::Utils::Vector2D Helix::Utils::Vector2D::operator-(const Helix::Utils::Vector2D & vector) const {
    return Helix::Utils::Vector2D(this->x - vector.getX(), this->y - vector.getY());
}

Helix::Utils::Vector2D Helix::Utils::operator*(const int k, const Helix::Utils::Vector2D & vector) {
    return Helix::Utils::Vector2D(k*vector.getX(), k*vector.getY());
}

Helix::Utils::Vector2D Helix::Utils::operator-(const Helix::Utils::Vector2D & vector) {
    return Helix::Utils::Vector2D(-vector.getX(), -vector.getY());
}


// METHODS
int Helix::Utils::Vector2D::norm() const {
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

void Helix::Utils::Vector2D::normalize() {
    int norm = this->norm();

    this->x *= 1 / norm;
    this->y *= 1 / norm;
}
