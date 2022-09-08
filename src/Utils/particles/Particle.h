#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL.h"
#include "../Vector2D.h"


namespace Helix {
    namespace Utils {
        class Particle {
            private:
                // FIELDS
                Vector2D position;
                Vector2D velocity;
                SDL_Color color;
                int life;
                int currentLife;

            public:
                // CONSTRUCTORS
                Particle(const Vector2D & position, const Vector2D & velocity, const int life);
                Particle(const Vector2D & position, const Vector2D & velocity, const int life, const SDL_Color & color);

                // GETTERS
                int getX() const;
                int getY() const;
                Vector2D getPosition() const;

                int getVelocityX() const;
                int getVelocityY() const;
                Vector2D getVelocity() const;

                SDL_Color getColor() const;
                int getLifeDuree() const;
                int getCurrentLife() const;

                // METHODS
                int update(const Uint32 & deltaTime);
                virtual void draw() const;
        };   
    }
}

#endif
