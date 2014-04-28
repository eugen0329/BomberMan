#ifndef _COLLISION_HPP_
#define _COLLISION_HPP_

#include "Game/Attributes/IAttributes.hpp"

class Collision {
public:
    IAttributes secWObjectAttributes;
    
    Collision(IAttributes& secWObjectAttributes) : 
    secWObjectAttributes(secWObjectAttributes) 
    {}
    ~Collision() 
    {}
    
};

#endif /* end of include guard: _COLLISION_HPP_ */