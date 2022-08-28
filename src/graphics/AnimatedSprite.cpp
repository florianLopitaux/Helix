#include "AnimatedSprite.h"

#include <iostream>


// Animation struct
bool Helix::Graphics::Animation::operator==(const Helix::Graphics::Animation & other) const {
    return this->startRow == other.startRow && this->startColumn == other.startColumn &&
           this->endRow == other.endRow && this->endColumn == other.endColumn &&
           this->frameDuree == other.frameDuree && this->isRepeating == other.isRepeating;
}


// CONSTRUCTORS
Helix::Graphics::AnimatedSprite::AnimatedSprite(const std::string & imagePath,
                                                const unsigned frameWidth, const unsigned frameHeight)
    : Helix::Graphics::Sprite(imagePath) {

    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;

    this->isFinished = false;
}

Helix::Graphics::AnimatedSprite::AnimatedSprite(const std::string & imagePath, const Utils::Vector2D & position,
                                                const unsigned frameWidth, const unsigned frameHeight)
    : Helix::Graphics::AnimatedSprite(imagePath, frameWidth, frameHeight) {

    this->setPosition(position);
}


// GETTERS
const SDL_Rect& Helix::Graphics::AnimatedSprite::getCurrentSprite() const {
    return this->source;
}

unsigned Helix::Graphics::AnimatedSprite::getFrameWidth() const {
    return this->frameWidth;
}

unsigned Helix::Graphics::AnimatedSprite::getFrameHeight() const {
    return this->frameHeight;
}

std::pair<unsigned, unsigned> Helix::Graphics::AnimatedSprite::getFrameSize() const {
    return std::make_pair(this->frameWidth, this->frameHeight);
}

bool Helix::Graphics::AnimatedSprite::isAnimationFinished() const {
    return this->isFinished;
}


// METHODS
void Helix::Graphics::AnimatedSprite::addNewAnimation(const std::string & name,
                                                      const Helix::Graphics::Animation & animation) {

    this->animations[name] = animation;
}

void Helix::Graphics::AnimatedSprite::launchAnimation(const std::string & animationName) {
    if (animations.find(animationName) == animations.end()) {
        std::cout << "Error ! The animation '" + animationName + "' doesn't exist !" << std::endl;
        return;
    }

    if (this->currentAnimation == animations[animationName]) {
        return;
    }

    this->currentAnimation = animations[animationName];
    this->currentFrameTime = 0;
    this->isFinished = false;

    this->source.x = this->currentAnimation.startColumn * this->frameWidth;
    this->source.y = this->currentAnimation.startRow * this->frameHeight;
    this->source.w = this->frameWidth;
    this->source.h = this->frameHeight;
}

void Helix::Graphics::AnimatedSprite::updateAnimation(const Uint32 & deltaTime) {
    this->currentFrameTime += deltaTime;

    if (this->currentFrameTime >= this->currentAnimation.frameDuree) {
        this->currentFrameTime = 0;
        this->source.x += this->frameWidth;

        if (this->source.x > this->currentAnimation.endColumn * this->frameWidth) {
            this->source.x = this->currentAnimation.startColumn * this->frameWidth;
            this->source.y += this->frameHeight;

            if (this->source.y > this->currentAnimation.endRow * this->frameHeight) {
                if (this->currentAnimation.isRepeating) {
                    this->source.y = this->currentAnimation.startRow * this->frameHeight;

                } else {
                    this->isFinished = true;

                    this->source.x = this->currentAnimation.endColumn * this->frameWidth;
                    this->source.y = this->currentAnimation.endRow * this->frameHeight;
                }
            }
        }
    }
}
