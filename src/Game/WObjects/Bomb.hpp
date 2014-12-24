#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include "TinyXML/tinyxml.h"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Vec2.hpp"
#include "Common/Angle.hpp"
#include "Common/Algorithms.hpp"

#include "Game/WObjects/Item.hpp"
#include "Game/WObjects/Fire.hpp"
#include "Game/CollisionManager.hpp"

class Bomb : public Item {
protected:
    struct  Attributes : public Item::Attributes {
        Vec2<float> origin;
        float lifeTime;
        float actLifeTime;
    
        texture_t texture;
        sprite_t  sprite;
    };
    class Initializer;

    CollisionManager cManager;

    Bomb::Attributes attr;
    Delegate destroyingSignal;
    Delegate createSignal;
public:
    Bomb();

    Bomb(const IWorldsObject::Attributes&);
    Bomb(xmlElem_t&, const IWorldsObject::Attributes&);
    virtual ~Bomb();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IWorldsObject::Attributes& getAttr() 
    {
        return attr;
    }

    virtual void addCollision(Collision);
    virtual void handleCollisions();
    virtual void checkCollisions();


    virtual void setSignal(Delegate*, std::string);

    virtual void setWorldObjects(wObjects_t&);


    void load(xmlElem_t&);

    void makeFire();
    void makeFireWave(Angle&);
};

#endif /* end of include guard: _BOMB_HPP_ */
