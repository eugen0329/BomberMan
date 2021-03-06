#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include "Game/WObjects/IWorldsObject.hpp"


class Item : public IWorldsObject {
protected:
    struct  Attributes : public IWorldsObject::Attributes {
    };
public:
    Item();
    Item(WObjects&, window_t&);
    virtual ~Item() {}

    virtual void setWorldObjects(WObjects&) = 0;

    virtual void addCollision(Collision) = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual IWorldsObject::Attributes& getAttr() = 0;

};


#endif /* end of include guard: _ITEM_HPP_ */
