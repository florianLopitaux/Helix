#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL.h"
#include "../Vector2D.h"


namespace Helix {
    namespace Utils {
        enum class Shape {EmptySquare, EmptyCircle, FillSquare, FillCircle};

        class Particle {
            private:
                // FIELDS
                Shape shape;
                unsigned size;

                Vector2D position;
                Vector2D velocity;

                SDL_Color color;

                int life;
                int currentLife;

            public:
                // CONSTRUCTORS
                Particle(const Shape & shape, const Vector2D & position, const Vector2D & velocity, const int life, const unsigned size);
                Particle(const Shape & shape, const Vector2D & position, const Vector2D & velocity, const int life, const unsigned size, const SDL_Color & color);

                // GETTERS
                Shape getShape() const;
                unsigned getSize() const;

                int getX() const;
                int getY() const;
                Vector2D getPosition() const;

                int getVelocityX() const;
                int getVelocityY() const;
                Vector2D getVelocity() const;

                SDL_Color getColor() const;

                int getLifeDuree() const;
                int getCurrentLife() const;

                // SETTERS
                void setSize(const unsigned size);
                void setColor(const SDL_Color & color);

                // METHODS
                int update(const Uint32 & deltaTime);
                void draw() const;
        };   
    }
}

#endif
