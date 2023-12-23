#ifndef _VECTOR2D_H
#define _VECTOR2D_H

#include <iostream>


namespace nsHelix {
    namespace nsMathUtils {
        class Vector2D {
            private:
                // FIELDS
                int x;
                int y;

            public:
                // CONSTRUCTORS
                Vector2D();
                Vector2D(const int x, const int y);
                Vector2D(const std::pair<int, int> & coordinates);

                // GETTERS
                int getX() const;
                int getY() const;
                std::pair<int, int> getCoordinates() const;


                // SETTERS
                void setX(const int x);
                void setY(const int y);
                void setCoordinates(const int x, const int y);
                void setCoordinates(const std::pair<int, int> & coordinates);


                // METHODS
                double norm() const;
                Vector2D & normalize();


                // STATIC METHODS
                static Vector2D zero();
                static Vector2D null();
                static double angleBetween(const Vector2D & v1, const Vector2D & v2);


                // OPERATORS OVERLOADED
                Vector2D operator+(const Vector2D & other) const;
                Vector2D operator-(const Vector2D & other) const;
                Vector2D operator*(const double coefficient) const;
                Vector2D & operator+=(const Vector2D & other);
                Vector2D & operator-=(const Vector2D & other);
                Vector2D & operator*=(const double coefficient);
                bool operator==(const Vector2D & other) const;
        };

        std::ostream & operator<<(std::ostream & stream, const Vector2D & vector);
    }
}

#endif
