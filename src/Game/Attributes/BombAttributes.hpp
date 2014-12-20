#ifndef _BOMBATTRIBUTES_HPP_
#define _BOMBATTRIBUTES_HPP_

#include "Common/Vec2.hpp"
#include "Game/Attributes/IAttributes.hpp"

class BombAttributes : public IAttributes {
public:
    Vec2<float> origin;
    float lifeTime;
    float actLifeTime;

    texture_t texture;
    sprite_t  sprite;
public:
    BombAttributes() {}
    ~BombAttributes() {}
};

#endif /* end of include guard: _BOMBATTRIBUTES_HPP_ */
