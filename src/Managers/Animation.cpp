#include "Managers/Animation.hpp"

Animation::Animation(sprite_t & sprite, int x, int y, int width, int heigth, int nFrames, float msecToFrame) 
{

    this->sprite = &sprite;
    this->frameIndex = 0;
    this->nFrames = nFrames;
    this->msecToFrame =  msecToFrame;
	this->passedMSec = 0;

	for (int i = 0; i < this->nFrames; i++) {
        frames.push_back(sf::IntRect(x + i*width, y, width, heigth));
    }
}
Animation::~Animation()
{
	frames.clear();
}