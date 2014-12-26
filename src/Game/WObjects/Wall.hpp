#ifndef _WALL_HPP_
#define _WALL_HPP_

#include "Common/BasicTypes.hpp"
#include "Common/Algorithms.hpp"
#include "Game/WObjects/Item.hpp"



class Wall : public Item {
protected:
    struct  Attributes : public Item::Attributes {
        texture_t texture;
        sprite_t  sprite;
        Vec2<float> origin;
    };
    class Initializer;

    Wall::Attributes attr;
public:
    Wall();
    Wall(xmlElem_t&);
    virtual ~Wall() {}
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IWorldsObject::Attributes& getAttr() 
    {
        return attr;
    }

    void load(xmlElem_t&);

    virtual void addCollision(Collision); 
    
    virtual void setWorldObjects(WObjects&);

};


#endif /* end of include guard: _WALL_HPP_ */
