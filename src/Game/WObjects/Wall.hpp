#ifndef _WALL_HPP_
#define _WALL_HPP_

#include "Common/Interfaces/IInitializer.hpp"

#include "Game/WObjects/Item.hpp"
#include "Game/Attributes/WallAttributes.hpp"

class Wall : public Item {
private:
    class Initializer;

    WallAttributes attrib;
public:
    Wall();
    Wall(xmlElement_t&);
    virtual ~Wall() {}
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IAttributes getAttributes() 
    {
        return attrib;
    }

};

class Wall::Initializer : public IInitializer {
private:
    mutable WallAttributes* attrib; 
public:
    Initializer();
    Initializer(xmlElement_t&, WallAttributes&);
    virtual ~Initializer();
    
    int load() const;
    
};

#endif /* end of include guard: _WALL_HPP_ */
