#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <utility>


namespace Helix {
    namespace Utils {
        class Vector2D {
            private:
                // FIELDS
                int x;
                int y;

            public:
                // CONSTRUCTORS
                Vector2D();
                Vector2D(const int x, const int y);

                // GETTERS
                int getX() const;
                int getY() const;
                std::pair<int, int> getCoordinate() const;

                // SETTERS
                void setX(const int x);
                void setY(const int y);
                void setCoordinate(const int x, const int y);

                // MEMBER OPERATORS OVERLOADING
                Vector2D operator+(const Vector2D & vector) const;
                Vector2D operator+=(const Vector2D & vector);
                Vector2D operator-(const Vector2D & vector) const;
                Vector2D operator-=(const Vector2D & vector);

                // METHODS
                int norm() const;
                void normalize();
        };

        // NON-MEMBER OPERATORS OVERLOADING
        Vector2D operator*(const int k, const Vector2D & vector); // scalar product
        Vector2D operator-(const Vector2D & vector); // opposite
    }
}

#endif
