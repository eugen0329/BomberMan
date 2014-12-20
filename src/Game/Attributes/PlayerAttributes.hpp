#ifndef _PLAYERATTRIBUTES_HPP_
#define _PLAYERATTRIBUTES_HPP_

#include <cmath>
#include "Common/Vec2.hpp"
#include "Game/Attributes/IAttributes.hpp"

class PlayerAttributes : public IAttributes {
public:
    Vec2<float> v;
    float vMax;
    Vec2<float> origin;

    texture_t texture;
    sprite_t  sprite;
public:
    PlayerAttributes() {}
    ~PlayerAttributes() {}

};

#endif /* end of include guard: _PLAYERATTRIBUTES_ */
