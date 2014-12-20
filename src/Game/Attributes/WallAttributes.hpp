#ifndef _WALLATTRIBUTES_HPP_
#define _WALLATTRIBUTES_HPP_

#include "Common/Vec2.hpp"
#include "Game/Attributes/IAttributes.hpp"

class WallAttributes : public IAttributes{
public:
    texture_t texture;
    sprite_t  sprite;
    
    Vec2<float> origin;
};



#endif /* end of include guard: _WALLATTRIBUTES_HPP_ */
