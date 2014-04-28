#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include "XMLParser/tinyxml.h"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Vector2D.hpp"

#include "Game/Attributes/IAttributes.hpp"
#include "Game/Attributes/BombAttributes.hpp" 
#include "Game/WObjects/Item.hpp"

//#include "Game/GameLevel.hpp"

class Bomb : public Item {
private:
    class Initializer;

    BombAttributes attrib;
    Delegate delCollisionExclude;
public:
    Bomb();
    //Bomb(xmlElement_t& xmlElement, int groupID = 0);

    Bomb(const IAttributes&);
    Bomb(xmlElement_t&, const IAttributes&);
    virtual ~Bomb();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IAttributes& getAttributes() 
    {
        return attrib;
    }

    virtual void addCollision(Collision);
    virtual void handleCollisions();
    virtual void checkCollisions();

    virtual void setSignal(Delegate*, std::string);

    virtual void setWorldsObjectsVector(wObjects_t&);

};

class Bomb::Initializer : public IInitializer {
private:
    mutable BombAttributes* attrib; 
public:
    Initializer();
    Initializer(xmlElement_t&, BombAttributes&);
    virtual ~Initializer();
    
    int load() const;
    
};



#endif /* end of include guard: _BOMB_HPP_ */
