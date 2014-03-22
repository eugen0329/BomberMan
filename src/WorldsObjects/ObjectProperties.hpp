#ifndef _OBJECTPROPERTIES_HPP_
#define _OBJECTPROPERTIES_HPP_

#include <cstdlib>
#include "SFML/Graphics.hpp"

class ObjectProperties;
typedef ObjectProperties properties_t;
typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;


class ObjectProperties {
public:
    size_t x;
    size_t y;
    size_t step;

    texture_t texture;
    sprite_t sprite;
};


#endif /* end of include guard: _OBJECTPROPERTIES_HPP_ */
