#ifndef _BOX_COLLIDER_H
#define _BOX_COLLIDER_H

#include "Vector2D.h"


namespace nsHelix {
    namespace nsMathUtils {
        class BoxCollider {
            private:
                // FIELDS
                Vector2D origin;
                Vector2D size;

            public:
                // CONSTRUCTORS
                BoxCollider();
                BoxCollider(const Vector2D & origin, const Vector2D & size);
                BoxCollider(const int x, const int y, const unsigned width, const unsigned height);


                // GETTERS
                int getX() const;
                int getY() const;
                unsigned getWidth() const;
                unsigned getHeight() const;
                Vector2D getOrigin() const;
                Vector2D getSize() const;


                // SETTERS
                void setX(const int x);
                void setY(const int y);
                void setWidth(const unsigned width);
                void setHeight(const unsigned height);
                void setOrigin(const int x, const int y);
                void setOrigin(const Vector2D & point);
                void setSize(const unsigned width, const unsigned height);
                void setSize(const Vector2D & size);


                // METHODS
                bool isCollideWith(const BoxCollider & other) const;
        };

        // OPERATORS OVERLOADED
        std::ostream & operator<<(std::ostream & stream, const BoxCollider & rect);
    }
}

#endif
