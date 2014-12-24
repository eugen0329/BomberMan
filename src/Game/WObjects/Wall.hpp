#ifndef _WALL_HPP_
#define _WALL_HPP_

#include "Common/Interfaces/IInitializer.hpp"
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

    virtual void addCollision(Collision); 
    
    virtual void setWorldObjects(wObjects_t&);

};

class Wall::Initializer : public IInitializer {
private:
    mutable Wall::Attributes* attr; 
public:
    Initializer();
    Initializer(xmlElem_t&, Wall::Attributes&);
    virtual ~Initializer();
    
    int load() const;
    
};

#endif /* end of include guard: _WALL_HPP_ */
