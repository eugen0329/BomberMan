#ifndef _OBJECTPROPERTIES_HPP_
#define _OBJECTPROPERTIES_HPP_

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Vector2D.hpp"

class Coordinates2D;
class ObjectProperties;
typedef ObjectProperties properties_t;
typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;


class ObjectProperties {
public:
    Vector2D<size_t> pos;
    size_t step;

    texture_t texture;
    sprite_t sprite;
    size_t   width;
    size_t   heigth;
};

#endif /* end of include guard: _OBJECTPROPERTIES_HPP_ */
