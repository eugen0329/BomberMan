#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <iostream>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

typedef sf::Sprite sprite_t;

class Animation {
private:
	std::vector<sf::IntRect> frames;
	float nFrames;
	unsigned int frameIndex;
	float msecToFrame;
    float passedMSec;
    int counter;

	sprite_t * sprite;
public:
    Animation(sprite_t & sprite, int x, int y, int width, int heigth, int nFrames, float msecToFrame = 100);
    ~Animation();

    inline void update(float dt)
    {
        passedMSec += dt;
        if(passedMSec >= msecToFrame ) {
            if(frameIndex + 1 < frames.size()) {
                frameIndex++;
            } else {
                frameIndex = 0;
            }
            passedMSec = 0;
        }
        //int i = floor(frame);
        std::cout << frameIndex << ", ";
        sprite->setTextureRect( frames[frameIndex] );
    }

    inline void resetFrameIndex()
    {
    	frameIndex = 0;
    }
};

#endif /* end of include guard: _ANIMATION_HPP_ */
