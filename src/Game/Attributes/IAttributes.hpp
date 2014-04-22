#ifndef _IATTRIBUTES_HPP_
#define _IATTRIBUTES_HPP_

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Common/BaseShape.hpp"

typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;

class IAttributes : public BaseShape {
public:
    texture_t texture;
    sprite_t  sprite;
    
    bool solid;
public:
    IAttributes(bool solid = true) : solid(solid) {}
    ~IAttributes() {}

    inline bool isSolid()
    {
        return solid;
    }
};



#endif /* end of include guard: _IATTRIBUTES_HPP_ */
