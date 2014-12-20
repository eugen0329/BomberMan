#ifndef _FIREATTRIBUTES_HPP_
#define _FIREATTRIBUTES_HPP_

#include "Common/Vec2.hpp"
#include "Game/Attributes/IAttributes.hpp"

class FireAttributes : public IAttributes {
public:
    Vec2<float> origin;
    float lifeTime;
    float actLifeTime;

    int damage;

    texture_t texture;
    sprite_t  sprite;
public:
    FireAttributes() {}
    ~FireAttributes() {}
};

#endif /* end of include guard: _FIREATTRIBUTES_HPP_*/
