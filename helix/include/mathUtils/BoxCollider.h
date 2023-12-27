/**
 * @file BoxCollider.h
 * @author Florian LOPITAUX
 * @brief This file contains the BoxCollider class declaration.
 * @version 1.0
 * @date 2023
 * @copyright GNU public License
*/

#ifndef _BOX_COLLIDER_H
#define _BOX_COLLIDER_H

#include "Vector2D.h"


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
         * @class BoxCollider "mathUtils/BoxCollider.h"
         * @brief Class to manage rectangle collision between objects.
        */
        class BoxCollider {

            private:
                // FIELDS
                /** @brief The top-left point of the rectangle. */
                Vector2D origin;

                /** @brief The size of the rectangle. */
                Vector2D size;


            public:
                // CONSTRUCTORS
                /**
                 * Create an empty rectangle at the (0, 0) position of the screen.
                */
                BoxCollider();

                /**
                 * Create a rectangle box with a given origin point and size.
                 * 
                 * @param origin The coordinates of the top-left point of the rectangle
                 * @param size The size (width and height) of the rectangle
                */
                BoxCollider(const Vector2D & origin, const Vector2D & size);

                /**
                 * Create a rectangle box with all variables passed as parameter.
                 * 
                 * @param x The abscissa of the origin point
                 * @param y The ordinate of the origin point
                 * @param width The width of the rectangle
                 * @param height The height of the rectangle
                */
                BoxCollider(const int x, const int y, const unsigned width, const unsigned height);



                // GETTERS
                /**
                 * Getter method of the 'origin.x' attribute.
                 * 
                 * @return The abscissa value of the top-left point of the rectangle
                */
                int getX() const;

                /**
                 * Getter method of the 'origin.y' attribute.
                 * 
                 * @return The ordinate value of the top-left point of the rectangle
                */
                int getY() const;

                /**
                 * Getter method of the 'size.x' attribute.
                 * 
                 * @return The width of the rectangle
                */
                unsigned getWidth() const;

                /**
                 * Getter method of the 'size.y' attribute.
                 * 
                 * @return The height of the rectangle
                */
                unsigned getHeight() const;

                /**
                 * Getter method of the 'origin' attribute.
                 * 
                 * @return The top-left point of the rectangle
                */
                Vector2D getOrigin() const;

                /**
                 * Getter method of the 'size' attribute.
                 * 
                 * @return The size (width and height) of the rectangle
                */
                Vector2D getSize() const;



                // SETTERS
                /**
                 * Setter method of the 'origin.x' attribute.
                 * 
                 * @param x The new abscissa value of the top-left point of the rectangle
                */
                void setX(const int x);

                /**
                 * Setter method of the 'origin.y' attribute.
                 * 
                 * @param x The new ordinate value of the top-left point of the rectangle
                */
                void setY(const int y);

                /**
                 * Setter method of the 'size.x' attribute.
                 * 
                 * @param x The new width value of the rectangle
                */
                void setWidth(const unsigned width);

                /**
                 * Setter method of the 'size.y' attribute.
                 * 
                 * @param x The new height value of the rectangle
                */
                void setHeight(const unsigned height);

                /**
                 * Setter method of the 'origin' attribute.
                 * 
                 * @param x The new abscissa value of the top-left point of the rectangle
                 * @param y The new ordinate value of the top-left point of the rectangle
                */
                void setOrigin(const int x, const int y);

                /**
                 * Setter method of the 'origin' attribute.
                 * 
                 * @param point The new top-left point of the rectangle
                */
                void setOrigin(const Vector2D & point);

                /**
                 * Setter method of the 'size' attribute.
                 * 
                 * @param x The new width value of the rectangle
                 * @param y The new height value of the rectangle
                */
                void setSize(const unsigned width, const unsigned height);

                /**
                 * Setter method of the 'size' attribute.
                 * 
                 * @param size The new size (width and height) of the rectangle
                */
                void setSize(const Vector2D & size);



                // PUBLIC METHODS
                /**
                 * Check if this box collides with an other box.
                 * The method used is the AABB (Axis-Aligned Bounding Box) algorithm.
                 * 
                 * @param other The other box to check if they collide
                 * 
                 * @return True if they collide or false else.
                */
                bool isCollideWith(const BoxCollider & other) const;
        };

        /**
         * ToString function for BoxCollider objects.
         * Send to the stream a string format of a rectangle box object.
         * 
         * @param stream The stream to add the string format object
         * @param rect The rectangle box to convert to a string
         * 
         * @return The stream with the object string format added
        */
        std::ostream & operator<<(std::ostream & stream, const BoxCollider & rect);
    }
}

#endif
