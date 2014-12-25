#include "Rendering/Animation.hpp"

Animation::Animation(sprite_t & sprite, int x, int y, int width, int heigth, int offset, int nFrames, float timeToFrame) 
{
    this->sprite = &sprite;
    this->frameIndex = 0; 
    this->nFrames = nFrames; 
    this->timeToFrame =  timeToFrame;
	this->passedMSec = 0;

	for (int i = 0; i < nFrames; i++) {  
        frames.push_back(sf::IntRect(x + i*offset, y, width, heigth));
    }
    this->sprite->setTextureRect(frames[0]);
}

Animation::~Animation()
{
	frames.clear();
}
