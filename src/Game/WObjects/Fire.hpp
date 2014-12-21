#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include "TinyXML/tinyxml.h"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Vec2.hpp"
#include "Common/Algorithms.hpp"

#include "Game/Attributes/IAttributes.hpp"
#include "Game/Attributes/FireAttributes.hpp" 
#include "Game/WObjects/Item.hpp"

class Fire : public Item {
private:
    class Initializer;

    FireAttributes attrib;
    Delegate destroyingSignal;
    Delegate createSignal;
public:
    Fire();

    Fire(const IAttributes&);
    Fire(const IAttributes&, Vec2<float>);
    Fire(xmlElem_t&);
    virtual ~Fire();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IAttributes& getAttr() 
    {
        return attrib;
    }

    virtual void addCollision(Collision);
    virtual void handleCollisions();
    virtual void checkCollisions();

    virtual void setSignal(Delegate*, std::string);

    virtual void setWorldObjects(wObjects_t&);
};



class Fire::Initializer : public IInitializer {
private:
    mutable FireAttributes* attrib; 
public:
    Initializer();
    Initializer(xmlElem_t&, FireAttributes&);
    virtual ~Initializer();
    
    int load() const;
    
};


#endif /* end of include guard: _FIRE_HPP_ */
