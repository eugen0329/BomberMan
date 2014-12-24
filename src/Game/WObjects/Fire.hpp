#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include "TinyXML/tinyxml.h"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Vec2.hpp"
#include "Common/Algorithms.hpp"
#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Item.hpp"

#include "Rendering/AnimationManager.hpp"

class Fire : public Item {
protected:
    struct  Attributes : public Item::Attributes {
        Vec2<float> origin;
        float lifeTime;
        float actLifeTime;
        int damage;
        texture_t texture;
        sprite_t  sprite;
    };
protected:
    class Initializer;

    Fire::Attributes attr;
    Delegate destroyingSignal;
    Delegate createSignal;
    AnimationManager animationManager;
public:
    Fire();

    Fire(const IWorldsObject::Attributes&);
    Fire(const IWorldsObject::Attributes&, Vec2<float>);
    Fire(xmlElem_t&);
    virtual ~Fire();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    void loadAttr(xmlElem_t& elem);
    virtual IWorldsObject::Attributes& getAttr() 
    {
        return attr;
    }

    virtual void addCollision(Collision);
    virtual void handleCollisions();
    virtual void checkCollisions();

    virtual void setSignal(Delegate*, std::string);

    virtual void setWorldObjects(wObjects_t&);
};



class Fire::Initializer : public IInitializer {
private:
    mutable Fire::Attributes* attr; 
public:
    Initializer();
    Initializer(xmlElem_t&, Fire::Attributes&);
    virtual ~Initializer();
    
    int load() const;
    
};


#endif /* end of include guard: _FIRE_HPP_ */
