#ifndef _WALLATTRIBUTES_HPP_
#define _WALLATTRIBUTES_HPP_

#include "Common/Vector2D.hpp"
#include "Game/Attributes/IAttributes.hpp"

class WallAttributes : public IAttributes{
public:
    texture_t texture;
    sprite_t  sprite;
    
    Vector2D<float> origin;
};



#endif /* end of include guard: _WALLATTRIBUTES_HPP_ */
