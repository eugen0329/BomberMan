#include "Managers/Animation.hpp"

Animation::Animation(sprite_t & sprite, int x, int y, int width, int heigth, int nFrames, float speed) : sprite(&sprite)
{

    this->frame = 0;
    this->nFrames = nFrames;
    this->speed = speed;

	for (int i = 0; i < this->nFrames; i++) {
        frames.push_back(sf::IntRect(x + i*width, y, width, heigth));
    }
}

void Animation::update()
{
    if(frame > nFrames) {
        frame -= nFrames;
    }
    frame += speed;
    int i = frame;
    sprite->setTextureRect( frames[i] );
}