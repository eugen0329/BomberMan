#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include "TinyXML/tinyxml.h"

#include "Common/Vec2.hpp"
#include "Common/Angle.hpp"
#include "Common/Algorithms.hpp"

#include "Game/DrawableScene.hpp"
#include "Game/WObjects/Item.hpp"
#include "Game/WObjects/Blow.hpp"
#include "Game/CollisionManager.hpp"

class DrawableScene;

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

    CollisionManager collisManager;

    Bomb::Attributes attr;
    Delegate destroyingSignal;
    Delegate createSignal;
public:
    Bomb();
    Bomb(const Vec2<float> pos, int groupId, float lifeTime);
    
    virtual ~Bomb();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    virtual IWorldsObject::Attributes& getAttr();

    void destroyWObject(IWObjectPtr object);
    void createWObject(IWObjectPtr object);

    virtual void addCollision(Collision);
    virtual void setWorldObjects(WObjects&);

    void load(xmlElem_t&);
    void makeFire();
    void makeFireWave(Angle&);
};

#endif /* end of include guard: _BOMB_HPP_ */
