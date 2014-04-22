#ifndef _PLAYERATTRIBUTES_HPP_
#define _PLAYERATTRIBUTES_HPP_

#include <cmath>
#include "Common/Vector2D.hpp"
#include "Game/Attributes/IAttributes.hpp"

class PlayerAttributes : public IAttributes {
public:
    Vector2D<float> v;
    float vMax;
    Vector2D<float> origin;
public:
    PlayerAttributes() {}
    ~PlayerAttributes() {}

};

#endif /* end of include guard: _PLAYERATTRIBUTES_ */
