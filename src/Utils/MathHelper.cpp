#include "MathHelper.h"

#include <math.h>


float Helix::Utils::distance(const Vector2D & pos1, const Vector2D & pos2,
                                const unsigned exponent, const unsigned coefX, const unsigned coefY) {
    
    const int distanceX = pow(abs((int)coefX * (pos1.getX() - pos2.getX())), exponent);
    const int distanceY = pow(abs((int)coefY * (pos1.getY() - pos2.getY())), exponent);

    return pow(distanceX + distanceY, 1/(float)exponent);
}


float Helix::Utils::ManathanDistance(const Vector2D & pos1, const Vector2D & pos2) {
    return distance(pos1, pos2, 1, 1, 1);
}

float Helix::Utils::euclideanDistance(const Vector2D & pos1, const Vector2D & pos2) {
    return distance(pos1, pos2, 2, 1, 1);
}
