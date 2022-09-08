#ifndef MATH_HELPER_H
#define MATH_HELPER_H

#include "Vector2D.h"


namespace Helix {
    namespace Utils {
        float distance(const Vector2D & pos1, const Vector2D & pos2,
                          const unsigned exponent, const unsigned coefX, const unsigned coefY);

        float ManathanDistance(const Vector2D & pos1, const Vector2D & pos2);             
        float euclideanDistance(const Vector2D & pos1, const Vector2D & pos2);
    }
}

#endif
