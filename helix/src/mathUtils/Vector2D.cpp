#include "../../include/mathUtils/Vector2D.h"

#include <math.h>


/*
* ---------------------------------------------
* CONSTRUCTORS
* ---------------------------------------------
*/
nsHelix::nsMathUtils::Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

nsHelix::nsMathUtils::Vector2D::Vector2D(const int x, const int y) {
    this->x = x;
    this->y = y;
}

nsHelix::nsMathUtils::Vector2D::Vector2D(const std::pair<int, int> & coordinates) {
    this->x = x;
    this->y = y;
}


/*
* ---------------------------------------------
* GETTERS
* ---------------------------------------------
*/
int nsHelix::nsMathUtils::Vector2D::getX() const {
    return this->x;
}

int nsHelix::nsMathUtils::Vector2D::getY() const {
    return this->y;
}

std::pair<int, int> nsHelix::nsMathUtils::Vector2D::getCoordinates() const {
    return std::make_pair(this->x, this->y);
}


/*
* ---------------------------------------------
* SETTERS
* ---------------------------------------------
*/
void nsHelix::nsMathUtils::Vector2D::setX(const int x) {
    this->x = x;
}

void nsHelix::nsMathUtils::Vector2D::setY(const int y) {
    this->y = y;
}

void nsHelix::nsMathUtils::Vector2D::setCoordinates(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void nsHelix::nsMathUtils::Vector2D::setCoordinates(const std::pair<int, int> & coordinates) {
    this->x = coordinates.first;
    this->y = coordinates.second;
}


/*
* ---------------------------------------------
* PUBLIC METHODS
* ---------------------------------------------
*/
double nsHelix::nsMathUtils::Vector2D::norm() const {
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

nsHelix::nsMathUtils::Vector2D & nsHelix::nsMathUtils::Vector2D::normalize() {
    const double norm = this->norm();

    this->x *= 1/norm;
    this->y *= 1/norm;

    return *this;
}


/*
* ---------------------------------------------
* OPERATORS OVERLOADED
* ---------------------------------------------
*/
nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::Vector2D::operator+(const Vector2D & other) const {
    const int x = this->x + other.x;
    const int y = this->y + other.y;

    return Vector2D(x, y);
}

nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::Vector2D::operator-(const Vector2D & other) const {
    const int x = this->x - other.x;
    const int y = this->y - other.y;

    return Vector2D(x, y);
}

nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::Vector2D::operator*(const double coefficient) const {
    const int x = this->x * coefficient;
    const int y = this->y * coefficient;

    return Vector2D(x, y);
}

nsHelix::nsMathUtils::Vector2D & nsHelix::nsMathUtils::Vector2D::operator+=(const Vector2D & other) {
    this->x += other.x;
    this->y += other.y;

    return *this;
}

nsHelix::nsMathUtils::Vector2D & nsHelix::nsMathUtils::Vector2D::operator-=(const Vector2D & other) {
    this->x -= other.x;
    this->y -= other.y;

    return *this;
}

nsHelix::nsMathUtils::Vector2D & nsHelix::nsMathUtils::Vector2D::operator*=(const double coefficient) {
    this->x = round(this->x * coefficient);
    this->y = round(this->y * coefficient);

    return *this;
}

bool nsHelix::nsMathUtils::Vector2D::operator==(const Vector2D & other) const {
    return this->x == other.x && this->y == other.y;
}

std::ostream & nsHelix::nsMathUtils::operator<<(std::ostream & stream, const nsHelix::nsMathUtils::Vector2D & vector) {
    stream << "Vector2D(" << vector.getX() << ',' << vector.getY() << ')';
    return stream;
}


/*
* ---------------------------------------------
* STATIC METHODS
* ---------------------------------------------
*/
nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::Vector2D::zero() {
    return Vector2D(0, 0);
}

nsHelix::nsMathUtils::Vector2D nsHelix::nsMathUtils::Vector2D::null() {
    return Vector2D(1, 1);
}

double nsHelix::nsMathUtils::Vector2D::angleBetween(const Vector2D & v1, const Vector2D & v2) {
    const int topNumber = v1.x*v2.x + v1.y*v2.y;
    const double bottomNumber = v1.norm() * v2.norm();

    return acos(topNumber / bottomNumber);
}
