#ifndef _IATTRIBUTES_HPP_
#define _IATTRIBUTES_HPP_

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Common/BaseShape.hpp"

typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;

class IAttributes : public BaseShape {
public: 
    bool solid;
    int groupID;
public:
    IAttributes(bool solid = true, int groupID = 0) : 
    solid(solid),
    groupID(groupID)
    {}
    ~IAttributes() 
    {}

    inline bool isSolid()
    {
        return solid;
    }
    inline int getGroupID()
    {
        return groupID;
    }
};



#endif /* end of include guard: _IATTRIBUTES_HPP_ */
