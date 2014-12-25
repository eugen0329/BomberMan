#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

#include <vector>
#include <queue>
#include "Game/WObjects/IWorldsObject.hpp"


class Actor : public IWorldsObject {
protected:
    struct Attributes : public IWorldsObject::Attributes {
        Vec2<float> v;
        float vMax;
        Vec2<float> origin;
        texture_t texture;
        sprite_t  sprite;
    };
public:
    Actor(GameMap &, wObjects_t&, window_t&);
    Actor();
    virtual ~Actor();

    virtual void addCollision(Collision) = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;

    virtual IWorldsObject::Attributes& getAttr() = 0;
    virtual void setWorldObjects(wObjects_t&) = 0;


};

#endif /* end of include guard: _ACTOR_HPP_ */
