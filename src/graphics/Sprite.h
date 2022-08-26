#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "SDL.h"
#include "../utils/Vector2D.h"

namespace Helix {
    namespace Graphics {
        class Sprite {
            private:
                // FIELDS
                SDL_Texture *texture;
                Utils::Vector2D position;
                int width, height;

            public:
                // CONSTRUCTORS
                Sprite(const std::string & imagePath);
                Sprite(const std::string & imagePath, const Utils::Vector2D & position);

                // DESTRUCTOR
                ~Sprite();

                // GETTERS
                SDL_Texture* getTexture() const;
                Utils::Vector2D getPosition() const;
                int getWidth() const;
                int getHeight() const;
                std::pair<int, int> getSize() const;

                // SETTER
                void setPosition(const Utils::Vector2D & vector);
        };
    }
}


#endif
