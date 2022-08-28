#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>

#include "Sprite.h"


namespace Helix {
    namespace Graphics {
        struct Animation {
            unsigned startRow, startColumn, endRow, endColumn;
            float frameDuree;
            bool isRepeating;

            bool operator==(const Animation & other) const;
        };

        class AnimatedSprite : public Sprite {
            private:
                // FIELDS
                SDL_Rect source;
                unsigned frameWidth, frameHeight;

                std::map<std::string, Animation> animations;
                Animation currentAnimation;
                Uint32 currentFrameTime;
                bool isFinished;

            public:
                // CONSTRUCTORS
                AnimatedSprite(const std::string & imagePath, const unsigned frameWidth, const unsigned frameHeight);
                AnimatedSprite(const std::string & imagePath, const Utils::Vector2D & position, const unsigned frameWidth, const unsigned frameHeight);
        
                // GETTERS
                const SDL_Rect& getCurrentSprite() const;

                unsigned getFrameWidth() const;
                unsigned getFrameHeight() const;
                std::pair<unsigned, unsigned> getFrameSize() const;

                bool isAnimationFinished() const;

                // METHODS
                void addNewAnimation(const std::string & name, const Animation & animation);
                void launchAnimation(const std::string & animationName);
                void updateAnimation(const Uint32 & deltaTime);
        };
    }
}

#endif
