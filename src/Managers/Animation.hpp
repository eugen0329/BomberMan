#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

typedef sf::Sprite sprite_t;

class Animation {
private:
	std::vector<sf::IntRect> frames;
	int nFrames;
	float speed;
	float frame;

	sprite_t * sprite;
public:
    Animation(sprite_t & sprite, int x, int y, int width, int heigth, int nFrames, float speed = 0.1);
    ~Animation();

    void update();
    inline void resetFrameNumber()
    {
    	frame = 0;
    }
};

#endif /* end of include guard: _ANIMATION_HPP_ */
