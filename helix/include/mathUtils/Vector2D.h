/**
 * @file Vector2D.h
 * @author Florian LOPITAUX
 * @brief This file contains the Vector2D class declaration.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#ifndef _VECTOR2D_H
#define _VECTOR2D_H

#include <iostream>


/**
 * @namespace nsHelix
 * @brief Base namespace that contains all contents of the Helix library.
*/
namespace nsHelix {

    /**
     * @namespace nsMathUtils
     * @brief Sub-namesapce that contains about mathematics like vector, collision, interpolation...
    */
    namespace nsMathUtils {

        /**
         * @class Vector2D "mathUtils/Vector2D.h"
         * @brief Class to manipulate 2 dimensional vectors (x and y) in orthogonal plan.
        */
        class Vector2D {

            private:
                // FIELDS
                /** @brief The abscissa value. */
                int x;

                /** @brief The ordinate value. */
                int y;



            public:
                // CONSTRUCTORS
                /**
                 * Create a Vector2D with values set to zero (0, 0).
                */
                Vector2D();

                /**
                 * Create a Vector2D with given values (x, y).
                 * 
                 * @param x the abscissa value of the vector
                 * @param y the ordinate value of the vector
                */
                Vector2D(const int x, const int y);

                /**
                 * Create a Vector2D with given pair of integers.
                 * 
                 * @param coordinates the pair of integers that contains the abscissa and ordinate
                */
                Vector2D(const std::pair<int, int> & coordinates);



                // GETTERS
                /**
                 * Getter method of the 'x' attribute.
                 * 
                 * @return the abscissa value of the vector
                */
                int getX() const;

                /**
                 * Getter method of the 'y' attribute.
                 * 
                 * @return the ordinate value of the vector
                */
                int getY() const;

                /**
                 * Getter method of the both attributes (x and y).
                 * 
                 * @return the abscissa and ordinate value of the vector
                */
                std::pair<int, int> getCoordinates() const;



                // SETTERS
                /**
                 * Setter method of the 'x' attribute.
                 * 
                 * @param x the new abscissa value of the vector
                */
                void setX(const int x);

                /**
                 * Setter method of the 'y' attribute.
                 * 
                 * @param y the new ordinate value of the vector
                */
                void setY(const int y);

                /**
                 * Setter method of the both attributes (x and y).
                 * 
                 * @param x the new abscissa value of the vector
                 * @param y the new ordinate value of the vector
                */
                void setCoordinates(const int x, const int y);

                /**
                 * Setter method of the both attributes (x and y).
                 * 
                 * @param coordinates a pair of integers that contains the abscissa and the ordinate
                */
                void setCoordinates(const std::pair<int, int> & coordinates);



                // PUBLIC METHODS
                /**
                 * Compute the norm of the vector.
                 * 
                 * @return the norm value
                */
                double norm() const;

                /**
                 * Transform the vector to normalized it.
                 * 
                 * @return The reference of this object after the normalization
                */
                Vector2D & normalize();



                // STATIC METHODS
                /**
                 * Compute the angle (in radians) between two given vectors.
                 * 
                 * @param v1 the first vector
                 * @param v2 the second vector
                 * 
                 * @return the computed angle
                */
                static double angleBetween(const Vector2D & v1, const Vector2D & v2);



                // OPERATORS OVERLOADED
                /**
                 * Compute the addition of this vector and an other.
                 * x' = x1 + x2
                 * y' = y1 + y2
                 * 
                 * @param other the second vector to add at this object
                 * 
                 * @return The result of the addition
                */
                Vector2D operator+(const Vector2D & other) const;

                /**
                 * Compute the substraction of this vector and an other.
                 * x' = x1 - x2
                 * y' = y1 - y2
                 * 
                 * @param other the second vector to sub at this object
                 * 
                 * @return The result of the substraction
                */
                Vector2D operator-(const Vector2D & other) const;

                /**
                 * Compute the product if this object with a given coefficient.
                 * x' = k*x
                 * y' = k*y
                 * 
                 * @param coefficient the coefficient (a real number) to multiply at this object
                 * 
                 * @return The result of the product
                */
                Vector2D operator*(const double coefficient) const;

                /**
                 * Add an other vector to this object.
                 * x1 = x1 + x2
                 * y1 = y1 + y2
                 * 
                 * @param other The other vector to add
                 * 
                 * @return The reference of this object after the addition
                */
                Vector2D & operator+=(const Vector2D & other);

                /**
                 * Substract an other vector to this object.
                 * x1 = x1 - x2
                 * y1 = y1 - y2
                 * 
                 * @param other The other vector to substract
                 * 
                 * @return The reference of this object after the substraction
                */
                Vector2D & operator-=(const Vector2D & other);

                /**
                 * Multiply this vector by a given coefficient.
                 * x = k*x
                 * y = k*y
                 * 
                 * @param coefficient the coefficient (a real number) to multiply at this object
                 * 
                 * @return The reference of this object after the product
                */
                Vector2D & operator*=(const double coefficient);

                /**
                 * Compare two vectors and check if they are equal.
                 * x == x && y == y
                 * 
                 * @param other The other vector to compare
                 * 
                 * @return True if they are equal or false else
                */
                bool operator==(const Vector2D & other) const;
        };

        /**
         * ToString function for Vector2D objects.
         * Send to the stream a string format of a vector object.
         * 
         * @param stream The stream to add the string format object
         * @param vector The vector to convert to a string
         * 
         * @return The stream with the object string format added
        */
        std::ostream & operator<<(std::ostream & stream, const Vector2D & vector);
    }
}

#endif
