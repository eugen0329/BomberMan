#ifndef _BASESHAPE_HPP_
#define _BASESHAPE_HPP_

#include "Common/Vec2.hpp"
#include "Common/Angle.hpp"

class BaseShape {
public:
    BaseShape() {}
    ~BaseShape() {}

    Vec2<float> pos;

    float    width;
    float    heigth;

    Angle angle;
};


#endif /* end of include guard: _BASESHAPE_HPP_ */
