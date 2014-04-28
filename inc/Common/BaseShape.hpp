#ifndef _BASESHAPE_HPP_
#define _BASESHAPE_HPP_

#include "Common/Vector2D.hpp"
#include "Common/Angle.hpp"

class BaseShape {
public:
    BaseShape() {}
    ~BaseShape() {}

    Vector2D<float> pos;

    float    width;
    float    heigth;

    Angle angle;
};


#endif /* end of include guard: _BASESHAPE_HPP_ */
