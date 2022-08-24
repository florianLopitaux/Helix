#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "../Helix.h"


namespace Helix {
    class Sprite
    {
        private:
            // FIELDS
            SDL_Texture *texture;
            Vector2D position;

        public:
            // CONSTRUCTORS
            Sprite(const std::string & imagePath);
            Sprite(const std::string & imagePath, const Vector2D & position);

            // DESTRUCTOR
            ~Sprite();

            // GETTERS
            SDL_Texture* getTexture() const;
            Vector2D getPosition() const;

            // SETTER
            void setPosition(const Vector2D & vector);
    };    
}


#endif
