/**
 * @file BoxCollider.cpp
 * @author Florian LOPITAUX
 * @brief This file contains the BoxCollider class implementation.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#include "../../include/mathUtils/BoxCollider.h"


/*
* ---------------------------------------------
* CONSTRUCTORS
* ---------------------------------------------
*/

nsHelix::nsMathUtils::BoxCollider::BoxCollider() {}

nsHelix::nsMathUtils::BoxCollider::BoxCollider(const Vector2D & origin, const Vector2D & size) {
    this->origin = origin;
    this->size = size;
}

nsHelix::nsMathUtils::BoxCollider::BoxCollider(const int x, const int y, const unsigned width, const unsigned height) {
    this->origin = Vector2D(x, y);
    this->size = Vector2D(width, height);
}


/*
* ---------------------------------------------
* GETTERS
* ---------------------------------------------
*/

int nsHelix::nsMathUtils::BoxCollider::getX() const {
    return this->origin.getX();
}

int nsHelix::nsMathUtils::BoxCollider::getY() const {
    return this->origin.getY();
}

unsigned nsHelix::nsMathUtils::BoxCollider::getWidth() const {
    return this->size.getX();
}

unsigned nsHelix::nsMathUtils::BoxCollider::getHeight() const {
    return this->size.getY();
}

nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::BoxCollider::getOrigin() const {
    return this->origin;
}

nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::BoxCollider::getSize() const {
    return this->size;
}


/*
* ---------------------------------------------
* SETTERS
* ---------------------------------------------
*/

void nsHelix::nsMathUtils::BoxCollider::setX(const int x) {
    this->origin.setX(x);
}

void nsHelix::nsMathUtils::BoxCollider::setY(const int y) {
    this->origin.setY(y);
}

void nsHelix::nsMathUtils::BoxCollider::setWidth(const unsigned width) {
    this->size.setX(width);
}

void nsHelix::nsMathUtils::BoxCollider::setHeight(const unsigned height) {
    this->size.setY(height);
}

void nsHelix::nsMathUtils::BoxCollider::setOrigin(const int x, const int y) {
    this->origin.setX(x);
    this->origin.setY(y);
}

void nsHelix::nsMathUtils::BoxCollider::setOrigin(const Vector2D & point) {
    this->origin = point;
}

void nsHelix::nsMathUtils::BoxCollider::setSize(const unsigned width, const unsigned height) {
    this->size.setX(width);
    this->size.setY(height);
}

void nsHelix::nsMathUtils::BoxCollider::setSize(const Vector2D & size) {
    this->size = size;
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/

bool nsHelix::nsMathUtils::BoxCollider::isCollideWith(const BoxCollider & other) const {
    return this->origin.getX() < other.getX() + other.getWidth() &&
        this->origin.getX() + this->size.getX() >= other.getX() &&
        this->origin.getY() < other.getY() + other.getHeight() &&
        this->origin.getY() + this->size.getY() >= other.getY();
}


/*
* ---------------------------------------------
* OPERATORS OVERLOADED
* ---------------------------------------------
*/

std::ostream & nsHelix::nsMathUtils::operator<<(std::ostream & stream, const nsHelix::nsMathUtils::BoxCollider & rect) {
    stream << "BoxCollider(" << rect.getX() << ',' << rect.getY() << ',' << rect.getWidth() << ',' << rect.getHeight() << ')';
    return stream;
}
