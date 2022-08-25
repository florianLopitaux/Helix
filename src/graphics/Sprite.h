#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "../Helix.h"


namespace Helix {
    namespace Graphics {
        class Sprite
        {
            private:
                // FIELDS
                SDL_Texture *texture;
                Utils::Vector2D position;

            public:
                // CONSTRUCTORS
                Sprite(const std::string & imagePath);
                Sprite(const std::string & imagePath, const Utils::Vector2D & position);

                // DESTRUCTOR
                ~Sprite();

                // GETTERS
                SDL_Texture* getTexture() const;
                Utils::Vector2D getPosition() const;

                // SETTER
                void setPosition(const Utils::Vector2D & vector);
        };
    }
}


#endif
